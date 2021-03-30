#include "motor.hpp"

Motor::SM_42BYG011::SM_42BYG011(std::string& devicePath)
{
    mode = '0';
    base = '0';
    counter = 0;
    device_path = devicePath;
}

Motor::SM_42BYG011::SM_42BYG011(std::string devicePath)
{
    mode = '0';
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
    useconds_t usec = (useconds_t)(seconds*1e6);
    usleep(usec);
}

void Motor::SM_42BYG011::micro_step_mode(uint32_t targetStep, bool mode, float seconds)
{
    counter = 0;
    targetStep = (mode) ? targetStep : targetStep*3+1;
    
    while (counter<=targetStep)
    {
        this->mode = counter%4 + 1 + base;
        dev_file.open(device_path);
        dev_file << this->mode;
        dev_file.close();

        if (mode)
            counter++;
        else
        {
            if ((targetStep-counter)<3)
                break;
            else
                counter += 3;
        }

        sleep_(seconds);
    }
    
    this->halt();
}

void Motor::SM_42BYG011::micro_step_mode(uint32_t &targetStep, bool &mode, float &seconds)
{
    counter = 0;
    targetStep = (mode) ? targetStep : targetStep*3+1;
    while (counter<=targetStep)
    {
        this->mode = counter%4 + 1 + base;
        dev_file.open(device_path);
        dev_file << this->mode;
        dev_file.close();

        if (mode)
            counter++;
        else
        {
            if ((targetStep-counter)<3)
                break;
            else
                counter += 3;
        }
        sleep_(seconds);
    }
    this->halt();
}

void Motor::SM_42BYG011::half_step_mode(uint32_t targetStep, bool mode, float seconds)
{
    int steps[] = {1, 5, 2, 6, 3, 7, 4, 8};
    counter = 0;
    targetStep = (mode) ? targetStep : targetStep*7+1;
    while (counter<=targetStep)
    {
        this->mode = steps[counter%8] + base;
        dev_file.open(device_path);
        dev_file << this->mode;
        dev_file.close();

        if (mode)
            counter++;
        else
        {
            if ((targetStep-counter)<7)
                break;
            else
                counter += 7;
        }
        sleep_(seconds);
    }
    this->halt();
}

void Motor::SM_42BYG011::half_step_mode(uint32_t &targetStep, bool &mode, float &seconds)
{
    int steps[] = {1, 5, 2, 6, 3, 7, 4, 8};
    counter = 0;
    targetStep = (mode) ? targetStep : targetStep*7+1;
    while (counter<=targetStep)
    {
        this->mode = steps[counter%8] + base;
        dev_file.open(device_path);
        dev_file << this->mode;
        dev_file.close();

        if (mode)
            counter++;
        else
        {
            if ((targetStep-counter)<7)
                break;
            else
                counter += 7;
        }
        sleep_(seconds);
    }
    this->halt();
}

void Motor::SM_42BYG011::full_step_mode(uint32_t targetStep, bool mode, float seconds)
{
    counter = 0;
    targetStep = (mode) ? targetStep : targetStep*3+1;
    while (counter<=targetStep)
    {
        this->mode = counter%4 + 5 + base;
        dev_file.open(device_path);
        dev_file << this->mode;
        dev_file.close();

        if (mode)
            counter++;
        else
        {
            if ((targetStep-counter)<3)
                break;
            else
                counter += 3;
        }
        sleep_(seconds);
    }
    this->halt();
}

void Motor::SM_42BYG011::full_step_mode(uint32_t &targetStep, bool &mode, float &seconds)
{
    counter = 0;
    targetStep = (mode) ? targetStep : targetStep*3+1;
    while (counter<=targetStep)
    {
        this->mode = counter%4 + 5 + base;
        dev_file.open(device_path);
        dev_file << this->mode;
        dev_file.close();

        if (mode)
            counter++;
        else
        {
            if ((targetStep-counter)<3)
                break;
            else
                counter += 3;
        }
        sleep_(seconds);
    }
    this->halt();
}

void Motor::SM_42BYG011::micro_step_mode_spin(bool mode, float seconds)
{
    counter = 0;
    while(true)
    {
        this->mode = counter%4 + 1 + base;
        dev_file.open(device_path);
        dev_file << this->mode;
        dev_file.close();

        if (mode)
            counter++;
        else
            counter += 3;
        sleep_(seconds);
    }
}

void Motor::SM_42BYG011::micro_step_mode_spin(bool &mode, float &seconds)
{
    counter = 0;
    while(true)
    {
        this->mode = counter%4 + 1 + base;
        dev_file.open(device_path);
        dev_file << this->mode;
        dev_file.close();

        if (mode)
            counter++;
        else
            counter += 3;
        sleep_(seconds);
    }
}

void Motor::SM_42BYG011::half_step_mode_spin(bool mode, float seconds)
{
    int steps[] = {1, 5, 2, 6, 3, 7, 4, 8};
    counter = 0;
    while(true)
    {
        this->mode = steps[counter%8] + base;
        dev_file.open(device_path);
        dev_file << this->mode;
        dev_file.close();

        if (mode)
            counter++;
        else
            counter += 7;
        sleep_(seconds);
    }
}

void Motor::SM_42BYG011::half_step_mode_spin(bool &mode, float &seconds)
{
    int steps[] = {1, 5, 2, 6, 3, 7, 4, 8};
    counter = 0;
    while(true)
    {
        this->mode = steps[counter%8] + base;
        dev_file.open(device_path);
        dev_file << this->mode;
        dev_file.close();

        if (mode)
            counter++;
        else
            counter += 7;
        sleep_(seconds);
    }
}

void Motor::SM_42BYG011::full_step_mode_spin(bool mode, float seconds)
{
    counter = 0;
    while(true)
    {
        this->mode = counter%4 + 5 + base;
        dev_file.open(device_path);
        dev_file << this->mode;
        dev_file.close();

        if (mode)
            counter++;
        else
            counter += 3;
        sleep_(seconds);
    }
}

void Motor::SM_42BYG011::full_step_mode_spin(bool &mode, float &seconds)
{
    counter = 0;
    while(true)
    {
        this->mode = counter%4 + 5 + base;
        dev_file.open(device_path);
        dev_file << this->mode;
        dev_file.close();

        if (mode)
            counter++;
        else
            counter += 3;
        sleep_(seconds);
    }
}

void Motor::SM_42BYG011::halt()
{
    dev_file.open(device_path);
    dev_file << '0';
    dev_file.close();
}

std::unique_ptr<Motor::SM_42BYG011> Motor::create_unique_SM_42BYG011(std::string& devicePath)
{
    std::unique_ptr<Motor::SM_42BYG011> unique_ptr = std::make_unique<Motor::SM_42BYG011>(devicePath);

    return unique_ptr;
}

std::unique_ptr<Motor::SM_42BYG011> Motor::create_unique_SM_42BYG011(std::string devicePath)
{
    std::unique_ptr<Motor::SM_42BYG011> unique_ptr = std::make_unique<Motor::SM_42BYG011>(devicePath);

    return unique_ptr;
}

std::unique_ptr<Motor::SM_42BYG011> Motor::create_unique_SM_42BYG011(const char* devicePath)
{
    std::unique_ptr<Motor::SM_42BYG011> unique_ptr = std::make_unique<Motor::SM_42BYG011>(std::string(devicePath));

    return unique_ptr;
}

std::shared_ptr<Motor::SM_42BYG011> Motor::create_shared_SM_42BYG011(std::string& devicePath)
{
    auto shared_ptr = std::make_shared<Motor::SM_42BYG011>(devicePath);

    return shared_ptr;
}

std::shared_ptr<Motor::SM_42BYG011> Motor::create_shared_SM_42BYG011(std::string devicePath)
{
    auto shared_ptr = std::make_shared<Motor::SM_42BYG011>(devicePath);

    return shared_ptr;
}

std::shared_ptr<Motor::SM_42BYG011> Motor::create_shared_SM_42BYG011(const char* devicePath)
{
    auto shared_ptr = std::make_shared<Motor::SM_42BYG011>(std::string(devicePath));

    return shared_ptr;
}