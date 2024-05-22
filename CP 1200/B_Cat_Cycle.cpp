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
        int n , k ; take2(n,k) ;
        if(n % 2 == 0)
        {
            ll num = (k % n) ;
            if(k % n == 0) give(n) ;
            else give(k%n) ;
        }
        else
        {
            ll diff = n - 2 ;
            ll sub = (diff+1)/2 ;
            ll timeleft = k - sub ;
            if(timeleft <= 0) give(k) ;
            else
            {
                ll num1 = sub , num2 ;
                if(timeleft % sub == 0) num2 = timeleft/sub ;
                else num2 = timeleft/sub + 1 ;
                ll num3 = (k - num1 - num2 ) ;
                num1 = num1 + num3 ;
                ll ans = (num1 + 2*num2) ;
                if(ans % n == 0) give(n) ;
                else give(ans % n) ;
            }
        }
    }
}
