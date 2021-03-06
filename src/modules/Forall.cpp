//@author : GINISTY Valentin
#include "Forall.h"
#include <iostream>
#include <string>

using namespace std;

Forall::Forall(int ind_begin, int ind_end, int step, int imbrication): ind_begin(ind_begin), ind_end(ind_end), step(step), imbrication(imbrication){
    name = "Forall";
}

string operator+ (string s, int i)
{
    return s+to_string(i);
}
string operator+ (string s, double i)
{
    return s+to_string(i);
}
string operator+ (string s, float i)
{
    return s+to_string(i);
}

//forall i in 1..10 (step X)
string Forall::translate() {
    //Temporary solution before refactoring of indices
    string i = "indice_" + to_string(imbrication);
    string res = "for(int "+i+" = "+(ind_begin-1)+"; "+i+" < "+(ind_end-1)+"; "+i+" = "+i+"+"+step+"){";
    res = res + this->left_son->translate();
    res = res + "}";
    return res;
}