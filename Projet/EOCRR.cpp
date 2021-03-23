//
//  EOCRR.cpp
//  Projet
//
//  Created by Youri Semaan on 25/11/2020.
//  Copyright © 2020 Youri Semaan. All rights reserved.
//

#include "EOCRR.hpp"
#define _USE_MATH_DEFINES
#include "math.h"


// Constructors

EOCRR::EOCRR(char t, float a, int b, float c, float d, float e)
{
    type = t;
    K = a;
    N = b;
    S0 = c;
    r = d;
    sigma = e;
}

EOCRR::EOCRR(const EOCRR& source)
{
    type = source.type;
    K = source.K;
    N = source.N;
    S0 = source.S0;
    r = source.r;
    sigma = source.sigma;
}


// Methods

float** EOCRR::CalculPriceIterative()
{
    float h = 0;
    float S = 0;
    float U = exp(sigma);
    float D = exp(-sigma);
    float R = exp(r);
    float q = (R - D) / (U - D);
    int n = N-1;
    float* H = new float[N + 1];            // Vector where values of H(n,i) are going to be stock for one n in 0;N
    float* Htemp = new float[N + 1];        // Vector where values of H(n,i) are going to be stock for one n in 0;N calculate with values of H thanks to CRR
    float** matrix = new float*[N + 1];        // Matrix where all the H(n,i) are going to be stock

    if (type == 'C')        // h() fonction is not the same if the option is a Call or a Put
    {
        for (int i = 0; i <= N; i++)
        {
            S = S0 * pow(1 + U, i) * pow(1 + D, N - i);        // Calcul of S(N,i) for each node i

            if (S - K > 0)
            {
                h = S;
            }
            else
            {
                h = 0;
            }

            H[i] = h;        // We add each values of H for each i at the end we have a vector of length N+1 with the values of H(N,i) for i in 0;N

        }

        matrix[0] = H;        // We add the vector H at the matrix with all the H(n,i) for n in 0;N and i in 0;N (here the first line of the matrix are also the H(N,i))

        while (n >= 0)        // loop finish when all the H(n,i) are calculate
        {
            for (int i2 = 0; i2 <= n; i2++)
            {
                Htemp[i2] = (q * H[i2 + 1] + (1 - q) * H[i2]) / (1 + R);
            }

            matrix[N - n] = Htemp;            // Add the value of H(n,i) for each i in 0;n
            H = Htemp;                        // Reset the value of H to continue the CRR method
            Htemp = new float[N + 1];        // Reset the value of Htemps at vector null to continue the calcul
            n = n - 1;                        // Same for n (thanks to CRR we can calculate H(n-1,i) with the H(n,i) for each i)
        }

        return matrix;

    }


    else
    {
        for (int j = 0; j <= N; j++)
        {
            S = S0 * pow(1 + U, j) * pow(1 + D, N - j);        // Calcul of S(n,j) for each node j

            if (K - S > 0)
            {
                h = S;
            }
            else
            {
                h = 0;
            }

            H[j] = h;        // We add each values of H for each j at the end we have a vector of length N+1 with the values of H(N,j) for j in 0;N

        }

        matrix[0] = H;        // We add the vector H at the matrix with all the H(n,i) for n in 0;N and i in 0;N (here the first line of the matrix are also the H(N,i))

        while (n >= 0)        // loop finish when all the H(n,i) are calculate
        {
            for (int j2 = 0; j2 <= n; j2++)
            {
                Htemp[j2] = (q * H[j2 + 1] + (1 - q) * H[j2]) / (1 + R);
            }

            matrix[N - n] = Htemp;            // Add the value of H(n,i) for each i in 0;n
            H = Htemp;                        // Reset the value of H to continue the CRR method
            Htemp = new float[N + 1];        // Reset the value of Htemps at vector null to continue the calcul
            n = n - 1;                        // Same for n
        }

        return matrix;
    }


}

float EOCRR::CalculPriceClosedForme()
{
    float h = 0;
    float S = 0;
    float H = 0;
    float U = exp(sigma);
    float D = exp(-sigma);
    float R = exp(r);
    float q = (R - D) / (U - D);

    if (type == 'C')        // h() fonction is not the same if the option is a Call or a Put
    {
        for (int i = 0; i <= N; i++)
        {
            S = S0 * pow(1 + U, i) * pow(1 + D, N - i);        // Calcul of S(N,i) for each node i

            if (S - K > 0)
            {
                h = S;
            }
            else
            {
                h = 0;
            }

            H = H + (fact(N) * pow(q, i) * pow(1 - q, N - i) * h) / (fact(i) * fact(N));        // Member of the Sum in the CRR Closed Form formula
        }

        H = H * (1 / pow(1 + R, N));        // Final H thanks to CRR Closed Form

        return H;

    }

    else
    {
        for (int j = 0; j <= N; j++)
        {
            S = S0 * pow(1 + U, j) * pow(1 + D, N - j);        // Calcul of S(N,j) for each node j

            if (K - S > 0)
            {
                h = S;
            }
            else
            {
                h = 0;
            }

            H = H + (fact(N) * pow(q, j) * pow(1 - q, N - j) * h) / (fact(j) * fact(N));        // Member of the Sum in the CRR Closed Form formula
        }

        H = H * (1 / pow(1 + R, N));        // Final H thanks to CRR Closed Form

        return H;

    }


}


// Intermediaries Methods

int EOCRR::fact(int n)
{
    int fact = 1;

    if (n == 0)
    {
        return 1;
    }

    else
    {
        for (int i = 1; i <= n; i++)
        {
            fact = fact * i;
        }

        return fact;
    }
}
