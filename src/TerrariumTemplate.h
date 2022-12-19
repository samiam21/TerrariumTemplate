#ifndef TERR_TEMPLATE_H
#define TERR_TEMPLATE_H

#include "../include/PedalConfig.h"
#include "../lib/DaisyEffects/CleanBoost.h"

// Use the daisy namespace to prevent having to type
// daisy:: before all libdaisy functions
using namespace daisy;

// Declare a DaisySeed object called hw
DaisySeed *hw;

// Declare the effects objects being used
CleanBoost boost;

// DEBUG
Knob levelKnob;
float level = 1.0f;

/**
 * Audio callback to process each enabled effect
 */
void AudioCallback(AudioHandle::InterleavingInputBuffer in, AudioHandle::InterleavingOutputBuffer out, size_t size);

/**
 * Initializes the input controls
 */
void InitializeControls();

/**
 * Initializes the effects
 */
void InitializeEffects();

#endif