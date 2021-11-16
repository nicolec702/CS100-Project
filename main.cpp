#include "attackCharacter.hpp"
#include <iostream>

int main()
{
    Attribute wizardStats(10,8,12,10);
    AttackChacracter wizard(wizardStats);
    wizard.setName ("Wizard");

    std::cout<<"You have chosen the "<<wizard.getName ()<<std::endl;
    wizard.printVitals();
    printf("----------------------------\n");
    wizard.increaseEXP(12);
    wizard.printVitals();
}