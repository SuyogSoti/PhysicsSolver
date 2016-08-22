#include<iostream>
#include <vector>
#include <fstream>
#include "Question.hpp"
#include "Functions.h"

int main(int argc, char const *argv[]) {
    std::vector<std::string> tempArr;
    if (argc == 2) {
        // std::cout << std::string(file.data()) << std::endl;
        std::string file = argv[1];
        std::cout << file << " is the file that is entered to be compiled" << std::endl;
        std::ifstream aFile(file.c_str(), std::ios::in);
        if(aFile.is_open()) {
            std::string line;
            int countLine = 0;
            while( getline(aFile, line) ) {
                tempArr.push_back(line);
                countLine++;
            }
            aFile.close();
        }
        else {
            std::cout << "Unable to open file" << std::endl;
            return 0;
        }
    }else{
        std::cout << "> ";
        std::string ques;
        getline(std::cin, ques);
        std::cout << " " << std::endl;
        tempArr.push_back(ques);
    }
    Question q(tempArr);
    q.printArrayValues();
    Functions F(q.getQuestion(), q.getValue());
    std::cout << "The answer is: " <<F.getAnswer() << std::endl;
    return 0;
}
