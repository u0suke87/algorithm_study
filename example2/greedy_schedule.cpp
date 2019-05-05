//https://atcoder.jp/contests/abc103/tasks/abc103_d
//例題2-2-2 区間スケジューリング問題 https://qiita.com/drken/items/e77685614f3c6bf86f44
#include<iostream>
#include<vector>
#include<utility>
#include<set>
#include<algorithm>
using namespace std;

typedef pair<int,int> P;
int main(){
  int n,m; cin>>n>>m;
  vector<P> v;
  for(int i=0; i<m; ++i){
    int a,b; cin>>a>>b;
    v.push_back(P(b-1,a-1));
  }
  sort(v.begin(), v.end());
  set<int> remove_bridge;
  int ret=0;
  for(int i=0; i<m; i++){
    bool meet_needs =false;
    for(set<int>::iterator it=remove_bridge.begin(); it != remove_bridge.end(); ++it){
      if( *it >= v[i].second && *it+1 <= v[i].first){
        meet_needs = true; break;
      }
    }
    if( meet_needs) continue;
    else{
      remove_bridge.insert(v[i].first-1);
      ++ret;
    }
  }
  cout<<ret<<endl;
  return 0;
}
