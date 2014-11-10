#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> man;

bool comp(const man &a, const man &b) {

  // order by strength desc
  return a.first > b.first ? true : a.first == b.first && a.second > b.second ? true : false;
}

int main() {
  int n;
  cin>>n;
  vector<man> v(n,man());
  for(int i=0;i<n;i++) {
    cin >> v[i].first >> v[i].second;
  }

  sort(v.begin(), v.end(), comp);


  int cnt = 1;
  long long s = v[n - 1].first;
  for(int i = n - 2; i >= 0; i--) {

    if(v[i].second >= s) {
      cnt ++;
      s += v[i].first;
      // we know that if we pick this one will not affect our solution
      // because they are sorted in descending order and the ones above it are only heavier
    }
  }

  cout << cnt << endl;

  return 0;
}
