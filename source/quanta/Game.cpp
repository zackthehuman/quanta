#include "quanta/Game.hpp"

#include <cstdlib>

namespace quanta {

    const unsigned int Game::BITS_PER_PIXEL = 32;

    Game::Game(unsigned int width, unsigned int height)
        : width(width)
        , height(height)
        , quit(false)
        , clock()
        , videoMode(width, height, BITS_PER_PIXEL)
        , contextSettings(0, 0, 0, 2, 0)
        , window()
        , hex(30)
    {

    }

    int Game::run() {
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

                update(dt);

                accumulator -= dt;
                totalRunningTime += dt;
            } // closes integration loop

            window.clear(sf::Color::Magenta);

            render();

            window.display();

        } // closes !quit loop

        return EXIT_SUCCESS;
    }

    void Game::update(float dt) {
        // hex.rotate(dt * 60.0f);
    }

    void Game::render() {
        const float spacing = 0.0f;
        const float offsetX = ((static_cast<float>(width) / 2.0f) - (hex.getBoxWidth() * 4.0f / 2.0f)); // center the hexagons horizontally
        const float offsetY = 30.0f;
        const unsigned char ROW_COUNT = 4;
        const unsigned char COLUMN_COUNT = 5;

        for(unsigned char x = 0; x < COLUMN_COUNT; ++x) {
            for(unsigned char y = 0; y < ROW_COUNT; ++y) {
                float spacingX = x * spacing;
                float spacingY = y * spacing;

                hex.setPosition(x * hex.getBoxWidth() + spacingX + offsetX, y * (hex.getFaceLength() + hex.getTriangleHeight()) + spacingY + offsetY);
                hex.setColor(sf::Color(
                    ((x * 255) / COLUMN_COUNT) % 255,
                    ((y * 255) / ROW_COUNT) % 255,
                    (((y + x) * 255) / COLUMN_COUNT) % 255)
                );

                if(y % 2 == 1) {
                    hex.move(hex.getTriangleWidth() + (spacing / 2.0f), 0.0f);
                }
                    
                // Don't draw last hex in odd rows
                if(!((y % 2 == 1) && x == (COLUMN_COUNT - 1))) {
                    window.draw(hex);
                }
            }
        }
    }

} // quanta