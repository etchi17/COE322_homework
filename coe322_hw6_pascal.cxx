//Ethan Chang ehc586
//Ethan Colley ebc742
//Jason Kim jk46965
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double fact(int num) {
  double fact = 1;
  if (num == 0) {
    return 1;
  }
  else {
    for (int b = 1; b <= num; b++) {
      fact = fact * b;
    }
    return fact;
  }
}

class pascal{
private:
  vector<vector<double>> elements;
public:
  pascal(int n) {
    elements = vector<vector<double>>(n, vector<double>(n));
    for (int a = 0; a < n; a++) {
      for (int c = 0; c <= a; c++) {
	if (c == 0 || c == a) {
	  elements.at(a).at(c) = 1;
	}
	else {
	  elements.at(a).at(c) = (fact(a-1) / (fact(c-1) * fact((a-1) - (c-1)))) + (fact(a - 1) / (fact(c) * fact((a - 1) - (c))));
	}
      }
    }
  }

  int get(int i, int j) {
    return round(elements.at(i).at(j));
  }

  void print() {
    int size = elements.size();
    for (int d = 0; d < size; d++) {
      for (int e = 0; e <= d; e++) {
	cout << elements.at(d).at(e) << " ";
      }
      cout << endl;
    }
  }

  void print(int m) {
    int size = elements.size();
    for (int d = 0; d < size; d++) {
      for (int e = 0; e <= d; e++) {
	if (get(d, e) % m == 0) {
	  cout << " ";
	}
	else {
	  cout << "*";
	}
      }
      cout << endl;
    }
  }
};

int main() {
  int n;
  cout << "Enter number of rows for Pascal's Triangle: " << endl;
  cin >> n;
  pascal vector = pascal(n);
  int m=1;
  cout << "Enter number of modulos: " << endl;
  while (m != 0) {
    cin >> m;
    vector.print(m);
  }
  return 0;
}
