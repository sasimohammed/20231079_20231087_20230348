#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

template<typename T>
class player {
private:
    T symbol;
public:
    player(const T& symbol) : symbol(symbol) {}

    T get_symbol() const {
        return symbol;
    }
};

#endif
