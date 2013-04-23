#include "Main.hpp"
#include "quanta/Game.hpp"

int main(int argc, char** argv) {
    quanta::Game game(640, 480);
    return game.run();
}