#include <iostream>
using namespace std;

bool isPossible1(int x,int y, int k) {
  //  # go south
  int xx = x;
  if (xx % k > 1)
    return false;


  int yy = y;
  if (xx % k == 0)
    yy = y - 1;

  //  # go east
  if (yy % k > 1)
    return false;

  xx = x;
  if (yy % k == 0)
    xx = x - 1;

  //  # go north
  if (xx % k > 1)
    return false;


  yy = y;
  if (xx % k == 0)
    yy = y - 1;

  //  # go west
  if (yy % k != 1)
    return false;
  return true;
}

bool isPossible2(int x, int y, int k) {

  //  # go east
  int yy = y;
  if (yy % k > 1)
    return false;

  int xx = x;
  if (yy % k == 0)
    xx = x - 1;

  //  # go south
  if (xx % k > 1)
    return false;

  yy = y;
  if (xx % k == 0)
    yy = y - 1;

  //  # go west
  if (yy % k > 1)
    return false;

  xx = x;
  if (yy % k == 0)
    xx = x - 1;

  //  # go north
  if (xx % k != 1)
    return false;
  return true;
}

int main() {

  int x,y,n,t;
  cin>>x>>y>>n;
  while(n--) {
    cin>>t;
    if(t == 1 || isPossible1(x,y,t) || isPossible2(x,y,t)) {
      cout <<"YES" << endl;
    }
    else cout << "NO" << endl;
  }
  return 0;

}
