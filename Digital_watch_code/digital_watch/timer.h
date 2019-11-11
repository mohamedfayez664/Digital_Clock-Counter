#ifndef TIMER_Init_H
#define TIMER_Init_H

#include "std_types.h"
#include "std_macros.h"
#include "std_micro_comp_conf.h"


typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}TIMER_Clock;

typedef enum
{
	TIMER0, TIMER0_OVF ,TIMER0_CTC ,TIMER0_Square_Wave,TIMER0_Fast_PWM, TIMER1
}TIMER_Type;


typedef struct
{
	TIMER_Type type;
	uint16 Reg_value;
	TIMER_Clock clock;

}TIMER_ConfigType;


/* timer 0 */

void TIMER0_init    (TIMER_ConfigType *Config_Ptr);
void TIMER0_CallBack(void(*a_ptr)(void));

/*   timer 1     */
void TIMER1_OVF_init  (uint16 init_start, uint8 clk_slect) ;  //need to modify
void TIMER1_CTC_A_init(uint16 comp_reg, uint8 clk_slect);

void TIMER1_OVF_CallBack  (void(*a_ptr)(void));
void TIMER1_CTC_A_CallBack(void(*a_ptr)(void));

void TIMER1_CTC_Square_Wave_init  (uint16 comp_regA, uint8 clk_slect);
void Timer1_Fast_PWM_n_invert_init(uint16 comp_regA, uint16 top,uint8 clk_slect);
void Timer1_Fast_PWM_n_invert_speed(uint16 comp_regA);

void TIMER_Start (uint8 timer_type, uint8 clk_slect);
void TIMER_Stop  (uint8 timer_type);
void TIMER_Clear (uint8 timer_type);
void TIMER_Deinit(uint8 timer_type);

#if 0
/*   timer 2     */
void TIMER2_OVF_init(uint8 init_start, uint8 clk_slect);
void TIMER2_comp_init(uint8 comp_reg , uint8 clk_slect);

void TIMER2_OVF_CallBack(void(*a_ptr)(void));
void TIMER2_CTC_CallBack(void(*a_ptr)(void));

void TIMER2_CTC_Square_Wave_init  (uint8 comp_reg ,uint8 clk_slect);
void TIMER2_Fast_PWM_n_invert_init(uint8 comp_reg ,uint8 clk_slect);

void TIMER2_start(uint8 clk_slect);
void TIMER2_stop  (void);
void TIMER2_clear(void);
void TIMER2_deinit(void);

#endif

////////////////////////////////////////////////////////////////////////
void WDT_ON (uint8 WDClk);
void WDT_OFF(uint8 four_cycles);

#endif  //TIMER_Init_H
