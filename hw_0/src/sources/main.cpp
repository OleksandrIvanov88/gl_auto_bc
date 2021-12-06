#include <iostream>
#include "input_process.hpp"
#include "quadratic.hpp"

int main()
{
    double a = 0.0, b = 0.0, c = 0.0;
    input_process(a, b, c);
    return quadratic(a, b, c);
}