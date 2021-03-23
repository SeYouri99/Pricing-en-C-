//
//  Pricing.hpp
//  Projet
//
//  Created by Youri Semaan on 25/11/2020.
//  Copyright © 2020 Youri Semaan. All rights reserved.
//

#ifndef Pricing_hpp
#define Pricing_hpp
#include "Option.hpp"
#include <stdio.h>

class Pricing
{
public:

    // Constructors
    
    Pricing(float, float, float);       //  Constructor
    Pricing(const Pricing&);
    
    //Methods
    double norm_pdf(const double& );
    double norm_cdf(const double& );
    double call_price(const Option&, const double& S,  const double& r, const double& sigma);
    double put_price(const Option&, const double& S,  const double& r, const double& sigma);
   

private:
    float m_S;            // Underlaying price
    float m_r;            // Interest rate
    float m_sigma;        // Volatility
//    Option *m_option;
    
};

#endif /* Pricing_hpp */
