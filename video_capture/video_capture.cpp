#include "video_capture.h"

camera_t::camera_t( size_t idx )
{
   ostringstream object_name;
   object_name << "camera " << idx;

   settings_.set_object_name(object_name.str());
}

void camera_t::update_capture( cv_video_capture_ptr_t capture )
{
   capture_ = capture;
   
   settings_for_restore_.brightness_hwr_ = capture_->get(CV_CAP_PROP_BRIGHTNESS);
   settings_for_restore_.contrast_hwr_   = capture_->get(CV_CAP_PROP_CONTRAST);
   settings_for_restore_.saturation_hwr_ = capture_->get(CV_CAP_PROP_SATURATION);
   settings_for_restore_.hue_hwr_        = capture_->get(CV_CAP_PROP_HUE);
   settings_for_restore_.gain_hwr_       = capture_->get(CV_CAP_PROP_GAIN);
   settings_for_restore_.exposure_hwr_   = capture_->get(CV_CAP_PROP_EXPOSURE);
   
   intermediate_settings_ = settings_for_restore_;
   
   intermediate_settings_.brightness_swr_ = 2;
   intermediate_settings_.contrast_swr_   = 2;
   
   settings_.add_setting(&intermediate_settings_.brightness_hwr_, "brightness hardware");
   settings_.add_setting(&intermediate_settings_.contrast_hwr_, "contrast hardware");
   settings_.add_setting(&intermediate_settings_.saturation_hwr_, "saturation hardware");
   settings_.add_setting(&intermediate_settings_.hue_hwr_, "hue hardware");
   settings_.add_setting(&intermediate_settings_.gain_hwr_, "gain hardware");
   settings_.add_setting(&intermediate_settings_.exposure_hwr_, "exposure hardware");
   settings_.add_setting(&intermediate_settings_.brightness_swr_, "brightness software");
   settings_.add_setting(&intermediate_settings_.contrast_swr_, "contrast software");
}

void camera_t::get_frame( Mat & frame )
{
   capture_->read(frame);
   
   frame.convertTo(frame, -1, intermediate_settings_.contrast_swr_, intermediate_settings_.brightness_swr_);
}

camera_t::~camera_t()
{
   set_hardware_settings(settings_for_restore_);
}

void camera_t::import_settings( string const & file_name )
{
   settings_.import_settings(file_name);
   
   set_hardware_settings(intermediate_settings_);
}

void camera_t::export_settings( ofstream & output_file )
{
   settings_.export_settings(output_file);
}

void camera_t::set_hardware_settings( camera_settings_t const & settings )
{
   capture_->set(CV_CAP_PROP_BRIGHTNESS, settings.brightness_hwr_);
   capture_->set(CV_CAP_PROP_CONTRAST, settings.contrast_hwr_);
   capture_->set(CV_CAP_PROP_SATURATION, settings.saturation_hwr_);
   capture_->set(CV_CAP_PROP_HUE, settings.hue_hwr_);
   capture_->set(CV_CAP_PROP_GAIN, settings.gain_hwr_);
   capture_->set(CV_CAP_PROP_EXPOSURE, settings.exposure_hwr_);
}

///////////////////////////////////////////////////////
/// setters / getters
///////////////////////////////////////////////////////

void camera_t::set_brightness_hwr( double val )
{
   capture_->set(CV_CAP_PROP_BRIGHTNESS, val);
}

void camera_t::set_contrast_hwr( double val )
{
   capture_->set(CV_CAP_PROP_CONTRAST, val);
}

void camera_t::set_saturation_hwr( double val )
{
   capture_->set(CV_CAP_PROP_SATURATION, val);
}

void camera_t::set_hue_hwr( double val )
{
   capture_->set(CV_CAP_PROP_HUE, val);
}

void camera_t::set_gain_hwr( double val )
{
   capture_->set(CV_CAP_PROP_GAIN, val);
}

void camera_t::set_exposure_hwr( double val )
{
   capture_->set(CV_CAP_PROP_EXPOSURE, val);
}

void camera_t::set_brightness_swr( double val )
{
   intermediate_settings_.brightness_swr_ = val;
}

void camera_t::set_contrast_swr( double val )
{
   intermediate_settings_.contrast_swr_ = val;
}

double camera_t::get_brightness_swr() const
{
   return intermediate_settings_.brightness_swr_;
}

double camera_t::get_contrast_swr() const
{
   return intermediate_settings_.contrast_swr_;
}

double camera_t::get_brightness_hwr() const
{
   return intermediate_settings_.brightness_hwr_;
}

double camera_t::get_contrast_hwr() const
{
   return intermediate_settings_.contrast_hwr_;
}

double camera_t::get_saturation_hwr() const
{
   return intermediate_settings_.saturation_hwr_;
}

double camera_t::get_hue_hwr() const
{
   return intermediate_settings_.hue_hwr_;
}

double camera_t::get_gain_hwr() const
{
   return intermediate_settings_.gain_hwr_;
}

double camera_t::get_exposure_hwr() const
{
   return intermediate_settings_.exposure_hwr_;
}

//////////////////////////////////////////
/// video capture
//////////////////////////////////////////

video_capture_t::video_capture_t( )
{
   size_t   cameras_num = 0
          , max_cameras_num = 10;
   
   int stop_cam_emumerated = 0;

   VideoCapture ** capture = new VideoCapture *[max_cameras_num];
   
   while (!stop_cam_emumerated)
   {
      capture[cameras_num] = new VideoCapture(cameras_num);
      
      if (capture[cameras_num]->isOpened())
         cameras_num++;
      else
         stop_cam_emumerated = 1;
   }
   
   if (!cameras_num)
   {
      cerr << "No one camera detect!" << endl;

      return;
   }
   
   cameras_num_ = cameras_num;
   
   cameras_.reset(new camera_ptr_t[cameras_num]);
   
   for (size_t i = 0; i < cameras_num; ++i)
   {
      cameras_.get()[i].reset(new camera_t(i));
      
      cameras_.get()[i]->update_capture(cv_video_capture_ptr_t(capture[i]));
   }
      
   delete capture[cameras_num];
      
   delete[] capture;
}

video_capture_t::~video_capture_t()
{
}

camera_ptr_t video_capture_t::get_camera( size_t idx )
{
   return cameras_.get()[idx];
}

size_t video_capture_t::cameras_num() const
{
   return cameras_num_;
}
