#include "Snake.h" // for rand()

// List of available console colors for the snake.
const WORD availableColors[] = {
    FOREGROUND_RED | FOREGROUND_INTENSITY,
    FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    FOREGROUND_BLUE | FOREGROUND_INTENSITY,
    FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY, // Yellow
    FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY,  // Magenta
    FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,// Cyan
    FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY // White
};

const int numAvailableColors = sizeof(availableColors) / sizeof(availableColors[0]);

Snake::Snake(int startX, int startY) {
    head.x = startX;
    head.y = startY;
    direction = Direction::STOP;
    tail.clear();
    // Set default snake color (green)
    color = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
}

void Snake::ChangeDirection(Direction newDirection) {
    // (Optional) Add logic to reject an immediate reversal based on the current direction.
    direction = newDirection;
}

void Snake::Move() {
    // Update the tail segments.
    if (!tail.empty()) {
        // Shift tail segments so that each segment follows the previous segment.
        for (int i = tail.size() - 1; i > 0; --i) {
            tail[i] = tail[i - 1];
        }
        tail[0] = head;
    }

    // Move the head in the current direction.
    switch (direction) {
    case Direction::LEFT:
        head.x--;
        break;
    case Direction::RIGHT:
        head.x++;
        break;
    case Direction::UP:
        head.y--;
        break;
    case Direction::DOWN:
        head.y++;
        break;
    default:
        break;
    }
}

void Snake::Grow() {
    // Add a new segment at the end of the tail.
    Point newSegment;
    if (!tail.empty())
        newSegment = tail.back();
    else
        newSegment = head;
    tail.push_back(newSegment);
}

bool Snake::CollidesWithSelf() const {
    // Check if the head collides with any tail segment.
    for (const auto& segment : tail) {
        if (segment.x == head.x && segment.y == head.y)
            return true;
    }
    return false;
}

const Point& Snake::GetHead() const {
    return head;
}

bool Snake::IsAtPosition(int posX, int posY) const {
    if (head.x == posX && head.y == posY)
        return true;
    for (const auto& segment : tail) {
        if (segment.x == posX && segment.y == posY)
            return true;
    }
    return false;
}

const std::vector<Point>& Snake::GetTail() const {
    return tail;
}

Direction Snake::GetDirection() const {
    return direction;
}

void Snake::Reset(int startX, int startY) {
    head.x = startX;
    head.y = startY;
    direction = Direction::STOP;
    tail.clear();
    color = FOREGROUND_GREEN | FOREGROUND_INTENSITY; // reset to default
}

void Snake::RandomizeColor() {
    color = availableColors[rand() % numAvailableColors];
}

WORD Snake::GetColor() const {
    return color;
}