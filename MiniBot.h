//All pin assignments will be defined here
#define MOTOR_1_PWM_PIN       9    //Motor 1 PWM pin, will connect to motors DIR pin
#define MOTOR_2_PWM_PIN       10   //Motor 2 PWM pin, will connect to motors DIR pin
#define MOTOR_ENABLE_PIN      12  //Motor enable pin, will connect to both motor PWM inputs, drive HIGH to enable motors


///MiniBot.cpp function declarations
void buttoncommands(int buttnum, boolean pressed);
void stop_all_motors(void);
void enable_motors(void);
void disable_motors(void);
