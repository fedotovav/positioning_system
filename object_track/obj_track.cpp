#include <chrono>
#include <algorithm>

#include "obj_track.h"

using namespace std;
using namespace cv;

obj_track_t::obj_track_t() : 
     terminate_     (0)
   , capture_       (0)
   , brightness_swr_(2)
   , contrast_swr_  (2)
{
   save_camera_hardware_settings();
}

obj_track_t::~obj_track_t()
{
   capture_.set(CV_CAP_PROP_BRIGHTNESS, brightness_hwr_);
   capture_.set(CV_CAP_PROP_CONTRAST, contrast_hwr_);
   capture_.set(CV_CAP_PROP_SATURATION, saturation_hwr_);
   capture_.set(CV_CAP_PROP_HUE, hue_hwr_);
   capture_.set(CV_CAP_PROP_GAIN, gain_hwr_);
   capture_.set(CV_CAP_PROP_EXPOSURE, exposure_hwr_);
}

inline QImage cvMatToQImage( cv::Mat const & frame )
{
   QImage img;
   
   if (frame.channels()== 3)
   {
      cv::cvtColor(frame, frame, CV_BGR2RGB);
      img = QImage((const unsigned char*)(frame.data), frame.cols, frame.rows, QImage::Format_RGB888);
   }
   else
   {
      img = QImage((const unsigned char*)(frame.data), frame.cols, frame.rows, QImage::Format_Indexed8);
   }
   
   return img;
}

void obj_track_t::loop()
{
   if (!capture_.isOpened())
      throw "Error: capture is not opened!";

   int   contrast_std              = 40
       , brightness_std            = 1000
       , max_contrast_std          = 3
       , max_contrast_std_trackbar = 5000;

   vector< vector<Point> > contours;
   vector< Vec4i >         hierarchy;
   
   ostringstream fps_string;
   
   fps_string << "FPS counting...";
   
   chrono::time_point<chrono::system_clock> time_point;
   
   time_point = chrono::system_clock::now();
   
   double time;

   while (!terminate_)
   {
      capture_.read(frame_);

      if (frame_.empty())
         break;
      
      frame_.convertTo(frame_, -1, contrast_swr_, brightness_swr_);

      frame_.copyTo(threshold_frm_);
      
      cvtColor(threshold_frm_, threshold_frm_, CV_BGR2HSV);

      inRange(threshold_frm_, Scalar(min_h_, min_s_, min_v_), Scalar(max_h_, max_s_, max_v_), threshold_frm_);

      findContours(threshold_frm_, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);

      Point2d center;
      
      double area;
      
      if (hierarchy.size())
      {
         for (int index = 0; index >= 0; index = hierarchy[index][0])
         {
				Moments moment = moments((cv::Mat)contours[index]);
				area = moment.m00;

            center.x = moment.m10 / area;
            center.y = moment.m01 / area;

            drawContours(frame_, contours, index, Scalar(0, 255, 0), 3, 8, hierarchy);
            
            circle(frame_, center, 10, Scalar(0, 0, 255), 2);
			}      
      }

      time = chrono::duration_cast<std::chrono::milliseconds>(chrono::system_clock::now() - time_point).count() / 1000.;
      
      time_point = chrono::system_clock::now();
      
      fps_string << "FPS: " << (60. / time);
      
      putText(frame_, fps_string.str(), Point2i(10, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255));
      
      fps_string.str("");
      fps_string.clear();
      
      emit frame_is_ready(cvMatToQImage(frame_));
   }
}

void obj_track_t::save_camera_hardware_settings()
{
   brightness_hwr_ = capture_.get(CV_CAP_PROP_BRIGHTNESS);
   contrast_hwr_   = capture_.get(CV_CAP_PROP_CONTRAST);
   saturation_hwr_ = capture_.get(CV_CAP_PROP_SATURATION);
   hue_hwr_        = capture_.get(CV_CAP_PROP_HUE);
   gain_hwr_       = capture_.get(CV_CAP_PROP_GAIN);
   exposure_hwr_   = capture_.get(CV_CAP_PROP_EXPOSURE);
}

void obj_track_t::set_brightness_hwr( double val )
{
   capture_.set(CV_CAP_PROP_BRIGHTNESS, val);
}

void obj_track_t::set_contrast_hwr( double val )
{
   capture_.set(CV_CAP_PROP_CONTRAST, val);
}

void obj_track_t::set_saturation_hwr( double val )
{
   capture_.set(CV_CAP_PROP_SATURATION, val);
}

void obj_track_t::set_hue_hwr( double val )
{
   capture_.set(CV_CAP_PROP_HUE, val);
}

void obj_track_t::set_gain_hwr( double val )
{
   capture_.set(CV_CAP_PROP_GAIN, val);
}

void obj_track_t::set_exposure_hwr( double val )
{
   capture_.set(CV_CAP_PROP_EXPOSURE, val);
}

void obj_track_t::set_brightness_swr( double val )
{
   brightness_swr_ = val;
}

void obj_track_t::set_contrast_swr( double val )
{
   contrast_swr_ = val;
}

double obj_track_t::get_brightness_swr() const
{
   return brightness_swr_;
}

double obj_track_t::get_contrast_swr() const
{
   return contrast_swr_;
}

/////////////////////////////////////////
/// setters / getters
/////////////////////////////////////////

double obj_track_t::get_brightness_hwr() const
{
   return brightness_hwr_;
}

double obj_track_t::get_contrast_hwr() const
{
   return contrast_hwr_;
}

double obj_track_t::get_saturation_hwr() const
{
   return saturation_hwr_;
}

double obj_track_t::get_hue_hwr() const
{
   return hue_hwr_;
}

double obj_track_t::get_gain_hwr() const
{
   return gain_hwr_;
}

double obj_track_t::get_exposure_hwr() const
{
   return exposure_hwr_;
}

void obj_track_t::set_max_v( int max_v )
{
   this->max_v_ = max_v;
}

void obj_track_t::set_min_v( int min_v )
{
   this->min_v_ = min_v;
}

void obj_track_t::set_max_s( int max_s )
{
   this->max_s_ = max_s;
}

void obj_track_t::set_min_s( int min_s )
{
   this->min_s_ = min_s;
}

void obj_track_t::set_max_h( int max_h )
{
   this->max_h_ = max_h;
}

void obj_track_t::set_min_h( int min_h )
{
   this->min_h_ = min_h;
}

int obj_track_t::get_max_v() const
{
   return max_v_;
}

int obj_track_t::get_min_v() const
{
   return min_v_;
}

int obj_track_t::get_max_s() const
{
   return max_s_;
}

int obj_track_t::get_min_s() const
{
   return min_s_;
}

int obj_track_t::get_max_h() const
{
   return max_h_;
}

int obj_track_t::get_min_h() const
{
   return min_h_;
}

void obj_track_t::stop()
{
   terminate_ = 1;
}