#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

template<typename T>
class player {
private:
    T symbol;
public:
    explicit player(const T& symbol) : symbol(symbol) {}

    T get_symbol() const {
        return symbol;
    }
};

#endif
