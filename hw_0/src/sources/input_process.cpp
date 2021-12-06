#include "input_process.hpp"

#include <iostream>
#include <limits>

static constexpr int64_t MIN_LIMITS{std::numeric_limits<int>::min()};
static constexpr int64_t MAX_LIMITS{std::numeric_limits<int>::max()};

static bool check_inputs(const double coeff, std::istream &is) {

  if (std::cin.fail()) {
    is.clear();
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Coefficients must be defined as a number." << std::endl;
    return false;
  }

  if (coeff < MIN_LIMITS || coeff > MAX_LIMITS) {
    std ::cout << "Coefficients must be defined from " << MIN_LIMITS << " to "
               << MAX_LIMITS << std ::endl;
    return false;
  }
  return true;
}

void input_process(double &a, double &b, double &c) {
  std ::cout
      << "This simple program solves quadratic equations ax^2 + bx + c = 0. "
         "The roots displays with precision 16 numbers after point. "
         "Coefficients must be NUMBERS defined from "
      << MIN_LIMITS << " to " << MAX_LIMITS << std ::endl;

  bool inputs_status{false};
  do {
    std ::cout << "Please enter coefficient a = ";
    std ::cin >> a;
    inputs_status = check_inputs(a, std::cin);
    if (a == 0 && inputs_status) {
      std ::cout << "Coefficient a can not be equal to 0" << std ::endl;
    }

  } while (a == 0 || !inputs_status);

  do {
    std ::cout << "Please enter coefficient b = ";
    std ::cin >> b;
    inputs_status = check_inputs(b, std::cin);
  } while (!inputs_status);

  do {
    std ::cout << "Please enter coefficient c = ";
    std ::cin >> c;
    inputs_status = check_inputs(c, std::cin);
  } while (!inputs_status);
}
