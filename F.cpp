#include <iostream>
#include <vector>
using namespace std;
unsigned gcd(unsigned m,unsigned n) {
    if(m == 0) return n;
    return gcd(n % m,m);
}

vector<vector<unsigned> > groups;

void put_into_group(unsigned n) {
  for (auto& group:groups) {
    bool should_in_this_group = true;
    for(auto ele:group) {
      if(gcd(ele,n) != 1) {
        should_in_this_group = false;
        break;
      }
    }
    if(should_in_this_group) {
      group.push_back(n);
      return;
    }
  }
  vector<unsigned> new_group{n};
  groups.push_back(new_group);
}

int main() {
  unsigned n;
  cin >> n;
  for (unsigned i = 0; i < n; ++i) {
    unsigned val;
    cin >> val;
    put_into_group(val);
  }
  cout << groups.size();
  return 0;
}
