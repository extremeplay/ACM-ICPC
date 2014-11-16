#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 10000;
const int oo = 0x7FFFFFFF;
int dist[2 * MAX + 1], tori[2 * MAX + 1], tole[2 * MAX + 1];

// this does NOT construct vertex-disjoint paths
bool BFS( vector< vector<int> > & G, int L, int R) {

  queue<int> Q;
  
  for(int i = 0; i <= 2 * MAX; i++) {
    dist[i] = oo;
  }

  for(int i = 1; i <= L; i++) {
    if(tori[i] == 0) {
      dist[i] = 0;
      Q.push(i);
    }
  }

  int u,v;
  while(!Q.empty()) {
    u = Q.front();
    Q.pop();
    
    if(dist[u] == dist[0])
      continue;

    for(int i = 0; i < G[u].size(); i++) {
      v = G[u][i];
      if(dist[tole[v]] == oo) {
        dist[tole[v]] = dist[u] + 1;
        Q.push(tole[v]);
      }
    }
  }

  return dist[0] != oo;
}

bool DFS(vector< vector<int> > & G, int k) {

  if(k == 0) {
    return true;
  }
  else {

    int v;
    bool found = false;
    for(int i = 0; i < G[k].size(); i++) {
      v = G[k][i];
      if(dist[tole[v]] == dist[k] + 1 && DFS(G, tole[v])) {
	tole[v] = k;
	tori[k] = v;
	found = true;
	break;
      }
    }
    dist[k] = oo;
    return found;

  }
}

void hopcroftKarp( vector< vector<int> > & G, int L, int R) {

  while(BFS(G, L, R)) {
    for(int i = 1; i <= L; i++) {
      if(tori[i] == 0) {
        DFS(G, i);
      }
    }
  }

  int cnt = 0;
  for(int i = 1; i <= L; i++) {
    if (tori[i] != 0)
      cnt ++;
  }
  cout << cnt << endl;
  for(int i = 1; i <= L; i++) {

    if(tori[i] != 0) {

      cout << i << ' ' <<  tori[i] - L << endl;
    }
  }
}

int main() {

  int L,R,C,u,v;
  cin>>L>>R>>C;
  vector< vector<int> > G(L + R + 1);
  while(C--) {
    cin >> u >> v;
    G[u].push_back(v + L);
    G[v + L].push_back(u);
  }

  hopcroftKarp(G, L, R);
  return 0;
}
