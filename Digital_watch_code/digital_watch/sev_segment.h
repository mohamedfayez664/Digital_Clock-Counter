#ifndef sev_seg_H
#define sev_seg_H

#include "std_types.h"
#include "std_macros.h"
#include "std_micro_comp_conf.h"

#define N_OF_VALUES   3
#define N_OF_SEGMENTS (2*N_OF_VALUES)

#define delay_between_segments_ms     5       //between every segment
/*in case of 4 segments data port is the same control port
 * but data in lower bins and control always begin from bin 4*/
#define SEG_DATA_PORT_DIR         DDRC   // to set port connect with BCD as output
#define SEG_DATA_PORT_OUT         PORTC     //to out data
#define SEG_CTRL_PORT_DIR         DDRA  // to set port connect with enables as output
#define SEG_CTRL_PORT_OUT         PORTA   //to out enables

//#define TOOGLE 0
enum {seg1,seg2,seg3,seg4,seg5,seg6,seg7,seg8};  //8 segments

void seven_seg_init();       //Initialization

#if (N_OF_VALUES == 4)
void seg_display4(uint8  ,uint8  ,uint8 , uint8 ,uint8 ); //to display
#elif (N_OF_VALUES == 3)
void seg_display3(uint8  ,uint8  ,uint8   ); //to display
#elif (N_OF_VALUES == 2)
void seg_display2(uint8  ,uint8   ); //to display
#elif (N_OF_VALUES == 1)
void seg_display(uint8   ); //to display
#endif

#endif //sev_seg_H
