#include "Game.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
using namespace std;

Game::Game(const std::string& playerName, int fieldWidth, int fieldHeight)
    : playerName(playerName),
    width(fieldWidth),
    height(fieldHeight),
    snake(fieldWidth / 2, fieldHeight / 2)
{
    score = 0;
    gameOver = false;
    delay = 100; // Default game speed delay (milliseconds)
    SpawnFruit();
}

void Game::Init() {
    score = 0;
    gameOver = false;
    snake.Reset(width / 2, height / 2);
    SpawnFruit();
}

void Game::Render() const {
    system("cls");

    // Get handle for console color settings.
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    WORD defaultColor = csbi.wAttributes;

    // Draw the top wall.
    for (int i = 0; i < width + 2; i++)
        cout << "-";
    cout << "\n";

    // Draw the game field.
    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= width; j++) {
            if (j == 0 || j == width) {
                cout << "|";
            }
            else if (i == fruitY && j == fruitX) {
                cout << "#";
            }
            else if (i == snake.GetHead().y && j == snake.GetHead().x) {
                SetConsoleTextAttribute(hConsole, snake.GetColor());
                cout << "O";
                SetConsoleTextAttribute(hConsole, defaultColor);
            }
            else {
                bool printed = false;
                for (const auto& segment : snake.GetTail()) {
                    if (segment.x == j && segment.y == i) {
                        SetConsoleTextAttribute(hConsole, snake.GetColor());
                        cout << "o";
                        SetConsoleTextAttribute(hConsole, defaultColor);
                        printed = true;
                        break;
                    }
                }
                if (!printed)
                    cout << " ";
            }
        }
        cout << "\n";
    }

    // Draw the bottom wall.
    for (int i = 0; i < width + 2; i++)
        cout << "-";
    cout << "\n";

    // Display player's score.
    cout << playerName << "'s Score: " << score << "\n";
}

void Game::ProcessInput() {
    if (_kbhit()) {
        char key = _getch();
        switch (key) {
        case 'a':
            snake.ChangeDirection(Direction::LEFT);
            break;
        case 'd':
            snake.ChangeDirection(Direction::RIGHT);
            break;
        case 'w':
            snake.ChangeDirection(Direction::UP);
            break;
        case 's':
            snake.ChangeDirection(Direction::DOWN);
            break;
        case 'x':
            gameOver = true;
            break;
        default:
            break;
        }
    }
}

void Game::Update() {
    snake.Move();

    // Check for collision with walls.
    Point head = snake.GetHead();
    if (head.x <= 0 || head.x >= width || head.y < 0 || head.y >= height)
        gameOver = true;

    // Check for collision with the snake itself.
    if (snake.CollidesWithSelf())
        gameOver = true;

    // Check if the snake eats the fruit.
    if (head.x == fruitX && head.y == fruitY) {
        score += 10;
        snake.Grow();
        snake.RandomizeColor();
        SpawnFruit();
    }
}

bool Game::IsGameOver() const {
    return gameOver;
}

int Game::GetScore() const {
    return score;
}

void Game::SetDelay(int d) {
    delay = d;
}

void Game::SpawnFruit() {
    // Spawn a fruit at a random location not occupied by the snake.
    do {
        fruitX = rand() % (width - 1) + 1; // Ensure fruit is within walls.
        fruitY = rand() % height;
    } while (snake.IsAtPosition(fruitX, fruitY));
}