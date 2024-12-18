#pragma once
#include "raylib.h"
#include "GameConfig.h"
#include <vector>

struct Raindrop {
    Vector2 position;
    float speed;
    float length;
};

class Weather {
private:
    std::vector<Raindrop> raindrops;
    float timeOfDay;
    Color skyColor;
    bool isRaining;

public:
    Weather();
    ~Weather();
    void Update();
    void Draw();
    void ToggleRain();
    void UpdateDayCycle();
};
