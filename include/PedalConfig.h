#ifndef PEDAL_CONFIG_H
#define PEDAL_CONFIG_H

#include "daisy_seed.h"

#define DEBUG 1

#define WAIT_FOR_SERIAL false

#define DAISY_BLOCKSIZE 1
#define DAISY_SAMPLE_RATE daisy::SaiHandle::Config::SampleRate::SAI_96KHZ

#define NUM_KNOBS 4
#define KNOB_1_CHN 0
#define KNOB_2_CHN 1
#define KNOB_3_CHN 2
#define KNOB_4_CHN 3

#define PI_VAL 3.14159265

/** Serial debug print macros **/
#define initDebugPrint(hw, pcBlock)                                                                   \
    {                                                                                                 \
        if (DEBUG)                                                                                    \
            hw.StartLog(pcBlock); /* true == wait for PC: will block until a terminal is connected */ \
    }
#define debugPrintln(hw, msg)  \
    {                          \
        if (DEBUG)             \
            hw.PrintLine(msg); \
    }
#define debugPrint(hw, msg) \
    {                       \
        if (DEBUG)          \
            hw.Print(msg);  \
    }
#define debugPrintlnF(hw, msg, args...) \
    {                                   \
        if (DEBUG)                      \
            hw.PrintLine(msg, args);    \
    }
#define debugPrintF(hw, msg, args...) \
    {                                 \
        if (DEBUG)                    \
            hw.Print(msg, args);      \
    }

// Pin Definitions - SPDT
const int effectSPDT1Pin1 = 12;
const int effectSPDT1Pin2 = 13;

// Pin Definitions - POT
const int effectPotPin1 = 21;
const int effectPotPin2 = 22;
const int effectPotPin3 = 23;
const int effectPotPin4 = 24;

#endif