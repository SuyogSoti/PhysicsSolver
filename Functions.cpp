//
// Created by suyog on 2/24/16.
//

#include <iostream>
#include <vector>
#include <cmath>
#include "Functions.h"

Functions::Functions(int question, std::vector<std::string> v) {
    Functions::question = question;
    Functions::tester = v;
    for (int i = 0; i < v.size(); ++i) {
        Functions::values.push_back(float(atof(v[i].c_str())));
    }
}

float Functions::getAnswer() {
    int q = Functions::question;
    switch(q){
        case 0:
            return Functions::acceleration();
        case 1:
            return Functions::avg_vel();
        case 2:
            return Functions::inst_vel();
        case 3:
            return Functions::final_vel();
        case 4:
            return Functions::time();
        case 5:
            return Functions::distance();
        default:
            std::cout << "Question not in the list..." << std::endl;
            std::cout << "This is most likely a bug in the program, please contact the developers" << std::endl;
            return 0;
    }
}

float Functions::distance() {
    if (Functions::tester[5].length() > 0){
        return Functions::values[5];
    }else{
        float ans = 0;
        if(Functions::tester[0].length() > 0){
            if (Functions::tester[2].length() > 0 && Functions::tester[4].length() > 0){
                ans = float((Functions::values[2] * Functions::values[4]) +
                        (Functions::values[0] * 0.5 * Functions::values[4] * Functions::values[4]));
            }else if(Functions::tester[0] != "0" && Functions::tester[2].length() > 0 && Functions::tester[3].length() > 0){
                float f = Functions::values[3] * Functions::values[3];
                float i = Functions::values[2] * Functions::values[2];
                float twiceAD = f - i;
                ans = twiceAD/(Functions::values[0] * 2);
            }else{
                std::cout << "Sorry but enough information has not been provided" << std::endl;
            }
        }else{
            if (Functions::tester[1].length() > 0 && Functions::tester[4].length() > 0){
                ans = Functions::values[1] * Functions::values[4];
            }else if(Functions::tester[2].length() > 0 && Functions::tester[4].length() > 0 && Functions::tester[3].length() > 0){
                float avg = (Functions::values[2] + Functions::values[3]) / 2;
                ans = avg * Functions::values[4];
            }else{
                std::cout << "Sorry but enough information has not been provided" << std::endl;
            }
        }
        Functions::values[5] = ans;
        return ans;
    }
}

float Functions::acceleration() {
    if (Functions::tester[0].length() > 0){
        return Functions::values[0];
    }else {
        // Acceleration is delta velocity/over time
        if (Functions::tester[4].length() > 0 && Functions::tester[3].length() > 0 &&
            Functions::tester[2].length() > 0) {
            return (Functions::values[3] - Functions::values[2]) / Functions::values[4];
        } else if (Functions::tester[5].length() > 0 && Functions::tester[2].length() > 0 &&
                   Functions::tester[3].length() > 0) {
            float avg = Functions::values[3] * Functions::values[3] - Functions::values[2] * Functions::values[2];
            avg = avg / 2;
            return avg / Functions::values[5];
        } else if (Functions::tester[5].length() > 0 && Functions::tester[2].length() > 0 &&
                   Functions::tester[4].length() > 0) {
            float temp = Functions::values[5] - (Functions::values[2] * Functions::values[4]);
            temp = temp * 2;
            return temp / (Functions::values[4] * Functions::values[4]);
        } else {
            return 0;
        }
    }
}

float Functions::avg_vel() {
    if (Functions::tester[1].length() > 0){
        return Functions::values[1];
    }else {
        if (Functions::time() != 0 && Functions::tester[4].length() > 0) {
            return Functions::distance()/Functions::time();
        }else if( Functions::tester[2].length() > 0 && Functions::tester[3].length() > 0){
            return (Functions::inst_vel()+Functions::final_vel())/2;
        }
        return 0;
    }
}

float Functions::time() {
    if (Functions::tester[4].length() > 0){
        return Functions::values[4];
    }else{
        if (Functions::tester[2].length() > 0 && Functions::tester[3].length() > 0 && Functions::tester[0].length() > 0){
            float temp = Functions::final_vel() - Functions::inst_vel();
            return temp/Functions::acceleration();
        }else if (Functions::tester[5].length() > 0){
            if (Functions::tester[0].length() > 0 && Functions::tester[2].length() > 0){
                float tempPositive = -Functions::inst_vel() +
                        std::sqrt(Functions::inst_vel()*Functions::inst_vel() - (4*Functions::acceleration()*Functions::distance()*-1));
                float tempNegative = -Functions::inst_vel() -
                        std::sqrt(Functions::inst_vel()*Functions::inst_vel() - (4*Functions::acceleration()*Functions::distance()*-1));
                float ansPositive = tempPositive/(2*Functions::acceleration());
                float ansNegative = tempNegative/(2*Functions::distance());
                if (ansPositive > 0){
                    return ansPositive;
                }else if (ansNegative > 0){
                    return ansNegative;
                }
            }else if (Functions::tester[1].length() > 0 || (Functions::tester[2].length() > 0 && Functions::tester[3].length() > 0)){
                return Functions::distance()/Functions::avg_vel();
            }else{
                std::cout << "there is not enough information!!" << std::endl;
            }
        }
        return 0;
    }
}

float Functions::inst_vel() {
    if (Functions::tester[2].length() > 0){
        return Functions::values[2];
    }else {
        if (Functions::tester[4].length() > 0 && Functions::tester[0].length() > 0 &&
            Functions::tester[5].length() > 0 && Functions::tester[4] != "0") {
            float temp = (float) (0.5 * Functions::acceleration() * std::pow(Functions::time(), 2));
            temp = Functions::distance() - temp;
            return temp / Functions::time();
        } else if (Functions::tester[4].length() > 0 && Functions::tester[3].length() > 0 &&
                Functions::tester[0].length() > 0) {
            float temp = Functions::acceleration() * Functions::time();
            return Functions::final_vel() - temp;
        } else if (Functions::tester[3].length() > 0 && Functions::tester[0].length() > 0 &&
                Functions::tester[5].length() > 0) {
            float temp = std::pow(Functions::final_vel(), 2) - (2*Functions::acceleration()*Functions::distance());
            return std::sqrt(temp);
        }else if (Functions::tester[3].length() > 0 && Functions::tester[4].length() > 0 &&
                Functions::tester[5].length() > 0 && Functions::tester[4] != "0"){
            float temp = Functions::distance()/Functions::time();
            temp *= 2;
            return temp - Functions::final_vel();
        }
        return 0;
    }
}

float Functions::final_vel(){
    if (Functions::tester[3].length() > 0) {
        return Functions::values[3];
    }else {
        if (Functions::tester[0].length() > 0 && Functions::tester[4].length() > 0 &&
                Functions::tester[2].length() > 0){
            return Functions::acceleration()*Functions::time() - Functions::inst_vel();
        }else if (Functions::tester[5].length() > 0 && Functions::tester[4].length() > 0 &&
                Functions::tester[2].length() > 0 && Functions::tester[4] != "0"){
            float temp = Functions::distance()/Functions::time();
            temp *= 2;
            return temp - Functions::inst_vel();
        }else if (Functions::tester[0].length() > 0 && Functions::tester[5].length() > 0 &&
                Functions::tester[2].length() > 0){
            float temp = std::pow(Functions::inst_vel(), 2) + (2*Functions::acceleration()*Functions::distance());
            return std::sqrt(temp);
        }
        return 0;
    }
}