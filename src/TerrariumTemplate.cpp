#include "TerrariumTemplate.h"

/**
 * Audio callback to process each enabled effect
 */
void AudioCallback(AudioHandle::InterleavingInputBuffer in, AudioHandle::InterleavingOutputBuffer out, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        // out[i] = boost.Process(in[i]);
        if (audioOn)
        {
            out[i] = in[i] * level;
            // out[i + 1] = boost.Process(in[i + 1]);
        }
        else
        {
            out[i] = 0;
        }
    }
}

void InitializeControls()
{
    // Initialize the ADC
    AdcChannelConfig adcConfig[MAX_KNOBS];
    adcConfig[KNOB_1_CHN].InitSingle(hw->GetPin(effectPotPin1));
    adcConfig[KNOB_2_CHN].InitSingle(hw->GetPin(effectPotPin2));
    adcConfig[KNOB_3_CHN].InitSingle(hw->GetPin(effectPotPin3));
    adcConfig[KNOB_4_CHN].InitSingle(hw->GetPin(effectPotPin4));
    adcConfig[KNOB_5_CHN].InitSingle(hw->GetPin(effectPotPin5));
    adcConfig[KNOB_6_CHN].InitSingle(hw->GetPin(effectPotPin6));
    hw->adc.Init(adcConfig, MAX_KNOBS);
    hw->adc.Start();

    // TODO: Find a better way to do this?
    // Give the ADC time to start up
    System::Delay(500);

    // Initialize the knobs
    levelKnob.Init(hw, KNOB_1_CHN, level, 0.f, 20.f);

    // Initialize the toggles
    onOffToggle.Init(hw->GetPin(effectTogglePin3));
}

void InitializeEffects()
{
    // Initialize the boost effect
    // boost.Setup(hw);
}

int main(void)
{
    // Initialize the hardware
    hw->Init();

    // Update the block size and sample rate to minimize noise
    hw->SetAudioBlockSize(DAISY_BLOCKSIZE);
    hw->SetAudioSampleRate(DAISY_SAMPLE_RATE);

    // Initialize the input controls
    InitializeControls();

    // Initialize the effect objects
    InitializeEffects();

    // Start the audio processing
    debugPrintln(hw, "Starting Audio");
    hw->StartAudio(AudioCallback);

    // Turn on the onboard LED
    hw->SetLed(true);

    while (1)
    {
        // Knob controls the boost level
        if (levelKnob.SetNewValue(level))
        {
            debugPrintlnF(hw, "Updated the boost level to: %f", level);
        }

        // Toggle controls audio output on or off
        audioOn = onOffToggle.ReadToggle();
    }
}
