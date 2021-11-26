#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include <string>

class Character {
    private:
        std::string name;
    public:
        Character(){}
        Character(std::string name){ this->name = name; }
        std::string getName(){ return name;}
        void setName(std::string n){ name=n;}
};

#endif