// https://atcoder.jp/contests/abc006/tasks/abc006_4
// 例題2-3-6 最長増加部分列問題 https://qiita.com/drken/items/e77685614f3c6bf86f44
#include<iostream>
#include<algorithm>
using namespace std;

int const INF = 10e5;

int main(void){
  int n; cin>>n;
  int c[n];
  for(int i=0; i<n; ++i) cin>>c[i];
  int dp[n];
  for(int i=0; i<n; ++i) dp[i] = INF;
  for(int i=0; i<n; ++i){
    *lower_bound(dp, dp+n, c[i]) = c[i];
  }
  cout << n - (lower_bound(dp, dp+n, INF)-dp) << endl;
  return 0;
}
