#pragma once
#include "raylib.h"

class GameSound {
private:
    Sound wingFlap;
    Sound scoring;
    Music bgMusic;
    bool isMuted;

public:
    GameSound();
    ~GameSound();
    void Load();
    void PlayWingFlap();
    void PlayScore();
    void UpdateMusic();
    void ToggleMute();
};
