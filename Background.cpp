#include "Background.h"
#include <cmath>

Background::Background() {
    position = { 0, 0 };
    timeOfDay = 0.0f;
    overlayColor = WHITE;
    scrollingSpeed = 0.5f;
    isHellMode = false;
}

Background::~Background() {
    UnloadTexture(texture);
    UnloadTexture(hellBackground);
}

void Background::Load() {
    texture = LoadTexture("assets/sprites/background.png");
    hellBackground = LoadTexture("assets/sprites/Hell.png");
}

void Background::Update() {
    if (!isHellMode) {
        UpdateDayCycle();
        position.x -= scrollingSpeed;
        if (position.x <= -SCREEN_WIDTH) {
            position.x = 0;
        }
    }
}

void Background::UpdateDayCycle() {
    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
        if (overlayColor.r > 128) {
            overlayColor = Color{ 20, 20, 40, 255 };
            timeOfDay = 0.0f;
        }
        else {
            overlayColor = WHITE;
            timeOfDay = 12.0f;
        }
    }
}

void Background::Draw() {
    if (isHellMode) {
        DrawTexturePro(
            hellBackground,
            { 0, 0, (float)hellBackground.width, (float)hellBackground.height },
            { 0, 0, (float)SCREEN_WIDTH, (float)SCREEN_HEIGHT },
            { 0, 0 },
            0,
            WHITE
        );
        float time = (float)GetTime();
        Color glowColor = { 255, 50, 0, (unsigned char)(127 + sin(time) * 127) };
        DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, ColorAlpha(glowColor, 0.3f));
    }
    else {
        float scaleX = (float)SCREEN_WIDTH / texture.width;
        float scaleY = (float)SCREEN_HEIGHT / texture.height;
        Rectangle source = { 0, 0, (float)texture.width, (float)texture.height };
        Rectangle dest = { position.x, position.y, SCREEN_WIDTH, SCREEN_HEIGHT };
        DrawTexturePro(texture, source, dest, Vector2{ 0, 0 }, 0, overlayColor);
        Rectangle dest2 = { position.x + SCREEN_WIDTH, position.y, SCREEN_WIDTH, SCREEN_HEIGHT };
        DrawTexturePro(texture, source, dest2, Vector2{ 0, 0 }, 0, overlayColor);
    }
}

void Background::SetHellMode(bool mode) {
    isHellMode = mode;
}
