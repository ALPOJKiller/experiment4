#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
bool is_prime(unsigned n) {
        if(n == 2 || n == 3)
                return true;
        //性质：素数都在6n的两侧
        if(n <= 1 || (n % 6 != 1 && n % 6 != 5)) {
                return false;
        }
        for(unsigned i=2;i*i<=n;++i) {
            if(n % i == 0) {
                return false;
            }
        }
        return true;
}
vector<unsigned> combinations(vector<unsigned>::iterator bg,vector<unsigned>::iterator ed,unsigned k) {
	vector<unsigned> result;
  if(k == 1) {
    for(auto it = bg;it != ed;++it) {
      result.push_back(*it);
    }
  } else if(ed-bg == k) {
		result.push_back(accumulate(bg,ed,0U));
	} else {
		for(auto it = bg;it != ed - k + 1;++it) {
			for(auto vk_1:combinations(it+1,ed,k-1)) {
				result.push_back(*it + vk_1);
			}
		}
	}
	return result;
}
vector<unsigned> combinations(vector<unsigned>& src,unsigned k) {
	return combinations(src.begin(),src.end(),k);
}
int main() {
    unsigned n,k;
		vector<unsigned> v;
    cin >> n >> k;
    for(unsigned i=0;i<n;++i) {
      unsigned num;
      cin >> num;
      v.push_back(num);
    }
		auto r = combinations(v,k);
    unsigned result=0;
		for(auto ele:r) {
      if(is_prime(ele))
			   ++ result;
		}
    cout << result;
		return 0;
}
