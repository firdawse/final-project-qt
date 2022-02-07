
#ifndef GAME_H
#define GAME_H
class Game
{
        public:
            int score = 0;
            int gridboard[4][4] = {};
            Game();
            void Up();
            void Down();
            void Right();
            void Left();
            void Restart();
            bool WIN();
            bool LOSE();


       private:
           void AddRandom();
           bool condition;
};


#endif // GAME_H
