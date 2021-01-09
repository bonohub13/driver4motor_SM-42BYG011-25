#include "motor.hpp"

Motor::SM_42BYG011::SM_42BYG011(std::string &devicePath)
{
    mode[0] = '0';
    mode[1] =  '\n';
    base = '0';
    counter = 0;
    device_path = devicePath;
}
Motor::SM_42BYG011::SM_42BYG011(std::string devicePath)
{
    mode[0] = '0';
    mode[1] =  '\n';
    base = '0';
    counter = 0;
    device_path = devicePath;
}
Motor::SM_42BYG011::~SM_42BYG011()
{
    this->halt();
    delete this;
}
void Motor::SM_42BYG011::sleep_(float seconds)
{
    uint sec = (uint)seconds;
    useconds_t usec = (useconds_t)((seconds - sec)*1e6);

    if (sec > 0)
        sleep(sec);
    usleep(usec);
}
void Motor::SM_42BYG011::micro_step_mode(uint32_t targetStep, bool mode, float seconds)
{
    counter = 0;
    targetStep = (mode) ? targetStep : targetStep*3;
    while (counter<targetStep)
    {
        this->mode[0] = counter%4 + 1 + base;
        dev_file.open(device_path);
        dev_file << this->mode;
        dev_file.close();

        counter = (mode) ? counter+1 : counter+3;
        sleep_(seconds);
    }
}
void Motor::SM_42BYG011::micro_step_mode(uint32_t &targetStep, bool &mode, float seconds)
{
    counter = 0;
    targetStep = (mode) ? targetStep : targetStep*3;
    while (counter<targetStep)
    {
        this->mode[0] = counter%4 + 1 + base;
        dev_file.open(device_path);
        dev_file << this->mode;
        dev_file.close();

        counter = (mode) ? counter+1 : counter+3;
        sleep_(seconds);
    }
}
void Motor::SM_42BYG011::half_step_mode(uint32_t targetStep, bool mode, float seconds)
{
    counter = 0;
    targetStep = (mode) ? targetStep : targetStep*7;
    while (counter<targetStep)
    {
        this->mode[0] = counter%8 + 1 + base;
        dev_file.open(device_path);
        dev_file << this->mode;
        dev_file.close();

        counter = (mode) ? counter+1 : counter+7;
        sleep_(seconds);
    }
}
void Motor::SM_42BYG011::half_step_mode(uint32_t &targetStep, bool &mode, float seconds)
{
    counter = 0;
    targetStep = (mode) ? targetStep : targetStep*7;
    while (counter<targetStep)
    {
        this->mode[0] = counter%8 + 1 + base;
        dev_file.open(device_path);
        dev_file << this->mode;
        dev_file.close();

        counter = (mode) ? counter+1 : counter+7;
        sleep_(seconds);
    }
}
void Motor::SM_42BYG011::full_step_mode(uint32_t targetStep, bool mode, float seconds)
{
    counter = 0;
    targetStep = (mode) ? targetStep : targetStep*3;
    while (counter<targetStep)
    {
        this->mode[0] = counter%4 + 5 + base;
        dev_file.open(device_path);
        dev_file << this->mode;
        dev_file.close();

        counter = (mode) ? counter+1 : counter+3;
        sleep_(seconds);
    }
}
void Motor::SM_42BYG011::full_step_mode(uint32_t &targetStep, bool &mode, float seconds)
{
    counter = 0;
    targetStep = (mode) ? targetStep : targetStep*3;
    while (counter<targetStep)
    {
        this->mode[0] = counter%4 + 5 + base;
        dev_file.open(device_path);
        dev_file << this->mode;
        dev_file.close();

        counter = (mode) ? counter+1 : counter+3;
        sleep_(seconds);
    }
}
void Motor::SM_42BYG011::micro_step_mode_spin(bool mode, float seconds)
{
    counter = 0;
    while(true)
    {
        this->mode[0] = counter%4 + 1 + base;
        dev_file.open(device_path);
        dev_file << this->mode;
        dev_file.close();

        counter = (mode) ? counter+1 : counter+3;
        sleep_(seconds);
    }
}
void Motor::SM_42BYG011::micro_step_mode_spin(bool &mode, float seconds)
{
    counter = 0;
    while(true)
    {
        this->mode[0] = counter%4 + 1 + base;
        dev_file.open(device_path);
        dev_file << this->mode;
        dev_file.close();

        counter = (mode) ? counter+1 : counter+3;
        sleep_(seconds);
    }
}
void Motor::SM_42BYG011::half_step_mode_spin(bool mode, float seconds)
{
    counter = 0;
    while(true)
    {
        this->mode[0] = counter%8 + 1 + base;
        dev_file.open(device_path);
        dev_file << this->mode;
        dev_file.close();

        counter = (mode) ? counter+1 : counter+7;
        sleep_(seconds);
    }
}
void Motor::SM_42BYG011::half_step_mode_spin(bool &mode, float seconds)
{
    counter = 0;
    while(true)
    {
        this->mode[0] = counter%8 + 1 + base;
        dev_file.open(device_path);
        dev_file << this->mode;
        dev_file.close();

        counter = (mode) ? counter+1 : counter+7;
        sleep_(seconds);
    }
}
void Motor::SM_42BYG011::full_step_mode_spin(bool mode, float seconds)
{
    counter = 0;
    while(true)
    {
        this->mode[0] = counter%4 + 5 + base;
        dev_file.open(device_path);
        dev_file << this->mode;
        dev_file.close();

        counter = (mode) ? counter+1 : counter+3;
        sleep_(seconds);
    }
}
void Motor::SM_42BYG011::full_step_mode_spin(bool &mode, float seconds)
{
    counter = 0;
    while(true)
    {
        this->mode[0] = counter%4 + 5 + base;
        dev_file.open(device_path);
        dev_file << this->mode;
        dev_file.close();

        counter = (mode) ? counter+1 : counter+3;
        sleep_(seconds);
    }
}
void Motor::SM_42BYG011::halt()
{
    dev_file.open(device_path);
    dev_file << "0\n";
    dev_file.close();
}