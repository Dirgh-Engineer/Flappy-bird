#include "Bird.h"

Bird::Bird() {
    position = { SCREEN_WIDTH / 4.0f, SCREEN_HEIGHT / 2.0f };
    velocity = 0;
    gravity = 0.4f;
    jumpForce = -8.0f;
    frameTime = 0;
    currentFrame = 0;
    totalFrames = 6;
    frameRec = { 0, 0, 0, 0 };
}

Bird::~Bird() {
    UnloadTexture(texture);
}

void Bird::Load() {
    Image birdImage = LoadImage("assets/sprites/bird_sprites.png");
    ImageColorReplace(&birdImage, WHITE, BLANK);
    texture = LoadTextureFromImage(birdImage);
    UnloadImage(birdImage);
    frameRec.width = (float)texture.width / 3;
    frameRec.height = (float)texture.height / 2;
    bounds.width = frameRec.width * 0.03f;
    bounds.height = frameRec.height * 0.03f;
}

void Bird::Update() {
    velocity += gravity;
    position.y += velocity;

    if (position.y < 0) {
        position.y = 0;
        velocity = 0;
    }

    if (position.y > SCREEN_HEIGHT - bounds.height) {
        position.y = SCREEN_HEIGHT - bounds.height;
        velocity = 0;
    }

    // Calculate sprite frame dimensions with adjusted scale
    float scale = 0.02f;
    int frameIndex = (int)currentFrame;
    int row = frameIndex / 3;
    int col = frameIndex % 3;

    float spriteWidth = frameRec.width * scale * 0.8f;
    float spriteHeight = frameRec.height * scale * 0.8f;

    // Center the collision box with adjusted dimensions
    collisionBox = {
        position.x - spriteWidth / 1,
        position.y - spriteHeight / 1,
        spriteWidth,
        spriteHeight
    };

    if (IsKeyPressed(KEY_SPACE) || IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Jump();
    }

    float baseAnimationSpeed = 0.1f;
    float currentAnimationSpeed;

    if (velocity < 0) {
        currentAnimationSpeed = baseAnimationSpeed * 0.5f;
    }
    else if (velocity > 5) {
        currentAnimationSpeed = baseAnimationSpeed * 1.5f;
    }
    else {
        currentAnimationSpeed = baseAnimationSpeed;
    }

    frameTime += GetFrameTime();
    if (frameTime >= currentAnimationSpeed) {
        frameTime = 0;
        currentFrame++;
        if (currentFrame >= totalFrames) currentFrame = 0;
    }
}

void Bird::Draw() {
    float scale = 0.02f;
    int frameIndex = (int)currentFrame;
    int row = frameIndex / 3;
    int col = frameIndex % 3;

    Rectangle source = {
        frameRec.width * col,
        frameRec.height * row,
        frameRec.width,
        frameRec.height
    };

    Rectangle dest = {
        position.x - (frameRec.width * scale / 2),
        position.y - (frameRec.height * scale / 2),
        frameRec.width * scale,
        frameRec.height * scale
    };

    float rotation = velocity * 5.0f;
    if (rotation < -60.0f) rotation = -60.0f;
    if (rotation > 90.0f) rotation = 90.0f;

    Vector2 origin = { dest.width / 2, dest.height / 2 };
    DrawTexturePro(texture, source, dest, origin, rotation, WHITE);

    
}

void Bird::Jump() {
    velocity = jumpForce;
}
