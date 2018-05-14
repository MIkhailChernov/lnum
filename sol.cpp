//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
#define re return
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define sqrt(x) sqrt(abs(x))
#define mp make_pair
#define pi (3.14159265358979323846264338327950288419716939937510)
#define fo(i, n) for(int i = 0; i < n; ++i)
#define ro(i, n) for(int i = n - 1; i >= 0; --i)
#define unique(v) v.resize(unique(all(v)) - v.begin())
 
template <class T> T abs (T x) { re x > 0 ? x : -x; }
template <class T> T sqr (T x) { re x * x; }
template <class T> T gcd (T a, T b) { re a ? gcd (b % a, a) : b; }
template <class T> int sgn (T x) { re x > 0 ? 1 : (x < 0 ? -1 : 0); }
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef double D;
typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef unsigned long long ull;
typedef tree <pair<int, char>, null_type, less<pair<int, char>>, rb_tree_tag, tree_order_statistics_node_update> _tree;
 
map <pair<ii, int>, pair<int, bool>>  table;
const int maxn = 300;
int n;
int h1[maxn], h2[maxn], w1[maxn], w2[maxn];
 
int f (int pos, int _fi, int _se) {
    if (pos == n) re max (_fi, _se);
    if (table.count(mp(mp(pos, _fi), _se))) re table[mp(mp(pos, _fi), _se)].fi;
    int time1 = _fi + h1[pos], time2 = _se + h2[pos];
    int ans1 = f(pos + 1, w1[pos], max (0, _se - time1)) + time1, ans2 = time2 + f(pos + 1, max (0, _fi - time2), w2[pos]);
   	if (ans1 < ans2) table[mp(mp(pos, _fi), _se)] = mp(ans1, true);
   	else table[mp(mp(pos, _fi), _se)] = mp(ans2, false);
   	re table[mp(mp(pos, _fi), _se)].fi; 
}
 
int main() {
    scanf("%d", &n);
    fo(i, n) scanf("%d%d%d%d", h1 + i, w1 + i, h2 + i, w2 + i);
    cout << f(0, 0, 0) << endl;
    int pos = 0, _fi = 0, _se = 0;
    while (table.count (mp(mp(pos, _fi), _se))) {
    	int n1 = pos + 1, n2, n3;
    	if (table[mp(mp(pos, _fi), _se)].se) {
    		cout << 1 << ' ';
    		n2 = w1[pos];
    		n3 = max (0, _se - (_fi + h1[pos])); 
    	} else {
    		cout << 2 << ' ';
    		n2 = max (0, _fi - (_se + h2[pos]));
    		n3 = w2[pos];
    	}
    	pos = n1, _fi = n2, _se = n3;
    }
    return 0;
}