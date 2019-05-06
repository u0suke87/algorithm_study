// https://atcoder.jp/contests/abc015/tasks/abc015_4
// 例題2-3-1 個数制約付きナップサックDP https://qiita.com/drken/items/e77685614f3c6bf86f44
#include<iostream>
#include<utility>
using namespace std;
typedef pair<int,int> P;

int main(void){
  int w,n,k; cin>>w>>n>>k;
  P s[n];
  for(int i=0; i<n; ++i){
    int a,b; cin>>a>>b;
    s[i] = P(a,b);
  }
  int dp[w+1][k+1];
  for(int j=0; j<=w; ++j){
    for(int t=0; t<=k; ++t){
      dp[j][t] = 0;
    }
  }
  int max = 0;
  for(int i=0; i<n; ++i){
    for(int j=w-s[i].first; j>=0; --j){
      for(int t=0; t<k; ++t){
        if( (dp[j][t]+s[i].second) > dp[j+s[i].first][t+1]){
          dp[j+s[i].first][t+1] = dp[j][t]+s[i].second;
          if( dp[j+s[i].first][t+1] > max) max = dp[j+s[i].first][t+1];
        }
      }
    }
  }
  cout << max << endl;
  return 0;
}
