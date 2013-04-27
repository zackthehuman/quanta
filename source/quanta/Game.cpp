#include "quanta/Game.hpp"
#include "quanta/ui/HexagonShape.hpp"

#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/WindowStyle.hpp>

namespace quanta {

    Game::Game(unsigned int width, unsigned int height)
        : width(width)
        , height(height)
    {

    }

    int Game::run() {
        sf::Clock clock;
        sf::VideoMode videoMode(width, height, 32);
        sf::ContextSettings contextSettings(0, 0, 0, 2, 0);
        sf::RenderWindow window;

        window.create(videoMode, "Quanta", sf::Style::Default, contextSettings);
        window.setActive(true);
        window.setVerticalSyncEnabled(false);
        window.setKeyRepeatEnabled(false);

        const float dt = 1.0f/60.0f;
        float totalRunningTime = 0.0f;
        float accumulator = 0.0f;
        float frameTime = 0.0f;

        sf::Time currentTime(clock.getElapsedTime());
        sf::Time newTime;
        sf::Event event;

        bool quit = false;

        HexagonShape hex(30);

        while(!quit) {

            newTime = clock.getElapsedTime();
            frameTime = newTime.asSeconds() - currentTime.asSeconds();
            currentTime = newTime;

            accumulator += frameTime;

            while(accumulator >= dt) {
                while(window.pollEvent(event)) {
                    if(event.type == sf::Event::Closed) {
                        quit = true;
                    }
                } // closes event processing loop

                // update simulation here
                // simulation.update(dt);
                // hex.rotate(1000.0f / 60.0f / 13.0f);
                // done updating simulation

                accumulator -= dt;
                totalRunningTime += dt;
            } // closes integration loop

            window.clear(sf::Color::Magenta);

            const float spacing = 3.0f;
            for(int x = 0; x < 5; ++x) {
                for(int y = 0; y < 5; ++y) {
                    float spacingX = x * spacing;
                    float spacingY = y * spacing;

                    hex.setPosition(x * hex.getBoxWidth() + spacingX, y * (hex.getFaceLength() + hex.getTriangleHeight()) + spacingY);

                    if(y % 2 == 1) {
                        hex.move(hex.getTriangleWidth() + (spacing / 2.0f), 0.0f);
                    }
                    
                    // Don't draw last hex in odd rows
                    if(!((y % 2 == 1) && x == 4)) {
                        window.draw(hex);
                    }
                }
            }

            window.display();

        } // closes !quit loop

        return EXIT_SUCCESS;
    }

} // quanta