#pragma once

#include <memory>
#include <iostream>

#include <opencv2/opencv.hpp>

#include "../settings/settings.h"

using namespace std;
using namespace cv;

typedef shared_ptr<VideoCapture> cv_video_capture_ptr_t;

class camera_t
{
public:
   camera_t( size_t idx = 0 );
   ~camera_t();
   
   void update_capture( cv_video_capture_ptr_t capture );
   
   void get_frame( Mat & frame );
   
   void import_settings( string const & file_name );
   void export_settings( ofstream & output_file );

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

   void set_brightness_swr( double val );
   void set_contrast_swr  ( double val );

   double get_brightness_swr() const;
   double get_contrast_swr  () const;

private:
   struct camera_settings_t
   {
      double   brightness_hwr_
             , contrast_hwr_
             , saturation_hwr_
             , hue_hwr_
             , gain_hwr_
             , exposure_hwr_;

      double   brightness_swr_
             , contrast_swr_;
   };
   
   camera_settings_t  settings_for_restore_
                    , intermediate_settings_;

   void set_hardware_settings( camera_settings_t const & settings );

   cv_video_capture_ptr_t capture_;
   
   settings_t settings_;
};

typedef shared_ptr<camera_t>     camera_ptr_t;
typedef shared_ptr<camera_ptr_t> cameras_t;

class video_capture_t
{
public:
   video_capture_t();
   ~video_capture_t();
   
   camera_ptr_t get_camera( size_t idx );
   
   size_t cameras_num() const;
   
private:
   size_t cameras_num_;
   
   cameras_t cameras_;
};

typedef shared_ptr<video_capture_t> video_capture_ptr_t;