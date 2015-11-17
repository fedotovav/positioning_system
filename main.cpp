#include <QApplication>

#include <omp.h>

#include <unistd.h> 

#include "gui/gui.h"
#include "object_track/obj_track.h"

int main( int argc, char ** argv )
{
   obj_track_ptr_t track(new obj_track_t());

   QApplication a(argc, argv);
   gui w(track);
   
   w.show();
   
   #pragma omp parallel num_threads(2) shared(track, w)
   {
      if (omp_get_thread_num() == 0)
         a.exec();
      else if (omp_get_thread_num() == 1)
         track->loop();
   }

   return 0;
}
