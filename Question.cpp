#include <string>
#include <iostream>
#include "Question.hpp"
#include <sstream>

Question::Question(std::vector<std::string> tempArr){
    // resize values to the as long as the keyword
    Question::values.resize(Question::keyWord.size());
    //cycles through the sentences
    for (int i = 0; i < tempArr.size(); i++) {
        std::cout << tempArr[i] << std::endl;
        //next couple of lines is to cycles through the indivisual words
        std::stringstream tempStringStream(tempArr[i]);
        std::string word;
        bool valuePlace = false;
        int index = -1;
        bool find = false;
        while (tempStringStream >> word) {
            // if word is find, then prepare the next word!!
            if (word == "find") {
                find = true;
            }else{
                //check if it is the value or the keyword
                //value place implies that it is value
                if (valuePlace) {
                    Question::values[index] = word;
                    valuePlace = false;
                //the bottom here implies that word is not a value
                }else {
                    //check if it is a keyword
                    index = Question::findInArr(Question::keyWord, word);
                    // if it is a key word and and this is not the question then set the next word as value
                    if (index >= 0 && !find) {
                        Question::values[index] = word;
                        valuePlace = true;
                    // if question is allowed or not and it is after find
                    }else if (index >= 0 && find){
                        std::cout << "You asked to find the word: " << word << std::endl;
                        Question::question = index;
                    // there was an error somewhere brother
                    } else{
                        std::cout << "This is not the correct syntax or the correct keyword" << std::endl;
                        std::cout << word << std::endl;
                    }
                }
            }
        }
    }
}
int Question::findInArr(std::vector<std::string> arg, std::string search) {
    for (int i = 0; i < arg.size(); i++) {
        if (arg[i] == search) {
            return i;
        }
    }
    return -1;
}
void Question::printArrayValues() {
    for (int i = 0; i < Question::keyWord.size(); ++i) {
        std::cout << "Question::keyWord[" << i << "]: " << Question::keyWord[i] << std::endl;
        std::cout << "Question::values[" << i << "]: " << Question::values[i] << std::endl;
    }
}
std::vector<std::string> Question::getValue() {
    return Question::values;
}
int Question::getQuestion() {
    return Question::question;
}
