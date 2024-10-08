/* Om Gam Ganapataye Namah */
#include <bits/stdc++.h>
using namespace std;

#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define take(a) cin >> a
#define take2(a, b) cin >> a >> b
#define take3(a, b, c) cin >> a >> b >> c
#define take4(a, b, c, d) cin >> a >> b >> c >> d
#define give(n) cout << n << endl
#define give_(n) cout << n << " "
#define pb push_back
#define sort(v) sort(v.begin(), v.end())
#define ff first
#define ss second
#define repi(a,b) for(int i = a ; i < b ; i++)

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<int> vii;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<ll, ll>> vpll;

ll factorial(ll n)
{
    ll product = 1;
    for (int i = 1; i <= n; i++) product = product * i; return product;
}

bool isprime(int n)
{
    for (int i = 2; i * i <= n; i++){ if (n % i == 0) return true;} return false;
}

ll mod(ll n, ll m)
{ 
    return ((n % m + m) % m);
}

int convertonum(string s)
{
    int num = 0;
    for (int i = 0; i < s.size(); i++){ num = num * 10 + (int(s[i]) - '0');} return num;
}

string tobin(int a)
{
    string binary = ""; int mask = 1;
    for(int i = 0; i < 31; i++)
    {
        if((mask&a) >= 1) binary = "1"+binary;
        else binary = "0"+binary;
        mask<<=1;
    }
    /* cout<<binary<<endl; */ return binary;
}

ll ncr(int n, int r) 
{
    if (r > n || n < 0 || r < 0) return 0;
    
    ll result = 1;
    for (int i = 0; i < r; ++i) 
    {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

string reversestr(std::string& str) 
{
  int len = str.length();
  for (int i = 0; i < len / 2; i++) {
    std::swap(str[i], str[len - i - 1]);
  }
  return str ;
}

ll pow(ll a, ll b)
{
    ll ans = 1;
    while (b > 0) 
    {
        ll ans = (b & 1);
        if (ans)  ans = ans * a;
        a = a * a;
        b = b >> 1;
    }
    return ans;
}

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b) ; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b ; }

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; deb(x); cerr << endl;
#else
#define debug(x)
#endif

//Primitive Data Types
void deb(ll t) {cerr << t;}
void deb(int t) {cerr << t;}
void deb(string t) {cerr << t;}
void deb(char t) {cerr << t;}
void deb(lld t) {cerr << t;}
void deb(double t) {cerr << t;}

//Complex Data Types
template <class T, class V> void deb(pair <T, V> p);
template <class T> void deb(vector <T> v);
template <class T> void deb(set <T> v);
template <class T, class V> void deb(map <T, V> v);
template <class T> void deb(multiset <T> v);
template <class T, class V> void deb(pair <T, V> p) {cerr << "{"; deb(p.first); cerr << ","; deb(p.second); cerr << "}";}
template <class T> void deb(vector <T> v) {cerr << "[ "; for (T i : v) {deb(i); cerr << " ";} cerr << "]";}
template <class T> void deb(set <T> v) {cerr << "[ "; for (T i : v) {deb(i); cerr << " ";} cerr << "]";}
template <class T> void deb(multiset <T> v) {cerr << "[ "; for (T i : v) {deb(i); cerr << " ";} cerr << "]";}
template <class T, class V> void deb(map <T, V> v) {cerr << "[ "; for (auto i : v) {deb(i); cerr << " ";} cerr << "]";}

// cout << fixed <<  setprecision(9) << sum << endl;


int main() 
{
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif

    ll T ; take(T) ;
    while(T--)
    {
        int n ; take(n) ;
        string s ; take(s) ;
        map<char,int> m ;
        repi(0,s.size()) m[s[i]]++ ;
        if((m['N'] + m['S'])%2) no ;
        else if((m['E'] + m['W'])%2) no ;
        else
        {
            if(m['S']==1 && m['N']==1 &&(m['E'] + m['W'] == 0)) no ;
            else if(m['E']==1 && m['W']==1 &&(m['S'] + m['N'] == 0)) no ;
            else
            {
                int vert = (m['N'] - m['S'])/2 ;
                int hori = (m['E'] - m['W'])/2 ;
                int v1 = 0 , h1 = 0 , f1 = 0 ;
                string ans ;
                repi(0,n) ans.pb('*') ;
                for(int i = 0 ; i < n ; i++)
                {
                    debug(i) ;
                    if(v1 == vert && h1 == hori && f1==1) break ;
                    if(s[i]=='N')
                    {
                        if(v1 < vert || f1==0) 
                        {
                            v1++ ;
                            debug(v1) ;
                            ans[i] = 'R' ;
                            f1 = 1 ;
                        }
                    }
                    if(s[i]=='S')
                    {
                        if(v1 > vert || f1==0)
                        {
                            v1--;
                            debug(v1) ;
                            ans[i] = 'R'; 
                            f1 = 1 ;
                        }
                    }
                    if(s[i] == 'E')
                    {
                        if(h1 < hori || f1==0)
                        {
                            h1++ ;
                            debug(h1) ;
                            ans[i] = 'R' ;
                            f1=1 ;
                        }
                    }
                    if(s[i] == 'W')
                    {
                        if(h1 > hori || f1==0)
                        {
                            h1-- ;
                            debug(h1) ;
                            ans[i] = 'R' ;
                            f1=1 ;
                        }
                    }
                    cerr<<endl ;
                }
                debug(ans) ;
                for(int i = 0 ; i < n ; i++)
                {
                    if(ans[i] == '*') ans[i] = 'H' ;
                }
                for(int i = 0 ; i < n ; i++) cout<<ans[i] ;
                cout<<endl ;
            }
        }
    }
}
