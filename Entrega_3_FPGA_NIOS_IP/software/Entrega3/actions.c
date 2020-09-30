#include <stdio.h>
#include "system.h"
#include <alt_types.h>
#include <io.h> /* Leiutura e escrita no Avalon */

#include "actions.h"


#define REG_DATA_VEL_OFFSET 1
#define REG_DATA_MOTOR_OFFSET 0
#define REG_DATA_MOTOR_MASK_ENABLE 1<<0
#define REG_DATA_MOTOR_MASK_DIR 1<<1
#define REG_DATA_MOTOR_MASK_VEL_MAX 0x03


void enable_reset_motor(unsigned int *p_motor){
	printf("Enable/Reset Motor \n");
	*(p_motor+REG_DATA_MOTOR_OFFSET) = *(p_motor+REG_DATA_MOTOR_OFFSET) & 0x02;
	  usleep(10000);
	 *(p_motor+REG_DATA_MOTOR_OFFSET) = *(p_motor+REG_DATA_MOTOR_OFFSET) | 0x01;
}

void disable_motor(unsigned int *p_motor){
	printf("Disable Motor \n");
	*(p_motor+REG_DATA_MOTOR_OFFSET) = 0;
}

void dir_change_motor(unsigned int *p_motor){
	printf("Motor Direction Change Triggered \n");
	*(p_motor+REG_DATA_MOTOR_OFFSET) ^= (0x02);
}

void change_vel(int vel,unsigned int *p_motor){
	printf("Motor Velocity Change Triggered to %d \n",(vel));

	switch (vel){

	case 0:
		*(p_motor+REG_DATA_VEL_OFFSET) =   0x00;
		break;

	case 1:
		*(p_motor+REG_DATA_VEL_OFFSET) =   0x01;
		break;

	case 2:
		*(p_motor+REG_DATA_VEL_OFFSET) =   0x02;
		break;

	case 3:
		*(p_motor+REG_DATA_VEL_OFFSET) =   REG_DATA_MOTOR_MASK_VEL_MAX;
		break;

	};
}
