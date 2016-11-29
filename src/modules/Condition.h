//@author : GINISTY Valentin
#ifndef CONDITION_H
#define CONDITION_H

#include <string>
#include "Node.h"

using namespace std;

//boolean value (used in the loop)
class Condition :
        public Node {
protected:
    vector<string> conds;
public:
    Condition();

    std::string translate();

};

#endif