#ifdef __unix__
# include <unistd.h>
#define sleep(x) usleep(1000 *(x))
#elif defined _WIN32
# include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#endif

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "CharacterFiles/npc.hpp"


int main(){
    NPC *narrator = new NPC("Narrator");
    NPC *mentor = new NPC("Mentor");

    std::cout << narrator->getName() << std::endl;
    std::cout << mentor ->getName() << std::endl;

    std::ifstream file;
    file.open("tutorial.txt");

    if (file.fail()) {
        std::cout << "Tutorial file failed to open.\n";
        exit(1);
    }   

}