//Ethan Chang - ehc586
//Jason Kim - jk46965

#include <iostream>
#include <iomanip>
#include <vector>
#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp" 

using namespace std;

//exercise 5

//hard coded
vector<double> set_coefficients = {1, 2.5, 3.08, 4.78};

//user input
//vector<double> set_coefficients() {
//int degree;
//cout << "Degree of polynomial?";
//cin >> degree;
//cout << endl;
//
//vector<double> coefficients(degree+1);
//for (int i=0; i<=degree; i++) {
//  cout << "coeff" << i << ": ";
//  cin >> coefficients.at(i);
//}
//cout << endl;
//return coefficients;
//};

//exercise 6
bool proper_polynomial(const vector<double>& coefficients) {
  if (coefficients.size() > 0 and coefficients.front() != 0) {
    return true;
  }
  else {
    return false;
  }
};

//TEST_CASE( "proper test","[2]" ) {
//auto coefficients = set_coefficients;
//REQUIRE( proper_polynomial(coefficients) );
//coefficients.at(0) = 0.;
//REQUIRE( not proper_polynomial(coefficients) );
//vector<double> zeroset;
//REQUIRE( not proper_polynomial(zeroset) );
//}

//exercise 7
double evaluate_at(const vector<double>& coefficients, double x) {
  double y = coefficients[0];
  for (int i = 1; i < coefficients.size(); i++) {
    y = x*y + coefficients[i];
  }
  return y;
};

//exercise 8
bool is_odd(const vector<double>& coefficients) {
  if (coefficients.size() %2 == 0) {
    return true;
  }
  else {
    return false;
  }
};

//exercise 9
void find_outer(const vector<double>& coefficients, double &left, double &right) {
  if (is_odd(coefficients)){
    left = -1;
    right = 1;
    while(evaluate_at(coefficients, left)*evaluate_at(coefficients, right) >= 0) {
      left = left-1;
      right = right+1;
    }
  }
  else {
    throw("even function, cannot find outer");
  }
}

//exercise 10
double find_zero(const vector<double>& coefficients, double left, double right) {
  double left_val = evaluate_at(coefficients, left);
  double right_val = evaluate_at(coefficients, right);
  assert(left_val*right_val <= 0);
  while (abs(left_val)>1.e-8 && abs(right_val)>1.e-8) {
    left = left+1;
    double left_val2 = evaluate_at(coefficients, left);
    if (abs(left_val)<abs(left_val2)){
      left = left-2;
      left_val = evaluate_at(coefficients, left);
      right = right+1;
      right_val = evaluate_at(coefficients, right);
    }
    else {
      left_val = evaluate_at(coefficients, left);
      right = right-1;
      right_val = evaluate_at(coefficients, right);
    }
    assert(left_val*right_val<=0);
  }
  return (left+right)/2;
}
