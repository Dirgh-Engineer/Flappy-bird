#include "ParticleSystem.h"

ParticleSystem::ParticleSystem() {
    particles.resize(MAX_PARTICLES);
}

void ParticleSystem::EmitCrashParticles(Vector2 position) {
    for (auto& particle : particles) {
        if (!particle.active) {
            particle.position = position;
            particle.velocity = {
                (float)GetRandomValue(-200, 200) / 100.0f,
                (float)GetRandomValue(-200, 200) / 100.0f
            };
            particle.size = GetRandomValue(2, 5);
            particle.life = 1.0f;
            particle.color = RED;
            particle.active = true;
        }
    }
}

void ParticleSystem::Update() {
    for (auto& particle : particles) {
        if (particle.active) {
            particle.position.x += particle.velocity.x;
            particle.position.y += particle.velocity.y;
            particle.life -= 0.02f;

            if (particle.life <= 0) {
                particle.active = false;
            }
        }
    }
}

void ParticleSystem::Draw() {
    for (const auto& particle : particles) {
        if (particle.active) {
            Color color = particle.color;
            color.a = (unsigned char)(255.0f * particle.life);
            DrawCircleV(particle.position, particle.size, color);
        }
    }
}