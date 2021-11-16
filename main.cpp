#include "weapons.hpp"
#include "weaponBehavior.hpp"
#include "longSword.hpp"
#include "staff.hpp"

int main(int argc, char* argv[]){
    Weapons weapon("Sword");
    weapon.setBehavior(new LongSword());

    for(int i = 0; i < 10; i++)
        weapon.specialMove(1);

    return 0;
    
}
