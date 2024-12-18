#pragma once
#include "raylib.h"
#include <vector>

class ParticleSystem {
private:
    struct Particle {
        Vector2 position;
        Vector2 velocity;
        float size;
        float life;
        Color color;
        bool active;
        float rotation;
        float rotationSpeed;
    };

    std::vector<Particle> particles;
    const int MAX_PARTICLES = 200;  // Increased particle count

public:
    ParticleSystem();
    void EmitCrashParticles(Vector2 position);
    void Update();
    void Draw();
};
