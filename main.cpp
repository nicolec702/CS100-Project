#include "weapons.hpp"
#include "weaponBehavior.hpp"
#include "longSword.hpp"
#include "staff.hpp"

int main(){
    Weapons weapon("Sword");
    weapon.setBehavior(new LongSword);

    for(int i = 0; i < 5; i++)
        weapon.attack(1);
    
}