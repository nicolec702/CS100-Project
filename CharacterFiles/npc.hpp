#ifndef __NPC_HPP__
#define __NPC_HPP__

#include "character.hpp"
#include <vector>
#include <fstream>

class NPC: public Character{
    private:
        std::vector<std::string> dialogue;

    public:
        NPC(){}

        NPC(std::string name){
                Character(name);
        }

        void populateDialogue(std::ifstream& file){
            file.clear();
            file.seekg(0, std::ios::beg);   //reset to beginning of file
            std::string findName = Character::getName();
            while (!file.eof()) {           //while not at end of file
                std::string temp = "";      //create temp string
                getline(file, temp);        //retrieve line

                std::size_t found = temp.find(findName);
                if (found != std::string::npos) //if name is found in line
                    dialogue.push_back(temp.substr(findName.size() + 2));  //add to dialogue vector
            }
        }

        std::string getLineAt(int i){  
            return dialogue.at(i);  //retrieve dialogue line at i
        }

};


#endif