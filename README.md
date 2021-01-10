# driver4motor_SM-42BYG011-25

## ::::: Documentation :::::
### How to install driver
1. clone repository<br/>
```git clone https://github.com/bonohub13/driver4motor_SM-42BYG011-25.git```
2. enter the _driver_ directory<br/>
```cd driver```
3. run ```make``` inside the _driver_ directory to compile.
4. run ```install.sh``` to install the module.
- After used, make sure to uninstall the module by running ```rmmod mystep```

### How to use driver
- By writing 1, 2, 3, 4 into the device file, (/dev/mystep0) the motor turns using micro step mode (low torque).
- By writing 5, 5, 7, 8 into the device file, the motor turns using full step mode (high torque).
- ex.) ```echo 1 > /dev/mystep0```
### How to use package (functions to easilly utilize the driver)
1. Copy the _driver\_pkg_ directory under _include_ directory of your project.
2. Follow the CMakeLists.txt file under sample directory and modify your CMakeLists.txt file.
3. Compile

## Utilized equipment
1. Motor
    - SM-42BYG011
2. Raspberry PI
    - Raspberry Pi 3B+

## Pin layout
- Red cable
    - 29(GPIO: 5)
- Green cable
    - 31(GPIO: 6)
- Yellow cable
    - 33(GPIO: 13)
- Cyan cable
    - 35(GPIO: 19)

### GPIO layout
[GPIO layout](https://www.raspberrypi.org/documentation/usage/gpio/README.md)
