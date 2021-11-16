#ifndef GAME_HPP
#define GAME_HPP
#include "CharacterSelection.hpp"

#include <iostream>

class Game
{
    private:
        int gameState;
        Character* user;
    
    public:
        void screenUpdate();
        void newGame();
        



};

void Game::screenUpdate()
{
    
}


void Game::newGame()
{
    char userInput;
    user = new Character();
    std::cout << "Welcome Prompt Message! It's time to create your character!" << '\n' << "[Press any Key To Continue...]";






}


#endif GAME_HPP