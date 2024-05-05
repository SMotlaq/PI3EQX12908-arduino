#include <Wire.h>
#include <PI3EQX12908A2.h>

PI3EQX12908 RD;

void setup() {
  Wire.begin();
  Serial.begin(115200);
 
  delay(1000);
  Serial.println("\n\r -------- CONFIGURATION --------");
    RD.init(0x70);                            // Setting the I2C address
    RD.setEQ_A0(0);                           // Setting EQ for channel A0
    RD.setEQ_A1(2);                           // Setting EQ for channel A1
    RD.setEQ_A2(1);                           // Setting EQ for channel A2
    RD.setPowerDown_A(3, CFG_OFF);            //  Turn channel A3 off
    RD.setFG_A(FLAT_GAIN_00db);               // Setting flat gain for channel A
    RD.setSW_A(SWING_900mVpp);                // Setting swing for channel A
    RD.setSDTConfig(SDT_OFF_30_ON_130_mVpp);  // Setting signal detect threshold
    RD.setPowerDown_B(CFG_OFF);               // Turn channel B off
    RD.print_all();                           // Print all of the registers
}

void loop() {
 
}