#include <stdio.h>
#include "system.h"
#include <alt_types.h>
#include <io.h> /* Leiutura e escrita no Avalon */

//#define SIM

// LED Peripheral
#define REG_DATA_OFFSET 1
#define REG_DATA_MOTOR_OFFSET 0
#define REG_DATA_MOTOR_MASK_ENABLE 1<<0
#define REG_DATA_MOTOR_MASK_DIR 1<<1
#define REG_DATA_MOTOR_MASK_VEL_MAX 0x03

int main(void){
//  unsigned int led = 0;
//  unsigned int *p_led = (unsigned int *) PERIPHERAL_LED_0_BASE;
  unsigned int *p_motor = (unsigned int *) MOTO_0_BASE;

#ifndef SIM
  printf("Embarcados++ \n");
#endif

  while(1){
//      if (led < 4){
//          *(p_led+REG_DATA_OFFSET) = (0x1 << led++);
//      }
//      else{
//          led = 0;
//      }

      *(p_motor+REG_DATA_MOTOR_OFFSET) = REG_DATA_MOTOR_MASK_ENABLE | REG_DATA_MOTOR_MASK_DIR;
      *(p_motor+REG_DATA_OFFSET) =   REG_DATA_MOTOR_MASK_VEL_MAX;
      printf("%x \n",*(p_motor+REG_DATA_OFFSET));
      usleep(10000000);
  };



  return 0;
}
