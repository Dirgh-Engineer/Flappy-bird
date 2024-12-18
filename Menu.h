#pragma once
#include "raylib.h"
#include "GameConfig.h"

enum class GameState {
    MENU,
    PLAYING,
    GAME_OVER
};

class Menu {
private:
    Font titleFont;
    Font buttonFont;
    Rectangle playButton;
    Rectangle settingsButton;
    Rectangle quitButton;
    Color buttonColor;
    Color hoverColor;
    Color titleColor;
    float titleWave;

public:
    Menu();
    ~Menu();
    void Load();
    void Update();
    void Draw();
    GameState HandleInput();
};
