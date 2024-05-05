#include <Wire.h>
#include <PI3EQX12908A2.h>

PI3EQX12908 RD;

void setup() {
  Wire.begin();
  Serial.begin(115200);
 
  delay(1000);
  Serial.println("\n\r -------- CONFIGURATION --------");
    RD.init(0x70);                            // Setting the I2C address
    RD.setEQ(0);                              // Setting EQ for all channels
    RD.setFG(FLAT_GAIN_00db);                 // Setting flat gain for all channels
    RD.setSW(SWING_900mVpp);                  // Setting swing for all channels
    RD.setSDTConfig(SDT_OFF_30_ON_130_mVpp);  // Setting signal detect threshold
    RD.print_all();                           // Print all of the registers
}

void loop() {
 
}