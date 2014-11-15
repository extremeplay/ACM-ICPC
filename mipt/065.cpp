#include <iostream>
#include <vector>
using namespace std;

int main() {

  int N;
  cin >> N;
  vector<int> fi(N + 4,0),se(N + 4,0),th(N + 4,0);
  for(int t = N;t > 0; t--) {
    cin >> fi[t] >>se[t] >> th[t];
  }

  vector<int> dp(N + 4, 0x7FFFFFF);
  dp[0] = 0;
  for(int i = 0; i <= N;i++) {
    dp[i + 3] = min(dp[i + 3], dp[i] + th[i + 3]);
    dp[i + 2] = min(dp[i + 2], dp[i] + se[i + 2]);
    dp[i + 1] = min(dp[i + 1], dp[i] + fi[i + 1]);
  }

  cout << dp[N] << endl;
}
