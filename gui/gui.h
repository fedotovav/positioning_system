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

#include "../object_track/obj_track.h"
#include "ui/gui_ui.h"
#include "ui/color_range_ui.h"
#include "ui/camera_settings_ui.h"
#include "ui/track_ui.h"

namespace Ui
{
   class track;
   class color_range;
   class camera_settings;
   class gui;
}

///////////////////////////////////////
/// track window
///////////////////////////////////////

class track : public QMainWindow
{
   Q_OBJECT

public:
   track( obj_track_t * obj_track_, QWidget * parent = 0 );
   ~track();
   
   void set_layout();

private:
   
   obj_track_t * obj_track_;

   Ui::track * track_;
};

///////////////////////////////////////
/// color range window
///////////////////////////////////////

class color_range : public QMainWindow
{
   Q_OBJECT

public:
   color_range( obj_track_t * obj_track_, QWidget * parent = 0 );
   ~color_range();

private:
   
   Q_SLOT void set_h_min( int val );
   Q_SLOT void set_h_max( int val );
   Q_SLOT void set_s_min( int val );
   Q_SLOT void set_s_max( int val );
   Q_SLOT void set_v_min( int val );
   Q_SLOT void set_v_max( int val );
   
   obj_track_t * obj_track_;

   Ui::color_range * color_range_;
};

///////////////////////////////////////
/// camera settings window
///////////////////////////////////////

class camera_settings : public QMainWindow
{
   Q_OBJECT

public:
   camera_settings( obj_track_t * obj_track_, QWidget * parent = 0 );
   ~camera_settings();
   
private:
   
   Q_SLOT void set_brightness_hardware( double val );
   Q_SLOT void set_contrast_hardware  ( double val );
   Q_SLOT void set_saturation_hardware( double val );
   Q_SLOT void set_hue_hardware       ( double val );
   Q_SLOT void set_gain_hardware      ( double val );
   Q_SLOT void set_exposure_hardware  ( double val );
   Q_SLOT void set_brightness_software( double val );
   Q_SLOT void set_contrast_software  ( double val );

   obj_track_t * obj_track_;

   Ui::camera_settings * camera_settings_;
};

///////////////////////////////////////
/// MAIN window
///////////////////////////////////////

class gui : public QMainWindow
{
   Q_OBJECT

public:
   gui( obj_track_t * ot, QWidget * parent = 0 );
   ~gui();

   Q_SLOT void redraw( QImage image );

   Q_SLOT void call_color_range_win         ();
   Q_SLOT void call_camera_settings_win     ();
   Q_SLOT void call_camera_settings_save_win();
   Q_SLOT void call_record_track            ();
   Q_SLOT void call_play_track              ();

   void closeEvent( QCloseEvent* event );

private:
   Ui::gui * ui_;

   obj_track_t * obj_track_;
   
   color_range     * cr_win_;
   camera_settings * cs_win_;
   track           * t_win_;
};
