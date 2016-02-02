#pragma once
#include <opencv2/opencv.hpp>
#include "../gui/gui.h"
#include "../camera/camera.h"

class hub_t
{
private:
   static hub_t * p_instance;

   // Конструкторы и оператор присваивания недоступны клиентам
   hub_t( );
   hub_t( const hub_t& );
   hub_t& operator=(hub_t&);
public:
   static hub_t * getInstance( );
#ifndef NOGUI
   gui* gui_ptr;
#endif
   camera_t** camera_ptr;
   //CAMERA
   void frame_is_ready( cv::Mat );
   void position_is_ready( double x, double y, size_t obj_idx );


};
