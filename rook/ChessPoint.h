#ifndef CHESSPOINT_H
#define CHESSPOINT_H

#include <stdexcept>

class ChessPoint {
public:
    int X;
    int Y;

    ChessPoint(int y, int x) {
        if (y < 0 || y > 7)
            throw std::invalid_argument("Param must be positive and less than 8.");

        if (x < 0 || x > 7)
            throw std::invalid_argument("Param must be positive and less than 8.");

        Y = y;
        X = x;
    }

    bool TryAdd(ChessPoint& point, int x, int y) {
        point = ChessPoint(0, 0);
        int newY = Y + y;
        int newX = X + x;

        if (newY < 0 || newY > 7 || newX < 0 || newX > 7)
            return false;

        point = ChessPoint(newY, newX);
        return true;
    }

    std::string ToString() const {
        return std::string(1, 'A' + X) + std::to_string(Y + 1);
    }

    bool operator == (const ChessPoint& other) const {
        return X == other.X && Y == other.Y;
    }

    bool operator != (const ChessPoint& other) const {
        return !(*this == other);
    }
};

#endif  // CHESSPOINT_H
