//https://atcoder.jp/contests/abc007/tasks/abc007_3
//例題2-1-3 bfs https://qiita.com/drken/items/e77685614f3c6bf86f44
#include<iostream>
#include<queue>
#include<utility>
using namespace std;

typedef pair<int, int> P;
const int INF = 1e6;

char m[50][50];
int d[50][50];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int sy, int sx, int h, int w){
  queue<P> q;
  q.push(P(sy,sx));
  while( !q.empty()){
    P cur;
    cur = q.front();
    q.pop();
    for(int i=0; i<4; ++i){
      int ny = cur.first + dy[i], nx = cur.second + dx[i];
      if( nx >=0 && nx < w && ny >= 0 && ny < h && d[ny][nx] == INF && m[ny][nx] == '.'){
        d[ny][nx] = d[cur.first][cur.second] + 1;
        q.push(P(ny,nx));
      }
    }
  }
}
int main(void){
  int r,c; cin >> r >> c;
  int sy,sx,gy,gx; cin >> sy >> sx >> gy >> gx;
  for(int i=0; i<r; ++i){
    for(int j=0; j<c; ++j){
      cin >> m[i][j];
      d[i][j] = INF;
    }
  }
  d[sy-1][sx-1] = 0;
  bfs(sy-1,sx-1,r,c);
  cout << d[gy-1][gx-1] << endl;
  return 0;
}
