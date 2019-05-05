// https://atcoder.jp/contests/arc006/tasks/arc006_3
// 例題2-2-4 「交換しても悪くない」Greedy https://qiita.com/drken/items/e77685614f3c6bf86f44
#include<iostream>
#include<vector>
using namespace std;

int main(void){
  int n; cin>>n;
  vector<int> w(n);
  for(int i=0; i<n; ++i) cin>>w[i];
  vector<bool> piled(n, false);
  int ret = 0;
  for(int i=0; i<n; ++i){
    if( !piled[i]){
      int tmp_w = w[i]; piled[i] = true;
      for(int j=i+1; j<n; ++j){
        if( tmp_w >= w[j] && !piled[j]){
          tmp_w = w[j]; piled[j] = true;
        }
      }
      ret++;
    }
  }
  cout << ret << endl;
  return 0;
}
