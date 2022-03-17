//Ethan Chang ehc586
//Jason Kim jk46965 
//Ethan Colley ebc742
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool isprime(int n) {
  if (n < 2){
    return false;
  }

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
  int last_number_tested{1};
  int found{0};
public:
  int number_of_primes_found(){
    return found;
  }
  

  int nextprime(){
    while(not isprime(last_number_tested)){
      last_number_tested++;
    }
    found++;
    return last_number_tested++;
  }
};

int main() {
  int evenNum;
  cin >> evenNum;
  primegenerator sequence;
  vector<int> p = {sequence.nextprime()};
  for(int i = 4; i <= evenNum; i = i + 2){
    for (int j = 0; j < p.size(); j++){
      int q = i - p.at(j);
      if (isprime(q)) {
        cout << "The number " << i << " is " << p.at(j) << " + " << q << endl;
	break;
      }
      else {
	p.push_back(sequence.nextprime());
      }
    }
  }

  return 0;
};
