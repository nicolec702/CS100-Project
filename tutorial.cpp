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


void populateList(std::ifstream& file, std::vector<std::string>& dialogue, std::string);
void typingEffect(std::string str);

int main()
{
    std::string char1 = "NARRATOR";
    std::string char2 = "MENTOR";

    std::vector<std::string> narrator;
    std::vector<std::string> mentor;

    std::ifstream file;
    file.open("tutorial.txt");

    if (file.fail()) {
        std::cout << "Tutorial file failed to open.\n";
        exit(1);
    }
    
    populateList(file, narrator, char1);
    populateList(file, mentor, char2);

    int i = 0;
    int j = 0;
    
    typingEffect(narrator.at(i));
    std::cout << std::endl;
    i++;
    typingEffect(narrator.at(i));
    std::cout << std::endl;
    i++;
    typingEffect(narrator.at(i));
    std::cout << std::endl;
    std::cin.get();


    typingEffect("\t\tMentor: " + mentor.at(j));
    std::cout << std::endl;
    std::cin.get();
       
    i++;
    j++;
 
    typingEffect(narrator.at(i));
    std::cout << std::endl;
    std::cin.get();
    i++;
    std::cout << narrator.at(i) << " ";
    
    int input;
    std::cin >> input;
    while (input != 1) {
        std::cout << "\033[F";
        std::cout << narrator.at(i) << " ";
        std::cin >> input;
    }

    std::cout << std::endl;
    typingEffect("\t\tMentor: " + mentor.at(j));
    std::cout << std::endl;
    std::cin.get();
    std::cin.get();

    i++;
    j++;

    typingEffect(narrator.at(i));
    std::cout << std::endl;
    std::cin.get();

    i++;
    std::cout << narrator.at(i) << " ";
    std::cin >> input;
    
    while (input != 2) {
        std::cout << "\033[F";
        std::cout << narrator.at(i) << " ";
        std::cin >> input;
    }

    i++;

    std::cout << std::endl;
    typingEffect("\t\tMentor: " + mentor.at(j));
    std::cout << std::endl;
    std::cin.get();
    std::cin.get();

    std::cout << narrator.at(i) << " ";
    std::cin >> input;

    while (input != 3) {
        std::cout << "\033[F";
        std::cout << narrator.at(i) << " ";
        std::cin >> input;
    }

    i++;
    j++;

    std::cout << std::endl;
    typingEffect("\t\tMentor: " + mentor.at(j));
    std::cout << std::endl;
    std::cin.get();
    std::cin.get();

  
    std::cout << narrator.at(i) << " ";
    std::cin >> input;

    while (input != 4) {
        std::cout << "\033[F";
        std::cout << narrator.at(i) << " ";
        std::cin >> input;
    }

    i++;
    j++;

    std::cout << std::endl;
    typingEffect("\t\tMentor: " + mentor.at(j));
    std::cout << std::endl;
    std::cin.get();
    std::cin.get();

    typingEffect(narrator.at(i));
    std::cout << std::endl;
    std::cin.get();

    i++;

    typingEffect(narrator.at(i));
    std::cout << std::endl;
    std::cin.get();

    system("CLS");

           
}

void populateList(std::ifstream& file, std::vector<std::string>& dialogue, std::string character) {
    file.clear();
    file.seekg(0, std::ios::beg);
    while (!file.eof()) {
        std::string temp = "";
       
        getline(file, temp);

        std::size_t found = temp.find(character);
        if (found != std::string::npos)
            dialogue.push_back(temp.substr(character.size() + 2));

    }
}

void typingEffect(std::string str) {
    for (int i = 0; i < str.size(); i++) {
        std::cout << str[i];
        sleep(0.1);
    }
}