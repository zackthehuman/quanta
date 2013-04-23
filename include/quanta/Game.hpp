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