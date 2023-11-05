#ifndef TINYGPS_H
#define TINYGPS_H

#include <Arduino.h>
#include <SoftwareSerial.h>

class TinyGPS {
private:
    SoftwareSerial serial;
public:
    float lng;
    float lat;
    TinyGPS(char rx): serial(rx, NOT_A_PIN) {}
    void begin();
    void getData();
};

#endif