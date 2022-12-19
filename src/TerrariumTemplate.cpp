#include "TerrariumTemplate.h"

/**
 * Audio callback to process each enabled effect
 */
void AudioCallback(AudioHandle::InterleavingInputBuffer in, AudioHandle::InterleavingOutputBuffer out, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        out[i] = in[i] * 1.f;
        out[i + 1] = in[i + 1] * 1.f;
    }
}

int main(void)
{
    // Initialize the hardware
    hw.Init();

    // Update the block size and sample rate to minimize noise
    hw.SetAudioBlockSize(DAISY_BLOCKSIZE);
    hw.SetAudioSampleRate(DAISY_SAMPLE_RATE);

    // Start the audio processing
    debugPrintln(hw, "Starting Audio");
    hw.StartAudio(AudioCallback);

    while (1)
    {
    }
}
