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
#include <memory>

#include "../object_track/obj_track.h"
#include "../video_capture/video_capture.h"
#include "ui/gui_ui.h"
#include "ui/object_params_ui.h"
#include "ui/camera_settings_ui.h"

using namespace std;

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
   object_params( obj_track_ptr_t obj_track_, QWidget * parent = 0 );
   virtual ~object_params();
   
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

   shared_ptr<Ui::object_params> object_params_;
};

///////////////////////////////////////
/// camera settings window
///////////////////////////////////////

class camera_settings : public QMainWindow
{
   Q_OBJECT

public:
   camera_settings( camera_ptr_t camera, QWidget * parent = 0 );
   virtual ~camera_settings();
   
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

   camera_ptr_t camera_;

   shared_ptr<Ui::camera_settings> camera_settings_;
};

///////////////////////////////////////
/// MAIN window
///////////////////////////////////////

class camera_menu_t : public QMenu
{
   Q_OBJECT
   
public:

   camera_menu_t( QWidget * ot_parent, QMenu * view_parent, shared_ptr<QMainWindow> gui, obj_track_ptr_t ot, camera_ptr_t camera, size_t idx );
   ~camera_menu_t();

   Q_SLOT void call_object_params_win  ();
   Q_SLOT void call_camera_settings_win();
   Q_SLOT void call_show_camera        ();
   
   Q_SIGNAL void make_this_camera_current( size_t camera_idx );
   
   void is_current( int is_current );

   shared_ptr<QMenu> camera_menu_;

   shared_ptr<QAction> object_params_;
   shared_ptr<QAction> camera_settings_;
   shared_ptr<QAction> view_camera_;

   obj_track_ptr_t obj_track_;

   camera_ptr_t camera_;

   shared_ptr<object_params>   op_win_;
   shared_ptr<camera_settings> cs_win_;
   
   size_t idx_;
};

typedef shared_ptr<camera_menu_t>     camera_menu_ptr_t;
typedef shared_ptr<camera_menu_ptr_t> cameras_menues_t;

class gui : public QMainWindow
{
   Q_OBJECT

public:
   gui( obj_tracks_t ot, video_capture_ptr_t video_capture, QWidget * parent = 0 );
   ~gui();

   Q_SLOT void redraw( QImage image );

   Q_SLOT void call_record_track       ();
   Q_SLOT void call_stop_record_track  ();
   Q_SLOT void call_show_track         ();
   Q_SLOT void call_show_mesh          ();
   Q_SLOT void import_settings         ();
   Q_SLOT void export_settings         ();

   Q_SLOT void set_current_cam( size_t cam_idx );

   void closeEvent( QCloseEvent* event );

private:
   Ui::gui * ui_;
   
   shared_ptr<QMainWindow> gui_;

   obj_tracks_t obj_tracks_;
   
   video_capture_ptr_t video_capture_;
   
   cameras_menues_t ot_cam_menu_;
   
   size_t curr_cam_idx_;
   
   size_t cameras_num_;
};
