#pragma once

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QTimer>
#include <QObject>

#include "../object_track/obj_track.h"

class robot_control_t : public QObject
{
   Q_OBJECT
   
public:
   robot_control_t ( obj_track_ptr_t obj_track );
   ~robot_control_t();
   
   Q_SLOT void start_robot();
   Q_SLOT void stop_robot ();

   void stop();
   
   void loop();
   
private:
   
   Q_SLOT void get_robot_pos( double x, double y );
   
private:
   int   robot_is_run_
       , need_stop_;
   
   pos_t position_;
   
   obj_track_ptr_t obj_track_;
   
   track_ptr_t track_;
};

typedef shared_ptr<robot_control_t> robot_cntrl_ptr_t;