#ifndef PEDAL_CONFIG_H
#define PEDAL_CONFIG_H

#include "daisy_seed.h"

#define DEBUG 1

#define WAIT_FOR_SERIAL false
#define ENABLE_DISPLAY false

#define DAISY_BLOCKSIZE 1
#define DAISY_SAMPLE_RATE daisy::SaiHandle::Config::SampleRate::SAI_96KHZ

// This define is to make the effects library play nice in a non-multi-world
#define MAX_EFFECTS 0

#define MAX_KNOBS 6
#define KNOB_1_CHN 0
#define KNOB_2_CHN 1
#define KNOB_3_CHN 2
#define KNOB_4_CHN 3
#define KNOB_5_CHN 4
#define KNOB_6_CHN 5

// Pin Definitions - SPDT
const int effectSPDT1Pin1 = 7;
const int effectSPDT1Pin2 = 8;

// Pin Definitions - POT
const int effectPotPin1 = 16;
const int effectPotPin2 = 17;
const int effectPotPin3 = 18;
const int effectPotPin4 = 19;
const int effectPotPin5 = 20;
const int effectPotPin6 = 21;

#define PI_VAL 3.14159265

/** Serial debug print macros **/
#define initDebugPrint(hw, pcBlock)                                                                    \
    {                                                                                                  \
        if (DEBUG)                                                                                     \
            hw->StartLog(pcBlock); /* true == wait for PC: will block until a terminal is connected */ \
    }
#define debugPrintln(hw, msg)   \
    {                           \
        if (DEBUG)              \
            hw->PrintLine(msg); \
    }
#define debugPrint(hw, msg) \
    {                       \
        if (DEBUG)          \
            hw->Print(msg); \
    }
#define debugPrintlnF(hw, msg, args...) \
    {                                   \
        if (DEBUG)                      \
            hw->PrintLine(msg, args);   \
    }
#define debugPrintF(hw, msg, args...) \
    {                                 \
        if (DEBUG)                    \
            hw->Print(msg, args);     \
    }

/** OLED display macros **/
#define initDisplay(hw, display) \
    {                            \
        if (ENABLE_DISPLAY)      \
            display.Init(hw);    \
    }
#define updateOutputLevel(display, outputLevel)     \
    {                                               \
        if (ENABLE_DISPLAY)                         \
            display.UpdateOutputLevel(outputLevel); \
    }
#define updatePlayModeEffects(display, currentEffectNames)     \
    {                                                          \
        if (ENABLE_DISPLAY)                                    \
            display.UpdatePlayModeEffects(currentEffectNames); \
    }
#define showEditModeStartupScreen(display)       \
    {                                            \
        if (ENABLE_DISPLAY)                      \
            display.ShowEditModeStartupScreen(); \
    }
#define showEditModeEffectScreen(display, effectName, knobNames)     \
    {                                                                \
        if (ENABLE_DISPLAY)                                          \
            display.ShowEditModeEffectScreen(effectName, knobNames); \
    }
#define updateEditModeToggleValue(display, value)      \
    {                                                  \
        if (ENABLE_DISPLAY)                            \
            display->UpdateEditModeToggleValue(value); \
    }
#define updateEditModeKnobValue(display, knobPosition, value)      \
    {                                                              \
        if (ENABLE_DISPLAY)                                        \
            display->UpdateEditModeKnobValue(knobPosition, value); \
    }
#define updateEditModeKnobValueI(display, knobPosition, value)      \
    {                                                               \
        if (ENABLE_DISPLAY)                                         \
            display->UpdateEditModeKnobValueI(knobPosition, value); \
    }
#define writeDisplayMessage(display, message) \
    {                                         \
        if (ENABLE_DISPLAY)                   \
            display.WriteMessage(message);    \
    }
#define writeDisplayMessageF(display, message, args...) \
    {                                                   \
        if (ENABLE_DISPLAY)                             \
            display.WriteMessage(message, args);        \
    }

#endif