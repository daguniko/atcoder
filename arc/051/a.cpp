#include <bits/stdc++.h>
using namespace std;

#define all(g) (g).begin(),(g).end()
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define F(i,j,k) fill(i[0],i[0]+j*j,k)
#define P(p) cout<<(p)<<endl;
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define INF 1<<25
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

int x_1, y_1, r, x_2, y_2, x_3, y_3;

bool is_include(int x, int y){
    return pow(abs(x_1 - x),2) + pow(abs(y_1 - y),2) <= pow(r,2);
}

void solve(){
    bool red,blue;

    // red judge
    if (x_2<=(x_1-r) and (x_1+r)<=x_3 and y_2<=(y_1-r) and (y_1+r)<=y_3) red = false;
    else red = true;

    // blue judge
    if (is_include(x_2,y_3) and is_include(x_2,y_2) and is_include(x_3,y_3) and is_include(x_3, y_2)) blue = false;
    else blue = true;

    if (red) cout << "YES" << endl;
    else cout << "NO" << endl;
    if (blue) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> x_1 >> y_1 >> r;
    cin >> x_2 >> y_2 >> x_3 >> y_3;

    solve();
    return 0;
}
















