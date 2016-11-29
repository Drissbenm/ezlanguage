//@author : GINISTY Valentin
#include "Condition.h"
#include <iostream>
//c'est normal que ça marche pas l'include là ?
//#include <boost/algorithm/string/split.hpp>

using namespace std;

//expression conditionnelle
//une condition peut être un appel à une méthode retournant un booléen
//l'appel à une procédure étant le même en C++ et en EZ facilite la tâche
//exemples de conditions :
    //3 < 6
    //chocolat < 7
    //manger(chocolat)
    //true
    //manger(chocolat) and boire(cafe)
    //manger(chocolat) or boire(cafe) and 3 < 6
//séparer la chaîne au niveau des opérateurs "and" et "or"
//séparer les sous-chaînes
//chaque sous chaîne peut être un des cas suivant :
    //booléen direct : true ou false
    //variable de type booléen
    //expression avec un opérateur <= >= < > !=

    //si une sous-chaîne n'est pas dans un de ces cas, alors il y a une erreur
    //reprendre chaque sous-sous-chaîne et les traduire





Condition::Condition() {
}


string Condition::translate() {
    string res = "";

    return res;
}