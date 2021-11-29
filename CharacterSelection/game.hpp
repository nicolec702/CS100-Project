#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>

class Game
{
    public:
        virtual void screenUpdate() = 0;
        virtual void dialogueType(std::string x) = 0;
        virtual void CharacterScreen() = 0;
};




#endif //GAME_HPP