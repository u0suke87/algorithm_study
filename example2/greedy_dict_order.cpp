// https://abc076.contest.atcoder.jp/tasks/abc076_c
// 例題2-2-3 辞書順最小 gredy https://qiita.com/drken/items/e77685614f3c6bf86f44
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(void){
  string s,t; cin>>s>>t;
  if( s.length() < t.length()){
    cout << "UNRESTORABLE" << endl;
    return 0;
  }
  // S'文字列に既にtが含まれている場合、?を全てaに置換
  for( int i=(s.length()-t.length()); i>=0; --i){
    bool is_restorable = true;
    for( int j=0; j<t.length(); ++j){
      if( s[i+j] != t[j] ){
        is_restorable = false;
        break;
      }
    }
    if( is_restorable ){
      replace(s.begin(), s.end(), '?', 'a');
      cout << s << endl;
      return 0;
    }
  }
  // S'文字列に既にtが含まれていない場合
  for( int i=(s.length()-t.length()); i>=0; --i){
    bool is_restorable = true;
    for( int j=0; j<t.length(); ++j){
      if( s[i+j] != '?' && s[i+j] != t[j]){
        is_restorable = false;
        break;
      }
    }
    if( is_restorable ){
      for( int j=0; j<t.length(); ++j){
        s[i+j] = t[j];
      }
      replace(s.begin(), s.end(), '?', 'a');
      cout << s << endl;
      return 0;
    }
  }
  cout << "UNRESTORABLE" << endl;
  return 0;
}
