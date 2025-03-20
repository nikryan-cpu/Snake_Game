#ifndef SNAKE_H
#define SNAKE_H

#include <windows.h>
#include <vector>

// Represents a point on the game field
struct Point {
    int x;
    int y;
};

enum class Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };

class Snake {
public:
    // Constructs a snake with the given starting position.
    Snake(int startX, int startY);

    // Change the snake's direction.
    void ChangeDirection(Direction newDirection);

    // Moves the snake in its current direction.
    void Move();

    // Increases the snake's tail length by one.
    void Grow();

    // Checks whether the snake's head collides with its tail.
    bool CollidesWithSelf() const;

    // Returns the snake's head position.
    const Point& GetHead() const;

    // Checks if the snake (head or tail segments) occupies the given position.
    bool IsAtPosition(int posX, int posY) const;

    // Returns the snake's tail segments.
    const std::vector<Point>& GetTail() const;

    // Returns the current direction.
    Direction GetDirection() const;

    // Resets the snake to the initial state at the given position.
    void Reset(int startX, int startY);

    // Chooses a new random color for the snake.
    void RandomizeColor();

    // Returns the snake's current color.
    WORD GetColor() const;

private:
    Point head;
    std::vector<Point> tail;
    Direction direction;
    WORD color; // Used for console rendering.
};

#endif // SNAKE_H