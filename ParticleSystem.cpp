#include "ParticleSystem.h"

ParticleSystem::ParticleSystem() {
    particles.resize(MAX_PARTICLES);
    for (auto& particle : particles) {
        particle.active = false;
    }
}

void ParticleSystem::EmitCrashParticles(Vector2 position) {
    const Color colors[] = { RED, MAROON, RED, RED };

    for (int i = 0; i < 60; i++) {
        for (auto& particle : particles) {
            if (!particle.active) {
                float angle = GetRandomValue(-180, 180) * DEG2RAD; // Full 360-degree spread
                float speed = GetRandomValue(200, 600) / 30.0f; // Much faster speed

                particle.position = position;
                particle.velocity = {
                    cosf(angle) * speed * 2.0f, // Doubled horizontal speed
                    sinf(angle) * speed * 2.0f  // Doubled vertical speed
                };
                particle.size = GetRandomValue(3, 8);
                particle.life = GetRandomValue(60, 120) / 100.0f; // Longer life
                particle.color = colors[GetRandomValue(0, 3)];
                particle.active = true;
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

            // Stronger gravity for blood-like falling effect
            particle.velocity.y += 0.8f;

            // Slight air resistance
            particle.velocity.x *= 0.98f;

            particle.life -= 0.016f;

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

            // Draw elongated blood particles
            Vector2 trailEnd = {
                particle.position.x - particle.velocity.x * 0.3f,
                particle.position.y - particle.velocity.y * 0.3f
            };

            DrawLineEx(particle.position, trailEnd, particle.size, color);
            DrawCircleV(particle.position, particle.size * 0.8f, color);
        }
    }
}
