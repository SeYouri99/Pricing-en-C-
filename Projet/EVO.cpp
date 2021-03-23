//
//  EVO.cpp
//  Projet
//
//  Created by Youri Semaan on 25/11/2020.
//  Copyright © 2020 Youri Semaan. All rights reserved.
//

#include "EVO.hpp"
#define _USE_MATH_DEFINES
#include "math.h"
#include "random"

// Constructors

EVO::EVO(char type, float K, float T, float S, float r, float sigma)
{
    m_type = type;
    m_K = K;
    m_T = T;
    m_S = S;
    m_r = r;
    m_sigma = sigma;
}

EVO::EVO(const EVO& source)
{
    m_type = source.m_type;
    m_K = source.m_K;
    m_T = source.m_T;
    m_S = source.m_S;
    m_r = source.m_r;
    m_sigma = source.m_sigma;
}

// Intermediaries methods

 /*
float EVO::CalculIntNormal(float x, int n) // The integral has an infinite boundary (-inf) we also use a result known to calculate the value of the integral : N(0) = 0.5
{
    if (x == 0)
    {
        return 0.5;
    }


    else if (x > 0) // Here we cut the integral in two part and sum it (-inf -> 0 sum 0 -> x)
    {
        float I = 0;            // Value of the integral
        float h = x / n;        // step of integration
        float u = 0;
        float Na = 0;            // Initialisation
        float Nb = 0;            // Initialisation

        for (int i = 0; i < n; i = i + 1)    // Calcul of the integral 0 -> x
        {
            Na = (1 / sqrt(2 * M_PI)) * exp(-(u * u) / 2);
            u = u + h;
            Nb = (1 / sqrt(2 * M_PI)) * exp(-(u * u) / 2);
            I = 0.5 * h * (Na + Nb);
        };

        I = 0.5 + I; // Calcul of the final integral with the sum of the two part : -inf -> 0 and 0 -> x

        return I;
    }


    else  // Here we cut the integral in two part and substract it (-inf -> 0 substract x -> 0)
    {
        float I2 = 0;            // Value of the integral
        float h2 = x / n;        // step of integration
        float u2 = x;
        float Na2 = 0;            // Initialisation
        float Nb2 = 0;            // Initialisation

        for (int j = 0; j < n; j = j + 1)    // Calcul of the integral x -> 0
        {
            Na2 = (1 / sqrt(2 * M_PI)) * exp(-(u2 * u2) / 2);
            u2 = u2 + h2;
            Nb2 = (1 / sqrt(2 * M_PI)) * exp(-(u2 * u2) / 2);
            I2 = 0.5 * h2 * (Na2 + Nb2);
        };

        I2 = 0.5 - I2; // Calcul of the final integral with the soustraction of the two part : -inf -> 0 and x -> 0

        return I2;
    }

}
*/

// Standard normal probability density function
double norm_pdf(const double& x) {
    return (1.0/(pow(2*M_PI,0.5)))*exp(-0.5*x*x);
}

// An approximation to the cumulative distribution function for the standard normal distribution Note: This is a recursive function
double norm_cdf(const double& x) {
    double k = 1.0/(1.0 + 0.2316419*x);
    double k_sum = k*(0.319381530 + k*(-0.356563782 + k*(1.781477937 + k*(-1.821255978 + 1.330274429*k))));

    if (x >= 0.0) {
        return (1.0 - (1.0/(pow(2*M_PI,0.5)))*exp(-0.5*x*x) * k_sum);
    } else {
        return 1.0 - norm_cdf(-x);
    }
}



// Calculate the European vanilla call price based on underlying S, strike K, risk-free rate r, volatility of underlying sigma and time to maturity T
double call_price(const double& S, const double& K, const double& r, const double& sigma, const double& T) {
    return S * norm_cdf((log(S / K) + (r + (sigma * sigma) / 2) * T) / (sigma * sqrt(T))-K*exp(-r*T)) * norm_cdf(((log(S / K) + (r + (sigma * sigma) / 2) * T) / (sigma * sqrt(T)))-(sigma * sqrt(T)));
}

// Calculate the European vanilla put price based on underlying S, strike K, risk-free rate r, volatility of underlying sigma and time to maturity T
double put_price(const double& S, const double& K, const double& r, const double& sigma, const double& T) {
    return -S*norm_cdf((log(S / K) + (r + (sigma * sigma) / 2) * T) / (sigma * sqrt(T))-K*exp(-r*T))+K*exp(-r*T) * norm_cdf(((log(S / K) + (r + (sigma * sigma) / 2) * T) / (sigma * sqrt(T)))-(sigma * sqrt(T)));
}

int main(int argc, char **argv) {
    // First we create the parameter list
    double S = 100.0;  // Option price
    double K = 100.0;  // Strike price
    double r = 0.05;   // Risk-free rate (5%)
    double sigma = 0.2;    // Volatility of the underlying (20%)
    double T = 1.0;    // One year until expiry

    // Then we calculate the call/put values
    double call = call_price(S, K, r, sigma, T);
    double put = put_price(S, K, r, sigma, T);

    // Finally we output the parameters and prices
    std::cout << "Underlying:      " << S << std::endl;
    std::cout << "Strike:          " << K << std::endl;
    std::cout << "Risk-Free Rate:  " << r << std::endl;
    std::cout << "Volatility:      " << sigma << std::endl;
    std::cout << "Maturity:        " << T << std::endl;

    std::cout << "Call Price:      " << call << std::endl;
    std::cout << "Put Price:       " << put << std::endl;

    return 0;
}


