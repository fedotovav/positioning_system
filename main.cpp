#include <QApplication>

#include <omp.h>

#include <unistd.h> 

#include "gui/gui.h"
#include "object_track/obj_track.h"
#include "video_capture/video_capture.h"

int main( int argc, char ** argv )
{
   video_capture_ptr_t capture(new video_capture_t());
   
   obj_tracks_t tracks(new obj_track_ptr_t[capture->cameras_num()]);
   
   for (size_t i = 0; i < capture->cameras_num(); ++i)
      tracks.get()[i].reset(new obj_track_t(capture->get_camera(i), i));

   robot_cntrl_ptr_t robot_control(new robot_control_t(tracks.get()[0]));
   
   QApplication a(argc, argv);
   gui w(tracks, capture, robot_control);
   
   w.show();
   
   #pragma omp parallel num_threads(capture->cameras_num() + 2) shared(tracks, w)
   {
      size_t thread_idx = omp_get_thread_num();
      
      if (thread_idx == 0)
         a.exec();
      else if (thread_idx == 1)
         robot_control->loop();
      else
         tracks.get()[thread_idx - 2]->loop();
   }

   return 0;
}
