#ifndef ACTIONS_H_
#define ACTIONS_H_

void enable_reset_motor(unsigned int *p_motor);

void disable_motor(unsigned int *p_motor);

void dir_change_motor(unsigned int *p_motor);

void change_vel(int vel,unsigned int *p_motor);

#endif
