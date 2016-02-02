#pragma once

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QTimer>
#include <QObject>

class robot_control_t : public QObject
{
   Q_OBJECT
   
public:
   robot_control_t ( obj_track_ptr_t obj_track1, obj_track_ptr_t obj_track2 );
   ~robot_control_t();
   
   Q_SLOT void start_robot();
   Q_SLOT void stop_robot ();

   void stop();
   
   void loop();
   
private:
   
   Q_SLOT void get_robot_pos1( double x, double y );
   Q_SLOT void get_robot_pos2( double x, double y );
   
private:
   int   robot_is_run_
       , need_stop_;
   
   pos_t   position1_
         , position2_;
   
   obj_track_ptr_t   obj_track1_
                   , obj_track2_;
   
   track_ptr_t track_;
};
