#include "c2000BoardSupport.h"
#include "F2837xD_device.h"
#include "F2837xD_Examples.h"
#include "F2837xD_GlobalPrototypes.h"
#include "rtwtypes.h"
#include "F28379D_IPC_CPU2_2020a.h"
#include "F28379D_IPC_CPU2_2020a_private.h"

extern void configureInputXBar(uint32_T gpioNumber, uint32_T inputXbarNumber);
void enableExtInterrupt (void);
void disableWatchdog(void)
{
  int *WatchdogWDCR = (void *) 0x7029;
  asm(" EALLOW ");
  *WatchdogWDCR = 0x0068;
  asm(" EDIS ");
}

interrupt void IPC1_INT_isr(void)
{
  volatile unsigned int PIEIER1_stack_save = PieCtrlRegs.PIEIER1.all;
  PieCtrlRegs.PIEIER1.all &= ~8256;
                              /*disable group1 lower/equal priority interrupts*/
  asm(" RPT #5 || NOP");               /*wait 5 cycles        */
  IFR &= ~1;      /*eventually disable lower/equal priority pending interrupts*/
  PieCtrlRegs.PIEACK.all = 1;
                   /*ACK to allow other interrupts from the same group to fire*/
  IER |= 1;
  EINT;                                /*global interrupt enable*/
  isr_int1pie14_task_fcn();
  DINT;
  /* disable global interrupts during context switch, CPU will enable global interrupts after exiting ISR    */
  PieCtrlRegs.PIEIER1.all = PIEIER1_stack_save;
                                   /*restore PIEIER register that was modified*/
  PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
                                     /* Acknowledge to receive more interrupts*/
}

void enable_interrupts()
{
  EALLOW;
  PieVectTable.IPC1_INT = &IPC1_INT_isr;/* Hook interrupt to the ISR*/
  EDIS;
  PieCtrlRegs.PIEIER1.bit.INTx14 = 1;  /* Enable interrupt IPC1_INT*/
  IER |= M_INT1;

  /* Enable global Interrupts and higher priority real-time debug events:*/
  EINT;                                /* Enable Global interrupt INTM*/
  ERTM;                               /* Enable Global realtime interrupt DBGM*/
}

void configureGPIOExtInterrupt (void)
{
}

void enableExtInterrupt (void)
{
}
