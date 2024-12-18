#include "raylib.h"
#include "Bird.h"
#include "Pipe.h"
#include "Background.h"
#include "Weather.h"
#include "GameConfig.h"
#include "Menu.h"
#include <vector>

const char* GAME_TITLE = "Flappy Bird";
bool hellModeActivated = false;

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);
    SetTargetFPS(60);

    Background background;
    background.Load();
    Bird bird;
    bird.Load();
    Weather weather;
    Menu menu;
    menu.Load();

    GameState gameState = GameState::MENU;
    std::vector<Pipe> pipes;
    float pipeSpawnTimer = 0;
    float pipeSpawnInterval = 2.0f;
    int score = 0;
    bool gameOver = false;

    while (!WindowShouldClose()) {
        switch (gameState) {
        case GameState::MENU:
            menu.Update();
            if (menu.HandleInput() == GameState::PLAYING) {
                gameState = GameState::PLAYING;
                Pipe::LoadPipeTexture();
                pipes.clear();
                score = 0;
                gameOver = false;
                hellModeActivated = false;
                bird = Bird();
                bird.Load();
            }
            break;

        case GameState::PLAYING:
            if (!gameOver) {
                background.Update();
                weather.Update();
                bird.Update();

                // Hell mode transition check
                if (score == 10) {
                    hellModeActivated = true;
                }

                pipeSpawnTimer += GetFrameTime();
                if (pipeSpawnTimer >= pipeSpawnInterval) {
                    pipes.emplace_back(SCREEN_WIDTH);
                    pipeSpawnTimer = 0;
                }

                for (auto& pipe : pipes) {
                    pipe.Update();
                    if (pipe.CheckCollision(bird.GetCollisionBox())) {
                        gameOver = true;
                    }
                    if (!pipe.HasPassed() && pipe.GetX() < bird.GetX()) {
                        score++;
                        pipe.SetPassed(true);
                    }
                }

                pipes.erase(std::remove_if(pipes.begin(), pipes.end(),
                    [](const Pipe& pipe) { return pipe.IsOffscreen(); }), pipes.end());
            }
            break;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch (gameState) {
        case GameState::MENU:
            background.Draw();
            menu.Draw();
            break;

        case GameState::PLAYING:
            background.Draw();
            weather.Draw();
            for (auto& pipe : pipes) {
                pipe.Draw();
            }
            bird.Draw();
            DrawText(TextFormat("Score: %d", score), 10, 10, 20, BLACK);

            // Hell mode indicator
            if (hellModeActivated) {
                DrawText("HELL MODE ACTIVE", SCREEN_WIDTH / 2 - 100, 40, 30, RED);
            }

            if (gameOver) {
                DrawText("Game Over!", SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2, 40, RED);
                DrawText("Press R to Restart", SCREEN_WIDTH / 2 - 120, SCREEN_HEIGHT / 2 + 50, 20, BLACK);
                DrawText("Press M for Menu", SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 + 80, 20, BLACK);
            }
            break;
        }

        EndDrawing();

        if (gameOver) {
            if (IsKeyPressed(KEY_R)) {
                pipes.clear();
                score = 0;
                gameOver = false;
                hellModeActivated = false;
                bird = Bird();
                bird.Load();
                pipeSpawnTimer = 0;
            }
            else if (IsKeyPressed(KEY_M)) {
                gameState = GameState::MENU;
                gameOver = false;
            }
        }
    }

    Pipe::UnloadPipeTexture();
    CloseWindow();
    return 0;
}
