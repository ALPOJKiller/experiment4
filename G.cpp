#include <iostream>
#include <map>
using namespace std;
map<unsigned,map<unsigned,unsigned> > buffer;
unsigned divide_count(unsigned n,unsigned less_than) {
  if(less_than > n)
    less_than = n;
  if(n == 1 || less_than== 1) {
    return 1;
  }
  if(buffer.find(n) != buffer.end() && buffer[n].find(less_than) != buffer[n].end()) {
    return buffer[n][less_than];
  }
  if(n == less_than)
    buffer[n][less_than] = 1;
  for(unsigned i=1;i<=less_than;++i)
    if(n-i != 0)
      buffer[n][less_than] += divide_count(n-i,i);
  return buffer[n][less_than];
}
int main() {
  unsigned n;
  while (cin >> n) {
    cout << divide_count(n,n) << endl;
  }
  return 0;
}


