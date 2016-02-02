#include "pos_sys.h"

pos_sys_t::pos_sys_t( )
{

}

pos_sys_t::~pos_sys_t( )
{

}

///////////////////////////////////////////////
/// track methods
///////////////////////////////////////////////

track_t::track_t()
{
   row_cnt_ = 64;
   col_cnt_ = 48;

   x_left_   = 0;
   x_right_  = 640;
   y_bottom_ = 0;
   y_top_    = 480;

   tile_idx_ = 0;

   max_positions_cnt_ = 1000;

   positions_ = new pos_t[max_positions_cnt_];

   mesh_ = new pos_t[row_cnt_ * col_cnt_];

   x_step_ = (x_right_ - x_left_) / (col_cnt_ - 1);
   y_step_ = (y_top_ - y_bottom_) / (row_cnt_ - 1);
   
   for (size_t i = 0; i < row_cnt_; ++i)
      for (size_t j = 0; j < col_cnt_; ++j)
         mesh_[i * col_cnt_ + j] = pos_t(x_step_ * j, y_step_ * i);
}

track_t::~track_t()
{
   delete[] positions_;
   delete[] mesh_;
}

pos_t track_t::mesh_coord( size_t i, size_t j ) const
{
   return mesh_[i * col_cnt_ + j];
}

pos_t track_t::get_pos( size_t i ) const
{
   size_t idx;

   if (one_loop_in_done_)
   {
      idx = tile_idx_ + i;

      if (idx > max_positions_cnt_ - 1)
         idx -= max_positions_cnt_;
   }
   else
      idx = i;

   return positions_[idx];
}

void track_t::add_pos( double x, double y )
{
   if (tile_idx_ > max_positions_cnt_ - 1)
   {
      tile_idx_ = 0;

      one_loop_in_done_ = 1;
   }
   
   size_t   mesh_cell_x_idx = x / x_step_
          , mesh_cell_y_idx = y / y_step_;
   
   pos_t   left_top_node     = mesh_coord(mesh_cell_y_idx, mesh_cell_x_idx)
         , right_bottom_node = mesh_coord(mesh_cell_y_idx + 1, mesh_cell_x_idx + 1)
         , curr_pos(left_top_node.x + right_bottom_node.x, left_top_node.y + right_bottom_node.y);

   static int first_call = 1;
   
   curr_pos.x /= 2.;
   curr_pos.y /= 2.;

   if (first_call)
   {
      positions_[tile_idx_++] = curr_pos;
      
      first_call = 0;
      
      return;
   }

   pos_t prev_pos = positions_[tile_idx_ - 1];

   if (curr_pos.x == prev_pos.x && curr_pos.y == prev_pos.y)
      return;

   positions_[tile_idx_++] = curr_pos;
}

void track_t::draw_track( Mat & frame ) const
{
   size_t end_idx;

   if (one_loop_in_done_)
      end_idx = max_positions_cnt_ - 1;
   else if (tile_idx_ > 0)
      end_idx = tile_idx_ - 1;
   else
      return;

   for (size_t i = 0; i < end_idx; ++i)
      line(frame, Point(get_pos(i).x, get_pos(i).y), Point(get_pos(i + 1).x, get_pos(i + 1).y), Scalar(255, 255 * i / max_positions_cnt_, 255 * i / max_positions_cnt_), 2);
}
   
void track_t::draw_mesh( Mat & frame ) const
{
   Scalar color(0, 255, 255);
   
   for (size_t i = 0; i < row_cnt_ - 1; ++i)
      for (size_t j = 0; j < col_cnt_ - 1; ++j)
      {
         line(frame, Point(mesh_coord(i, j).x, mesh_coord(i, j).y), Point(mesh_coord(i, j + 1).x, mesh_coord(i, j + 1).y), color, 1);
         line(frame, Point(mesh_coord(i, j).x, mesh_coord(i, j).y), Point(mesh_coord(i + 1, j).x, mesh_coord(i + 1, j).y), color, 1);
         line(frame, Point(mesh_coord(i + 1, j).x, mesh_coord(i + 1, j).y), Point(mesh_coord(i + 1, j + 1).x, mesh_coord(i + 1, j + 1).y), color, 1);
         line(frame, Point(mesh_coord(i, j + 1).x, mesh_coord(i, j + 1).y), Point(mesh_coord(i + 1, j + 1).x, mesh_coord(i + 1, j + 1).y), color, 1);
      }
}
