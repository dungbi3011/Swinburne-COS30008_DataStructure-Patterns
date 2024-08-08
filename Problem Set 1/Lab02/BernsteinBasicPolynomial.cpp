#pragma once 
#include <iostream>
#include <cmath>
#include "Combination.cpp" 

using namespace std;

class BernsteinBasisPolynomial
{
private:
    unsigned int fN;
    unsigned int fV;
public:

    // constructor for b(v,n) with defaults 
    BernsteinBasisPolynomial(unsigned int aN, unsigned int aV) {
        fN = aN;
        fV = aV;
    }

    // call operator to calculate Berstein base 
    // polynomial for a given x (i.e., aX) 
    double Operator2(double x) const {
        double result;
        Combination factor(fN, fV);
        result = factor.Operator1() * pow(x, fV) * pow((1 - x), (fN - fV));
        return result;
    }
};


