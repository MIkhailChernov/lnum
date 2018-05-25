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
 
const int maxn = (int) 1e5;
vi pn, cn;

void massive_suffix (vector<vi> &p, vector <vi> &c, string &str) {
	int n = str.size();
	int m = (int)log2(n) + 2;
	p.resize(m), c.resize(m);
	for (int i = 0; i < m; ++i) p[i].resize(n), c[i].resize(n);
	vi cnt(max(256, n)), pn(n), cn(n);
	for (int i = 0; i < n; ++i) cnt[str[i]]++;		
	for (int i = 1; i < cnt.size(); ++i) cnt[i] += cnt[i - 1];
	for (int i = 0; i < n; ++i) p[0][--cnt[str[i]]] = i;
	int classes = 1;
	for (int i = 1; i < n; ++i) {
		if (str[p[0][i]] != str[p[0][i - 1]]) ++classes;
		c[0][p[0][i]] = classes - 1;
	}
	///
	for (int h = 0; (1 << h) < n; ++h) {
		for (int i = 0; i < n; ++i) {
			pn[i] = p[h][i] - (1 << h);
			if (pn[i] < 0) pn[i] += n;
		}
		fill(all(cnt), 0);
		for (int i = 0; i < n; ++i) ++cnt[c[h][pn[i]]];
		for (int i = 1; i < cnt.size(); ++i) cnt[i] += cnt[i - 1];
		for (int i = n - 1; i >= 0; --i) p[h + 1][--cnt[c[h][pn[i]]]] = pn[i];
		classes = 1;
		cn[p[h + 1][0]] = 0;
		for (int i = 1; i < n; ++i) {
			int mid1 = (p[h + 1][i] + (1 << h)) % n, mid2 = (p[h + 1][i - 1] + (1 << h)) % n;
			if (c[h][p[h + 1][i]] != c[h][p[h + 1][i - 1]] || c[h][mid1] != c[h][mid2]) ++classes;
			cn[p[h + 1][i]] = classes - 1;
		}
		copy(all(cn), c[h + 1].begin());
	}
}

int main() {
	string str;
	cin >> str;
	vector <vi> p, c;
	massive_suffix(p, c, str);
	int m = p.size();
	fo(i, m) {
		cout << (1 << i) << endl;
		for (int j : p[i]) cout << j << ' ' ;
		cout << endl;
	}
	re 0;
}