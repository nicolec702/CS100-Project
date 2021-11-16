#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include <string>

class Character {
    protected:
        std::string name;
    public:
        std::string getName(){ return name;}
        void setName(std::string n){ name=n;}
};

#endif