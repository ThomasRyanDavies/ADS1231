#include <ADS1231.h>

uint8_t CLK_PIN = 7;
uint8_t DATA_PIN =  8;

ADS1231 adc(CLK_PIN,DATA_PIN);

void setup() {
    Serial.begin(115200);

    if (!adc.begin()) {
        Serial.println("Invalid pins bro!");
    }
}

void loop() {
    long val;
    if (adc.getValue(val)) {        //this call blocks until a sample is ready!
        Serial.print(millis());
        Serial.print(",");
        Serial.println((4.2/8388607.0)*val, 10);  //23 bits of accuracy (24th is sign) with 4.2 volt (measured) AVDD. 2^23 = 8388607 !
    } else {
      Serial.println("Failed to get data");
    }
}