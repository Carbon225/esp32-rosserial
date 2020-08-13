#ifndef _ROS_ESP32_HARDWARE_H_
#define _ROS_ESP32_HARDWARE_H_

#include <cstdint>

class ESP32Hardware
{
public:
    ESP32Hardware();
    void init();
    int read();
    void write(uint8_t *data, int length);
    unsigned long time();

private:

};

#endif
