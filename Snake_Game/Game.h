#ifndef GAME_H
#define GAME_H

#include <string>
#include "Snake.h"

class Game {
public:
    // Constructs the game with a given player's name and field dimensions.
    Game(const std::string& playerName, int fieldWidth = 80, int fieldHeight = 20);

    // Initializes or resets the game state.
    void Init();

    // Renders the game field (walls, snake, fruit, and score).
    void Render() const;

    // Processes user input.
    void ProcessInput();

    // Updates game state (moves snake, checks collisions, etc.).
    void Update();

    // Returns true if the game is over.
    bool IsGameOver() const;

    // Returns the current score.
    int GetScore() const;

    // Sets the delay (in milliseconds) used in the game loop.
    void SetDelay(int delay);

private:
    std::string playerName;
    int width;
    int height;
    int fruitX;
    int fruitY;
    int score;
    bool gameOver;
    int delay; // Delay in milliseconds used to control the game speed.
    Snake snake;

    // Spawns a new fruit at a random location not occupied by the snake.
    void SpawnFruit();
};

#endif // GAME_H