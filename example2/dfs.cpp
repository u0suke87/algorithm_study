//https://atc001.contest.atcoder.jp/tasks/dfs_a
//例題2-1-2 dfs https://qiita.com/drken/items/e77685614f3c6bf86f44  
#include<iostream>

using namespace std;

char m[500][500];
bool is_reached[500][500];

int dx[] = { -1, 0, 1, 0};
int dy[] = { 0, 1, 0, -1};

void dfs(int x, int y, int h, int w){
  for(int dir = 0; dir < 4; ++dir){
    if( y+dy[dir] >=0 && y+dy[dir] < h && x+dx[dir] >=0 && x+dx[dir] < w){
      if( m[y+dy[dir]][x+dx[dir]] == '.' && !is_reached[y+dy[dir]][x+dx[dir]]){
        is_reached[y+dy[dir]][x+dx[dir]] = true;
        dfs(x+dx[dir], y+dy[dir], h, w);
      }
      else if( m[y+dy[dir]][x+dx[dir]] == 'g' && !is_reached[y+dy[dir]][x+dx[dir]]){
        is_reached[y+dy[dir]][x+dx[dir]] = true;
      }
    }
  }
}

int main(void){
  int h,w; cin >> h >> w;
  int sx, sy, gx, gy;
  for(int i=0; i<h; ++i){
    for(int j=0; j<w; ++j){
      cin >> m[i][j]; 
      is_reached[i][j] = false;
      if (m[i][j] == 's'){
        sx = j; sy = i;
        is_reached[i][j] = true;
      }
      if (m[i][j] == 'g'){
        gx = j; gy = i;
      }
    }
  }
  dfs( sx, sy, h, w);
  if( is_reached[gy][gx] == true) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
