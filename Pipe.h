#pragma once
#include "raylib.h"
#include "GameConfig.h"

class Pipe {
private:
    Rectangle topPipe;
    Rectangle bottomPipe;
    bool passed;
    float speed;
    static bool isHellMode;  // Make it static
    float flameTimer;
    Vector2 flamePosition;
    bool isEmittingFlame;
    void DrawFlameParticle(Vector2 position, float speed);

public:
    Pipe(float xPos);
    ~Pipe();
    void Update();
    void Draw() const;
    bool CheckCollision(Rectangle birdBounds) const;
    bool IsOffscreen() const;
    bool HasPassed() const;
    void SetPassed(bool value);
    float GetX() const;
    static void SetHellMode(bool mode) { isHellMode = mode; }  // Static function
    void UpdateFlames();
    static void LoadPipeTexture();
    static void UnloadPipeTexture();
};