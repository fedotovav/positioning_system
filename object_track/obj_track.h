#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <chrono>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d.hpp>

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QTimer>
#include <QObject>

using namespace cv;

class track_t
{
   struct pos_t
   {
      pos_t( double x_val = 0, double y_val = 0 ) :
           x(x_val)
         , y(y_val)
      {}

      pos_t & operator = ( pos_t const & pos )
      {
         this->x = pos.x;
         this->y = pos.y;
      }

      double x, y;
   };
   
public:
   track_t();
   ~track_t();
   
   pos_t get_pos( size_t i ) const;

   void add_pos( double x, double y );
   
   void draw_track( Mat & frame ) const;
   void draw_mesh ( Mat & frame ) const;
   
   pos_t mesh_coord( size_t i, size_t j ) const;
   
private:
   size_t   row_cnt_
          , col_cnt_;
   
   double   x_left_
          , x_right_
          , y_bottom_
          , y_top_;

   size_t max_positions_cnt_;
   
   size_t tile_idx_;
   
   int one_loop_in_done_ = 0;
      
   pos_t   * positions_
         , * mesh_;
          
   double   x_step_
          , y_step_;
};

class obj_track_t : public QObject
{
   Q_OBJECT
   
public:
   obj_track_t();
   ~obj_track_t();

   void loop();

   Q_SIGNAL void frame_is_ready( QImage image );
   
   void stop();

   void start_recording_track();
   void stop_recording_track();
   
   void draw_track     ();
   void stop_draw_track();

   void draw_mesh     ();
   void stop_draw_mesh();
   
   void set_max_v( int max_v );
   void set_min_v( int min_v );
   void set_max_s( int max_s );
   void set_min_s( int min_s );
   void set_max_h( int max_h );
   void set_min_h( int min_h );

   int get_min_h() const;
   int get_max_h() const;
   int get_min_s() const;
   int get_max_s() const;
   int get_min_v() const;
   int get_max_v() const;
   
   void set_min_obj_size( int max_h );
   void set_max_obj_size( int min_h );

   int get_min_obj_size() const;
   int get_max_obj_size() const;

   void set_brightness_hwr( double val );
   void set_contrast_hwr  ( double val );
   void set_saturation_hwr( double val );
   void set_hue_hwr       ( double val );
   void set_gain_hwr      ( double val );
   void set_exposure_hwr  ( double val );

   double get_brightness_hwr() const;
   double get_contrast_hwr  () const;
   double get_saturation_hwr() const;
   double get_hue_hwr       () const;
   double get_gain_hwr      () const;
   double get_exposure_hwr  () const;

   void save_camera_hardware_settings();
   
   void set_brightness_swr( double val );
   void set_contrast_swr  ( double val );

   double get_brightness_swr() const;
   double get_contrast_swr  () const;

private:
   VideoCapture capture_;

   Mat   frame_
       , threshold_frm_;
   
   int   min_h_ = 0, max_h_ = 255
       , min_s_ = 0, max_s_ = 255
       , min_v_ = 0, max_v_ = 255
       , min_obj_size_ = 0, max_obj_size_ = 10000;
   
   // store cam settings for restore in exit
   double   brightness_hwr_
          , contrast_hwr_
          , saturation_hwr_
          , hue_hwr_
          , gain_hwr_
          , exposure_hwr_;
   
   double   brightness_swr_
          , contrast_swr_;

   int   terminate_
       , start_recording_track_
       , draw_track_
       , draw_mesh_;
   
   track_t track_;
};
