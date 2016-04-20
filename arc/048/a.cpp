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

int a, b;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> a >> b;
    if (a < 0 and 0 < b) cout << b-a-1 << endl;
    else cout << b-a << endl;
}