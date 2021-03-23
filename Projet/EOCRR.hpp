//
//  EOCRR.hpp
//  Projet
//
//  Created by Youri Semaan on 25/11/2020.
//  Copyright © 2020 Youri Semaan. All rights reserved.
//

#ifndef EOCRR_hpp
#define EOCRR_hpp
#pragma once
#include <stdio.h>
#include <iostream>

class EOCRR
{
public:

    // Constructors

    EOCRR(char, float, int, float, float, float);                // Constructor
    EOCRR(const EOCRR&);                                        // Copy Constructor

    //Methods

    float** CalculPriceIterative();    // The idea with this method is to return a matrix N+1*N+1 whith all the H(n,i)
                                    //values of the element where number of the row > number of the line will be by default 0 because H(n,i) with i > n is impossible

    float CalculPriceClosedForme();

private:
    char type;            // Call or Put (C or P)
    float K;            // Strike price
    int N;                // Expiry Date (Here the expiry Date correspond to the number of steps so the time deltaT between two steps = 1)
    float S0;            // Underlaying Price
    float r;            // Interest rate
    float sigma;        // Volatility

    // Private Methods

    int fact(int n);



};

#endif /* EOCRR_hpp */
