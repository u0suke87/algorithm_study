// https://atcoder.jp/contests/maximum-cup-2018/tasks/maximum_cup_2018_d
// 例題2-3-5 個数制限付き部分和問題 https://qiita.com/drken/items/e77685614f3c6bf86f44
#include<iostream>
#include<vector>
using namespace std;

int main(void){
  int n,m,l,x; cin>>n>>m>>l>>x;
  int a[n];
  for(int i=0; i<n; ++i) cin>>a[i];
  vector<vector<int> > dp(n+1, vector<int>(m, 0));
  dp[0][0] = 1;
  for(int i=0; i<n; ++i){
    for(int j=0; j<m; ++j){
      if( dp[i][j] > 0){
        dp[i+1][j] = dp[i][j];
      }
    }
    for(int j=0; j<m; ++j){
      if( dp[i][j] > 0){
        if( dp[i+1][(j+a[i])%m] == 0){
          dp[i+1][(j+a[i])%m] = dp[i][j] + (j+a[i])/m;
        }
        else dp[i+1][(j+a[i])%m] = min( dp[i+1][(j+a[i])%m], dp[i][j] + (j+a[i])/m);
      }
    }
  }
  if( dp[n][l] < x && dp[n][l]>0) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
