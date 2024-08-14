// Rules of the game:
//
// 1. Any live cell with fewer than two live neighbours dies, as if caused by under-population.
// 2. Any live cell with two or three live neighbours lives on to the next generation.
// 3. Any live cell with more than three live neighbours dies, as if by overcrowding.
// 4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
//

#include <cstddef>
#include <array>
#include <ostream>
#include <iostream>
using namespace std;

template<size_t R, size_t C>
class Life {
public:
    Life() {
        for (auto& row : m_board) {
            for (auto& element : row) {
                element = false;
            }
        }
    }
    Life& operator=(Life&  life) {
        for (size_t row = 0; row < R; ++row) {
            for (size_t col = 0; col < C; ++col) {
                set(row, col, life.get(row, col));
            }
        }
        return *this;
    }
    ~Life() = default;

    void set(int row, int col, bool value) {
        if (isValid(row, col)) {
            m_board[row][col] = value;
        }
    }

    bool get(int row, int col) const {
        if (isValid(row, col)) {
            return m_board[row][col];
        }
        return false;
    }

    void next() {
        Life<R,C> nextBoard = *this;
        for (size_t row = 0; row < R; ++row) {
            for (size_t col = 0; col < C; ++col) {
                size_t liveNeighbours = countLiveNeighbours(row, col);
                if (get(row, col)) {
                    if (liveNeighbours < 2 || liveNeighbours > 3) {
                        nextBoard.set(row, col, false);
                    }
                }
                else {
                    if (liveNeighbours == 3) {
                        nextBoard.set(row, col, true);
                    }
                }
            }
        }
        *this = nextBoard;
    }

    friend ostream& operator<<(ostream& os, const Life<R, C>& life) {
        for (const auto& row : life.m_board) {
            for (const auto& element : row) {
                os << (element ? "*" : ".");
            }
            os << endl;
        }
        return os;
    }

private:
    bool isValid(int row, int col) const {
        if (row >= 0 && row < R && col >= 0 && col < C) {
            return true;
        }
        return false;
    }

    size_t countLiveNeighbours(size_t row, size_t col) const {
        size_t count = 0;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (isValid(row + i, col + 1)) {
                    count += get(row + i, col + j);
                }
            }
        }
        return count;
    }
    array<array<bool, C>, R> m_board;
};

int main() {
    Life<4, 4> life;
    life.set(1, 2, true);
    life.set(0, 0, true);
    life.set(2, 1, true);
    life.set(1, 1, true);
    for (int i=0; i<7; i++) {
        cout << life << endl;
        life.next();
    }
    cout << life << endl;
    return 0;
}