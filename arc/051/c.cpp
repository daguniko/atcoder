#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(g) (g).begin(),(g).end()
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define F(i,j,k) fill(i[0],i[0]+j*j,k)
#define P(p) cout<<(p)<<endl;
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define INF 1<<25
#define MOD 1e9+7
#define pb push_back
#define mp make_pair
#define trace(x) (cerr << "\033[31m" << #x << ": " << (x) << "\033[39m" << endl)

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
typedef long long ll;
typedef vector<pii> vpii;
// function //
template<class T> T gcd(T a,T b)
{
    if(a<0) return gcd(-a,b);
    if(b<0)return gcd(a,-b);
    return (b==0)?a:gcd(b,a%b);
}
template <class T> T lcm(T a,T b)
{
    return a*(b/gcd(a,b));
}
template<class T> inline vector<pair<T,int> > factorize(T n)
{
    vector<pair<T,int> > R;
    for (T i=2; n>1;)
    {
        if (n%i==0)
        {
            int C=0;
            for (; n%i==0; C++,n/=i);
            R.push_back(make_pair(i,C));
        }
        i++;
        if (i>n/i) i=n;
    }
    if (n>1) R.push_back(make_pair(n,1));
    return R;
}
template<class T> inline bool isPrimeNumber(T n)
{
    if(n<=1)return false;
    for (T i=2; i*i<=n; i++) if (n%i==0) return false;
    return true;
}
template<class T> inline T eularFunction(T n)
{
    vector<pair<T,int> > R=factorize(n);
    T r=n;
    for (int i=0; i<R.size(); i++)r=r/R[i].first*(R[i].first-1);
    return r;
}
template<class T> string toString(T n)
{
    ostringstream ost;
    ost<<n;
    ost.flush();
    return ost.str();
}
int toInt(string s)
{
    int r=0;
    istringstream sin(s);
    sin>>r;
    return r;
}

// ostream //
// pair
template<typename T1, typename T2> ostream& operator<<(ostream& s, const pair<T1, T2>& p) {return s << "(" << p.first << ", " << p.second << ")";}
// vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
    int len = v.size();
    for (int i = 0; i < len; ++i) {
        s << v[i]; if (i < len - 1) s << " ";
    }
    return s;
}

// 2 dimentional array
template< typename T, size_t N, size_t M >
void printArray( T(&theArray)[N][M]  ) {
    for ( int x = 0; x < N; x ++ ) {
        for ( int y = 0; y < M; y++ ) {
            cout << theArray[x][y] << " ";
        }
    }
}

// 2 dimentional vector
template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv) {
    int len = vv.size();
    for (int i = 0; i < len; ++i) {
        s << vv[i] << endl;
    }
    return s;
}
// map
template<typename T1, typename T2> ostream& operator<<(ostream& s, const map<T1, T2>& m) {
    s << "{" << endl;
    for (auto itr = m.begin(); itr != m.end(); ++itr) {
        s << "\t" << (*itr).first << " : " << (*itr).second << endl;
    }
    s << "}" << endl;
    return s;
}

/* input example start
input example end */

const int MAX_N = INF;
ll N,A,B;
ll a[60];
const ll mod = 1e9 + 7;

ll mpow(ll n,ll m){
    n%=mod;
    ll ret=1;
    while(m){
        if(m&1)ret=ret*n%mod;
        n=n*n%mod;
        m>>=1;
    }
    return ret;
}



void solve(){
    if (A == 1){
        for (int i = 0; i < N; ++i) cout << a[i] << endl;
        exit(0);
    }
    while(B && (a[N-1]+a[0]-1)/a[0]>A){
        a[0] *= A;
        sort(a,a+N);
        B--;
    }
    for (int i = 0; i < N; ++i) a[i]=a[i] % mod * mpow(A,B/N) % mod;
    for (int i = 0; i < B%N; ++i) a[i]=a[i] * A % mod;
    for (int i = B%N; i < N; ++i)
    {
        cout << a[i] << endl;
    }
    for (int i = 0; i < B%N; ++i)
    {
        cout << a[i] << endl;
    }

}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> A >> B;
    for (int i = 0; i < N; ++i) cin >> a[i];
    sort(a,a+N);
    solve();
    return 0;
}
















