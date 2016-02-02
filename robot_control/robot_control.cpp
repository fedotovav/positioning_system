#include <chrono>
#include <cmath>

#include "robot_control.h"

#include "sender.h"

using namespace LibSerial;
using namespace std;

robot_control_t::robot_control_t( obj_track_ptr_t obj_track1, obj_track_ptr_t obj_track2 ) :
     robot_is_run_(0)
   , need_stop_   (0)
   , obj_track1_  (obj_track1)
   , obj_track2_  (obj_track2)
{
   track_ = obj_track1_->get_track();
   
   connect(obj_track1_.get(), SIGNAL(position_is_ready(double, double)), this, SLOT(get_robot_pos1(double, double)));
   connect(obj_track2_.get(), SIGNAL(position_is_ready(double, double)), this, SLOT(get_robot_pos2(double, double)));
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

Q_SLOT void robot_control_t::get_robot_pos1( double x, double y )
{
   position1_.x = x;
   position1_.y = y;
}

Q_SLOT void robot_control_t::get_robot_pos2( double x, double y )
{
   position2_.x = x;
   position2_.y = y;
}

void robot_control_t::stop()
{
   need_stop_ = 1;
}

void robot_control_t::loop()
{
   
   SerialStream serial_port;
   MySerialInit(&serial_port,"/dev/ttyACM0");

   pos_t   cur_position
         , point;
   
   pos_t tmp;
   
   pos_t dir, dir_to_point;
   
   double positive_or_negative_angel;
   
   int velocity1 = 100, velocity2 = 100, velocity = 170;
   
   chrono::time_point<chrono::system_clock> time_point;
   
   time_point = chrono::system_clock::now();
   
   while (!need_stop_)
   {
      if (!robot_is_run_)
         continue;

      // get robot orientation
      cur_position.x = (position1_.x + position2_.x) / 2.;
      cur_position.y = (position1_.y + position2_.y) / 2.;

      tmp.x = position1_.x - position2_.x;
      tmp.y = position1_.y - position2_.y;

      dir_to_point.x = point.x - cur_position.x;
      dir_to_point.y = point.y - cur_position.y;

      dir.x = tmp.y;
      dir.y = -tmp.x;
      
      positive_or_negative_angel = dir.x / sqrt(dir.x * dir.x + dir.y * dir.y);
      
      //positive_or_negative_angel = acos(positive_or_negative_angel);
      
      velocity2 = 0;

//      if (positive_or_negative_angel > 0)
//         velocity1 = velocity;
//      else
//         velocity1 = -velocity;
      
      velocity1 = velocity * positive_or_negative_angel;
      
//      if ((chrono::duration_cast<std::chrono::milliseconds>(chrono::system_clock::now() - time_point).count() / 1000.) > 0.05)
//      {
         send_ctr(&serial_port, velocity1, velocity2);
         
         time_point = chrono::system_clock::now();
\
         cout << positive_or_negative_angel << endl;
//      }
   }
}

