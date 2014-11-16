#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void swap(vector<int> &a, int le, int ri) {

  int tmp = a[le];
  a[le] = a[ri];
  a[ri] = tmp;
}

int kth_elem(vector<int> & a, int le, int ri, int kth) {

  if(ri > le + 1) {

    int p = le + rand() / (RAND_MAX + 1.0) * (ri - le);

    swap(a, ri - 1, p);

    int k = le;

    for(int i = le;i < ri - 1;i++) {
    
      if(a[i] < a[ri - 1]) {
	swap(a,k++,i);
      }
    }

    swap(a, k, ri - 1);
  
    if(kth ==  k - le + 1)
      return k;
    else if(kth > (k - le + 1))
      return kth_elem(a, k + 1, ri, kth - (k - le + 1));
    else // kth < (k - le + 1)
      return kth_elem(a, le, k, kth);
  }

  else return le;
}

int main() {
  
  srand(666013);

  int N;
  cin >> N;
  vector<int> v(N,0);
  for(int i = 0;i < N;i++) {
    v[i] = i + 1;
  }
  
  int r,t;
  vector<int> s(N,0);
  for(int i = 0; i < N; i++) {

    cin >> r;
    
    if(r <= v.size() - 1 && r >= 0) {
      t = kth_elem(v, 0, v.size(), v.size() - r);
      s[i] = v[t];

      for(int j = t; j < v.size(); j ++) {
	v[j] = v[j + 1];
      }
      v.pop_back();

    }
    else {
      cout << -1 << endl;
      return 0;
    }
  }

  for(int i = 0; i < N; i++) {
    cout << s[i] << ' ';
  }
  cout << endl;

  return 0;
}
