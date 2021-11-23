#include "Board.hpp"

#include <vector>

Board::Board() {
    for (int x = 0; x < BOARD_WIDTH; x++) {
        for (int y = 0; y < BOARD_HEIGHT; y++) {
            this->gems[x][y] = Gem::EMPTY;
        }
    }
}


int Board::match() {
    std::vector<SDL_Point> to_remove;
    for (int x = 0; x < BOARD_WIDTH; x++) {
        Gem last = Gem::EMPTY;
        int matches = 0;
        for (int y = 0; y < BOARD_HEIGHT; y++) {
            if (this->gems[x][y] == last) {
                if (last != Gem::EMPTY) {
                    matches++;
                } else {
                    matches = 0;
                    continue;
                }
                if (y == (BOARD_HEIGHT - 1) && matches > 1) {
                    for (matches; matches >= 0; matches--) {
                        to_remove.push_back(SDL_Point{x,y-matches});
                    }
                }
            } else {
                if (matches > 1) {
                    for (matches; matches >= 0; matches--) {
                        to_remove.push_back(SDL_Point{x,y-1-matches});
                    }
                }
            }
            last = this->gems[x][y];
        }
    }

    for (int y = 0; y < BOARD_HEIGHT; y++) {
        Gem last = Gem::EMPTY;
        int matches = 0;
        for (int x = 0; x < BOARD_WIDTH; x++) {
            if (this->gems[x][y] == last) {
                if (last != Gem::EMPTY)
                    matches++;
                if (x == (BOARD_WIDTH - 1) && matches > 1) {
                    for (matches; matches >= 0; matches--) {
                        to_remove.push_back(SDL_Point{x,y-matches});
                    }
                    matches = 0;
                }
            } else {
                if (matches > 1) {
                    for (matches; matches >= 0; matches--) {
                        to_remove.push_back(SDL_Point{x-1-matches,y});
                    }
                }
                matches = 0;
            }
            last = this->gems[x][y];
        }
    }
    SDL_Log("Amount of gems which have been matched is %d", to_remove.size());
    for (SDL_Point p : to_remove) {
        SDL_Log("Removing gem at %d,%d", p.x, p.y);
        this->gems[p.x][p.y] = Gem::EMPTY;
    }
    
    return to_remove.size();
}

void Board::fillEmpty() {
    for (int x = 0; x < BOARD_WIDTH; x++) {
        for (int y = (BOARD_HEIGHT - 1); y >= 0; y--) {
            if (this->gems[x][y] != Gem::EMPTY)
                continue;
            
            if (y > 0) {
                this->gems[x][y] = this->gems[x][y-1];
                this->gems[x][y-1] = Gem::EMPTY;
            } else {
                this->gems[x][y] = (Gem) (rand() % (int) Gem::NUMBER_OF_COLORS);
            }
        }
    }
}

bool Board::hasEmpty() {
    for (int x = 0; x < BOARD_WIDTH; x++) {
        for (int y = 0; y < BOARD_HEIGHT; y++) {
            if (this->gems[x][y] == Gem::EMPTY) {
                return true;
            }
        }
    }
    return false;
}

void Board::swap(SDL_Point p1, SDL_Point p2) {

}