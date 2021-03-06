//Ethan Chang ehc586
//Ethan Colley ebc742
//Jason Kim jk46965

#include <iostream>
#include <functional>
#include <cmath>

using namespace std;

double find_zero(function<double(double)>f, function<double(double)>g){
  double x{ 1.};
  while (true) {
    auto fx = f(x);
    // cout << "f( " << x << " ) = " << fx << "\n";
    if (abs(fx) < 1.e-10) break;
    x = x - fx / g(x);
  }
  return x;
}

double newton_root(function<double(double)> f, double h = .001) {
  auto g = [f, h](double x) -> double {return(f(x + h)-f(x))/h;};
  return find_zero(f,g);
}

int main() {
  int n;
  cout << "Input integer: " << endl;
  cin >> n;
  auto f = [n](double x) -> double {return (x * x) - n; };
  cout << "The root of this number is " << newton_root(f) << endl;
  return 0;
  /*
    for (int n = 2; n <= 8; n++) {
    auto f = [n](double x)-> double {return (x * x) - n; };
    auto fprime = [n](double x)-> double {return 2*x; };
    cout << "sqrt(" << n << ") = " << find_zero(f, fprime) << "\n";
    }
  */
}
