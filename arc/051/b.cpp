#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
typedef long long ll;
typedef vector<pii> vpii;

/*
    fibonacchi
    a0 = 0
    a1 = 1
    an = an-1 + an-2
    a0 a1 a2 a3 a4 a5 a6
    0  1  1  2  3  5  8
*/
int dp[50],k,a,b;
int fib(int n){
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = (fib(n-1) + fib(n-2));
}

int solve(){
    cout << fib(k) << " " << fib(k+1) << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    memset(dp,-1,sizeof(dp));

    cin >> k;
    solve();
}
