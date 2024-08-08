#pragma once
#include <iostream>
#include <cstddef> 

using namespace std;

class Combination
{
private:
    size_t fN;
    size_t fK;

public:
    Combination(size_t n, size_t k) {
        fN = n;
        fK = k;
    }
    size_t getN() { return fN; }
    size_t getK() { return fK; }



    // call operator to calculate n over k 
    // We do not want to evaluate factorials.  
    // Rather, we use this method 
    //  
    //   n      (n-0)    (n-1)         (n - (k - 1)) 
    // (   ) =  ----- *  ----- * ... * -------------   
    //   k        1        2                 k 
    //  
    // which maps to a simple for-loop over 64-bit values.

public:
    unsigned long long Operator1() {
        long long result = 1;
        for (int i = 1; i <= fK; i++) {
            result = result * (fN - i + 1) / i;
        }
        return result;
    }
};

// write "Combination_name".setN for fN value
// write "Combination_name".setK for fK value


