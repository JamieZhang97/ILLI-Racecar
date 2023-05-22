#include "c2000BoardSupport.h"
#include "F2837xD_device.h"
#include "F2837xD_Examples.h"
#include "F2837xD_GlobalPrototypes.h"
#include "rtwtypes.h"
#include "F28379D_IPC_CPU2_2020a.h"
#include "F28379D_IPC_CPU2_2020a_private.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_can.h"
#include "driverlib/can.h"

void init_eCAN_B ( uint16_T bitRatePrescaler, uint16_T timeSeg1, uint16_T
                  timeSeg2, uint16_T sbg, uint16_T sjw, uint16_T sam)
{
  uint32_t ui32RegValue;
  uint16_t ui16CANCTL;
  EALLOW;
  CpuSysRegs.PCLKCR10.bit.CAN_B = 1;
  configureCPU2Peripherals(12, 0, 2);
  configureCPU2Peripherals(17, 0, 2);
  EDIS;
  ui32RegValue = (((uint32_T)((bitRatePrescaler-1) & 0x03C0))<<10)|((timeSeg2-1)<<
    12)|((timeSeg1-1)<<8)|((sjw-1)<<6)|((bitRatePrescaler-1) & 0x3F);
  CANInit(CANB_BASE);
  CANClkSourceSelect(CANB_BASE, 0);

  //Set init mode
  ui16CANCTL = HWREGH(CANB_BASE + CAN_O_CTL);
  HWREGH(CANB_BASE + CAN_O_CTL) = ui16CANCTL | CAN_CTL_INIT | CAN_CTL_CCE;

  //Set Bit Timing register
  HWREGH(CANB_BASE + CAN_O_BTR) = (ui32RegValue & CAN_REG_WORD_MASK);
  HWREGH(CANB_BASE + CAN_O_BTR + 2) = (ui32RegValue >> 16);

  // Restore the saved CAN Control register.
  HWREGH(CANB_BASE + CAN_O_CTL) = ui16CANCTL;
  HWREGH(CANB_BASE + CAN_O_IP_MUX21) = 0;
  HWREGH(CANB_BASE + CAN_O_IP_MUX21 + 2) = 0;

  // Enable the CAN for operation.
  CANEnable(CANB_BASE);
}
