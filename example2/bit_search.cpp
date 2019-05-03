//https://arc061.contest.atcoder.jp/tasks/arc061_a
//例題2-1-1 部分和 bit全探索 https://qiita.com/drken/items/e77685614f3c6bf86f44

#include<iostream>

using namespace std;
typedef long long ll;

int main(void){
  string s; cin>>s;
  ll sum = 0;
  ll tmp;
  for(int bit=0; bit < (1<<(s.length()-1)); ++bit){
    tmp = (int)(s[0] -'0');
    for(int i=0; i<s.length()-1; ++i){
      if( bit & (1 << i) ){
        sum += tmp; tmp = (int)(s[i+1] - '0');
      }
      else tmp = 10*tmp + (int)(s[i+1] - '0');
    }
    sum += tmp;
  }
  cout << sum << endl;
  return 0;
}
