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
    Rectangle frameRec;
    float frameTime;
    int currentFrame;
    int totalFrames;

public:
    Bird();
    ~Bird();
    void Load();
    void Update();
    void Draw();
    void Jump();
    Rectangle GetCollisionBox() const { return collisionBox; }
    float GetX() const { return position.x; }
    float GetY() const { return position.y; }
};
