#pragma once
#include "raylib.h"
#include "GameConfig.h"

class Bird {
private:
    Vector2 position;
    float velocity;
    float gravity;
    float jumpForce;
    Rectangle bounds;
    Rectangle collisionBox;
    Texture2D texture;
    float frameTime;
    float currentFrame;
    int totalFrames;
    Rectangle frameRec;

public:
    Bird();
    ~Bird();
    void Load();
    void Update();
    void Draw();
    void Jump();
    Rectangle GetCollisionBox() const { return collisionBox; }
    float GetVelocity() const { return velocity; }
    float GetX() const { return position.x; }
    void ApplyWind(float force);
};
