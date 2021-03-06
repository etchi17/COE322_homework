//Ethan Chang ehc586
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool isprime(int n) {
  if (n == 2){
    return true;
  }

  for ( int i = 2; i<n; i++) {
    if (n % i == 0){
      return false;
    }
  }
    return true;
};

class primegenerator {
private:
  int last_number_tested{2};
  int found{0};
public:
  int number_of_primes_found(){
    return found;
  }
  

  int nextprime(){
    while(isprime(last_number_tested)==false){
      last_number_tested++;
    }
    found++;
    return last_number_tested++;
  }
};

int main() {
  int nprimes;
  cin >> nprimes;
  primegenerator sequence;
  while (sequence.number_of_primes_found()<nprimes){
    int number = sequence.nextprime();
    cout << "Number " << number << " is prime" << endl;
  }
  return 0;
};
