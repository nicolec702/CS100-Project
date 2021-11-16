#include "weapons.hpp"
#include "weaponBehavior.hpp"
#include "longSword.hpp"
#include "dagger.hpp"
#include "staff.hpp"
#include "broom.hpp"
#include <iostream>

int main(int argc, char* argv[]){
    Weapons weapon("Sword");
    weapon.setBehavior(new LongSword());

    std::cout << "Between 5 - 8" << std::endl;
    for(int i = 0; i < 5; i++)
        weapon.attack(1);

    std::cout << std::endl;

    weapon.setBehavior(new Dagger());
    std::cout << "Between 2 - 5" << std::endl;
    for(int i = 0; i < 5; i++)
        weapon.attack(1);

    weapon.setBehavior(new Broom());
    std::cout << "Between 3 - 5" << std::endl;
    for(int i = 0; i < 5; i++)
        weapon.attack(1);

    weapon.setBehavior(new Staff());
    std::cout << "Between 3 - 6" << std::endl;
    for(int i = 0; i < 5; i++)
        weapon.attack(1);


    return 0;
    
}
