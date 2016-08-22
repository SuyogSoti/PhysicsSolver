#ifndef QUESTION_HPP
#define QUESTION_HPP
#include <string>
#include <vector>

class Question {
private:
    std::vector<std::string> keyWord = {
            "acceleration",
            "avg_vel",
            "init_vel",
            "final_vel",
            "time",
            "distance"
    };
    std::vector<std::string> values;
    int findInArr(std::vector<std::string> arg, std::string search);
    int question;
public:
    Question (std::vector<std::string> tempArr);
    //this is the test for this function!!!
//    =============Test Function==========
    void printArrayValues();//            ||
//    ==============Test Function=========
    std::vector<std::string> getValue();
    int getQuestion();
};
#endif
