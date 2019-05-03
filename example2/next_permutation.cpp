//https://atcoder.jp/contests/abc054/tasks/abc054_c
//例題2-1-4 n!通りの全探索 https://qiita.com/drken/items/e77685614f3c6bf86f44
#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

typedef pair<int, int> P;

int main(){
  int n,m; cin >> n >> m;
  vector<P> edge(m);
  vector<int> node;
  for(int i=0; i<m; ++i){
    int a,b; cin>>a>>b;
    edge[i] = P(a,b);
  }
  for(int i=2; i<=n; ++i) node.push_back(i);
  long sum=0;
  bool failed;
  do{
    int cur = 1;
    for(vector<int>::iterator itr=node.begin(); itr!=node.end(); ++itr){
      failed = true;
      for(int i=0; i<m; ++i){
        if(edge[i].first == cur){
          if(edge[i].second == *itr){
            cur = *itr; failed = false; break;
          }
        }
        if(edge[i].second == cur){
          if(edge[i].first == *itr){
            cur = *itr; failed = false; break;
          }
        }
      }
      if(failed) break;
    }
    if(!failed) sum++;
  }while(next_permutation(node.begin(), node.end()));

  cout << sum << endl;
  return 0;
}
