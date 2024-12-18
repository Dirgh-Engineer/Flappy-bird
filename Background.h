#pragma once
#include "raylib.h"
#include "GameConfig.h"
#include <cmath>

class Background {
private:
    Texture2D texture;
    Vector2 position;
    float timeOfDay;
    Color overlayColor;
    float scrollingSpeed;
    Texture2D normalBackground;
    Texture2D hellBackground;
    bool isHellMode;

public:
    Background();
    ~Background();
    void Load();
    void Update();
    void Draw();
    void UpdateDayCycle();
    void SetHellMode(bool mode);
};
