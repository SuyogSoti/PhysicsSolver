//
// Created by suyog on 2/24/16.
//

#ifndef PHYSICS_FUNCTIONS_H
#define PHYSICS_FUNCTIONS_H


class Functions {
private:
    int question;
    /**
     * the point of the test to see if it is null or not!!
     */
    std::vector<std::string> tester;
    std::vector<float> values;
    /**
     * this function is for the distance... should not be changed
     */
    float acceleration(), avg_vel(), inst_vel(), final_vel(), time(), distance();
public:
    Functions(int question, std::vector<std::string> v);
    float getAnswer();
};


#endif //PHYSICS_FUNCTIONS_H
