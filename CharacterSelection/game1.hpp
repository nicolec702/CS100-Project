#ifndef GAME1_HPP
#define GAME1_HPP

#include "CharacterSelection.hpp"
#include "curses.h"

#include <iostream>


class newGame
{
    private:
        int gameState;
        Character* user;

    public:
        void screenUpdate();
        void dialogueType(std::string x);
        void CharacterScreen();
};

void newGame::screenUpdate()
{
    std::cout << "\033[2J\033[1;1H";
}

void newGame::dialogueType(std::string x)
{

}

void newGame::CharacterScreen()
{
    std::string userInput;
    int userKeypress;
    int selectedClass;
    user = new Character();

    screenUpdate();
    std::cout << "[Insert Welcome Prompt Message] It's time to create your character!";
    std::cout << '\n' << "[Press any Key To Continue...]";

    getch();
    screenUpdate();

    while(user->getName().empty() == true)
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
        }
    }

    //

    while(userInput.size() != 0 && userInput.at(0) == ' ')
    {
        userInput.erase(0, 1);
    }

    screenUpdate();

    if (userInput.size() != 0)
    {
        std::cout << "Just to make sure, you said your name was " + userInput + " right?" + '\n' + "[a] Yes" + '\n' + "[b] No" + '\n';
        while (1)
        {
            userKeypress = getch();
            if (userKeypress == 'a')
            {
                user->setName(userInput);
                // TEST TO VERIFY NAME HAS BEEN SET //
                std::cout << "Name has been successfully set to " << user->getName() << "!" << '\n';
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
}




#endif //GAME1_HPP

