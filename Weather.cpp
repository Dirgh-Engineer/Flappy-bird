#include "Weather.h"

Weather::Weather() {
    timeOfDay = 0.0f;
    isRaining = true;  // Start with rain enabled
}

Weather::~Weather() {
}

void Weather::Update() {
    UpdateDayCycle();

    // Add new raindrops
    if (GetRandomValue(0, 10) < 3) {
        Raindrop drop = {
            Vector2{(float)GetRandomValue(0, SCREEN_WIDTH), -10.0f},
            (float)GetRandomValue(10, 15),
            (float)GetRandomValue(10, 20)
        };
        raindrops.push_back(drop);
    }

    // Update existing raindrops
    for (auto& drop : raindrops) {
        drop.position.y += drop.speed;
        drop.position.x -= drop.speed * 0.5f;
    }

    // Remove raindrops that are off screen
    raindrops.erase(
        std::remove_if(raindrops.begin(), raindrops.end(),
            [](const Raindrop& drop) { return drop.position.y > SCREEN_HEIGHT; }),
        raindrops.end()
    );
}

void Weather::Draw() {
    ClearBackground(skyColor);

    // Draw rain
    for (const auto& drop : raindrops) {
        DrawLineEx(
            drop.position,
            Vector2{ drop.position.x - drop.length, drop.position.y + drop.length },
            2.0f,
            SKYBLUE
        );
    }
}

void Weather::UpdateDayCycle() {
    timeOfDay += GetFrameTime() * 0.1f;
    if (timeOfDay > 24.0f) timeOfDay = 0.0f;

    float dayProgress = timeOfDay / 24.0f;
    if (dayProgress < 0.25f) { // Night
        skyColor = Color{ 20, 20, 40, 255 };
    }
    else if (dayProgress < 0.3f) { // Sunrise
        skyColor = Color{ 120, 80, 90, 255 };
    }
    else if (dayProgress < 0.7f) { // Day
        skyColor = Color{ 135, 206, 235, 255 };
    }
    else if (dayProgress < 0.75f) { // Sunset
        skyColor = Color{ 255, 160, 100, 255 };
    }
    else { // Night
        skyColor = Color{ 20, 20, 40, 255 };
    }
}

void Weather::ToggleRain() {
    isRaining = !isRaining;
}
