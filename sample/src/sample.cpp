#include <iostream>
#include <string>
#include <memory>
#include <cmath>

#include "../include/driver_pkg/include/motor.hpp"

void micro_step_wipe(std::unique_ptr<Motor::SM_42BYG011> &motor)
{
    uint targetStep = 75; // 1.8[radius per step]*25 = 45.0
    bool mode;

    for (uint i=0; i<2; i++)
    {
        mode = (i%2 == 0) ? false : true;
        motor->micro_step_mode(targetStep, mode, 0.075);
    }
}

void half_step_wipe(std::unique_ptr<Motor::SM_42BYG011> &motor)
{
    uint targetStep = 75; // 1.8[radius per step]*25 = 45.0
    bool mode;

    for (uint i=0; i<2; i++)
    {
        mode = (i%2 == 0) ? false : true;
        motor->half_step_mode(targetStep, mode, 0.075);
    }
}

void full_step_wipe(std::unique_ptr<Motor::SM_42BYG011> &motor)
{
    uint targetStep = 75; // 1.8[radius per step]*25 = 45.0
    bool mode;

    for (uint i=0; i<2; i++)
    {
        mode = (i%2 == 0) ? false : true;
        motor->full_step_mode(targetStep, mode, 0.075);
    }
}

int main(int argc, char** argv)
{
    Motor::SM_42BYG011_UniquePtr motor;
    auto mode = std::string(argv[1]);

    std::cout << "argc: " << argc << std::endl;
    std::cout << "argv[1]: " << argv[1] << std::endl;

    motor = Motor::create_unique_SM_42BYG011("/dev/mystep0");

    if (argc > 1)
    {
        if (mode == "00")
            motor->micro_step_mode_spin(false, 0.075);
        else if (mode == "01")
            motor->micro_step_mode_spin(true, 0.075);
        else if (mode == "02")
            micro_step_wipe(motor);
        else if (mode == "10")
            motor->full_step_mode_spin(false, 0.075);
        else if (mode == "11")
            motor->full_step_mode_spin(true, 0.075);
        else if (mode == "12")
            full_step_wipe(motor);
        else if (mode == "20")
            motor->half_step_mode_spin(false, 0.075);
        else if (mode == "21")
            motor->half_step_mode_spin(true, 0.075);
        else if (mode == "22")
            half_step_wipe(motor);
    }
}
