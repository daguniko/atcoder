#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
typedef long long ll;
typedef vector<pii> vpii;


char c[8][8];
int n,m;

bool is_ok(int x, int y){
  // tate yoko
  for (int i = 0; i < 8; ++i)
  {
    if (c[i][y] == 'Q' and i != x) return false;
    if (c[x][i] == 'Q' and i != y) return false;
  }

  // 左上
  m = x;
  n = y;
  while(m > 0 and n > 0){
    if (c[--m][--n]  == 'Q') return false;
  }
  m = x;
  n = y;
  // 右下
  while(7 > m and 7 > n){
    if (c[++m][++n]  == 'Q') return false;
  }
  m = x;
  n = y;
  // 右上
  while(0 < m and  n < 7){
    if (c[--m][++n]  == 'Q') return false;
  }
  m = x;
  n = y;
  // 左下
  while(m < 7 and n > 0){
    if (c[++m][--n]  == 'Q') return false;
  }

  return true;
}


bool solve(int x){
  if (x == 8) return true;
  for (int i = 0; i < 8; ++i)
  {
    if (c[i][x] == 'Q'){
        if (solve(x + 1)) return true;
    } else{
        if (is_ok(i,x)){
              c[i][x] = 'Q';
              if (solve(x+1)) return true;
              c[i][x] = '.';
        }
    }
  }

  return false;
}



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            cin >> c[i][j];
        }
    }

    // check initial state
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
              if (c[i][j] == 'Q' and !is_ok(i,j)){
              cout << "No Answer" << endl;
              return 0;
            }
        }
    }

    if (solve(0)){
      for (int i = 0; i < 8; ++i)
      {
          for (int j = 0; j < 8; ++j)
          {
              cout << c[i][j];
          }
          cout << endl;
      }
    } else{
      cout << "No Answer" << endl;
    }
}
