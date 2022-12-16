#ifndef TERR_TEMPLATE_H
#define TERR_TEMPLATE_H

#include "../include/PedalConfig.h"

// Use the daisy namespace to prevent having to type
// daisy:: before all libdaisy functions
using namespace daisy;

// Declare a DaisySeed object called hw
DaisySeed hw;

/**
 * Audio callback to process each enabled effect
 */
void AudioCallback(AudioHandle::InterleavingInputBuffer in, AudioHandle::InterleavingOutputBuffer out, size_t size);

#endif