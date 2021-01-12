#include <fstream>
#include <string>
#include "unistd.h"

namespace Motor
{
    class SM_42BYG011
    {
    public:
        SM_42BYG011(std::string &devicePath);
        SM_42BYG011(std::string devicePath);
        ~SM_42BYG011();
    private: // variables
        char mode, base; // data written to device file
        uint32_t counter; // data used for switching pin
        std::string device_path;
        std::ofstream dev_file;
    private:
        void sleep_(float seconds);
    public: // functions
        // moves motors to a certain angle (1.8 * targetSteps)
        /* mode:
            * true or 1  > counterclockwise
            * false or 0 > clockwise
        */
        void micro_step_mode(uint32_t targetSteps, bool mode, float seconds);
        void micro_step_mode(uint32_t &targetSteps, bool &mode, float &seconds);
        void half_step_mode(uint32_t targetSteps, bool mode, float seconds);
        void half_step_mode(uint32_t &targetSteps, bool &mode, float &seconds);
        void full_step_mode(uint32_t targetSteps, bool mode, float seconds);
        void full_step_mode(uint32_t &targetSteps, bool &mode, float &seconds);
        /* moves motor infinitely clockwise/counterclockwise
            * mode:
                * true or 1  > counterclockwise
                * false or 0 > clockwise
        */
        void micro_step_mode_spin(bool mode, float seconds);
        void micro_step_mode_spin(bool &mode, float &seconds);
        void half_step_mode_spin(bool mode, float seconds);
        void half_step_mode_spin(bool &mode, float &seconds);
        void full_step_mode_spin(bool mode, float seconds);
        void full_step_mode_spin(bool &mode, float &seconds);
        // stop motor
        void halt();
    };
}
