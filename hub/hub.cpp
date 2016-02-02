#include "hub.h"
#include "util.h"
hub_t* hub_t::p_instance = nullptr;

hub_t::hub_t( )
{

}

void hub_t::frame_is_ready( cv::Mat mat )
{
#ifndef NOGUI
   this->gui_ptr->redraw(cvMatToQImage(mat));
#endif
}

void hub_t::position_is_ready( double x, double y, size_t obj_idx )
{

}

hub_t* hub_t::getInstance( )
{
   return p_instance;
}