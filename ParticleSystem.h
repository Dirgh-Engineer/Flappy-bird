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
    };

    std::vector<Particle> particles;
    const int MAX_PARTICLES = 100;

public:
    ParticleSystem();
    void EmitCrashParticles(Vector2 position);
    void Update();
    void Draw();
};