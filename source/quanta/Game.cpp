#include "quanta/Game.hpp"
#include "quanta/ui/HexagonShape.hpp"

#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

namespace quanta {

    Game::Game(unsigned int width, unsigned int height)
        : width(width)
        , height(height)
    {

    }

    int Game::run() {
        sf::Clock clock;
        sf::VideoMode videoMode(width, height, 32);
        sf::RenderWindow window;

        window.create(videoMode, "Quanta");
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

        HexagonShape hex(60);
        hex.setPosition(200.0f, 200.0f);

        sf::RectangleShape rect(sf::Vector2f(1.0f, 1.0f));
        rect.setPosition(hex.getPosition());
        rect.setFillColor(sf::Color::Red);

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
                // done updating simulation

                accumulator -= dt;
                totalRunningTime += dt;
            } // closes integration loop

            window.clear(sf::Color::Magenta);
            window.draw(hex);
            window.draw(rect);
            window.display();

        } // closes !quit loop

        return EXIT_SUCCESS;
    }

} // quanta