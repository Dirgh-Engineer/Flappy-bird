#include "ParticleSystem.h"

ParticleSystem::ParticleSystem() {
    particles.resize(MAX_PARTICLES);
    for (auto& particle : particles) {
        particle.active = false;
    }
}

void ParticleSystem::EmitCrashParticles(Vector2 position) {
    const Color colors[] = {
        RED,
        ORANGE,
        GOLD,
        MAROON
    };

    for (int i = 0; i < 50; i++) {  // Emit more particles at once
        for (auto& particle : particles) {
            if (!particle.active) {
                float angle = GetRandomValue(0, 360) * DEG2RAD;
                float speed = GetRandomValue(200, 400) / 60.0f;

                particle.position = position;
                particle.velocity = {
                    cosf(angle) * speed,
                    sinf(angle) * speed
                };
                particle.size = GetRandomValue(5, 12);
                particle.life = 1.0f;
                particle.color = colors[GetRandomValue(0, 3)];
                particle.active = true;
                particle.rotation = GetRandomValue(0, 360);
                particle.rotationSpeed = GetRandomValue(-10, 10);
                break;
            }
        }
    }
}

void ParticleSystem::Update() {
    for (auto& particle : particles) {
        if (particle.active) {
            particle.position.x += particle.velocity.x;
            particle.position.y += particle.velocity.y;

            // Add gravity and air resistance
            particle.velocity.y += 0.3f;
            particle.velocity.x *= 0.98f;
            particle.velocity.y *= 0.98f;

            particle.rotation += particle.rotationSpeed;
            particle.life -= 0.016f;  // Slower fade out

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

            // Draw particle with rotation
            Vector2 center = particle.position;
            float radius = particle.size;

            // Draw main particle
            DrawCircleV(center, radius, color);

            // Draw particle trail
            Vector2 trailEnd = {
                center.x - particle.velocity.x * 0.5f,
                center.y - particle.velocity.y * 0.5f
            };

            Color trailColor = color;
            trailColor.a = (unsigned char)(127.0f * particle.life);
            DrawLineEx(center, trailEnd, radius * 0.5f, trailColor);
        }
    }
}
