#ifndef CALC_H
#define CALC_H


class Calc
{
public:
    explicit Calc(double comp1 = 0, double comp2 = 0,
                        double (*action)(double, double) = 0,
                        bool isDigitOnDisplay = false);
    ~Calc();
    double comp1;
    double comp2;
    double (*action)(double, double);
    bool isDigitOnDisplay;
    double memory;
};

#endif // CALC_H
