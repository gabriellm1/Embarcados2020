#include "system.h"
#include <stdio.h>
#include <alt_types.h>
#include <io.h> /* Leiutura e escrita no Avalon */

#include "actions.h"

//#define SIM

// LED Peripheral
//#define REG_DATA_VEL_OFFSET 1
//#define REG_DATA_MOTOR_OFFSET 0
//#define REG_DATA_MOTOR_MASK_ENABLE 1<<0
//#define REG_DATA_MOTOR_MASK_DIR 1<<1
//#define REG_DATA_MOTOR_MASK_VEL_MAX 0x03

int main(void){


  unsigned int *p_motor = (unsigned int *) MOTO_0_BASE;




	  change_vel(3,p_motor);
	  enable_reset_motor(p_motor);

	  usleep(10000000);
	  printf("-------------sleep------------ \n");

	  enable_reset_motor(p_motor);
	  dir_change_motor(p_motor);

	  usleep(10000000);
	  printf("-------------sleep------------ \n");

	  enable_reset_motor(p_motor);
	  dir_change_motor(p_motor);
	  change_vel(1,p_motor);

	  usleep(30000000);
	  printf("-------------sleep------------ \n");

	  disable_motor(p_motor);


  return 0;
}
