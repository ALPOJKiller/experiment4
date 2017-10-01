#include <iostream>
#include <vector>
using namespace std;
unsigned gcd(unsigned m,unsigned n) {
    if(m == 0) return n;
    return gcd(n % m,m);
}
unsigned count_proper_fraction(std::vector<unsigned> v) {
  unsigned ret = 0;
  for(auto it=v.begin(); it!=v.end()-1; ++it) {
    for (auto it2 = it + 1; it2 != v.end(); it2++) {
      if(gcd(*it,*it2) == 1)
        ++ret;
    }
  }
  return ret;
}
int main() {
  unsigned n;
  cin >> n;
  vector<unsigned> input;
  for(unsigned i=0;i<n;++i) {
    unsigned val;
    cin >> val;
    input.push_back(val);
  }
  cout << count_proper_fraction(input);
  return 0;
}
