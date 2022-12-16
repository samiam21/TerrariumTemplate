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
    hw.Init();
    hw.SetAudioBlockSize(4);
    hw.StartAudio(AudioCallback);
    while (1)
    {
    }
}
