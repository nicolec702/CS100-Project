#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include <string>
#include "../helperFunction.hpp"

class Character {
    private:
        std::string name;
    public:
        std::string getName(){ return name;}
        void setName(std::string n){ name=n;}
};

#endif