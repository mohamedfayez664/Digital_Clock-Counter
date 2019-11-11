/*watch */

#include "switches.h"
#include "sev_segment.h"

int main(void){

	switch_init();
	seven_seg_init();

	while(1){

		seg_display3(Seconds,Minutes,Hours);

		while(g_turn_counter)
        	seg_display3(counter_S, counter_M, counter_H);
	}
}
