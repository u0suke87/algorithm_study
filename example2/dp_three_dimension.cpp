// https://indeednow-finala-open.contest.atcoder.jp/tasks/indeednow_2015_finala_c
// 例題2-3-2 3次元ナップサック 
#include<iostream>
using namespace std;

int main(void){
  int n,m; cin>>n>>m;
  int dp[101][101][101];
  for(int s=0; s<=100; ++s){
    for(int t=0; t<=100; ++t){
      for(int u=0; u<=100; ++u){
        dp[s][t][u] = 0;
      }
    }
  }
  for(int i=0; i<n; ++i){
    int a,b,c,w; cin>>a>>b>>c>>w;
		//tips) 一度a,b,c,wをコンテナに格納し、wの降順にソートすれば値の代入は101^3に抑えられる。
    for(int s=a; s<=100; ++s){
      for(int t=b; t<=100; ++t){
        for(int u=c; u<=100; ++u){
          if( dp[s][t][u] < w) dp[s][t][u] = w;
          else break;
        }
      }
    }
  }
  for(int i=0; i<m; ++i){
    int x,y,z; cin>>x>>y>>z;
    cout << dp[x][y][z] << endl;
  }
  return 0;
}
