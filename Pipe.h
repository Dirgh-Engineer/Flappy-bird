#pragma once
#include "raylib.h"
#include "GameConfig.h"

class Pipe {
private:
    Rectangle topPipe;
    Rectangle bottomPipe;
    bool passed;
    float speed;
    bool isHellMode;
    float flameTimer;
    Vector2 flamePosition;
    bool isEmittingFlame;

public:
public:
    Pipe(float xPos);
    ~Pipe();  // Add this line
    void Update();
    void Draw() const;
    bool CheckCollision(Rectangle birdBounds) const;
    bool IsOffscreen() const;
    bool HasPassed() const;
    void SetPassed(bool value);
    float GetX() const;
    void SetHellMode(bool mode);
    void UpdateFlames();
    static void LoadPipeTexture();
    static void UnloadPipeTexture();
};


