#include "Pipe.h"

const float PIPE_WIDTH = 70.0f;
const float PIPE_GAP = 200.0f;
const float PIPE_SPEED = 2.0f;

Pipe::Pipe(float xPos) {
    float minGap = 150;
    float maxGap = 400;
    float gapY = GetRandomValue(150, SCREEN_HEIGHT - 300);
    float pipeHeight = GetRandomValue(100, 400);

    topPipe = {
        xPos,
        0,
        PIPE_WIDTH,
        pipeHeight
    };

    bottomPipe = {
        xPos,
        pipeHeight + PIPE_GAP,
        PIPE_WIDTH,
        SCREEN_HEIGHT - (pipeHeight + PIPE_GAP)
    };

    speed = PIPE_SPEED;
    passed = false;
}

Pipe::~Pipe() {
}

void Pipe::Update() {
    topPipe.x -= speed;
    bottomPipe.x -= speed;
}

void Pipe::Draw() const {
    Color mainColor = { 34, 139, 34, 255 };
    Color highlightColor = { 50, 205, 50, 255 };
    Color shadowColor = { 0, 100, 0, 255 };
    Color metalShine = { 144, 238, 144, 255 };
    Color edgeColor = { 25, 120, 25, 255 };
    Color deepShadow = { 20, 80, 20, 255 };

    float lipWidth = topPipe.width + 24;
    float lipHeight = 35;
    float cornerRadius = 8.0f;

    DrawRectangle(topPipe.x, topPipe.y, topPipe.width, topPipe.height, mainColor);
    DrawRectangle(topPipe.x + 8, topPipe.y, 15, topPipe.height, highlightColor);
    DrawRectangle(topPipe.x + 12, topPipe.y, 5, topPipe.height, metalShine);
    DrawRectangle(topPipe.x + topPipe.width - 20, topPipe.y, 20, topPipe.height, shadowColor);
    DrawRectangleRounded({ topPipe.x - 12, topPipe.height - lipHeight, lipWidth, lipHeight }, cornerRadius, 8, edgeColor);
    DrawRectangleRounded({ topPipe.x - 10, topPipe.height - lipHeight + 3, lipWidth - 4, 6 }, cornerRadius / 2, 8, metalShine);

    DrawRectangle(bottomPipe.x, bottomPipe.y, bottomPipe.width, bottomPipe.height, mainColor);
    DrawRectangle(bottomPipe.x + 8, bottomPipe.y, 15, bottomPipe.height, highlightColor);
    DrawRectangle(bottomPipe.x + 12, bottomPipe.y, 5, bottomPipe.height, metalShine);
    DrawRectangle(bottomPipe.x + bottomPipe.width - 20, bottomPipe.y, 20, bottomPipe.height, shadowColor);
    DrawRectangleRounded({ bottomPipe.x - 12, bottomPipe.y, lipWidth, lipHeight }, cornerRadius, 8, edgeColor);
    DrawRectangleRounded({ bottomPipe.x - 10, bottomPipe.y + 3, lipWidth - 4, 6 }, cornerRadius / 2, 8, metalShine);

    DrawRectangleGradientV(topPipe.x + topPipe.width - 15, topPipe.y, 15, topPipe.height, shadowColor, deepShadow);
    DrawRectangleGradientV(bottomPipe.x + bottomPipe.width - 15, bottomPipe.y, 15, bottomPipe.height, shadowColor, deepShadow);
}

bool Pipe::CheckCollision(Rectangle birdBounds) const {
    Rectangle topPipeCollision = {
        topPipe.x + 8,
        topPipe.y,
        topPipe.width - 16,
        topPipe.height
    };

    Rectangle topLipCollision = {
        topPipe.x + 4,
        topPipe.height - 35,
        topPipe.width - 8,
        35
    };

    Rectangle bottomPipeCollision = {
        bottomPipe.x + 8,
        bottomPipe.y + 35,
        bottomPipe.width - 16,
        bottomPipe.height - 35
    };

    Rectangle bottomLipCollision = {
        bottomPipe.x + 4,
        bottomPipe.y,
        bottomPipe.width - 8,
        35
    };

    return CheckCollisionRecs(birdBounds, topPipeCollision) ||
        CheckCollisionRecs(birdBounds, bottomPipeCollision) ||
        CheckCollisionRecs(birdBounds, topLipCollision) ||
        CheckCollisionRecs(birdBounds, bottomLipCollision);
}

bool Pipe::IsOffscreen() const {
    return (topPipe.x + topPipe.width) < 0;
}

bool Pipe::HasPassed() const {
    return passed;
}

void Pipe::SetPassed(bool value) {
    passed = value;
}

float Pipe::GetX() const {
    return topPipe.x;
}

void Pipe::LoadPipeTexture() {
}

void Pipe::UnloadPipeTexture() {
}
