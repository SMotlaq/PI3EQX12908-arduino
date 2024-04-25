/*!
 * @file PI3EQX12908A2.cpp
 *
 * @mainpage PI3EQX12908 PCIe 3.0 redriver library
 *
 * @section intro_sec Introduction
 *
 * The PI3EQX12908 PCIe 3.0 redriver library is a software library that allows developers to easily access the I2C interfaces of the PI3EQX12908 PCIe 3.0 redriver chip.
 * It provides a simple API for performing common I2C operations and is compatible with Arduino platform.
 * The library includes example code to help developers get started quickly. 
 *
 * @section author Author
 *
 * Written by Salman Motlaq (@SMotlaq on GitHub)
 *
 * @section license License
 *
 * MIT License
 *
 */

#include "PI3EQX12908A2.h"
#include "Arduino.h"

/**************************************************************************/
/*!
    @brief  Initialize the PI3EQX12908 object
            This function sets the I2C address and the register names.
    @param    i2c_addr
              The 7 bit I2C address of the redriver.
*/
/**************************************************************************/
PI3EQX12908::init(uint8_t i2c_addr){
  _I2C_ADDR = i2c_addr;

  _REGS[0]  = "SIGNAL DETECT";
  _REGS[1]  = "    RX DETECT";
  _REGS[2]  = "   POWER DOWN";
  _REGS[3]  = "   CHANNEL A0";
  _REGS[4]  = "   CHANNEL A1";
  _REGS[5]  = "   CHANNEL A2";
  _REGS[6]  = "   CHANNEL A3";
  _REGS[7]  = "   CHANNEL B0";
  _REGS[8]  = "   CHANNEL B1";
  _REGS[9]  = "   CHANNEL B2";
  _REGS[10] = "   CHANNEL B3";
  _REGS[11] = "  SIG DET CFG";
  _REGS[12] = "   RX DET CFG";
  _REGS[13] = "  SIG DET THR";
  _REGS[14] = "    14th BYTE";
  _REGS[15] = "    15th BYTE";
}

// 0 - Signal Detect
/**************************************************************************/
/*!
    @brief  Gets the signal detect register
            This function reads the signal detect register values.
    @return 8 bit value of signal detect register.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getSignalDetect(){
  return _read_reg(SIGNAL_DETECT_REG);
}

/**************************************************************************/
/*!
    @brief  Gets the signal detect of A channel
            This function reads the signal detect register
            and returns the channel A status.
    @return 4 bit value of channel A signal detect.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getSignalDetect_A(){
  return _read_reg(SIGNAL_DETECT_REG) >> 4;
}

/**************************************************************************/
/*!
    @brief  Gets the signal detect A by channel index
            This function reads the signal detect register value
            and returns the status of given channel index of A channel.
    @param    index
              A reference to the channel index of A channel from 0 to 3.
    @return return zero for not detected, otherwise for detected.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getSignalDetect_A(uint8_t index){
  return _read_reg(SIGNAL_DETECT_REG) & (1 << (index + 4));
}

/**************************************************************************/
/*!
    @brief  Gets the signal detect of B channel
            This function reads the signal detect register
            and returns the channel B status.
    @return 4 bit value of channel B signal detect.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getSignalDetect_B(){
  return _read_reg(SIGNAL_DETECT_REG) & 0x0F;
}

/**************************************************************************/
/*!
    @brief  Gets the signal detect B by channel index
            This function reads the signal detect register value
            and returns the status of given channel index of B channel.
    @param    index
              A reference to the channel index of B channel from 0 to 3.
    @return return zero for not detected, otherwise for detected.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getSignalDetect_B(uint8_t index){
  return _read_reg(SIGNAL_DETECT_REG) & (1 << index);
}

// 1 - RX Detect
/**************************************************************************/
/*!
    @brief  Gets the RX detect register
            This function reads the RX detect register values.
    @return 8 bit value of RX detect register.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getRxDetect(){
  return _read_reg(RX_DETECT_REG);
}

/**************************************************************************/
/*!
    @brief  Gets the RX detect of A channel
            This function reads the RX detect register
            and returns the channel A status.
    @return 4 bit value of channel A RX detect.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getRxDetect_A(){
  return _read_reg(RX_DETECT_REG) >> 4;
}

/**************************************************************************/
/*!
    @brief  Gets the RX detect A by channel index
            This function reads the RX detect register value
            and returns the status of given channel index of A channel.
    @param    index
              A reference to the channel index of A channel from 0 to 3.
    @return return zero for not detected, otherwise for detected.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getRxDetect_A(uint8_t index){
  return _read_reg(RX_DETECT_REG) & (1 << (index + 4));
}

/**************************************************************************/
/*!
    @brief  Gets the RX detect of B channel
            This function reads the RX detect register
            and returns the channel B status.
    @return 4 bit value of channel B RX detect.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getRxDetect_B(){
  return _read_reg(RX_DETECT_REG) & 0x0F;
}

/**************************************************************************/
/*!
    @brief  Gets the RX detect B by channel index
            This function reads the RX detect register value
            and returns the status of given channel index of B channel.
    @param    index
              A reference to the channel index of B channel from 0 to 3.
    @return return zero for not detected, otherwise for detected.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getRxDetect_B(uint8_t index){
  return _read_reg(RX_DETECT_REG) & (1 << index);
}

// 2 - Power Down
/**************************************************************************/
/*!
    @brief  Gets the power down register
            This function reads the power down register values.
    @return 8 bit value of power down register.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getPowerDown(){
  return _read_reg(POWER_DOWN_REG);
}

/**************************************************************************/
/*!
    @brief  Gets the power down of A channel
            This function reads the power down register
            and returns the channel A status.
    @return 4 bit value of channel A power down.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getPowerDown_A(){
  return _read_reg(POWER_DOWN_REG) >> 4;
}

/**************************************************************************/
/*!
    @brief  Gets the power down A by channel index
            This function reads the power down register value
            and returns the status of given channel index of A channel.
    @param    index
              A reference to the channel index of A channel from 0 to 3.
    @return return zero for not detected, otherwise for detected.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getPowerDown_A(uint8_t index){
  return _read_reg(POWER_DOWN_REG) & (1 << (index + 4));
}

/**************************************************************************/
/*!
    @brief  Gets the power down of B channel
            This function reads the power down register
            and returns the channel B status.
    @return 4 bit value of channel B power down.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getPowerDown_B(){
  return _read_reg(POWER_DOWN_REG) & 0x0F;
}

/**************************************************************************/
/*!
    @brief  Gets the power down B by channel index
            This function reads the power down register value
            and returns the status of given channel index of B channel.
    @param    index
              A reference to the channel index of B channel from 0 to 3.
    @return return zero for not detected, otherwise for detected.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getPowerDown_B(uint8_t index){
  return _read_reg(POWER_DOWN_REG) & (1 << index);
}

/**************************************************************************/
/*!
    @brief  Sets the power down register.
            This function change the power down status of all channels.
    @param    isDown
              CFG_ON  for power up
              CFG_OFF for power down
*/
/**************************************************************************/
void PI3EQX12908::setPowerDown(uint8_t isDown){
  _write_reg(POWER_DOWN_REG, isDown ? 0xFF : 0x00);
}

/**************************************************************************/
/*!
    @brief  Sets the power down of A channel.
            This function change the power down status of channel A.
    @param    isDown
              CFG_ON  for power up
              CFG_OFF for power down
*/
/**************************************************************************/
void PI3EQX12908::setPowerDown_A(uint8_t isDown){
  uint8_t val = getPowerDown();
  if(isDown)
    val |= (uint8_t)0xF0;
  else
    val &= (uint8_t)0x0F;
  _write_reg(POWER_DOWN_REG, val);
}

/**************************************************************************/
/*!
    @brief  Sets the power down of a given index of A channel.
            This function change the power down status of the 
            given channel A index.
    @param    index
              A reference to the channel index of A channel from 0 to 3.
    @param    isDown
              CFG_ON  for power up
              CFG_OFF for power down
*/
/**************************************************************************/
void PI3EQX12908::setPowerDown_A(uint8_t index, uint8_t isDown){
  uint8_t val = getPowerDown();
  if(isDown)
    val |= (1 << (index + 4));
  else
    val &= ~(1 << (index + 4));
  _write_reg(POWER_DOWN_REG, val);
}

/**************************************************************************/
/*!
    @brief  Sets the power down of B channel.
            This function change the power down status of channel B.
    @param    isDown
              CFG_ON  for power up
              CFG_OFF for power down
*/
/**************************************************************************/
void PI3EQX12908::setPowerDown_B(uint8_t isDown){
  uint8_t val = getPowerDown();
  if(isDown)
    val |= (uint8_t)0x0F;
  else
    val &= (uint8_t)0xF0;
  _write_reg(POWER_DOWN_REG, val);
}

/**************************************************************************/
/*!
    @brief  Sets the power down of a given index of B channel.
            This function change the power down status of the 
            given channel B index.
    @param    index
              A reference to the channel index of B channel from 0 to 3.
    @param    isDown
              CFG_ON  for power up
              CFG_OFF for power down
*/
/**************************************************************************/
void PI3EQX12908::setPowerDown_B(uint8_t index, uint8_t isDown){
  uint8_t val = getPowerDown();
  if(isDown)
    val |= (1 << index);
  else
    val &= ~(1 << index);
  _write_reg(POWER_DOWN_REG, val);
}

// 3 - A0 Config
/**************************************************************************/
/*!
    @brief  Gets the configuration of the 0 index A channel.
            This function reads the configuration of the 0 index A channel value.
    @return 8 bit value of A0 config register.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getConfig_A0(){
  return _read_reg(CONFIG_A0_REG);
}

/**************************************************************************/
/*!
    @brief  Gets the equalizer configuration of the 0 index A channel.
            This function reads the equalizer value of the 0 index A channel value.
    @return 4 bit value of A0 equalizer.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getEQ_A0(){
  return _read_reg(CONFIG_A0_REG) >> EQ_SHIFT;
}

/**************************************************************************/
/*!
    @brief  Gets the flat gain configuration of the 0 index A channel.
            This function reads the flat gain value of the 0 index A channel value.
    @return 2 bit value of A0 flat gain:
            FLAT_GAIN_M4db -> -4 db
            FLAT_GAIN_M2db -> -2 db
            FLAT_GAIN_00db ->  0 db
            FLAT_GAIN_P2db -> +2 db
*/
/**************************************************************************/
uint8_t PI3EQX12908::getFlatGain_A0(){
  return (_read_reg(CONFIG_A0_REG) & 0x0F) >> FG_SHIFT;
}

/**************************************************************************/
/*!
    @brief  Gets the swing configuration of the 0 index A channel.
            This function reads the swing value of the 0 index A channel value.
    @return 1 bit value of A0 swing:
            SWING_900mVpp  ->  900 mVpp
            SWING_1000mVpp -> 1000 mVpp
*/
/**************************************************************************/
uint8_t PI3EQX12908::getSW_A0(){
  return _read_reg(CONFIG_A0_REG) & 0x01;
}

/**************************************************************************/
/*!
    @brief  Sets the configuration of the 0 index A channel.
            This function sets the configuration register of A0.
            * NOT RECOMENDED TO USE! *
    @param    config
              8 bit value of the config register
/**************************************************************************/
void PI3EQX12908::setConfig_A0(uint8_t config){
  _write_reg(CONFIG_A0_REG, config);
}

/**************************************************************************/
/*!
    @brief  Sets the equalizer value of the 0 index A channel.
            This function sets the equalizer value of A0.
    @param    EQ
              4 bit value of the equalizer index
/**************************************************************************/
void PI3EQX12908::setEQ_A0(uint8_t EQ){
  uint8_t val = getConfig_A0();
  val &= 0x0F;
  val |= (EQ & 0x0F) << EQ_SHIFT;
  _write_reg(CONFIG_A0_REG, val);
}

/**************************************************************************/
/*!
    @brief  Sets the flat gain value of the 0 index A channel.
            This function sets the flat gain value of A0.
    @param    flat_gain
              2 bit value of the flat gain:
              FLAT_GAIN_M4db -> -4 db
              FLAT_GAIN_M2db -> -2 db
              FLAT_GAIN_00db ->  0 db
              FLAT_GAIN_P2db -> +2 db
/**************************************************************************/
void PI3EQX12908::setFlatGain_A0(uint8_t flat_gain){
  uint8_t val = getConfig_A0();
  val &= 0xF3;
  val |= (flat_gain & 0x03) << FG_SHIFT;
  _write_reg(CONFIG_A0_REG, val);
}

/**************************************************************************/
/*!
    @brief  Sets the swing value of the 0 index A channel.
            This function sets the swing value of A0.
    @param    swing
              1 bit value of the swing:
              SWING_900mVpp  ->  900 mVpp
              SWING_1000mVpp -> 1000 mVpp
/**************************************************************************/
void PI3EQX12908::setSW_A0(uint8_t swing){
  uint8_t val = getConfig_A0();
  val &= 0xFE;
  val |= swing & 0x01;
  _write_reg(CONFIG_A0_REG, val);
}

// 4 - A1 Config
/**************************************************************************/
/*!
    @brief  Gets the configuration of the 1 index A channel.
            This function reads the configuration of the 1 index A channel value.
    @return 8 bit value of A1 config register.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getConfig_A1(){
  return _read_reg(CONFIG_A1_REG);
}

/**************************************************************************/
/*!
    @brief  Gets the equalizer configuration of the 1 index A channel.
            This function reads the equalizer value of the 1 index A channel value.
    @return 4 bit value of A1 equalizer.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getEQ_A1(){
  return _read_reg(CONFIG_A1_REG) >> EQ_SHIFT;
}

/**************************************************************************/
/*!
    @brief  Gets the flat gain configuration of the 1 index A channel.
            This function reads the flat gain value of the 1 index A channel value.
    @return 2 bit value of A1 flat gain:
            FLAT_GAIN_M4db -> -4 db
            FLAT_GAIN_M2db -> -2 db
            FLAT_GAIN_00db ->  0 db
            FLAT_GAIN_P2db -> +2 db
*/
/**************************************************************************/
uint8_t PI3EQX12908::getFlatGain_A1(){
  return (_read_reg(CONFIG_A1_REG) & 0x0F) >> FG_SHIFT;
}

/**************************************************************************/
/*!
    @brief  Gets the swing configuration of the 1 index A channel.
            This function reads the swing value of the 1 index A channel value.
    @return 1 bit value of A1 swing:
            SWING_900mVpp  ->  900 mVpp
            SWING_1000mVpp -> 1000 mVpp
*/
/**************************************************************************/
uint8_t PI3EQX12908::getSW_A1(){
  return _read_reg(CONFIG_A1_REG) & 0x01;
}

/**************************************************************************/
/*!
    @brief  Sets the configuration of the 1 index A channel.
            This function sets the configuration register of A1.
            * NOT RECOMENDED TO USE! *
    @param    config
              8 bit value of the config register
/**************************************************************************/
void PI3EQX12908::setConfig_A1(uint8_t config){
  _write_reg(CONFIG_A1_REG, config);
}

/**************************************************************************/
/*!
    @brief  Sets the equalizer value of the 1 index A channel.
            This function sets the equalizer value of A1.
    @param    EQ
              4 bit value of the equalizer index
/**************************************************************************/
void PI3EQX12908::setEQ_A1(uint8_t EQ){
  uint8_t val = getConfig_A1();
  val &= 0x0F;
  val |= (EQ & 0x0F) << EQ_SHIFT;
  _write_reg(CONFIG_A1_REG, val);
}

/**************************************************************************/
/*!
    @brief  Sets the flat gain value of the 1 index A channel.
            This function sets the flat gain value of A1.
    @param    flat_gain
              2 bit value of the flat gain:
              FLAT_GAIN_M4db -> -4 db
              FLAT_GAIN_M2db -> -2 db
              FLAT_GAIN_00db ->  0 db
              FLAT_GAIN_P2db -> +2 db
/**************************************************************************/
void PI3EQX12908::setFlatGain_A1(uint8_t flat_gain){
  uint8_t val = getConfig_A1();
  val &= 0xF3;
  val |= (flat_gain & 0x03) << FG_SHIFT;
  _write_reg(CONFIG_A1_REG, val);
}

/**************************************************************************/
/*!
    @brief  Sets the swing value of the 1 index A channel.
            This function sets the swing value of A1.
    @param    swing
              1 bit value of the swing:
              SWING_900mVpp  ->  900 mVpp
              SWING_1000mVpp -> 1000 mVpp
/**************************************************************************/
void PI3EQX12908::setSW_A1(uint8_t swing){
  uint8_t val = getConfig_A1();
  val &= 0xFE;
  val |= swing & 0x01;
  _write_reg(CONFIG_A1_REG, val);
}

// 5 - A2 Config
/**************************************************************************/
/*!
    @brief  Gets the configuration of the 2 index A channel.
            This function reads the configuration of the 2 index A channel value.
    @return 8 bit value of A2 config register.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getConfig_A2(){
  return _read_reg(CONFIG_A2_REG);
}

/**************************************************************************/
/*!
    @brief  Gets the equalizer configuration of the 2 index A channel.
            This function reads the equalizer value of the 2 index A channel value.
    @return 4 bit value of A2 equalizer.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getEQ_A2(){
  return _read_reg(CONFIG_A2_REG) >> EQ_SHIFT;
}

/**************************************************************************/
/*!
    @brief  Gets the flat gain configuration of the 2 index A channel.
            This function reads the flat gain value of the 2 index A channel value.
    @return 2 bit value of A2 flat gain:
            FLAT_GAIN_M4db -> -4 db
            FLAT_GAIN_M2db -> -2 db
            FLAT_GAIN_00db ->  0 db
            FLAT_GAIN_P2db -> +2 db
*/
/**************************************************************************/
uint8_t PI3EQX12908::getFlatGain_A2(){
  return (_read_reg(CONFIG_A2_REG) & 0x0F) >> FG_SHIFT;
}

/**************************************************************************/
/*!
    @brief  Gets the swing configuration of the 2 index A channel.
            This function reads the swing value of the 2 index A channel value.
    @return 1 bit value of A2 swing:
            SWING_900mVpp  ->  900 mVpp
            SWING_1000mVpp -> 1000 mVpp
*/
/**************************************************************************/
uint8_t PI3EQX12908::getSW_A2(){
  return _read_reg(CONFIG_A2_REG) & 0x01;
}

/**************************************************************************/
/*!
    @brief  Sets the configuration of the 2 index A channel.
            This function sets the configuration register of A2.
            * NOT RECOMENDED TO USE! *
    @param    config
              8 bit value of the config register
/**************************************************************************/
void PI3EQX12908::setConfig_A2(uint8_t config){
  _write_reg(CONFIG_A2_REG, config);
}

/**************************************************************************/
/*!
    @brief  Sets the equalizer value of the 2 index A channel.
            This function sets the equalizer value of A2.
    @param    EQ
              4 bit value of the equalizer index
/**************************************************************************/
void PI3EQX12908::setEQ_A2(uint8_t EQ){
  uint8_t val = getConfig_A2();
  val &= 0x0F;
  val |= (EQ & 0x0F) << EQ_SHIFT;
  _write_reg(CONFIG_A2_REG, val);
}

/**************************************************************************/
/*!
    @brief  Sets the flat gain value of the 2 index A channel.
            This function sets the flat gain value of A2.
    @param    flat_gain
              2 bit value of the flat gain:
              FLAT_GAIN_M4db -> -4 db
              FLAT_GAIN_M2db -> -2 db
              FLAT_GAIN_00db ->  0 db
              FLAT_GAIN_P2db -> +2 db
/**************************************************************************/
void PI3EQX12908::setFlatGain_A2(uint8_t flat_gain){
  uint8_t val = getConfig_A2();
  val &= 0xF3;
  val |= (flat_gain & 0x03) << FG_SHIFT;
  _write_reg(CONFIG_A2_REG, val);
}

/**************************************************************************/
/*!
    @brief  Sets the swing value of the 2 index A channel.
            This function sets the swing value of A2.
    @param    swing
              1 bit value of the swing:
              SWING_900mVpp  ->  900 mVpp
              SWING_1000mVpp -> 1000 mVpp
/**************************************************************************/
void PI3EQX12908::setSW_A2(uint8_t swing){
  uint8_t val = getConfig_A2();
  val &= 0xFE;
  val |= swing & 0x01;
  _write_reg(CONFIG_A2_REG, val);
}

// 6 - A3 Config
/**************************************************************************/
/*!
    @brief  Gets the configuration of the 3 index A channel.
            This function reads the configuration of the 3 index A channel value.
    @return 8 bit value of A3 config register.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getConfig_A3(){
  return _read_reg(CONFIG_A3_REG);
}

/**************************************************************************/
/*!
    @brief  Gets the equalizer configuration of the 3 index A channel.
            This function reads the equalizer value of the 3 index A channel value.
    @return 4 bit value of A3 equalizer.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getEQ_A3(){
  return _read_reg(CONFIG_A3_REG) >> EQ_SHIFT;
}

/**************************************************************************/
/*!
    @brief  Gets the flat gain configuration of the 3 index A channel.
            This function reads the flat gain value of the 3 index A channel value.
    @return 2 bit value of A3 flat gain:
            FLAT_GAIN_M4db -> -4 db
            FLAT_GAIN_M2db -> -2 db
            FLAT_GAIN_00db ->  0 db
            FLAT_GAIN_P2db -> +2 db
*/
/**************************************************************************/
uint8_t PI3EQX12908::getFlatGain_A3(){
  return (_read_reg(CONFIG_A3_REG) & 0x0F) >> FG_SHIFT;
}

/**************************************************************************/
/*!
    @brief  Gets the swing configuration of the 3 index A channel.
            This function reads the swing value of the 3 index A channel value.
    @return 1 bit value of A3 swing:
            SWING_900mVpp  ->  900 mVpp
            SWING_1000mVpp -> 1000 mVpp
*/
/**************************************************************************/
uint8_t PI3EQX12908::getSW_A3(){
  return _read_reg(CONFIG_A3_REG) & 0x01;
}

/**************************************************************************/
/*!
    @brief  Sets the configuration of the 3 index A channel.
            This function sets the configuration register of A3.
            * NOT RECOMENDED TO USE! *
    @param    config
              8 bit value of the config register
/**************************************************************************/
void PI3EQX12908::setConfig_A3(uint8_t config){
  _write_reg(CONFIG_A3_REG, config);
}

/**************************************************************************/
/*!
    @brief  Sets the equalizer value of the 3 index A channel.
            This function sets the equalizer value of A3.
    @param    EQ
              4 bit value of the equalizer index
/**************************************************************************/
void PI3EQX12908::setEQ_A3(uint8_t EQ){
  uint8_t val = getConfig_A3();
  val &= 0x0F;
  val |= (EQ & 0x0F) << EQ_SHIFT;
  _write_reg(CONFIG_A3_REG, val);
}

/**************************************************************************/
/*!
    @brief  Sets the flat gain value of the 3 index A channel.
            This function sets the flat gain value of A3.
    @param    flat_gain
              2 bit value of the flat gain:
              FLAT_GAIN_M4db -> -4 db
              FLAT_GAIN_M2db -> -2 db
              FLAT_GAIN_00db ->  0 db
              FLAT_GAIN_P2db -> +2 db
/**************************************************************************/
void PI3EQX12908::setFlatGain_A3(uint8_t flat_gain){
  uint8_t val = getConfig_A3();
  val &= 0xF3;
  val |= (flat_gain & 0x03) << FG_SHIFT;
  _write_reg(CONFIG_A3_REG, val);
}

/**************************************************************************/
/*!
    @brief  Sets the swing value of the 3 index A channel.
            This function sets the swing value of A3.
    @param    swing
              1 bit value of the swing:
              SWING_900mVpp  ->  900 mVpp
              SWING_1000mVpp -> 1000 mVpp
/**************************************************************************/
void PI3EQX12908::setSW_A3(uint8_t swing){
  uint8_t val = getConfig_A3();
  val &= 0xFE;
  val |= swing & 0x01;
  _write_reg(CONFIG_A3_REG, val);
}

// 7 - B0 Config
/**************************************************************************/
/*!
    @brief  Gets the configuration of the 0 index B channel.
            This function reads the configuration of the 0 index B channel value.
    @return 8 bit value of B0 config register.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getConfig_B0(){
  return _read_reg(CONFIG_B0_REG);
}

/**************************************************************************/
/*!
    @brief  Gets the equalizer configuration of the 0 index B channel.
            This function reads the equalizer value of the 0 index B channel value.
    @return 4 bit value of B0 equalizer.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getEQ_B0(){
  return _read_reg(CONFIG_B0_REG) >> EQ_SHIFT;
}

/**************************************************************************/
/*!
    @brief  Gets the flat gain configuration of the 0 index B channel.
            This function reads the flat gain value of the 0 index B channel value.
    @return 2 bit value of B0 flat gain:
            FLAT_GAIN_M4db -> -4 db
            FLAT_GAIN_M2db -> -2 db
            FLAT_GAIN_00db ->  0 db
            FLAT_GAIN_P2db -> +2 db
*/
/**************************************************************************/
uint8_t PI3EQX12908::getFlatGain_B0(){
  return (_read_reg(CONFIG_B0_REG) & 0x0F) >> FG_SHIFT;
}

/**************************************************************************/
/*!
    @brief  Gets the swing configuration of the 0 index B channel.
            This function reads the swing value of the 0 index B channel value.
    @return 1 bit value of B0 swing:
            SWING_900mVpp  ->  900 mVpp
            SWING_1000mVpp -> 1000 mVpp
*/
/**************************************************************************/
uint8_t PI3EQX12908::getSW_B0(){
  return _read_reg(CONFIG_B0_REG) & 0x01;
}

/**************************************************************************/
/*!
    @brief  Sets the configuration of the 0 index B channel.
            This function sets the configuration register of B0.
            * NOT RECOMENDED TO USE! *
    @param    config
              8 bit value of the config register
/**************************************************************************/
void PI3EQX12908::setConfig_B0(uint8_t config){
  _write_reg(CONFIG_B0_REG, config);
}

/**************************************************************************/
/*!
    @brief  Sets the equalizer value of the 0 index B channel.
            This function sets the equalizer value of B0.
    @param    EQ
              4 bit value of the equalizer index
/**************************************************************************/
void PI3EQX12908::setEQ_B0(uint8_t EQ){
  uint8_t val = getConfig_B0();
  val &= 0x0F;
  val |= (EQ & 0x0F) << EQ_SHIFT;
  _write_reg(CONFIG_B0_REG, val);
}

/**************************************************************************/
/*!
    @brief  Sets the flat gain value of the 0 index B channel.
            This function sets the flat gain value of B0.
    @param    flat_gain
              2 bit value of the flat gain:
              FLAT_GAIN_M4db -> -4 db
              FLAT_GAIN_M2db -> -2 db
              FLAT_GAIN_00db ->  0 db
              FLAT_GAIN_P2db -> +2 db
/**************************************************************************/
void PI3EQX12908::setFlatGain_B0(uint8_t flat_gain){
  uint8_t val = getConfig_B0();
  val &= 0xF3;
  val |= (flat_gain & 0x03) << FG_SHIFT;
  _write_reg(CONFIG_B0_REG, val);
}

/**************************************************************************/
/*!
    @brief  Sets the swing value of the 0 index B channel.
            This function sets the swing value of B0.
    @param    swing
              1 bit value of the swing:
              SWING_900mVpp  ->  900 mVpp
              SWING_1000mVpp -> 1000 mVpp
/**************************************************************************/
void PI3EQX12908::setSW_B0(uint8_t swing){
  uint8_t val = getConfig_B0();
  val &= 0xFE;
  val |= swing & 0x01;
  _write_reg(CONFIG_B0_REG, val);
}

// 8 - B1 Config
/**************************************************************************/
/*!
    @brief  Gets the configuration of the 1 index B channel.
            This function reads the configuration of the 1 index B channel value.
    @return 8 bit value of B1 config register.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getConfig_B1(){
  return _read_reg(CONFIG_B1_REG);
}

/**************************************************************************/
/*!
    @brief  Gets the equalizer configuration of the 1 index B channel.
            This function reads the equalizer value of the 1 index B channel value.
    @return 4 bit value of B1 equalizer.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getEQ_B1(){
  return _read_reg(CONFIG_B1_REG) >> EQ_SHIFT;
}

/**************************************************************************/
/*!
    @brief  Gets the flat gain configuration of the 1 index B channel.
            This function reads the flat gain value of the 1 index B channel value.
    @return 2 bit value of B1 flat gain:
            FLAT_GAIN_M4db -> -4 db
            FLAT_GAIN_M2db -> -2 db
            FLAT_GAIN_00db ->  0 db
            FLAT_GAIN_P2db -> +2 db
*/
/**************************************************************************/
uint8_t PI3EQX12908::getFlatGain_B1(){
  return (_read_reg(CONFIG_B1_REG) & 0x0F) >> FG_SHIFT;
}

/**************************************************************************/
/*!
    @brief  Gets the swing configuration of the 1 index B channel.
            This function reads the swing value of the 1 index B channel value.
    @return 1 bit value of B1 swing:
            SWING_900mVpp  ->  900 mVpp
            SWING_1000mVpp -> 1000 mVpp
*/
/**************************************************************************/
uint8_t PI3EQX12908::getSW_B1(){
  return _read_reg(CONFIG_B1_REG) & 0x01;
}

/**************************************************************************/
/*!
    @brief  Sets the configuration of the 1 index B channel.
            This function sets the configuration register of B1.
            * NOT RECOMENDED TO USE! *
    @param    config
              8 bit value of the config register
/**************************************************************************/
void PI3EQX12908::setConfig_B1(uint8_t config){
  _write_reg(CONFIG_B1_REG, config);
}

/**************************************************************************/
/*!
    @brief  Sets the equalizer value of the 1 index B channel.
            This function sets the equalizer value of B1.
    @param    EQ
              4 bit value of the equalizer index
/**************************************************************************/
void PI3EQX12908::setEQ_B1(uint8_t EQ){
  uint8_t val = getConfig_B1();
  val &= 0x0F;
  val |= (EQ & 0x0F) << EQ_SHIFT;
  _write_reg(CONFIG_B1_REG, val);
}

/**************************************************************************/
/*!
    @brief  Sets the flat gain value of the 1 index B channel.
            This function sets the flat gain value of B1.
    @param    flat_gain
              2 bit value of the flat gain:
              FLAT_GAIN_M4db -> -4 db
              FLAT_GAIN_M2db -> -2 db
              FLAT_GAIN_00db ->  0 db
              FLAT_GAIN_P2db -> +2 db
/**************************************************************************/
void PI3EQX12908::setFlatGain_B1(uint8_t flat_gain){
  uint8_t val = getConfig_B1();
  val &= 0xF3;
  val |= (flat_gain & 0x03) << FG_SHIFT;
  _write_reg(CONFIG_B1_REG, val);
}

/**************************************************************************/
/*!
    @brief  Sets the swing value of the 1 index B channel.
            This function sets the swing value of B1.
    @param    swing
              1 bit value of the swing:
              SWING_900mVpp  ->  900 mVpp
              SWING_1000mVpp -> 1000 mVpp
/**************************************************************************/
void PI3EQX12908::setSW_B1(uint8_t swing){
  uint8_t val = getConfig_B1();
  val &= 0xFE;
  val |= swing & 0x01;
  _write_reg(CONFIG_B1_REG, val);
}

// 9 - B2 Config
/**************************************************************************/
/*!
    @brief  Gets the configuration of the 2 index B channel.
            This function reads the configuration of the 2 index B channel value.
    @return 8 bit value of B2 config register.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getConfig_B2(){
  return _read_reg(CONFIG_B2_REG);
}

/**************************************************************************/
/*!
    @brief  Gets the equalizer configuration of the 2 index B channel.
            This function reads the equalizer value of the 2 index B channel value.
    @return 4 bit value of B2 equalizer.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getEQ_B2(){
  return _read_reg(CONFIG_B2_REG) >> EQ_SHIFT;
}

/**************************************************************************/
/*!
    @brief  Gets the flat gain configuration of the 2 index B channel.
            This function reads the flat gain value of the 2 index B channel value.
    @return 2 bit value of B2 flat gain:
            FLAT_GAIN_M4db -> -4 db
            FLAT_GAIN_M2db -> -2 db
            FLAT_GAIN_00db ->  0 db
            FLAT_GAIN_P2db -> +2 db
*/
/**************************************************************************/
uint8_t PI3EQX12908::getFlatGain_B2(){
  return (_read_reg(CONFIG_B2_REG) & 0x0F) >> FG_SHIFT;
}

/**************************************************************************/
/*!
    @brief  Gets the swing configuration of the 2 index B channel.
            This function reads the swing value of the 2 index B channel value.
    @return 1 bit value of B2 swing:
            SWING_900mVpp  ->  900 mVpp
            SWING_1000mVpp -> 1000 mVpp
*/
/**************************************************************************/
uint8_t PI3EQX12908::getSW_B2(){
  return _read_reg(CONFIG_B2_REG) & 0x01;
}

/**************************************************************************/
/*!
    @brief  Sets the configuration of the 2 index B channel.
            This function sets the configuration register of B2.
            * NOT RECOMENDED TO USE! *
    @param    config
              8 bit value of the config register
/**************************************************************************/
void PI3EQX12908::setConfig_B2(uint8_t config){
  _write_reg(CONFIG_B2_REG, config);
}

/**************************************************************************/
/*!
    @brief  Sets the equalizer value of the 2 index B channel.
            This function sets the equalizer value of B2.
    @param    EQ
              4 bit value of the equalizer index
/**************************************************************************/
void PI3EQX12908::setEQ_B2(uint8_t EQ){
  uint8_t val = getConfig_B2();
  val &= 0x0F;
  val |= (EQ & 0x0F) << EQ_SHIFT;
  _write_reg(CONFIG_B2_REG, val);
}

/**************************************************************************/
/*!
    @brief  Sets the flat gain value of the 2 index B channel.
            This function sets the flat gain value of B2.
    @param    flat_gain
              2 bit value of the flat gain:
              FLAT_GAIN_M4db -> -4 db
              FLAT_GAIN_M2db -> -2 db
              FLAT_GAIN_00db ->  0 db
              FLAT_GAIN_P2db -> +2 db
/**************************************************************************/
void PI3EQX12908::setFlatGain_B2(uint8_t flat_gain){
  uint8_t val = getConfig_B2();
  val &= 0xF3;
  val |= (flat_gain & 0x03) << FG_SHIFT;
  _write_reg(CONFIG_B2_REG, val);
}

/**************************************************************************/
/*!
    @brief  Sets the swing value of the 2 index B channel.
            This function sets the swing value of B2.
    @param    swing
              1 bit value of the swing:
              SWING_900mVpp  ->  900 mVpp
              SWING_1000mVpp -> 1000 mVpp
/**************************************************************************/
void PI3EQX12908::setSW_B2(uint8_t swing){
  uint8_t val = getConfig_B2();
  val &= 0xFE;
  val |= swing & 0x01;
  _write_reg(CONFIG_B2_REG, val);
}

// 10 - B3 Config
/**************************************************************************/
/*!
    @brief  Gets the configuration of the 3 index B channel.
            This function reads the configuration of the 3 index B channel value.
    @return 8 bit value of B3 config register.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getConfig_B3(){
  return _read_reg(CONFIG_B3_REG);
}

/**************************************************************************/
/*!
    @brief  Gets the equalizer configuration of the 3 index B channel.
            This function reads the equalizer value of the 3 index B channel value.
    @return 4 bit value of B3 equalizer.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getEQ_B3(){
  return _read_reg(CONFIG_B3_REG) >> EQ_SHIFT;
}

/**************************************************************************/
/*!
    @brief  Gets the flat gain configuration of the 3 index B channel.
            This function reads the flat gain value of the 3 index B channel value.
    @return 2 bit value of B3 flat gain:
            FLAT_GAIN_M4db -> -4 db
            FLAT_GAIN_M2db -> -2 db
            FLAT_GAIN_00db ->  0 db
            FLAT_GAIN_P2db -> +2 db
*/
/**************************************************************************/
uint8_t PI3EQX12908::getFlatGain_B3(){
  return (_read_reg(CONFIG_B3_REG) & 0x0F) >> FG_SHIFT;
}

/**************************************************************************/
/*!
    @brief  Gets the swing configuration of the 3 index B channel.
            This function reads the swing value of the 3 index B channel value.
    @return 1 bit value of B3 swing:
            SWING_900mVpp  ->  900 mVpp
            SWING_1000mVpp -> 1000 mVpp
*/
/**************************************************************************/
uint8_t PI3EQX12908::getSW_B3(){
  return _read_reg(CONFIG_B3_REG) & 0x01;
}

/**************************************************************************/
/*!
    @brief  Sets the configuration of the 3 index B channel.
            This function sets the configuration register of B3.
            * NOT RECOMENDED TO USE! *
    @param    config
              8 bit value of the config register
/**************************************************************************/
void PI3EQX12908::setConfig_B3(uint8_t config){
  _write_reg(CONFIG_B3_REG, config);
}

/**************************************************************************/
/*!
    @brief  Sets the equalizer value of the 3 index B channel.
            This function sets the equalizer value of B3.
    @param    EQ
              4 bit value of the equalizer index
/**************************************************************************/
void PI3EQX12908::setEQ_B3(uint8_t EQ){
  uint8_t val = getConfig_B3();
  val &= 0x0F;
  val |= (EQ & 0x0F) << EQ_SHIFT;
  _write_reg(CONFIG_B3_REG, val);
}

/**************************************************************************/
/*!
    @brief  Sets the flat gain value of the 3 index B channel.
            This function sets the flat gain value of B3.
    @param    flat_gain
              2 bit value of the flat gain:
              FLAT_GAIN_M4db -> -4 db
              FLAT_GAIN_M2db -> -2 db
              FLAT_GAIN_00db ->  0 db
              FLAT_GAIN_P2db -> +2 db
/**************************************************************************/
void PI3EQX12908::setFlatGain_B3(uint8_t flat_gain){
  uint8_t val = getConfig_B3();
  val &= 0xF3;
  val |= (flat_gain & 0x03) << FG_SHIFT;
  _write_reg(CONFIG_B3_REG, val);
}

/**************************************************************************/
/*!
    @brief  Sets the swing value of the 3 index B channel.
            This function sets the swing value of B3.
    @param    swing
              1 bit value of the swing:
              SWING_900mVpp  ->  900 mVpp
              SWING_1000mVpp -> 1000 mVpp
/**************************************************************************/
void PI3EQX12908::setSW_B3(uint8_t swing){
  uint8_t val = getConfig_B3();
  val &= 0xFE;
  val |= swing & 0x01;
  _write_reg(CONFIG_B3_REG, val);
}

// 11 - Signal Detect Config
/**************************************************************************/
/*!
    @brief  Gets the signal detect configuration register
            This function reads the signal detect configuration register values.
    @return 8 bit value of signal detect configuration register.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getSignalDetectConfig(){
  return _read_reg(SIGNAL_DET_CFG_REG);
}

/**************************************************************************/
/*!
    @brief  Gets the signal detect configuration of A channel
            This function reads the signal detect configuration register
            and returns the channel A status.
    @return 4 bit value of channel A signal detect configuration.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getSignalDetectConfig_A(){
  return _read_reg(SIGNAL_DET_CFG_REG) >> 4;
}

/**************************************************************************/
/*!
    @brief  Gets the signal detect configuration A by channel index
            This function reads the signal detect configuration register value.
    @param    index
              A reference to the channel index of A channel from 0 to 3.
    @return return zero for enabled, otherwise for disabled.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getSignalDetectConfig_A(uint8_t index){
  return _read_reg(SIGNAL_DET_CFG_REG) & (1 << (index + 4));
}

/**************************************************************************/
/*!
    @brief  Gets the signal detect configuration of B channel
            This function reads the signal detect configuration register
            and returns the channel B status.
    @return 4 bit value of channel B signal detect configuration.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getSignalDetectConfig_B(){
  return _read_reg(SIGNAL_DET_CFG_REG) & 0x0F;
}

/**************************************************************************/
/*!
    @brief  Gets the signal detect configuration B by channel index
            This function reads the signal detect configuration register value.
    @param    index
              A reference to the channel index of B channel from 0 to 3.
    @return return zero for enabled, otherwise for disabled.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getSignalDetectConfig_B(uint8_t index){
  return _read_reg(SIGNAL_DET_CFG_REG) & (1 << index);
}

/**************************************************************************/
/*!
    @brief  Sets the signal detect configuration register.
            This function change the signal detect configuration of all channels.
    @param    isDown
              CFG_ON  for enable
              CFG_OFF for disable
*/
/**************************************************************************/
void PI3EQX12908::setSignalDetectConfig(uint8_t isDown){
  _write_reg(SIGNAL_DET_CFG_REG, isDown ? 0xFF : 0x00);
}

/**************************************************************************/
/*!
    @brief  Sets the signal detect configuration of A channel.
            This function change the signal detect configuration of channel A.
    @param    isDown
              CFG_ON  for enable
              CFG_OFF for disable
*/
/**************************************************************************/
void PI3EQX12908::setSignalDetectConfig_A(uint8_t isDown){
  uint8_t val = getSignalDetectConfig();
  if(isDown)
    val |= 0xF0;
  else
    val &= 0x0F;
  _write_reg(SIGNAL_DET_CFG_REG, val);
}

/**************************************************************************/
/*!
    @brief  Sets the signal detect configuration of a given index of A channel.
            This function change the signal detect configuration of the 
            given channel A index.
    @param    index
              A reference to the channel index of A channel from 0 to 3.
    @param    isDown
              CFG_ON  for enable
              CFG_OFF for disable
*/
/**************************************************************************/
void PI3EQX12908::setSignalDetectConfig_A(uint8_t index, uint8_t isDown){
  uint8_t val = getSignalDetectConfig();
  if(isDown)
    val |= (1 << (index + 4));
  else
    val &= ~(1 << (index + 4));
  _write_reg(SIGNAL_DET_CFG_REG, val);
}

/**************************************************************************/
/*!
    @brief  Sets the signal detect configuration of B channel.
            This function change the signal detect configuration of channel B.
    @param    isDown
              CFG_ON  for enable
              CFG_OFF for disable
*/
/**************************************************************************/
void PI3EQX12908::setSignalDetectConfig_B(uint8_t isDown){
  uint8_t val = getSignalDetectConfig();
  if(isDown)
    val |= 0x0F;
  else
    val &= 0xF0;
  _write_reg(SIGNAL_DET_CFG_REG, val);
}

/**************************************************************************/
/*!
    @brief  Sets the signal detect configuration of a given index of B channel.
            This function change the signal detect configuration of the 
            given channel B index.
    @param    index
              A reference to the channel index of B channel from 0 to 3.
    @param    isDown
              CFG_ON  for enable
              CFG_OFF for disable
*/
/**************************************************************************/
void PI3EQX12908::setSignalDetectConfig_B(uint8_t index, uint8_t isDown){
  uint8_t val = getSignalDetectConfig();
  if(isDown)
    val |= (1 << index);
  else
    val &= ~(1 << index);
  _write_reg(SIGNAL_DET_CFG_REG, val);
}

// 12 - RX Detect Config
/**************************************************************************/
/*!
    @brief  Gets the RX detect configuration register
            This function reads the RX detect configuration register values.
    @return 8 bit value of RX detect configuration register.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getRxDetectConfig(){
  return _read_reg(RX_DET_CFG_REG);
}

/**************************************************************************/
/*!
    @brief  Gets the RX detect configuration of A channel
            This function reads the RX detect configuration register
            and returns the channel A status.
    @return 4 bit value of channel A RX detect configuration.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getRxDetectConfig_A(){
  return _read_reg(RX_DET_CFG_REG) >> 4;
}

/**************************************************************************/
/*!
    @brief  Gets the RX detect configuration A by channel index
            This function reads the RX detect configuration register value.
    @param    index
              A reference to the channel index of A channel from 0 to 3.
    @return return zero for enabled, otherwise for disabled.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getRxDetectConfig_A(uint8_t index){
  return _read_reg(RX_DET_CFG_REG) & (1 << (index + 4));
}

/**************************************************************************/
/*!
    @brief  Gets the RX detect configuration of B channel
            This function reads the RX detect configuration register
            and returns the channel B status.
    @return 4 bit value of channel B RX detect configuration.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getRxDetectConfig_B(){
  return _read_reg(RX_DET_CFG_REG) & 0x0F;
}

/**************************************************************************/
/*!
    @brief  Gets the RX detect configuration B by channel index
            This function reads the RX detect configuration register value.
    @param    index
              A reference to the channel index of B channel from 0 to 3.
    @return return zero for enabled, otherwise for disabled.
*/
/**************************************************************************/
uint8_t PI3EQX12908::getRxDetectConfig_B(uint8_t index){
  return _read_reg(RX_DET_CFG_REG) & (1 << index);
}

/**************************************************************************/
/*!
    @brief  Sets the RX detect configuration register.
            This function change the RX detect configuration of all channels.
    @param    isDown
              CFG_ON  for enable
              CFG_OFF for disable
*/
/**************************************************************************/
void PI3EQX12908::setRxDetectConfig(uint8_t isDown){
  _write_reg(RX_DET_CFG_REG, isDown ? 0xFF : 0x00);
}

/**************************************************************************/
/*!
    @brief  Sets the RX detect configuration of A channel.
            This function change the RX detect configuration of channel A.
    @param    isDown
              CFG_ON  for enable
              CFG_OFF for disable
*/
/**************************************************************************/
void PI3EQX12908::setRxDetectConfig_A(uint8_t isDown){
  uint8_t val = getRxDetectConfig();
  if(isDown)
    val |= 0xF0;
  else
    val &= 0x0F;
  _write_reg(RX_DET_CFG_REG, val);
}

/**************************************************************************/
/*!
    @brief  Sets the RX detect configuration of a given index of A channel.
            This function change the RX detect configuration of the 
            given channel A index.
    @param    index
              A reference to the channel index of A channel from 0 to 3.
    @param    isDown
              CFG_ON  for enable
              CFG_OFF for disable
*/
/**************************************************************************/
void PI3EQX12908::setRxDetectConfig_A(uint8_t index, uint8_t isDown){
  uint8_t val = getRxDetectConfig();
  if(isDown)
    val |= (1 << (index + 4));
  else
    val &= ~(1 << (index + 4));
  _write_reg(RX_DET_CFG_REG, val);
}

/**************************************************************************/
/*!
    @brief  Sets the RX detect configuration of B channel.
            This function change the RX detect configuration of channel B.
    @param    isDown
              CFG_ON  for enable
              CFG_OFF for disable
*/
/**************************************************************************/
void PI3EQX12908::setRxDetectConfig_B(uint8_t isDown){
  uint8_t val = getRxDetectConfig();
  if(isDown)
    val |= 0x0F;
  else
    val &= 0xF0;
  _write_reg(RX_DET_CFG_REG, val);
}

/**************************************************************************/
/*!
    @brief  Sets the RX detect configuration of a given index of B channel.
            This function change the RX detect configuration of the 
            given channel B index.
    @param    index
              A reference to the channel index of A channel from 0 to 3.
    @param    isDown
              CFG_ON  for enable
              CFG_OFF for disable
*/
/**************************************************************************/
void PI3EQX12908::setRxDetectConfig_B(uint8_t index, uint8_t isDown){
  uint8_t val = getRxDetectConfig();
  if(isDown)
    val |= (1 << index);
  else
    val &= ~(1 << index);
  _write_reg(RX_DET_CFG_REG, val);
}

// 13 - Signal Detect Threshold
/**************************************************************************/
/*!
    @brief  Gets the signal detect threshold of all channels.
            This function gets the signal detect threshold 
            of all channels.
    @return 2 bit value of the signal detect threshold:
            SDT_OFF_30_ON_130_mVpp  ->  30 mVpp for off and 130 mVpp for on
            SDT_OFF_50_ON_150_mVpp  ->  50 mVpp for off and 150 mVpp for on
            SDT_OFF_70_ON_170_mVpp  ->  70 mVpp for off and 170 mVpp for on
            SDT_OFF_110_ON_210_mVpp -> 110 mVpp for off and 210 mVpp for on
/**************************************************************************/
uint8_t PI3EQX12908::getSDTConfig(){
  return _read_reg(SIGNAL_DET_TH_REG);
}

/**************************************************************************/
/*!
    @brief  Sets the signal detect threshold for all channels.
            This function changes the signal detect threshold 
            of all channels.
    @param    thresh
              2 bit value of the threshold:
              SDT_OFF_30_ON_130_mVpp  ->  30 mVpp for off and 130 mVpp for on
              SDT_OFF_50_ON_150_mVpp  ->  50 mVpp for off and 150 mVpp for on
              SDT_OFF_70_ON_170_mVpp  ->  70 mVpp for off and 170 mVpp for on
              SDT_OFF_110_ON_210_mVpp -> 110 mVpp for off and 210 mVpp for on
*/
/**************************************************************************/
uint8_t PI3EQX12908::setSDTConfig(uint8_t thresh){
  uint8_t val = getSDTConfig();
  val &= 0x03;
  val |= (thresh & 0x03) << SDT_SHIFT;
  _write_reg(SIGNAL_DET_TH_REG, val);
}


// Others
/**************************************************************************/
/*!
    @brief  Sets the configuration of the channel A
            This function sets the configuration of channel A.
            * NOT RECOMENDED TO USE! *
    @param    config
              8 bit value of the config register
/**************************************************************************/
void PI3EQX12908::setConfig_A(uint8_t config){
  uint8_t data[4] = {config, config, config, config};
  _burst_write(CONFIG_A0_REG, data, 4);
}

/**************************************************************************/
/*!
    @brief  Sets the configuration of the given index of channel A
            This function sets the configuration of the given index of channel A.
            This function is equal to setConfig_Ax(...) (x is channel index)
            * NOT RECOMENDED TO USE! *
    @param    config
              8 bit value of the config register
/**************************************************************************/
void PI3EQX12908::setConfig_A(uint8_t index, uint8_t config){
  _write_reg(CONFIG_A_OFFSET + index, config);
}

/**************************************************************************/
/*!
    @brief  Sets the configuration of the channel A
            This function sets the configuration of channel A.
            * NOT RECOMENDED TO USE! *
    @param    config
              8 bit value of the config register
/**************************************************************************/
void PI3EQX12908::setConfig_B(uint8_t config){
  uint8_t data[4] = {config, config, config, config};
  _burst_write(CONFIG_B0_REG, data, 4);
}

/**************************************************************************/
/*!
    @brief  Sets the configuration of the given index of channel B
            This function sets the configuration of the given index of channel B.
            This function is equal to setConfig_Bx(...) (x is channel index)
            * NOT RECOMENDED TO USE! *
    @param    config
              8 bit value of the config register
/**************************************************************************/
void PI3EQX12908::setConfig_B(uint8_t index, uint8_t config){
  _write_reg(CONFIG_B_OFFSET + index, config);
}

/**************************************************************************/
/*!
    @brief  Sets the configuration of all channels
            This function sets the configuration of all channels.
            * NOT RECOMENDED TO USE! *
    @param    config
              8 bit value of the config register
/**************************************************************************/
void PI3EQX12908::setConfig(uint8_t config){
  uint8_t data[8] = {config, config, config, config, config, config, config, config};
  _burst_write(CONFIG_A0_REG, data, 8);
}

/**************************************************************************/
/*!
    @brief  Sets the equalizer of the channel A
            This function sets the equalizer settings of the channel A.
    @param    EQ
              4 bit value of the equalizer index
/**************************************************************************/
void PI3EQX12908::setEQ_A(uint8_t EQ){
  uint8_t val[4];
  _burst_read(CONFIG_A0_REG, val, 4);
  for(uint8_t i=0; i<4; i++){
    val[i] &= 0x0F;
    val[i] |= (EQ & 0x0F) << EQ_SHIFT;
  }
  _burst_write(CONFIG_A0_REG, val, 4);
}

/**************************************************************************/
/*!
    @brief  Sets the equalizer of the channel B
            This function sets the equalizer settings of the channel B.
    @param    EQ
              4 bit value of the equalizer index
/**************************************************************************/
void PI3EQX12908::setEQ_B(uint8_t EQ){
  uint8_t val[4];
  _burst_read(CONFIG_B0_REG, val, 4);
  for(uint8_t i=0; i<4; i++){
    val[i] &= 0x0F;
    val[i] |= (EQ & 0x0F) << EQ_SHIFT;
  }
  _burst_write(CONFIG_B0_REG, val, 4);
}

/**************************************************************************/
/*!
    @brief  Sets the equalizer of the all channels
            This function sets the equalizer settings of the all channels.
    @param    EQ
              4 bit value of the equalizer index
/**************************************************************************/
void PI3EQX12908::setEQ(uint8_t EQ){
  //setEQ_A(EQ);
  //setEQ_B(EQ);
  //*/
  uint8_t val[8];
  _burst_read(CONFIG_A0_REG, val, 8);
  for(uint8_t i=0; i<8; i++){
    val[i] &= 0x0F;
    val[i] |= (EQ & 0x0F) << EQ_SHIFT;
  }
  _burst_write(CONFIG_A0_REG, val, 8);
  //*/
}

/**************************************************************************/
/*!
    @brief  Sets the flat gain of the channel A
            This function sets the flat gain setting of the channel A.
    @param    flat_gain
              2 bit value of the flat gain:
              FLAT_GAIN_M4db -> -4 db
              FLAT_GAIN_M2db -> -2 db
              FLAT_GAIN_00db ->  0 db
              FLAT_GAIN_P2db -> +2 db
/**************************************************************************/
void PI3EQX12908::setFG_A(uint8_t flat_gain){
  uint8_t val[4];
  _burst_read(CONFIG_A0_REG, val, 4);
  for(uint8_t i=0; i<4; i++){
    val[i] &= 0xF3;
    val[i] |= (flat_gain & 0x03) << FG_SHIFT;
  }
  _burst_write(CONFIG_A0_REG, val, 4);
}

/**************************************************************************/
/*!
    @brief  Sets the flat gain of the channel B
            This function sets the flat gain setting of the channel B.
    @param    flat_gain
              2 bit value of the flat gain:
              FLAT_GAIN_M4db -> -4 db
              FLAT_GAIN_M2db -> -2 db
              FLAT_GAIN_00db ->  0 db
              FLAT_GAIN_P2db -> +2 db
/**************************************************************************/
void PI3EQX12908::setFG_B(uint8_t flat_gain){
  uint8_t val[4];
  _burst_read(CONFIG_B0_REG, val, 4);
  for(uint8_t i=0; i<4; i++){
    val[i] &= 0xF3;
    val[i] |= (flat_gain & 0x03) << FG_SHIFT;
  }
  _burst_write(CONFIG_B0_REG, val, 4);
}

/**************************************************************************/
/*!
    @brief  Sets the flat gain of all channels
            This function sets the flat gain setting of all channels.
    @param    flat_gain
              2 bit value of the flat gain:
              FLAT_GAIN_M4db -> -4 db
              FLAT_GAIN_M2db -> -2 db
              FLAT_GAIN_00db ->  0 db
              FLAT_GAIN_P2db -> +2 db
/**************************************************************************/
void PI3EQX12908::setFG(uint8_t flat_gain){
  //setFG_A(flat_gain);
  //setFG_B(flat_gain);
  //*/
  uint8_t val[8];
  _burst_read(CONFIG_A0_REG, val, 8);
  for(uint8_t i=0; i<8; i++){
    val[i] &= 0xF3;
    val[i] |= (flat_gain & 0x03) << FG_SHIFT;
  }
  _burst_write(CONFIG_A0_REG, val, 8);
  //*/
}

/**************************************************************************/
/*!
    @brief  Sets the swing value of the channel A
            This function sets the swing value of the channel A.
    @param    swing
              1 bit value of the flat gain:
              SWING_900mVpp  ->  900 mVpp
              SWING_1000mVpp -> 1000 mVpp
/**************************************************************************/
void PI3EQX12908::setSW_A(uint8_t swing){
  uint8_t val[4];
  _burst_read(CONFIG_A0_REG, val, 4);
  for(uint8_t i=0; i<4; i++){
    val[i] &= 0xFE;
    val[i] |= (swing & 0x01) << SW_SHIFT;
  }
  _burst_write(CONFIG_A0_REG, val, 4);
}

/**************************************************************************/
/*!
    @brief  Sets the swing value of the channel B
            This function sets the swing value of the channel B.
    @param    swing
              1 bit value of the flat gain:
              SWING_900mVpp  ->  900 mVpp
              SWING_1000mVpp -> 1000 mVpp
/**************************************************************************/
void PI3EQX12908::setSW_B(uint8_t swing){
  uint8_t val[4];
  _burst_read(CONFIG_B0_REG, val, 4);
  for(uint8_t i=0; i<4; i++){
    val[i] &= 0xFE;
    val[i] |= (swing & 0x01) << SW_SHIFT;
  }
  _burst_write(CONFIG_B0_REG, val, 4);
}

/**************************************************************************/
/*!
    @brief  Sets the swing value of all channels
            This function sets the swing value of all channels.
    @param    swing
              1 bit value of the flat gain:
              SWING_900mVpp  ->  900 mVpp
              SWING_1000mVpp -> 1000 mVpp
/**************************************************************************/
void PI3EQX12908::setSW(uint8_t swing){
  //setSW_A(swing);
  //setSW_B(swing);
  //*/
  uint8_t val[8];
  _burst_read(CONFIG_A0_REG, val, 8);
  for(uint8_t i=0; i<8; i++){
    val[i] &= 0xFE;
    val[i] |= (swing & 0x01) << SW_SHIFT;
  }
  _burst_write(CONFIG_A0_REG, val, 8);
  //*/
}

/**************************************************************************/
/*!
    @brief  Prints all of the registers
            This function prints all of the registers of the chip
            over the default UART (Serial)
/**************************************************************************/
void PI3EQX12908::print_all(){
  uint8_t data[16];
  dump_all(data);
  for(uint8_t i=0; i<16; i++){
    Serial.print(_REGS[i]);
    Serial.print(" = BIN: ");
    Serial.print((data[i] >> 7) & 0x01);
    Serial.print((data[i] >> 6) & 0x01);
    Serial.print((data[i] >> 5) & 0x01);
    Serial.print((data[i] >> 4) & 0x01);
    Serial.print((data[i] >> 3) & 0x01);
    Serial.print((data[i] >> 2) & 0x01);
    Serial.print((data[i] >> 1) & 0x01);
    Serial.print((data[i] >> 0) & 0x01);
    Serial.print(" - HEX: 0x");
    Serial.print(data[i] >> 4, HEX);
    Serial.println(data[i] & 0x0F, HEX);
  }
}

/**************************************************************************/
/*!
    @brief  Reads all of the registers
            This function reads all of the registers of the chip.
    @param    data
              A pointer to an array of 16 bytes to store
              the values.
/**************************************************************************/
void PI3EQX12908::dump_all(uint8_t* data){
  _burst_read(0, data, 16);
}

uint8_t PI3EQX12908::_read_reg(uint8_t mem_addr){
  //Wire.beginTransmission(_I2C_ADDR);
  //Wire.write(mem_addr);
  //Wire.endTransmission();
  Wire.requestFrom(_I2C_ADDR, (uint8_t)(mem_addr + 1));
  for(uint8_t i=0; i<mem_addr; i++)
    Wire.read();
  return Wire.read();
}

void PI3EQX12908::_write_reg(uint8_t mem_addr, uint8_t value){
  Wire.beginTransmission(_I2C_ADDR);
  Wire.write(mem_addr);
  Wire.write(value);
  Wire.endTransmission();
}

void PI3EQX12908::_burst_read(uint8_t mem_addr, uint8_t* data, uint8_t len){
  //Wire.beginTransmission(_I2C_ADDR);
  //Wire.write(mem_addr);
  //Wire.endTransmission();
  Wire.requestFrom(_I2C_ADDR, (uint8_t)(mem_addr + len));
  for(uint8_t i=0; i<mem_addr; i++)
    Wire.read();
  for(uint8_t i=0; i<len; i++)
    data[i] = Wire.read();
}

void PI3EQX12908::_burst_write(uint8_t mem_addr, uint8_t* data, uint8_t len){
  Wire.beginTransmission(_I2C_ADDR);
  Wire.write(mem_addr);
  for(uint8_t i=0; i<len; i++)
    Wire.write(data[i]);
  Wire.endTransmission();
}
