#include "robot_control.h"

robot_control_t::robot_control_t( obj_track_ptr_t obj_track ) :
     robot_is_run_(0)
   , need_stop_   (0)
   , obj_track_   (obj_track)
{
   connect(obj_track_.get(), SIGNAL(position_is_ready(pos_t)), this, SLOT(get_robot_pos(pos_t)));
}

robot_control_t::~robot_control_t()
{
}

Q_SLOT void robot_control_t::start_robot()
{
   robot_is_run_ = 1;
}

Q_SLOT void robot_control_t::stop_robot()
{
   robot_is_run_ = 0;
}

Q_SLOT void robot_control_t::get_robot_pos( double x, double y )
{
   position_.x = x;
   position_.y = y;
}

void robot_control_t::stop()
{
   need_stop_ = 1;
}

void robot_control_t::loop()
{
   while (!need_stop_)
   {
      if (!robot_is_run_)
         continue;
      
      cout << "Position: " << position_.x << ", " << position_.y << endl;
   }
}

