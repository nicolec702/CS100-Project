#ifndef WINGAME_HPP
#define WINGAME_HPP
#include "Game.hpp"

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string.h>

class newGame : public Game
{
    public:
        void dialogueType(std::string x);
        void playerSelection();
        void cls()
        {
             system("cls");
        }
};

void newGame::dialogueType(std::string x)
{
    int i = 0;
    for (i; i < x.size(); i++)
    {
        if (kbhit())         
        {
            if (getch() == 13)
            {
                break;
            }
        }
        std::cout << x[i];
        Sleep(50);
    }
    for (i; i < x.size(); i++)
    {
        std::cout << x[i];
    }
}


void newGame::playerSelection()
{
    Attribute model;
    std::string userInput;
    int userKeypress;
    int selectedClass;
    player = new PlayableCharacter();

    cls();
    dialogueType("[Insert Welcome Prompt Message] It's time to create your character!");
    std::cout << '\n' << "[Press any Key To Continue...]";
    
    // Awaits for user input... Once done, updates the screen. //
    getch();
    Sleep(500);
    cls();

    // PART 1: Name gathering prompt. //

    while (player->getName().empty() == true)
    {
        userKeypress = 0;
        userInput = "";
        dialogueType("Let us begin, please start by telling us your name...");
        std::cout << '\n';
        while(userKeypress != 13)
        {
            userKeypress = getch();
            if (userKeypress == 8)
            {
                if (userInput.empty() == false)
                {
                    userInput.pop_back();
                    cls();
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
            userInput.erase(0, 1);
        }

        cls();
        
        if (userInput.size() != 0)
        {
            dialogueType("Just to make sure, you said your name was " + userInput + " right?" + '\n' + "[a] Yes" + '\n' + "[b] No" + '\n');
            while (1)
            {
                userKeypress = getch();
                if (userKeypress == 'a')
                {
                    player->setName(userInput);
                    // TEST TO VERIFY NAME HAS BEEN SET //
                    //std::cout << "Name has been successfully set to " << user->getName() << "!" << '\n';
                    //Sleep(5000);
                    break;
                }
                else if (userKeypress == 'b')
                {
                    cls();
                    dialogueType("Okay, let's try this again then...");
                    std::cout << '\n' << "[Press any Key To Continue...]";
                    getch();
                    break;
                }
            }
        }
        else
        {
            dialogueType("I'm sorry, I didn't catch that... Please say that again?");
            std::cout << '\n' << "[Press any Key To Continue...]";
            getch();
        }
        cls();
    }

    // PART 2: Class selection prompt //
    userKeypress = 0;
    selectedClass = 0;
    dialogueType("Okay " + player->getName() + ", it is time to choose your class..." + '\n'); 
    std::cout << '\n' << "[Press any Key To Continue...]";
    getch();
    
    while(1)
    {
        cls();
        if (selectedClass == 0)
        {
             std::cout << "[ROGUE]             " << "WIZARD               " << "KNIGHT               " << "BOB"; 
             std::cout << '\n' << "=================================================================" << '\n';
             std::cout << "STATS:" << '\n' << "[==== ] HP: 13" << '\n' << "[==== ] DEF: 9" << '\n' << "[==== ] ATK: 13" << '\n' << "[==== ] STAMINA: 1.75" << '\n';             
             std::cout << "BACKGROUND: ";
        }
        else if (selectedClass == 1)
        {
             std::cout << "ROGUE              " << "[WIZARD]              " << "KNIGHT               " << "BOB"; 
             std::cout << '\n' << "=================================================================" << '\n';
             std::cout << "STATS:" << '\n' << "[===  ] HP: 12" << '\n' << "[===  ] DEF: 8" << '\n' << "[=====] ATK: 15" << '\n' << "[===  ] STAMINA: 1.5" << '\n';             
             std::cout << "BACKGROUND: " << "";
        }
        else if (selectedClass == 2)
        {
             std::cout << "ROGUE               " << "WIZARD              " << "[KNIGHT]              " << "BOB"; 
             std::cout << '\n' << "=================================================================" << '\n';
             std::cout << "STATS:" << '\n' << "[=====] HP: 14" << '\n' << "[=====] DEF: 10" << '\n' << "[==   ] ATK: 12" << '\n' << "[===  ] STAMINA: 1.5" << '\n';             
             std::cout << "BACKGROUND: Once an admired people, wizards were persecuted to the point of extinction due to the fear of their power. All high level wizards are now dead and all that remains are a mediocre batch.";
        }
        else if (selectedClass == 3)
        {
            std::cout << "ROGUE               " << "WIZARD               " << "KNIGHT             " << "[BOB]"; 
            std::cout << '\n' << "=================================================================" << '\n';
            std::cout << "STATS:" << '\n' << "[==   ] HP: 10" << '\n' << "[=    ] DEF: 5" << '\n' << "[=    ] ATK: 10" << '\n' << "[=====] STAMINA: 2" << '\n';
            std::cout << "BACKGROUND: ";
        }

        userKeypress = getch();
        // KEYPRESS TEST //
        // std::cout << userKeypress;

        if (userKeypress == 77 && selectedClass < 3)
        {
            ++selectedClass;
        }
        else if (userKeypress == 75 && selectedClass > 0)
        {
            --selectedClass;
        }

        else if (userKeypress == 13)
        {
            std::cout << '\n';
            std::cout.flush();
            dialogueType("Are you sure you want to pick this class?");
            std::cout << '\n' << "[a] Yes" << '\n' << "[b] No" << '\n';
            while (userKeypress != 'a' && userKeypress != 'b')
            {
                userKeypress = getch();
            }
            if (userKeypress == 'a')
            {
                switch(selectedClass)
                {
                    case 1: model.setBehavior(new Rogue());
                    case 2: model.setBehavior(new Wizard());
                    case 3: model.setBehavior(new Knight());
                    case 4: model.setBehavior(new Bob());
                }
                break;
            }
        }
    }









}
#endif //WINGAME_HPP
