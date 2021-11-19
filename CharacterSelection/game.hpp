#ifndef GAME_HPP
#define GAME_HPP
#include "CharacterSelection.hpp"

#include <iostream>
#include <conio.h>
#include <string.h>

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
    system("cls");
}


void Game::newGame()
{

    std::string userInput;
    int userKeypress;
    int selectedClass;
    user = new Character();

    screenUpdate();

    std::cout << "Welcome Prompt Message! It's time to create your character!" << '\n' << "[Press any Key To Continue...]";
    
    // Awaits for user input... Once done, updates the screen. //

    getch();
    _sleep(500);
    screenUpdate();

    // PART 1: Name gathering prompt. //

    while (user->getName().empty() == true)
    {
        userKeypress = 0;
        userInput = "";
        std::cout << "Let us begin, please start by telling us your name..." << '\n';
        while(userKeypress != 13)
        {
            userKeypress = getch();
            if (userKeypress == 8)
            {
                if (userInput.empty() == false)
                {
                    userInput.pop_back();
                    screenUpdate();
                    std::cout << "Let us begin, please start by telling us your name..." << '\n';
                    std::cout << userInput;
                }
            }
            else if (userKeypress >= 20 && userKeypress <= 126)
            {
                userInput.push_back(static_cast<char>(userKeypress));
                std::cout << static_cast<char>(userKeypress);
            }

            // DEBUG MODE: EMERGENCY LOOP BREAK. USE "DEL" KEY. //
            //else if (userKeypress == 127)
            //{
            //    break;
            //}
        }

        while (userInput.size() != 0 && userInput.at(0) == ' ')
        {
            userInput.erase(userInput.front());
        }

        screenUpdate();
        
        if (userInput.size() != 0)
        {
            std::cout << "Just to make sure, you said your name was " << userInput << " right?" << '\n';
            std::cout << "[a] Yes" << '\n' << "[b] No" << '\n';
            while (1)
            {
                userKeypress = getch();
                if (userKeypress == 'a')
                {
                    user->setName(userInput);
                    // TEST TO VERIFY NAME HAS BEEN SET //
                    //std::cout << "Name has been successfully set to " << user->getName() << "!" << '\n';
                    //_sleep(5000);
                    break;
                }
                else if (userKeypress == 'b')
                {
                    screenUpdate();
                    std::cout << "Okay, let's try this again then..." << '\n' << "[Press any Key To Continue...]";
                    getch();
                    break;
                }
            }
        }
        else
        {
            std::cout << "I'm sorry, I didn't catch that... Please say that again?" << '\n' << "[Press any Key To Continue...]";
            getch();
        }
        screenUpdate();
    }

    // PART 2: Class selection prompt //
    userKeypress = 0;
    while(userKeypress != 13)
    {
        
    }











}


#endif GAME_HPP