#pragma once 

#include <QApplication>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QTimer>
#include <QObject>

#include <opencv2/opencv.hpp>

#include <vector>
#include <string>
#include <iostream>

#include <yaml-cpp/yaml.h>

#include "../object_track/obj_track.h"
#include "ui/gui_ui.h"
#include "ui/object_params_ui.h"
#include "ui/camera_settings_ui.h"

using namespace std;
using namespace YAML;

namespace Ui
{
   class object_params;
   class camera_settings;
   class gui;
}

///////////////////////////////////////
/// object parameters window
///////////////////////////////////////

class object_params : public QMainWindow
{
   Q_OBJECT

public:
   object_params( obj_track_ptr_t & obj_track_, QWidget * parent = 0 );
   ~object_params();
   
   void update_values();

private:
   
   Q_SLOT void set_h_min( int val );
   Q_SLOT void set_h_max( int val );
   Q_SLOT void set_s_min( int val );
   Q_SLOT void set_s_max( int val );
   Q_SLOT void set_v_min( int val );
   Q_SLOT void set_v_max( int val );

   Q_SLOT void set_obj_size_min( int val );
   Q_SLOT void set_obj_size_max( int val );
   
   obj_track_ptr_t  obj_track_;

   Ui::object_params * object_params_;
};

///////////////////////////////////////
/// camera settings window
///////////////////////////////////////

class camera_settings : public QMainWindow
{
   Q_OBJECT

public:
   camera_settings( obj_track_ptr_t & obj_track_, QWidget * parent = 0 );
   ~camera_settings();
   
   void update_values();
   
private:
   
   Q_SLOT void set_brightness_hardware( double val );
   Q_SLOT void set_contrast_hardware  ( double val );
   Q_SLOT void set_saturation_hardware( double val );
   Q_SLOT void set_hue_hardware       ( double val );
   Q_SLOT void set_gain_hardware      ( double val );
   Q_SLOT void set_exposure_hardware  ( double val );
   Q_SLOT void set_brightness_software( double val );
   Q_SLOT void set_contrast_software  ( double val );

   obj_track_ptr_t  obj_track_;

   Ui::camera_settings * camera_settings_;
};

///////////////////////////////////////
/// MAIN window
///////////////////////////////////////

class gui : public QMainWindow
{
   Q_OBJECT

public:
   gui( obj_track_ptr_t & ot, QWidget * parent = 0 );
   ~gui();

   Q_SLOT void redraw( QImage image );

   Q_SLOT void call_object_params_win       ();
   Q_SLOT void call_camera_settings_win     ();
   Q_SLOT void call_camera_settings_save_win();
   Q_SLOT void call_record_track            ();
   Q_SLOT void call_stop_record_track       ();
   Q_SLOT void call_show_track              ();
   Q_SLOT void call_show_mesh               ();
   Q_SLOT void import_settings              ();
   Q_SLOT void export_settings              ();

   void closeEvent( QCloseEvent* event );

private:
   Ui::gui * ui_;

   obj_track_ptr_t obj_track_;
   
   object_params   * op_win_;
   camera_settings * cs_win_;
   
public:
   struct settings_t
   {
      settings_t( obj_track_ptr_t & ot );
      
      void import_settings( string const & file_name );
      void export_settings( string const & file_name );
      
      typedef map<string, double *> map_dbl_t;
      typedef map<string, size_t *> map_ui_t;
      
      void get_settings_values_for_export     ();
      void update_settings_values_after_import();
      
      obj_track_ptr_t obj_track_;
   };

private:   
   settings_t settings_;
};
