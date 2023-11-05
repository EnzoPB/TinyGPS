#include <Arduino.h>
#include <gps.h>

void TinyGPS::begin() {
    this->serial.begin(9600);
}

void TinyGPS::getData() {
    if (this->serial.available()) {
        String type = this->serial.readStringUntil(',');

        if (type == "GPGGA") {
            this->serial.readStringUntil(',');
            this->lng = this->serial.readStringUntil(',').toFloat();
            if (this->serial.readStringUntil(',') == "S") {
                this->lng = -this->lng;
            }

            lat = this->serial.readStringUntil(',').toFloat();
            if (this->serial.readStringUntil(',') == "W") {
                this->lat = -this->lat;
            }
        } else {
            char current = ' ';
            while (current != '$') {
                current = this->serial.read();
            }
        }
    }
}