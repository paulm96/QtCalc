#include "functions.h"

double add(double a, double b){
    return a+b;
}

double subtract(double a, double b){
    return a-b;
}

double multiply(double a, double b){
    return a*b;
}

double divide(double a, double b){    //tutaj powinno wyrzucic wyjatek
    return b == 0 ? 0 : a/b;
}
