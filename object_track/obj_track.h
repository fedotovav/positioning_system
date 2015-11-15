#pragma once

#include <string>
#include <iostream>
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

class obj_track_t : public QObject
{
   Q_OBJECT
   
public:
   obj_track_t();
   ~obj_track_t();

   void loop();

   Q_SIGNAL void frame_is_ready( QImage image );
   
   void stop();
   
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
       , min_v_ = 0, max_v_ = 255;
   
   // store cam settings for restore in exit
   double   brightness_hwr_
          , contrast_hwr_
          , saturation_hwr_
          , hue_hwr_
          , gain_hwr_
          , exposure_hwr_;
   
   double   brightness_swr_
          , contrast_swr_;

   int terminate_;
};
