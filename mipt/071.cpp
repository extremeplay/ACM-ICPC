#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

long long get(vector<int>& v,int l) {

  long long cnt = 0;
  for(int i = 0;i < v.size();i ++) {

    cnt += v[i] / l;
  }

  return cnt;
}

int main() {

  int n,k;
  cin >> n >> k;
  vector<int> v(n,0);

  for(int i = 0;i < n;i ++) {
    cin >> v[i];
  }

  // see if we have a solution
  if (accumulate(v.begin(), v.end(), 0LL) < k) {
    cout << 0 << endl;
    return 0;
  }
  
  int le = 1;
  int ri = *max_element(v.begin(), v.end());

  while(le < ri) {
    
    int mid = (le + ri + 1) / 2;
    if(get(v,mid) >= k)
      le = mid;
    else ri = mid - 1;
  }
  
  cout << le << endl;

  return 0;
}
