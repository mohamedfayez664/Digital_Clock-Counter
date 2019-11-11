#include "sev_segment.h"

void seven_seg_init(){
#if (N_OF_VALUES == 4)
	SEG_DATA_PORT_DIR  |= 0x0F;     //set 4pins(0,1,2,3) of data as output
	SEG_CTRL_PORT_DIR   = 0xFF;     //set control port output
	SEG_DATA_PORT_OUT  &=~0x0F;      //out 0 in the first
	SEG_CTRL_PORT_OUT   = 0x00;      //out 0 in the first

#elif (N_OF_VALUES == 3)
	SEG_DATA_PORT_DIR  |= 0x0F;     //set 4pins(0,1,2,3) of data as output
	SEG_CTRL_PORT_DIR  |= 0x3F;     //set 6pins(0,1,2,3,4,5)control port output
	SEG_DATA_PORT_OUT  &=~0x0F;      //out 0 in the first
	SEG_CTRL_PORT_OUT  &=~0x3F;      //out 0 in the first

#elif (N_OF_VALUES == 2)
	SEG_DATA_PORT_DIR   = 0xFF;     //set data and control pins(all port) as output
	SEG_DATA_PORT_OUT  &=~0x0F;      //out 0 in the first

#elif (N_OF_VALUES == 1)
	SEG_DATA_PORT_DIR  |= 0x3F;     //set data(0,1,2,3) and control(4,5) pins as output
	SEG_DATA_PORT_OUT  &=~0x3F;      //out 0 in the first

#endif
}

#if (N_OF_VALUES == 4)
void seg_display4(uint8 number1 ,uint8 number2 ,uint8 number3, uint8 number4)
{
	uint8 temp ;              //just variable
	temp = number1 % 10;   //to get fist num.
	SEG_CTRL_PORT_OUT = (1<<seg8);   //place to display
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f); //insert num in data port
	_delay_ms(delay_between_segments_ms);                  //dalay

	temp = number1 / 10;         //to get fist num.
	SEG_CTRL_PORT_OUT = (1<<seg7);         //place to display
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);  //insert num in data port
	_delay_ms(delay_between_segments_ms);

	temp = number2 % 10;
	SEG_CTRL_PORT_OUT = (1<<seg6);
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);
	_delay_ms(delay_between_segments_ms);

	temp = number2 / 10;
	SEG_CTRL_PORT_OUT = (1<<seg5);
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);
	_delay_ms(delay_between_segments_ms);

	////////////////////////////////////////////

	temp = number3 % 10;
	SEG_CTRL_PORT_OUT = (1<<seg4);
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);
	_delay_ms(delay_between_segments_ms);

	temp = number3 / 10;
	SEG_CTRL_PORT_OUT = (1<<seg3);
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);
	_delay_ms(delay_between_segments_ms);

	temp = number4 % 10;
	SEG_CTRL_PORT_OUT = (1<<seg2);
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);
	_delay_ms(delay_between_segments_ms);

	temp = number4 / 10;
	SEG_CTRL_PORT_OUT = (1<<seg1);
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);
	_delay_ms(delay_between_segments_ms);

}
#elif (N_OF_VALUES == 3)
void seg_display3(uint8 number1 ,uint8 number2 ,uint8 number3)
{
	uint8 temp ;              //just variable
	temp = number1 % 10;   //to get fist num.
	SEG_CTRL_PORT_OUT = (1<<seg6);   //place to display
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f); //insert num in data port
	_delay_ms(delay_between_segments_ms);                  //dalay

	temp = number1 / 10;         //to get fist num.
	SEG_CTRL_PORT_OUT = (1<<seg5);         //place to display
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);  //insert num in data port
	_delay_ms(delay_between_segments_ms);

	temp = number2 % 10;
	SEG_CTRL_PORT_OUT = (1<<seg4);
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);
	_delay_ms(delay_between_segments_ms);

	temp = number2 / 10;
	SEG_CTRL_PORT_OUT = (1<<seg3);
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);
	_delay_ms(delay_between_segments_ms);

	temp = number3 % 10;
//#if (TOOGLE == 3)
//	SEG_CTRL_PORT_OUT ^= (1<<seg2);
//#else
	SEG_CTRL_PORT_OUT  = (1<<seg2);
//#endif
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);
	_delay_ms(delay_between_segments_ms);

	temp = number3 / 10;
//#if (TOOGLE == 3)
//	SEG_CTRL_PORT_OUT ^= (1<<seg1);
//#else
	SEG_CTRL_PORT_OUT  = (1<<seg1);
//#endif
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);
	_delay_ms(delay_between_segments_ms);
}

#elif (N_OF_VALUES == 2)
void seg_display2(uint8 number1 ,uint8 number2 )
{
	uint8 temp ;              //just variable
	temp = number1 % 10;   //to get fist num.
	SEG_CTRL_PORT_OUT = (1<<seg8);   //place to display
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f); //insert num in data port
	_delay_ms(delay_between_segments_ms);                  //dalay

	temp = number1 / 10;         //to get fist num.
	SEG_CTRL_PORT_OUT = (1<<seg7);         //place to display
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);  //insert num in data port
	_delay_ms(delay_between_segments_ms);

	temp = number2 % 10;
	SEG_CTRL_PORT_OUT = (1<<seg6);
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);
	_delay_ms(delay_between_segments_ms);

	temp = number2 / 10;
	SEG_CTRL_PORT_OUT = (1<<seg5);
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);
	_delay_ms(delay_between_segments_ms);
}

#elif (N_OF_VALUES == 1)
void seg_display(uint8  number )
{
	uint8 temp;              //just variable
	temp = number % 10;      //to get fist num.
	SEG_CTRL_PORT_OUT = (1<<seg6);   //place to display
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f); //insert num in data port
	_delay_ms(delay_between_segments_ms);                   //dalay
  
	temp = number / 10;                    //to get fist num.
	SEG_CTRL_PORT_OUT = (1<<seg5);         //place to display
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);  //insert num in data port
	_delay_ms(delay_between_segments_ms);
}

#endif
