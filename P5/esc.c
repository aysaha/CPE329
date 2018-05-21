#include "msp.h"
#include "esc.h"

// initialize ESC output pins
void init_esc()
{
    // configure ESC_CTRL as PWM outputs
    ESC_CTRL->SEL1 &= ~(BIT7|BIT6|BIT5|BIT4);
    ESC_CTRL->SEL0 |= BIT7|BIT6|BIT5|BIT4;
    ESC_CTRL->DIR |= BIT7|BIT6|BIT5|BIT4;

    // setup TimerA for PWM
    TIMER_A0->CTL |= TIMER_A_CTL_TASSEL_1 | TIMER_A_CTL_MC__UP | TIMER_A_CTL_CLR;
    TIMER_A0->CCTL[1] |= TIMER_A_CCTLN_OUTMOD_7;
    TIMER_A0->CCTL[2] |= TIMER_A_CCTLN_OUTMOD_7;
    TIMER_A0->CCTL[3] |= TIMER_A_CCTLN_OUTMOD_7;
    TIMER_A0->CCTL[4] |= TIMER_A_CCTLN_OUTMOD_7;
    TIMER_A0->CCR[0] = 655;
    TIMER_A0->CCR[1] = 33;
    TIMER_A0->CCR[2] = 33;
    TIMER_A0->CCR[3] = 33;
    TIMER_A0->CCR[4] = 33;
}