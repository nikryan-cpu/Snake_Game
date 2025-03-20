#include "Game.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <string>
using namespace std;

int main() {
    // Seed random number generator.
    srand(static_cast<unsigned int>(time(0)));

    string playerName;
    cout << "Enter your name: ";
    cin >> playerName;

    // Ask the player to choose the game speed.
    int delay;
    cout << "\nSET GAME SPEED"
        << "\n1: Slow (approx 5 FPS)"
        << "\n2: Medium (approx 10 FPS)"
        << "\n3: Fast (approx 20 FPS)"
        << "\n4: Super Fast (approx 40 FPS)"
        << "\nChoose game speed (1-4): ";
    int speedChoice;
    cin >> speedChoice;
    switch (speedChoice) {
    case 1: delay = 200; break;
    case 2: delay = 100; break;
    case 3: delay = 50; break;
    case 4: delay = 0; break;
    default: delay = 100;
    }

    Game game(playerName);
    game.Init();
    game.SetDelay(delay);

    // Main game loop.
    while (!game.IsGameOver()) {
        game.Render();
        game.ProcessInput();
        game.Update();
        Sleep(delay); // Frame-rate is capped by this fixed delay.
    }

    // Game over screen.
    system("cls");
    cout << "Game Over!\n";
    cout << playerName << ", your final score is: " << game.GetScore() << "\n";
    cout << "Press any key to exit...";
    _getch();

    return 0;
}