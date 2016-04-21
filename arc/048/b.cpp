#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
typedef long long ll;
typedef vector<pii> vpii;
#define reps(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define pb push_back

/*
    input case

*/

int n,r[100100],h[100100];
int c[100100],g[100100],p[100100];
int dp[100100];

void solve(){
    int win,lose,draw;
    rep(i,n) {
        if (h[i] == 1) {
            win = dp[r[i]] + c[r[i]];
            draw = g[r[i]] - 1;
        } else if (h[i] == 2){
            win = dp[r[i]] + p[r[i]];
            draw = c[r[i]] - 1;
        } else if (h[i] == 3){
            win = dp[r[i]] + g[r[i]];
            draw = p[r[i]] - 1;
        }
        lose = (n - 1) - win - draw;
        cout << win << " " << lose << " " << draw << endl;
    }
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    memset(r,0,sizeof(r));
    memset(dp,0,sizeof(dp));

    rep(i,n) {
        cin >> r[i] >> h[i];
        if (h[i] == 1) g[r[i]]+=1;
        if (h[i] == 2) c[r[i]]+=1;
        if (h[i] == 3) p[r[i]]+=1;
    }
    dp[0] = 0;
    reps(i,1,100005) dp[i] = dp[i-1]+g[i-1]+c[i-1]+p[i-1];
    solve();
}