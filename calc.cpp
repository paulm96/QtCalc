#include "calc.h"

Calc::Calc(double comp1, double comp2, double  (*action)(double, double), bool isDigitOnDisplay, bool isDotUsed) :
    comp1(comp1),
    comp2(comp2),
    action(action),
    isDigitOnDisplay(isDigitOnDisplay),
    isDotUsed(isDotUsed){}

Calc::~Calc(){

}
