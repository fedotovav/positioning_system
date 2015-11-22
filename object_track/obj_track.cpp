#include <chrono>
#include <algorithm>

#include "obj_track.h"

using namespace std;
using namespace cv;

obj_track_t::obj_track_t( camera_ptr_t camera, size_t idx ) : 
     terminate_            (0)
   , start_recording_track_(0)
   , draw_track_           (0)
   , draw_mesh_            (0)
   , camera_               (camera)
   , track_                (new track_t)
{
   ostringstream object_name;
   object_name << "object track " << idx;

   settings_.set_object_name(object_name.str());
   
   settings_.add_setting(&min_h_, "minimum hue"       );
   settings_.add_setting(&min_s_, "minimum saturation");
   settings_.add_setting(&min_v_, "minimum value"     );
   settings_.add_setting(&max_h_, "maximum hue"       );
   settings_.add_setting(&max_s_, "maximum saturation");
   settings_.add_setting(&max_v_, "maximum value"     );

   settings_.add_setting(&min_obj_size_, "minimum object size");
   settings_.add_setting(&max_obj_size_, "maximum object size");
}

obj_track_t::~obj_track_t()
{
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
   vector< vector<Point> > contours;
   vector< Vec4i >         hierarchy;
   
   ostringstream fps_string;
   
   fps_string << "FPS counting...";
   
   chrono::time_point<chrono::system_clock> time_point;
   
   time_point = chrono::system_clock::now();
   
   double time;

   Point2d center;

   double area;
   
   size_t positions_find;
   
   while (!terminate_)
   {
      camera_->get_frame(frame_);

      if (frame_.empty())
         break;
      
      frame_.copyTo(threshold_frm_);
      
      cvtColor(threshold_frm_, threshold_frm_, CV_BGR2HSV);

      inRange(threshold_frm_, Scalar(min_h_, min_s_, min_v_), Scalar(max_h_, max_s_, max_v_), threshold_frm_);

      findContours(threshold_frm_, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_NONE);

      center.x = center.y = 0;

      positions_find = 0;
      
      if (hierarchy.size())
      {
         for (int index = 0; index >= 0; index = hierarchy[index][0])
         {
				Moments moment = moments((cv::Mat)contours[index]);
				area = moment.m00;

            if (area > min_obj_size_ && area < max_obj_size_)
            {
               center.x += moment.m10 / area;
               center.y += moment.m01 / area;
            
               positions_find++;

               drawContours(frame_, contours, index, Scalar(0, 255, 0), 3, 8, hierarchy);
            }
			}      
      }
      
      if (positions_find)
      {
         center.x /= (double)positions_find;
         center.y /= (double)positions_find;

         if (start_recording_track_)
            track_->add_pos(center.x, center.y);
            
         circle(frame_, center, 10, Scalar(0, 0, 255), 2);
      }

      if (draw_track_)
         track_->draw_track(frame_);

      if (draw_mesh_)
         track_->draw_mesh(frame_);

      time = chrono::duration_cast<std::chrono::milliseconds>(chrono::system_clock::now() - time_point).count() / 1000.;
      
      time_point = chrono::system_clock::now();
      
      fps_string << "FPS: " << (60. / time);
      
      putText(frame_, fps_string.str(), Point2i(10, 30), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 0, 255));
      
      fps_string.str("");
      fps_string.clear();
      
      fps_string << "Position: " << "[" << center.x << ", " << center.y << "]";
      
      putText(frame_, fps_string.str(), Point2i(10, 60), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 0, 255));

      fps_string.str("");
      fps_string.clear();
      
      emit position_is_ready(center.x, center.y);
      emit frame_is_ready   (cvMatToQImage(frame_));
   }
}

void obj_track_t::draw_track()
{
   draw_track_ = 1;
}

void obj_track_t::stop_draw_track()
{
   draw_track_ = 0;
}

void obj_track_t::draw_mesh()
{
   draw_mesh_ = 1;
}

void obj_track_t::stop_draw_mesh()
{
   draw_mesh_ = 0;
}

void obj_track_t::stop()
{
   terminate_ = 1;
}

void obj_track_t::start_recording_track()
{
   start_recording_track_ = 1;
}

void obj_track_t::stop_recording_track()
{
   start_recording_track_ = 0;
}

void obj_track_t::import_settings( string const & file_name )
{
   settings_.import_settings(file_name);
}

void obj_track_t::export_settings( ofstream & output_file )
{
   settings_.export_settings(output_file);
}

/////////////////////////////////////////
/// setters / getters
/////////////////////////////////////////

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

void obj_track_t::set_min_obj_size( int min_size )
{
   min_obj_size_ = min_size;
}

void obj_track_t::set_max_obj_size( int max_size )
{
   max_obj_size_ = max_size;
}

int obj_track_t::get_min_obj_size() const
{
   return min_obj_size_;
}

int obj_track_t::get_max_obj_size() const
{
   return max_obj_size_;
}

///////////////////////////////////////////////
/// track methods
///////////////////////////////////////////////

track_t::track_t()
{
   row_cnt_ = 640;
   col_cnt_ = 480;

   x_left_   = 0;
   x_right_  = 640;
   y_bottom_ = 0;
   y_top_    = 480;

   tile_idx_ = 0;

   max_positions_cnt_ = 1000;

   positions_ = new pos_t[max_positions_cnt_];

   mesh_ = new pos_t[row_cnt_ * col_cnt_];

   x_step_ = (x_right_ - x_left_) / (col_cnt_ - 1);
   y_step_ = (y_top_ - y_bottom_) / (row_cnt_ - 1);
   
   for (size_t i = 0; i < row_cnt_; ++i)
      for (size_t j = 0; j < col_cnt_; ++j)
         mesh_[i * col_cnt_ + j] = pos_t(x_step_ * j, y_step_ * i);
}

track_t::~track_t()
{
   delete[] positions_;
   delete[] mesh_;
}

pos_t track_t::mesh_coord( size_t i, size_t j ) const
{
   return mesh_[i * col_cnt_ + j];
}

pos_t track_t::get_pos( size_t i ) const
{
   size_t idx;

   if (one_loop_in_done_)
   {
      idx = tile_idx_ + i;

      if (idx > max_positions_cnt_ - 1)
         idx -= max_positions_cnt_;
   }
   else
      idx = i;

   return positions_[idx];
}

void track_t::add_pos( double x, double y )
{
   if (tile_idx_ > max_positions_cnt_ - 1)
   {
      tile_idx_ = 0;

      one_loop_in_done_ = 1;
   }
   
   size_t   mesh_cell_x_idx = x / x_step_
          , mesh_cell_y_idx = y / y_step_;
   
   pos_t   left_top_node     = mesh_coord(mesh_cell_y_idx, mesh_cell_x_idx)
         , right_bottom_node = mesh_coord(mesh_cell_y_idx + 1, mesh_cell_x_idx + 1)
         , curr_pos(left_top_node.x + right_bottom_node.x, left_top_node.y + right_bottom_node.y);

   static int first_call = 1;
   
   curr_pos.x /= 2.;
   curr_pos.y /= 2.;

   if (first_call)
   {
      positions_[tile_idx_++] = curr_pos;
      
      first_call = 0;
      
      return;
   }

   pos_t prev_pos = positions_[tile_idx_ - 1];

   if (curr_pos.x == prev_pos.x && curr_pos.y == prev_pos.y)
      return;

   positions_[tile_idx_++] = curr_pos;
}

void track_t::draw_track( Mat & frame ) const
{
   size_t end_idx;

   if (one_loop_in_done_)
      end_idx = max_positions_cnt_ - 1;
   else if (tile_idx_ > 0)
      end_idx = tile_idx_ - 1;
   else
      return;

   for (size_t i = 0; i < end_idx; ++i)
      line(frame, Point(get_pos(i).x, get_pos(i).y), Point(get_pos(i + 1).x, get_pos(i + 1).y), Scalar(255, 255 * i / max_positions_cnt_, 255 * i / max_positions_cnt_), 2);
}
   
void track_t::draw_mesh( Mat & frame ) const
{
   Scalar color(0, 255, 255);
   
   for (size_t i = 0; i < row_cnt_ - 1; ++i)
      for (size_t j = 0; j < col_cnt_ - 1; ++j)
      {
         line(frame, Point(mesh_coord(i, j).x, mesh_coord(i, j).y), Point(mesh_coord(i, j + 1).x, mesh_coord(i, j + 1).y), color, 1);
         line(frame, Point(mesh_coord(i, j).x, mesh_coord(i, j).y), Point(mesh_coord(i + 1, j).x, mesh_coord(i + 1, j).y), color, 1);
         line(frame, Point(mesh_coord(i + 1, j).x, mesh_coord(i + 1, j).y), Point(mesh_coord(i + 1, j + 1).x, mesh_coord(i + 1, j + 1).y), color, 1);
         line(frame, Point(mesh_coord(i, j + 1).x, mesh_coord(i, j + 1).y), Point(mesh_coord(i + 1, j + 1).x, mesh_coord(i + 1, j + 1).y), color, 1);
      }
}
