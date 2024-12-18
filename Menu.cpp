#include "Menu.h"
#include <math.h>

Menu::Menu() {
    buttonColor = SKYBLUE;
    hoverColor = BLUE;
    titleColor = RED;
    titleWave = 0.0f;

    float buttonWidth = 200;
    float buttonHeight = 50;
    float startY = SCREEN_HEIGHT / 2;

    playButton = {
        SCREEN_WIDTH / 2 - buttonWidth / 2,
        startY,
        buttonWidth,
        buttonHeight
    };

    settingsButton = {
        SCREEN_WIDTH / 2 - buttonWidth / 2,
        startY + buttonHeight + 20,
        buttonWidth,
        buttonHeight
    };

    quitButton = {
        SCREEN_WIDTH / 2 - buttonWidth / 2,
        startY + (buttonHeight + 20) * 2,
        buttonWidth,
        buttonHeight
    };
}

Menu::~Menu() {
    UnloadFont(titleFont);
    UnloadFont(buttonFont);
}

void Menu::Load() {
    titleFont = LoadFont("assets/fonts/youtbuttonfont.ttf");
    buttonFont = LoadFont("assets/fonts/youtbuttonfont.ttf");
}

void Menu::Update() {
    titleWave += GetFrameTime() * 2;
}

void Menu::Draw() {
    // Draw animated title
    const char* title = "FLAPPY BIRD";
    float fontSize = 80.0f;
    float spacing = 4.0f;
    Vector2 titleSize = MeasureTextEx(titleFont, title, fontSize, spacing);

    // Animated wave effect for title
    for (int i = 0; title[i] != '\0'; i++) {
        char letter[2] = { title[i], '\0' };
        float offset = sinf(titleWave + i * 0.5f) * 10.0f;
        Vector2 pos = {
            SCREEN_WIDTH / 2 - titleSize.x / 2 + i * (fontSize / 2),
            100 + offset
        };
        DrawTextEx(titleFont, letter, pos, fontSize, spacing, titleColor);
    }

    // Draw fancy buttons
    Color playColor = CheckCollisionPointRec(GetMousePosition(), playButton) ? hoverColor : buttonColor;
    Color settingsColor = CheckCollisionPointRec(GetMousePosition(), settingsButton) ? hoverColor : buttonColor;
    Color quitColor = CheckCollisionPointRec(GetMousePosition(), quitButton) ? hoverColor : buttonColor;

    DrawRectangleRounded(playButton, 0.3f, 8, playColor);
    DrawRectangleRounded(settingsButton, 0.3f, 8, settingsColor);
    DrawRectangleRounded(quitButton, 0.3f, 8, quitColor);

    // Draw button text with fancy font
    DrawTextEx(buttonFont, "PLAY",
        { playButton.x + 50, playButton.y + 10 },
        30, 2, WHITE);
    DrawTextEx(buttonFont, "SETTINGS",
        { settingsButton.x + 30, settingsButton.y + 10 },
        30, 2, WHITE);
    DrawTextEx(buttonFont, "QUIT",
        { quitButton.x + 60, quitButton.y + 10 },
        30, 2, WHITE);
}

GameState Menu::HandleInput() {
    Vector2 mousePoint = GetMousePosition();

    if (CheckCollisionPointRec(mousePoint, playButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        return GameState::PLAYING;
    }

    if (CheckCollisionPointRec(mousePoint, quitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        CloseWindow();
    }

    return GameState::MENU;
}
