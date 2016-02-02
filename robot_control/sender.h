#ifndef SENDER_H_INCLUDED
#define SENDER_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <SerialStream.h>
using namespace std;
using namespace LibSerial ;
void MySerialInit(SerialStream * serial_port_local,  char * p);
void send_ctr(SerialStream * serial_port,unsigned int ch1=0,unsigned int ch2=0,unsigned int ch3=0,unsigned int ch4=0,unsigned int ch5=0,unsigned int ch6=0);



#endif // SENDER_H_INCLUDED

