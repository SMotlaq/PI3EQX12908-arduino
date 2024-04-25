/*!
 * @file PI3EQX12908A2.h
 *
 * The PI3EQX12908 PCIe 3.0 redriver library is a software library that allows developers to easily access the I2C interfaces of the PI3EQX12908 PCIe 3.0 redriver chip.
 * It provides a simple API for performing common I2C operations and is compatible with Arduino platform.
 * The library includes example code to help developers get started quickly. 
 *
 * Written by Salman Motlaq (@SMotlaq on GitHub)
 *
 * MIT License
 *
 */

#ifndef _PI3EQX12908_H
#define _PI3EQX12908_H

#include <stdint.h>
#include <Wire.h>
#include <String.h>

#define SIGNAL_DETECT_REG   0
#define RX_DETECT_REG       1
#define POWER_DOWN_REG      2
#define CONFIG_A0_REG       3
#define CONFIG_A1_REG       4
#define CONFIG_A2_REG       5
#define CONFIG_A3_REG       6
#define CONFIG_B0_REG       7
#define CONFIG_B1_REG       8
#define CONFIG_B2_REG       9
#define CONFIG_B3_REG       10
#define SIGNAL_DET_CFG_REG  11
#define RX_DET_CFG_REG      12
#define SIGNAL_DET_TH_REG   13

#define CONFIG_A_OFFSET 3
#define CONFIG_B_OFFSET 7

#define A3_SHIFT  7
#define A2_SHIFT  6
#define A1_SHIFT  5
#define A0_SHIFT  4
#define B0_SHIFT  3
#define B1_SHIFT  2
#define B2_SHIFT  1
#define B3_SHIFT  0

#define EQ_SHIFT  4
#define FG_SHIFT  2
#define SW_SHIFT  0

#define SDT_SHIFT 1

#define FLAT_GAIN_M4db 0  ///< Flat gain = -4db
#define FLAT_GAIN_M2db 1  ///< Flat gain = -2db
#define FLAT_GAIN_00db 2  ///< Flat gain =  0db
#define FLAT_GAIN_P2db 3  ///< Flat gain = +2db

#define SWING_900mVpp   0 ///< Swing =  900 mVpp
#define SWING_1000mVpp  1 ///< Swing = 1000 mVpp

#define SDT_OFF_30_ON_130_mVpp   0  ///< Signal detect threshold =  30 mVpp for off and 130 mVpp for on
#define SDT_OFF_50_ON_150_mVpp   1  ///< Signal detect threshold =  50 mVpp for off and 150 mVpp for on
#define SDT_OFF_70_ON_170_mVpp   2  ///< Signal detect threshold =  70 mVpp for off and 170 mVpp for on
#define SDT_OFF_110_ON_210_mVpp  3  ///< Signal detect threshold = 110 mVpp for off and 210 mVpp for on

#define CFG_ON  0 ///< Use this for power down state
#define CFG_OFF 1 ///< Use this for power up state

/**************************************************************************/
/*! 
    @brief  Class that stores state and functions for interacting with PI3EQX12908A2
*/
/**************************************************************************/
class PI3EQX12908{
  public:
    init(uint8_t i2c_addr);

    // 0 - Signal Detect
    uint8_t getSignalDetect();
    uint8_t getSignalDetect_A();
    uint8_t getSignalDetect_A(uint8_t index);
    uint8_t getSignalDetect_B();
    uint8_t getSignalDetect_B(uint8_t index);

    // 1 - RX Detect
    uint8_t getRxDetect();
    uint8_t getRxDetect_A();
    uint8_t getRxDetect_A(uint8_t index);
    uint8_t getRxDetect_B();
    uint8_t getRxDetect_B(uint8_t index);

    // 2 - Power Down
    uint8_t getPowerDown();
    uint8_t getPowerDown_A();
    uint8_t getPowerDown_A(uint8_t index);
    uint8_t getPowerDown_B();
    uint8_t getPowerDown_B(uint8_t index);
    void setPowerDown(uint8_t isDown);
    void setPowerDown_A(uint8_t isDown);
    void setPowerDown_A(uint8_t index, uint8_t isDown);
    void setPowerDown_B(uint8_t isDown);
    void setPowerDown_B(uint8_t index, uint8_t isDown);

    // 3 - A0 Config
    uint8_t getConfig_A0();
    uint8_t getEQ_A0();
    uint8_t getFlatGain_A0();
    uint8_t getSW_A0();
    void setConfig_A0(uint8_t config);
    void setEQ_A0(uint8_t EQ);
    void setFlatGain_A0(uint8_t flat_gain);
    void setSW_A0(uint8_t swing);

    // 4 - A1 Config
    uint8_t getConfig_A1();
    uint8_t getEQ_A1();
    uint8_t getFlatGain_A1();
    uint8_t getSW_A1();
    void setConfig_A1(uint8_t config);
    void setEQ_A1(uint8_t EQ);
    void setFlatGain_A1(uint8_t flat_gain);
    void setSW_A1(uint8_t swing);

    // 5 - A2 Config
    uint8_t getConfig_A2();
    uint8_t getEQ_A2();
    uint8_t getFlatGain_A2();
    uint8_t getSW_A2();
    void setConfig_A2(uint8_t config);
    void setEQ_A2(uint8_t EQ);
    void setFlatGain_A2(uint8_t flat_gain);
    void setSW_A2(uint8_t swing);

    // 6 - A3 Config
    uint8_t getConfig_A3();
    uint8_t getEQ_A3();
    uint8_t getFlatGain_A3();
    uint8_t getSW_A3();
    void setConfig_A3(uint8_t config);
    void setEQ_A3(uint8_t EQ);
    void setFlatGain_A3(uint8_t flat_gain);
    void setSW_A3(uint8_t swing);

    // 7 - B0 Config
    uint8_t getConfig_B0();
    uint8_t getEQ_B0();
    uint8_t getFlatGain_B0();
    uint8_t getSW_B0();
    void setConfig_B0(uint8_t config);
    void setEQ_B0(uint8_t EQ);
    void setFlatGain_B0(uint8_t flat_gain);
    void setSW_B0(uint8_t swing);

    // 8 - B1 Config
    uint8_t getConfig_B1();
    uint8_t getEQ_B1();
    uint8_t getFlatGain_B1();
    uint8_t getSW_B1();
    void setConfig_B1(uint8_t config);
    void setEQ_B1(uint8_t EQ);
    void setFlatGain_B1(uint8_t flat_gain);
    void setSW_B1(uint8_t swing);

    // 9 - B2 Config
    uint8_t getConfig_B2();
    uint8_t getEQ_B2();
    uint8_t getFlatGain_B2();
    uint8_t getSW_B2();
    void setConfig_B2(uint8_t config);
    void setEQ_B2(uint8_t EQ);
    void setFlatGain_B2(uint8_t flat_gain);
    void setSW_B2(uint8_t swing);

    // 10 - B3 Config
    uint8_t getConfig_B3();
    uint8_t getEQ_B3();
    uint8_t getFlatGain_B3();
    uint8_t getSW_B3();
    void setConfig_B3(uint8_t config);
    void setEQ_B3(uint8_t EQ);
    void setFlatGain_B3(uint8_t flat_gain);
    void setSW_B3(uint8_t swing);

    // 11 - Signal Detect Config
    uint8_t getSignalDetectConfig();
    uint8_t getSignalDetectConfig_A();
    uint8_t getSignalDetectConfig_A(uint8_t index);
    uint8_t getSignalDetectConfig_B();
    uint8_t getSignalDetectConfig_B(uint8_t index);
    void setSignalDetectConfig(uint8_t isDown);
    void setSignalDetectConfig_A(uint8_t isDown);
    void setSignalDetectConfig_A(uint8_t index, uint8_t isDown);
    void setSignalDetectConfig_B(uint8_t isDown);
    void setSignalDetectConfig_B(uint8_t index, uint8_t isDown);

    // 12 - RX Detect Config
    uint8_t getRxDetectConfig();
    uint8_t getRxDetectConfig_A();
    uint8_t getRxDetectConfig_A(uint8_t index);
    uint8_t getRxDetectConfig_B();
    uint8_t getRxDetectConfig_B(uint8_t index);
    void setRxDetectConfig(uint8_t isDown);
    void setRxDetectConfig_A(uint8_t isDown);
    void setRxDetectConfig_A(uint8_t index, uint8_t isDown);
    void setRxDetectConfig_B(uint8_t isDown);
    void setRxDetectConfig_B(uint8_t index, uint8_t isDown);

    // 13 - Signal Detect Threshold
    uint8_t getSDTConfig();
    uint8_t setSDTConfig(uint8_t thresh);

    // Others
    void setConfig_A(uint8_t config);
    void setConfig_A(uint8_t index, uint8_t config);
    void setConfig_B(uint8_t config);
    void setConfig_B(uint8_t index, uint8_t config);
    void setConfig(uint8_t config);
    void setEQ_A(uint8_t EQ);
    void setEQ_B(uint8_t EQ);
    void setEQ(uint8_t EQ);
    void setFG_A(uint8_t flat_gain);
    void setFG_B(uint8_t flat_gain);
    void setFG(uint8_t flat_gain);
    void setSW_A(uint8_t swing);
    void setSW_B(uint8_t swing);
    void setSW(uint8_t swing);
    void print_all();
    void dump_all(uint8_t* data);

  private:
    uint8_t  _I2C_ADDR;
    String _REGS[16];

    uint8_t _read_reg(uint8_t mem_addr);
    void _write_reg(uint8_t mem_addr, uint8_t value);
    void _burst_read(uint8_t mem_addr, uint8_t* data, uint8_t len);
    void _burst_write(uint8_t mem_addr, uint8_t* data, uint8_t len);
};

#endif