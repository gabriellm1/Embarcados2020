#include "system.h"
#include <stdio.h>
#include <alt_types.h>
#include <io.h> /* Leiutura e escrita no Avalon */

#include "actions.h"


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

	  usleep(10000000);
	  printf("-------------sleep------------ \n");

	  disable_motor(p_motor);


  return 0;
}
