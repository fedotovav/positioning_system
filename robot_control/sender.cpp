#pragma GCC diagnostic ignored "-Wnarrowing"

#include "sender.h"
//using namespace std;
//using namespace LibSerial ;
//extern SerialStream serial_port_local;



SerialStream * serial_port_local;

void MySerialInit(SerialStream * serial_port_local,  char * p){
     char c;
     serial_port_local->Open(p) ;
     if ( ! serial_port_local->good() )
     {
         std::cerr << "[" << __FILE__ << ":" << __LINE__ << "] "
                   << "Error: Could not open serial port."
                   << std::endl ;
         exit(1) ;
     }

     // Set the baud rate of the serial port.
     serial_port_local->SetBaudRate( SerialStreamBuf::BAUD_57600 ) ;
     if ( ! serial_port_local->good() )
     {
         std::cerr << "Error: Could not set the baud rate." <<std::endl ;
         exit(1) ;
     }
     //
     // Set the number of data bits.
     serial_port_local->SetCharSize( SerialStreamBuf::CHAR_SIZE_8 ) ;
     if ( ! serial_port_local->good() )
     {
         std::cerr << "Error: Could not set the character size." <<std::endl ;
         exit(1) ;
     }
     //
     // Disable parity.
     serial_port_local->SetParity( SerialStreamBuf::PARITY_NONE ) ;
     if ( ! serial_port_local->good() )
     {
         std::cerr << "Error: Could not disable the parity." <<std::endl ;
         exit(1) ;
     }
     //
     // Set the number of stop bits.
     serial_port_local->SetNumOfStopBits( 1 ) ;
     if ( ! serial_port_local->good() )
     {
         std::cerr << "Error: Could not set the number of stop bits." << std::endl ;
         exit(1) ;
     }
     //
     // Turn off hardware flow control.
     serial_port_local->SetFlowControl( SerialStreamBuf::FLOW_CONTROL_NONE ) ;
     if ( ! serial_port_local->good() )
     {
         std::cerr << "Error: Could not use hardware flow control."
                   << std::endl ;
         exit(1) ;
     }

}

void send_ctr(SerialStream * serial_port,unsigned int ch1,unsigned int ch2,unsigned int ch3,unsigned int ch4,unsigned int ch5,unsigned int ch6)
{
    unsigned int in_control[7];
    in_control[0]=0;
    in_control[1] = ch1+1500;
    in_control[2] = ch2+1500;
    in_control[3] = ch3+1500;
    in_control[4] = ch4+1500;
    in_control[5] = ch5+1500;
    in_control[6] = ch6+1500;
    char send_mas[] = {83,116,3,232,3,232,3,232,3,232,3,232,3,232,5};//"St012345678901=";//83,116
    for(int i=1; i<=6; i++)
    {
        send_mas[2*i]=in_control[i]/256;
        send_mas[2*i+1]=in_control[i]%256;
    }

    //контрольная сумма
    char cs;
    cs=0;
    for(int i=2; i<=13; i++)
    {
        cs = cs+send_mas[i];
    }
    send_mas[14]=cs%256;
    serial_port->write( send_mas,sizeof(send_mas) ) ;
    //
}

#pragma GCC diagnostic pop