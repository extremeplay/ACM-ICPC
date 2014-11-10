#include <iostream>
#include <vector>
using namespace std;

const int MAX = 2000000000;

int main() {

  vector<long long> a;
  a.push_back(0);

  for(int i = 1; a.back() <= MAX; i++) {
    a.push_back( a.back() + i * i );
  }

  int n; 
  cin >> n;

  int le = 1, ri = a.size() - 1;

  while(le < ri) {

    int mid = le + (ri - le) / 2;

    if(a[mid] >= n)
      ri = mid;
    else le = mid + 1;
  }

  int r = (le - 1) * le / 2  + (n - 1 - a[le - 1]) / le;
  int c = (n - 1 - a[le - 1]) % le;
  cout << (r + 1) << ' ' << (c + 1) << endl;
}
