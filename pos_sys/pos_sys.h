#pragma once

#include <QObject>

#include <opencv2/opencv.hpp>

using namespace cv;

class pos_t;

class track_t
{
public:
   track_t();
   ~track_t();
   
   pos_t get_pos( size_t i ) const;

   void add_pos( double x, double y );
   
   void draw_track( Mat & frame ) const;
   void draw_mesh ( Mat & frame ) const;
   
   pos_t mesh_coord( size_t i, size_t j ) const;

private:
   size_t   row_cnt_
          , col_cnt_;
   
   double   x_left_
          , x_right_
          , y_bottom_
          , y_top_;

   size_t max_positions_cnt_;
   
   size_t tile_idx_;
   
   int one_loop_in_done_ = 0;
      
   pos_t   * positions_
         , * mesh_;
          
   double   x_step_
          , y_step_;
};

class pos_sys_t : public QObject
{
   Q_OBJECT
      
public:
   pos_sys_t();
   ~pos_sys_t();
   
private:
   track_t track_;
};

struct pos_t
{
   pos_t( double x_val = 0, double y_val = 0 ) :
        x(x_val)
      , y(y_val)
   {}

   pos_t & operator = ( pos_t const & pos )
   {
      this->x = pos.x;
      this->y = pos.y;
   }

   double x, y;
};

