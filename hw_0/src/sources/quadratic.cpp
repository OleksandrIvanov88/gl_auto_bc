#include "quadratic.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <limits>

RETURN_QUAD quadratic(const double a, const double b, const double c)
{
    if(0.0 == a)
    {
        return RETURN_QUAD::ERROR_ZERO_DIVISION;
    }
    constexpr uint8_t FOUR{4};
    constexpr uint8_t TWO{2}; 
    double D{std::pow(b,TWO) - FOUR * a * c};
    double x1 = 0, x2 = 0;
    std::cout << std::setprecision(16); 

    if (D > 0.0)
    {
        x1 = (- b + std::sqrt(D)) / (TWO * a); 
        x2 = (- b - std::sqrt(D)) / (TWO * a);
        if (fabs(x1 - 0.0) < std::numeric_limits<double>::epsilon())
        {
            x1 = 0;
        }
        if (fabs(x2 - 0.0) < std::numeric_limits<double>::epsilon())
        {
            x2 = 0;
        }
        std::cout << "x1 = " << x1 << std :: endl;
        std::cout << "x2 = " << x2 << std :: endl; 
    }
    else if(D < 0.0)
    {
        std::cout << "D < 0. The equation does not have real roots. " << std :: endl; 
    } else 
    {
        x1 = (- b + sqrt(D)) / (TWO * a);
        if(fabs(x1 - 0.0) < std::numeric_limits<double>::epsilon())
        {
              x1 = 0;
        }
        std::cout << "x1 = x2 = " << x1 << std :: endl;  
    }

    return RETURN_QUAD::SUCCESS;
}
