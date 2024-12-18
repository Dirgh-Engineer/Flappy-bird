#include "GameSound.h"

GameSound::GameSound() {
    isMuted = false;
}

GameSound::~GameSound() {
    UnloadSound(wingFlap);
    UnloadSound(scoring);
    UnloadMusicStream(bgMusic);
}

void GameSound::Load() {
    InitAudioDevice();
    wingFlap = LoadSound("assets/sounds/flap.wav");
    scoring = LoadSound("assets/sounds/score.wav");
    bgMusic = LoadMusicStream("assets/sounds/background.mp3");
    PlayMusicStream(bgMusic);
}

void GameSound::PlayWingFlap() {
    if (!isMuted) PlaySound(wingFlap);
}

void GameSound::PlayScore() {
    if (!isMuted) PlaySound(scoring);
}

void GameSound::UpdateMusic() {
    if (!isMuted) UpdateMusicStream(bgMusic);
}

void GameSound::ToggleMute() {
    isMuted = !isMuted;
    if (isMuted) {
        PauseMusicStream(bgMusic);
    }
    else {
        ResumeMusicStream(bgMusic);
    }
}
