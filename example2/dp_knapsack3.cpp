// https://arc057.contest.atcoder.jp/tasks/arc057_b
// 例題2-3-4 ナップサック問題(weightが大きく、配列の添字に使用できない場合) https://qiita.com/drken/items/e77685614f3c6bf86f44
// dp[w]:重みw以下での価値の最大値 → dp[v]:価値v以上を達成できる重さの最小値
#include<iostream>
#include<utility>
using namespace std;
typedef long long ll;
const ll INF = 10e9;

int main(void){
  int n; cin>>n;
  ll k; cin>>k;
  ll a[n];
  ll a_sum[n+1];
  a_sum[0]=0;
  for(int i=0; i<n; ++i){
    cin>>a[i];
    a_sum[i+1] = a_sum[i] + a[i];
  }
  if(a_sum[n] == k){
    cout << 1 << endl;
    return 0;
  }
  ll dp[n+1][n+1];
  for(int i=0; i<=n; ++i){
    for(int j=0; j<=n; ++j){
      if( j==0) dp[i][j] = 0;
      else dp[i][j] = INF; 
    }
  }
  for(int i=0; i<n; ++i){
    for(int j=0; j<=i; ++j){
      if( i==0) dp[i+1][j+1] = 1;
      else dp[i+1][j+1] = min(dp[i][j+1], dp[i][j] * a_sum[i+1] / a_sum[i] + 1);
    }
  }
  for(int i=n; i>=0; --i){
    if( dp[n][i] <= k){
      cout << i <<endl;
      break;
    }
  }
  return 0;
}
