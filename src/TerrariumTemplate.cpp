#include "TerrariumTemplate.h"

/**
 * Audio callback to process each enabled effect
 */
void AudioCallback(AudioHandle::InterleavingInputBuffer in, AudioHandle::InterleavingOutputBuffer out, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        out[i] = boost.Process(in[i]);
        // out[i + 1] = boost.Process(in[i + 1]);
    }
}

void InitializeControls()
{
}

void InitializeEffects()
{
    // Initialize the boost effect
    boost.Setup(hw);
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
    }
}
