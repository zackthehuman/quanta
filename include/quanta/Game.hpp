#ifndef QUANTA_GAME
#define QUANTA_GAME

namespace quanta {

    class Game {
    private:
        unsigned int width;
        unsigned int height;
                
    public:
        Game(unsigned int width, unsigned int height);
        int run();
    };

} // quanta

#endif // QUANTA_GAME