#include <QApplication>

#include <omp.h>

#include <unistd.h> 

#include "gui/gui.h"

int main( int argc, char ** argv )
{
   QApplication a(argc, argv);

   gui w;
   
   w.show();
   
   a.exec();

   return 0;
}
