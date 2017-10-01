#include <iostream>
#include <vector>
using namespace std;
unsigned gcd(unsigned m,unsigned n) {
    if(m == 0) return n;
    return gcd(n % m,m);
}
unsigned count_is_double(vector<unsigned> v) {
  unsigned ret = 0;
  for(auto it = v.begin(); it != v.end(); ++it) {
    for (auto it2 = v.begin(); it2 != v.end(); it2++) {
      if(*it2 == 2*(*it)) {
        ++ret;
      }
    }
  }
  return ret;
}
int main() {
  unsigned input_val;
  vector<unsigned> input;
  while(cin >> input_val) {
    if(input_val == 0U)
        break;
    input.push_back(input_val);
  }
  cout << count_is_double(input);
  return 0;
}
