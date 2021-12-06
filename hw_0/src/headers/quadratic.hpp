#pragma once 

enum RETURN_QUAD 
{
    SUCCESS,
    ERROR_ZERO_DIVISION
};

RETURN_QUAD quadratic(const double a, const double b, const double c);
