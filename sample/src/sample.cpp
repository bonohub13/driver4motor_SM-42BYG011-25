#include <iostream>
#include <cmath>

#include "../include/driver_pkg/include/motor.hpp"

void micro_step_wipe(Motor::SM_42BYG011 &motor)
{
    uint targetStep = 25; // 1.8[radius per step]*25 = 45.0

    for (uint i=0; i<2; i++)
        motor.micro_step_mode(targetStep, i%2, 0.075);

    motor.halt();
}

void half_step_wipe(Motor::SM_42BYG011 &motor)
{
    uint targetStep = 25; // 1.8[radius per step]*25 = 45.0

    for (uint i=0; i<2; i++)
        motor.half_step_mode(targetStep, i%2, 0.075);

    motor.halt();
}

void full_step_wipe(Motor::SM_42BYG011 &motor)
{
    uint targetStep = 25; // 1.8[radius per step]*25 = 45.0

    for (uint i=0; i<2; i++)
        motor.full_step_mode(targetStep, i%2, 0.075);

    motor.halt();
}

int main(int argc, char** argv)
{
    Motor::SM_42BYG011 motor("/dev/motor0");
    
    if (argc > 1)
    {
        if (argv[1] == "00")
            motor.micro_step_mode_spin(0, 0.75);
        else if (argv[1] == "01")
            motor.micro_step_mode_spin(1, 0.75);
        else if (argv[1] == "02")
            micro_step_wipe(motor);
        else if (argv[1] == "10")
            motor.full_step_mode_spin(0, 0.75);
        else if (argv[1] == "11")
            motor.full_step_mode_spin(1, 0.75);
        else if (argv[1] == "12")
            full_step_wipe(motor);
        else if (argv[1] == "20")
            motor.half_step_mode_spin(0, 0.75);
        else if (argv[1] == "21")
            motor.half_step_mode_spin(1, 0.75);
        else if (argv[1] == "22")
            half_step_wipe(motor);
    }
}