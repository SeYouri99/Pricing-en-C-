//
//  EVO.hpp
//  Projet
//
//  Created by Youri Semaan on 25/11/2020.
//  Copyright © 2020 Youri Semaan. All rights reserved.
//

#ifndef EVO_hpp
#define EVO_hpp

#include <stdio.h>
#pragma once
#include <iostream>

class EVO
{
public:

    // Constructors
    
    EVO(char, float, float, float, float, float);       //  Constructor
    EVO(const EVO&);                                    // Copy Constructor
    
    //Methods

    void CalculPriceandDelta();     // Calcul of price and Delta of the EVO

private:
    char m_type;            // Call or Put (C or P)
    float m_K;            // Strike price
    float m_T;            // Expiry Date
    float m_S;            // Underlaying price
    float m_r;            // Interest rate
    float m_sigma;        // Volatility

    // private Methods
    float Norm_cdf(double);               // An approximation to the cumulative distribution function for the standard normal distribution
    float CalculIntNormal(float,int);            // Calcul of integral of Noarmal law for Black-Scholes formula

};
#endif /* EVO_hpp */
