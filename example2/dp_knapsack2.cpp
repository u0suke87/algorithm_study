// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_C&lang=jp
// 例題2-3-3 個数制限なしナップサック問題 https://qiita.com/drken/items/e77685614f3c6bf86f44
#include<iostream>
#include<utility>
using namespace std;
typedef pair<int, int> P;

int main(void){
  int n,w; cin>>n>>w;
  P item[n];
  for(int i=0; i<n; ++i){
    int v,weight; cin>>v>>weight;
    item[i] = P(v,weight);
  }
  int dp[n+1][w+1];
  for(int i=0; i<=w; ++i) dp[0][i]=0;
  for(int i=0; i<n; ++i){
    for(int j=0; j<=w; ++j){
      if( j<item[i].second){
        dp[i+1][j] = dp[i][j];
      }
      else{
        dp[i+1][j] = max(dp[i+1][j-item[i].second] + item[i].first, dp[i][j]);
      }
    }
  }
  cout << dp[n][w] << endl;
  return 0;
}
