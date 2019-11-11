#ifndef SWITCHES_H
#define SWITCHES_H

#include "std_types.h"
#include "std_macros.h"
#include "std_micro_comp_conf.h"

extern volatile uint8 g_turn_counter;
extern volatile uint8    Hours,    Minutes ,   Seconds ;
extern volatile uint8    counter_H, counter_M, counter_S ,g_turn_counter ;

void switch_init();

void callBackTimer1(void);
void callBackin0 ();
void callBackin1 ();
void callBackin2 ();

#endif
