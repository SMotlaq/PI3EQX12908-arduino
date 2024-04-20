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
uint8_t PI3EQX12908::getSignalDetect(){
  return _read_reg(SIGNAL_DETECT_REG);
}

uint8_t PI3EQX12908::getSignalDetect_A(){
  return _read_reg(SIGNAL_DETECT_REG) >> 4;
}

uint8_t PI3EQX12908::getSignalDetect_A(uint8_t index){
  return _read_reg(SIGNAL_DETECT_REG) & (1 << (index + 4));
}

uint8_t PI3EQX12908::getSignalDetect_B(){
  return _read_reg(SIGNAL_DETECT_REG) & 0x0F;
}

uint8_t PI3EQX12908::getSignalDetect_B(uint8_t index){
  return _read_reg(SIGNAL_DETECT_REG) & (1 << index);
}

// 1 - RX Detect
uint8_t PI3EQX12908::getRxDetect(){
  return _read_reg(RX_DETECT_REG);
}

uint8_t PI3EQX12908::getRxDetect_A(){
  return _read_reg(RX_DETECT_REG) >> 4;
}

uint8_t PI3EQX12908::getRxDetect_A(uint8_t index){
  return _read_reg(RX_DETECT_REG) & (1 << (index + 4));
}

uint8_t PI3EQX12908::getRxDetect_B(){
  return _read_reg(RX_DETECT_REG) & 0x0F;
}

uint8_t PI3EQX12908::getRxDetect_B(uint8_t index){
  return _read_reg(RX_DETECT_REG) & (1 << index);
}

// 2 - Power Down
uint8_t PI3EQX12908::getPowerDown(){
  return _read_reg(POWER_DOWN_REG);
}

uint8_t PI3EQX12908::getPowerDown_A(){
  return _read_reg(POWER_DOWN_REG) >> 4;
}

uint8_t PI3EQX12908::getPowerDown_A(uint8_t index){
  return _read_reg(POWER_DOWN_REG) & (1 << (index + 4));
}

uint8_t PI3EQX12908::getPowerDown_B(){
  return _read_reg(POWER_DOWN_REG) & 0x0F;
}

uint8_t PI3EQX12908::getPowerDown_B(uint8_t index){
  return _read_reg(POWER_DOWN_REG) & (1 << index);
}

void PI3EQX12908::setPowerDown(uint8_t isDown){
  _write_reg(POWER_DOWN_REG, isDown ? 0xFF : 0x00);
}

void PI3EQX12908::setPowerDown_A(uint8_t isDown){
  uint8_t val = getPowerDown();
  if(isDown)
    val |= (uint8_t)0xF0;
  else
    val &= (uint8_t)0x0F;
  _write_reg(POWER_DOWN_REG, val);
}

void PI3EQX12908::setPowerDown_A(uint8_t index, uint8_t isDown){
  uint8_t val = getPowerDown();
  if(isDown)
    val |= (1 << (index + 4));
  else
    val &= ~(1 << (index + 4));
  _write_reg(POWER_DOWN_REG, val);
}

void PI3EQX12908::setPowerDown_B(uint8_t isDown){
  uint8_t val = getPowerDown();
  if(isDown)
    val |= (uint8_t)0x0F;
  else
    val &= (uint8_t)0xF0;
  _write_reg(POWER_DOWN_REG, val);
}

void PI3EQX12908::setPowerDown_B(uint8_t index, uint8_t isDown){
  uint8_t val = getPowerDown();
  if(isDown)
    val |= (1 << index);
  else
    val &= ~(1 << index);
  _write_reg(POWER_DOWN_REG, val);
}

// 3 - A0 Config
uint8_t PI3EQX12908::getConfig_A0(){
  return _read_reg(CONFIG_A0_REG);
}

uint8_t PI3EQX12908::getEQ_A0(){
  return _read_reg(CONFIG_A0_REG) >> EQ_SHIFT;
}

uint8_t PI3EQX12908::getFlatGain_A0(){
  return (_read_reg(CONFIG_A0_REG) & 0x0F) >> FG_SHIFT;
}

uint8_t PI3EQX12908::getSW_A0(){
  return _read_reg(CONFIG_A0_REG) & 0x01;
}

void PI3EQX12908::setConfig_A0(uint8_t config){
  _write_reg(CONFIG_A0_REG, config);
}

void PI3EQX12908::setEQ_A0(uint8_t EQ){
  uint8_t val = getConfig_A0();
  val &= 0x0F;
  val |= (EQ & 0x0F) << EQ_SHIFT;
  _write_reg(CONFIG_A0_REG, val);
}

void PI3EQX12908::setFlatGain_A0(uint8_t flat_gain){
  uint8_t val = getConfig_A0();
  val &= 0xF3;
  val |= (flat_gain & 0x03) << FG_SHIFT;
  _write_reg(CONFIG_A0_REG, val);
}

void PI3EQX12908::setSW_A0(uint8_t swing){
  uint8_t val = getConfig_A0();
  val &= 0xFE;
  val |= swing & 0x01;
  _write_reg(CONFIG_A0_REG, val);
}

// 4 - A1 Config
uint8_t PI3EQX12908::getConfig_A1(){
  return _read_reg(CONFIG_A1_REG);
}

uint8_t PI3EQX12908::getEQ_A1(){
  return _read_reg(CONFIG_A1_REG) >> EQ_SHIFT;
}

uint8_t PI3EQX12908::getFlatGain_A1(){
  return (_read_reg(CONFIG_A1_REG) & 0x0F) >> FG_SHIFT;
}

uint8_t PI3EQX12908::getSW_A1(){
  return _read_reg(CONFIG_A1_REG) & 0x01;
}

void PI3EQX12908::setConfig_A1(uint8_t config){
  _write_reg(CONFIG_A1_REG, config);
}

void PI3EQX12908::setEQ_A1(uint8_t EQ){
  uint8_t val = getConfig_A1();
  val &= 0x0F;
  val |= (EQ & 0x0F) << EQ_SHIFT;
  _write_reg(CONFIG_A1_REG, val);
}

void PI3EQX12908::setFlatGain_A1(uint8_t flat_gain){
  uint8_t val = getConfig_A1();
  val &= 0xF3;
  val |= (flat_gain & 0x03) << FG_SHIFT;
  _write_reg(CONFIG_A1_REG, val);
}

void PI3EQX12908::setSW_A1(uint8_t swing){
  uint8_t val = getConfig_A1();
  val &= 0xFE;
  val |= swing & 0x01;
  _write_reg(CONFIG_A1_REG, val);
}

// 5 - A2 Config
uint8_t PI3EQX12908::getConfig_A2(){
  return _read_reg(CONFIG_A2_REG);
}

uint8_t PI3EQX12908::getEQ_A2(){
  return _read_reg(CONFIG_A2_REG) >> EQ_SHIFT;
}

uint8_t PI3EQX12908::getFlatGain_A2(){
  return (_read_reg(CONFIG_A2_REG) & 0x0F) >> FG_SHIFT;
}

uint8_t PI3EQX12908::getSW_A2(){
  return _read_reg(CONFIG_A2_REG) & 0x01;
}

void PI3EQX12908::setConfig_A2(uint8_t config){
  _write_reg(CONFIG_A2_REG, config);
}

void PI3EQX12908::setEQ_A2(uint8_t EQ){
  uint8_t val = getConfig_A2();
  val &= 0x0F;
  val |= (EQ & 0x0F) << EQ_SHIFT;
  _write_reg(CONFIG_A2_REG, val);
}

void PI3EQX12908::setFlatGain_A2(uint8_t flat_gain){
  uint8_t val = getConfig_A2();
  val &= 0xF3;
  val |= (flat_gain & 0x03) << FG_SHIFT;
  _write_reg(CONFIG_A2_REG, val);
}

void PI3EQX12908::setSW_A2(uint8_t swing){
  uint8_t val = getConfig_A2();
  val &= 0xFE;
  val |= swing & 0x01;
  _write_reg(CONFIG_A2_REG, val);
}

// 6 - A3 Config
uint8_t PI3EQX12908::getConfig_A3(){
  return _read_reg(CONFIG_A3_REG);
}

uint8_t PI3EQX12908::getEQ_A3(){
  return _read_reg(CONFIG_A3_REG) >> EQ_SHIFT;
}

uint8_t PI3EQX12908::getFlatGain_A3(){
  return (_read_reg(CONFIG_A3_REG) & 0x0F) >> FG_SHIFT;
}

uint8_t PI3EQX12908::getSW_A3(){
  return _read_reg(CONFIG_A3_REG) & 0x01;
}

void PI3EQX12908::setConfig_A3(uint8_t config){
  _write_reg(CONFIG_A3_REG, config);
}

void PI3EQX12908::setEQ_A3(uint8_t EQ){
  uint8_t val = getConfig_A3();
  val &= 0x0F;
  val |= (EQ & 0x0F) << EQ_SHIFT;
  _write_reg(CONFIG_A3_REG, val);
}

void PI3EQX12908::setFlatGain_A3(uint8_t flat_gain){
  uint8_t val = getConfig_A3();
  val &= 0xF3;
  val |= (flat_gain & 0x03) << FG_SHIFT;
  _write_reg(CONFIG_A3_REG, val);
}

void PI3EQX12908::setSW_A3(uint8_t swing){
  uint8_t val = getConfig_A3();
  val &= 0xFE;
  val |= swing & 0x01;
  _write_reg(CONFIG_A3_REG, val);
}

// 7 - B0 Config
uint8_t PI3EQX12908::getConfig_B0(){
  return _read_reg(CONFIG_B0_REG);
}

uint8_t PI3EQX12908::getEQ_B0(){
  return _read_reg(CONFIG_B0_REG) >> EQ_SHIFT;
}

uint8_t PI3EQX12908::getFlatGain_B0(){
  return (_read_reg(CONFIG_B0_REG) & 0x0F) >> FG_SHIFT;
}

uint8_t PI3EQX12908::getSW_B0(){
  return _read_reg(CONFIG_B0_REG) & 0x01;
}

void PI3EQX12908::setConfig_B0(uint8_t config){
  _write_reg(CONFIG_B0_REG, config);
}

void PI3EQX12908::setEQ_B0(uint8_t EQ){
  uint8_t val = getConfig_B0();
  val &= 0x0F;
  val |= (EQ & 0x0F) << EQ_SHIFT;
  _write_reg(CONFIG_B0_REG, val);
}

void PI3EQX12908::setFlatGain_B0(uint8_t flat_gain){
  uint8_t val = getConfig_B0();
  val &= 0xF3;
  val |= (flat_gain & 0x03) << FG_SHIFT;
  _write_reg(CONFIG_B0_REG, val);
}

void PI3EQX12908::setSW_B0(uint8_t swing){
  uint8_t val = getConfig_B0();
  val &= 0xFE;
  val |= swing & 0x01;
  _write_reg(CONFIG_B0_REG, val);
}

// 8 - B1 Config
uint8_t PI3EQX12908::getConfig_B1(){
  return _read_reg(CONFIG_B1_REG);
}

uint8_t PI3EQX12908::getEQ_B1(){
  return _read_reg(CONFIG_B1_REG) >> EQ_SHIFT;
}

uint8_t PI3EQX12908::getFlatGain_B1(){
  return (_read_reg(CONFIG_B1_REG) & 0x0F) >> FG_SHIFT;
}

uint8_t PI3EQX12908::getSW_B1(){
  return _read_reg(CONFIG_B1_REG) & 0x01;
}

void PI3EQX12908::setConfig_B1(uint8_t config){
  _write_reg(CONFIG_B1_REG, config);
}

void PI3EQX12908::setEQ_B1(uint8_t EQ){
  uint8_t val = getConfig_B1();
  val &= 0x0F;
  val |= (EQ & 0x0F) << EQ_SHIFT;
  _write_reg(CONFIG_B1_REG, val);
}

void PI3EQX12908::setFlatGain_B1(uint8_t flat_gain){
  uint8_t val = getConfig_B1();
  val &= 0xF3;
  val |= (flat_gain & 0x03) << FG_SHIFT;
  _write_reg(CONFIG_B1_REG, val);
}

void PI3EQX12908::setSW_B1(uint8_t swing){
  uint8_t val = getConfig_B1();
  val &= 0xFE;
  val |= swing & 0x01;
  _write_reg(CONFIG_B1_REG, val);
}

// 9 - B2 Config
uint8_t PI3EQX12908::getConfig_B2(){
  return _read_reg(CONFIG_B2_REG);
}

uint8_t PI3EQX12908::getEQ_B2(){
  return _read_reg(CONFIG_B2_REG) >> EQ_SHIFT;
}

uint8_t PI3EQX12908::getFlatGain_B2(){
  return (_read_reg(CONFIG_B2_REG) & 0x0F) >> FG_SHIFT;
}

uint8_t PI3EQX12908::getSW_B2(){
  return _read_reg(CONFIG_B2_REG) & 0x01;
}

void PI3EQX12908::setConfig_B2(uint8_t config){
  _write_reg(CONFIG_B2_REG, config);
}

void PI3EQX12908::setEQ_B2(uint8_t EQ){
  uint8_t val = getConfig_B2();
  val &= 0x0F;
  val |= (EQ & 0x0F) << EQ_SHIFT;
  _write_reg(CONFIG_B2_REG, val);
}

void PI3EQX12908::setFlatGain_B2(uint8_t flat_gain){
  uint8_t val = getConfig_B2();
  val &= 0xF3;
  val |= (flat_gain & 0x03) << FG_SHIFT;
  _write_reg(CONFIG_B2_REG, val);
}

void PI3EQX12908::setSW_B2(uint8_t swing){
  uint8_t val = getConfig_B2();
  val &= 0xFE;
  val |= swing & 0x01;
  _write_reg(CONFIG_B2_REG, val);
}

// 10 - B3 Config
uint8_t PI3EQX12908::getConfig_B3(){
  return _read_reg(CONFIG_B3_REG);
}

uint8_t PI3EQX12908::getEQ_B3(){
  return _read_reg(CONFIG_B3_REG) >> EQ_SHIFT;
}

uint8_t PI3EQX12908::getFlatGain_B3(){
  return (_read_reg(CONFIG_B3_REG) & 0x0F) >> FG_SHIFT;
}

uint8_t PI3EQX12908::getSW_B3(){
  return _read_reg(CONFIG_B3_REG) & 0x01;
}

void PI3EQX12908::setConfig_B3(uint8_t config){
  _write_reg(CONFIG_B3_REG, config);
}

void PI3EQX12908::setEQ_B3(uint8_t EQ){
  uint8_t val = getConfig_B3();
  val &= 0x0F;
  val |= (EQ & 0x0F) << EQ_SHIFT;
  _write_reg(CONFIG_B3_REG, val);
}

void PI3EQX12908::setFlatGain_B3(uint8_t flat_gain){
  uint8_t val = getConfig_B3();
  val &= 0xF3;
  val |= (flat_gain & 0x03) << FG_SHIFT;
  _write_reg(CONFIG_B3_REG, val);
}

void PI3EQX12908::setSW_B3(uint8_t swing){
  uint8_t val = getConfig_B3();
  val &= 0xFE;
  val |= swing & 0x01;
  _write_reg(CONFIG_B3_REG, val);
}

// 11 - Signal Detect Config
uint8_t PI3EQX12908::getSignalDetectConfig(){
  return _read_reg(SIGNAL_DET_CFG_REG);
}

uint8_t PI3EQX12908::getSignalDetectConfig_A(){
  return _read_reg(SIGNAL_DET_CFG_REG) >> 4;
}

uint8_t PI3EQX12908::getSignalDetectConfig_A(uint8_t index){
  return _read_reg(SIGNAL_DET_CFG_REG) & (1 << (index + 4));
}

uint8_t PI3EQX12908::getSignalDetectConfig_B(){
  return _read_reg(SIGNAL_DET_CFG_REG) & 0x0F;
}

uint8_t PI3EQX12908::getSignalDetectConfig_B(uint8_t index){
  return _read_reg(SIGNAL_DET_CFG_REG) & (1 << index);
}

void PI3EQX12908::setSignalDetectConfig(uint8_t isDown){
  _write_reg(SIGNAL_DET_CFG_REG, isDown ? 0xFF : 0x00);
}

void PI3EQX12908::setSignalDetectConfig_A(uint8_t isDown){
  uint8_t val = getSignalDetectConfig();
  if(isDown)
    val |= 0xF0;
  else
    val &= 0x0F;
  _write_reg(SIGNAL_DET_CFG_REG, val);
}

void PI3EQX12908::setSignalDetectConfig_A(uint8_t index, uint8_t isDown){
  uint8_t val = getSignalDetectConfig();
  if(isDown)
    val |= (1 << (index + 4));
  else
    val &= ~(1 << (index + 4));
  _write_reg(SIGNAL_DET_CFG_REG, val);
}

void PI3EQX12908::setSignalDetectConfig_B(uint8_t isDown){
  uint8_t val = getSignalDetectConfig();
  if(isDown)
    val |= 0x0F;
  else
    val &= 0xF0;
  _write_reg(SIGNAL_DET_CFG_REG, val);
}
void PI3EQX12908::setSignalDetectConfig_B(uint8_t index, uint8_t isDown){
  uint8_t val = getSignalDetectConfig();
  if(isDown)
    val |= (1 << index);
  else
    val &= ~(1 << index);
  _write_reg(SIGNAL_DET_CFG_REG, val);
}

// 12 - RX Detect Config
uint8_t PI3EQX12908::getRxDetectConfig(){
  return _read_reg(RX_DET_CFG_REG);
}

uint8_t PI3EQX12908::getRxDetectConfig_A(){
  return _read_reg(RX_DET_CFG_REG) >> 4;
}

uint8_t PI3EQX12908::getRxDetectConfig_A(uint8_t index){
  return _read_reg(RX_DET_CFG_REG) & (1 << (index + 4));
}

uint8_t PI3EQX12908::getRxDetectConfig_B(){
  return _read_reg(RX_DET_CFG_REG) & 0x0F;
}

uint8_t PI3EQX12908::getRxDetectConfig_B(uint8_t index){
  return _read_reg(RX_DET_CFG_REG) & (1 << index);
}

void PI3EQX12908::setRxDetectConfig(uint8_t isDown){
  _write_reg(RX_DET_CFG_REG, isDown ? 0xFF : 0x00);
}

void PI3EQX12908::setRxDetectConfig_A(uint8_t isDown){
  uint8_t val = getRxDetectConfig();
  if(isDown)
    val |= 0xF0;
  else
    val &= 0x0F;
  _write_reg(RX_DET_CFG_REG, val);
}

void PI3EQX12908::setRxDetectConfig_A(uint8_t index, uint8_t isDown){
  uint8_t val = getRxDetectConfig();
  if(isDown)
    val |= (1 << (index + 4));
  else
    val &= ~(1 << (index + 4));
  _write_reg(RX_DET_CFG_REG, val);
}

void PI3EQX12908::setRxDetectConfig_B(uint8_t isDown){
  uint8_t val = getRxDetectConfig();
  if(isDown)
    val |= 0x0F;
  else
    val &= 0xF0;
  _write_reg(RX_DET_CFG_REG, val);
}

void PI3EQX12908::setRxDetectConfig_B(uint8_t index, uint8_t isDown){
  uint8_t val = getRxDetectConfig();
  if(isDown)
    val |= (1 << index);
  else
    val &= ~(1 << index);
  _write_reg(RX_DET_CFG_REG, val);
}

// 13 - Signal Detect Threshold
uint8_t PI3EQX12908::getSDTConfig(){
  return _read_reg(SIGNAL_DET_TH_REG);
}

uint8_t PI3EQX12908::setSDTConfig(uint8_t thresh){
  uint8_t val = getSDTConfig();
  val &= 0x03;
  val |= (thresh & 0x03) << SDT_SHIFT;
  _write_reg(SIGNAL_DET_TH_REG, val);
}


// Others
void PI3EQX12908::setConfig_A(uint8_t config){
  uint8_t data[4] = {config, config, config, config};
  _burst_write(CONFIG_A0_REG, data, 4);
}

void PI3EQX12908::setConfig_A(uint8_t index, uint8_t config){
  _write_reg(CONFIG_A_OFFSET + index, config);
}

void PI3EQX12908::setConfig_B(uint8_t config){
  uint8_t data[4] = {config, config, config, config};
  _burst_write(CONFIG_B0_REG, data, 4);
}

void PI3EQX12908::setConfig_B(uint8_t index, uint8_t config){
  _write_reg(CONFIG_B_OFFSET + index, config);
}

void PI3EQX12908::setConfig(uint8_t config){
  uint8_t data[8] = {config, config, config, config, config, config, config, config};
  _burst_write(CONFIG_A0_REG, data, 8);
}

void PI3EQX12908::setEQ_A(uint8_t EQ){
  uint8_t val[4];
  _burst_read(CONFIG_A0_REG, val, 4);
  for(uint8_t i=0; i<4; i++){
    val[i] &= 0x0F;
    val[i] |= (EQ & 0x0F) << EQ_SHIFT;
  }
  _burst_write(CONFIG_A0_REG, val, 4);
}

void PI3EQX12908::setEQ_B(uint8_t EQ){
  uint8_t val[4];
  _burst_read(CONFIG_B0_REG, val, 4);
  for(uint8_t i=0; i<4; i++){
    val[i] &= 0x0F;
    val[i] |= (EQ & 0x0F) << EQ_SHIFT;
  }
  _burst_write(CONFIG_B0_REG, val, 4);
}

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

void PI3EQX12908::setFG_A(uint8_t flat_gain){
  uint8_t val[4];
  _burst_read(CONFIG_A0_REG, val, 4);
  for(uint8_t i=0; i<4; i++){
    val[i] &= 0xF3;
    val[i] |= (flat_gain & 0x03) << FG_SHIFT;
  }
  _burst_write(CONFIG_A0_REG, val, 4);
}

void PI3EQX12908::setFG_B(uint8_t flat_gain){
  uint8_t val[4];
  _burst_read(CONFIG_B0_REG, val, 4);
  for(uint8_t i=0; i<4; i++){
    val[i] &= 0xF3;
    val[i] |= (flat_gain & 0x03) << FG_SHIFT;
  }
  _burst_write(CONFIG_B0_REG, val, 4);
}

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

void PI3EQX12908::setSW_A(uint8_t swing){
  uint8_t val[4];
  _burst_read(CONFIG_A0_REG, val, 4);
  for(uint8_t i=0; i<4; i++){
    val[i] &= 0xFE;
    val[i] |= (swing & 0x01) << SW_SHIFT;
  }
  _burst_write(CONFIG_A0_REG, val, 4);
}

void PI3EQX12908::setSW_B(uint8_t swing){
  uint8_t val[4];
  _burst_read(CONFIG_B0_REG, val, 4);
  for(uint8_t i=0; i<4; i++){
    val[i] &= 0xFE;
    val[i] |= (swing & 0x01) << SW_SHIFT;
  }
  _burst_write(CONFIG_B0_REG, val, 4);
}

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
