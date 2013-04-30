#ifndef QUANTA_GAME
#define QUANTA_GAME

#include "quanta/ui/HexagonShape.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window/WindowStyle.hpp>

namespace quanta {

    class Game {
    private:
        static const unsigned int BITS_PER_PIXEL;
        unsigned int width;
        unsigned int height;
        bool quit;

        sf::Clock clock;
        sf::VideoMode videoMode;
        sf::ContextSettings contextSettings;
        sf::RenderWindow window;

        HexagonShape hex;
                
    public:
        Game(unsigned int width, unsigned int height);
        int run();
        void update(float dt);
        void render();
    };

} // quanta

#endif // QUANTA_GAME