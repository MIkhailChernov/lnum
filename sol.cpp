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
 
const int max_size = (int) 1e6;
#define left (0)
#define right ((int)1e9)

class node {
public:
	node *l, *r;
	int value;
	node() {
		l = r = nullptr;
		value = 0;
	}
};

#define tree node *
node root[max_size];
int _now = 1;

void add (tree t, int l, int r, int pos, int val) {
	t->value += val;
	if (r - l == 1) return;
	int c = (l + r) >> 1;
	if (pos < c) {
		if (!t->l) t->l = &root[_now++];
		add (t->l, l, c, pos, val);		
	} else {
		if (!t->r) t->r = &root[_now++];
		add (t->r, c, r, pos, val);
	}                              
}

int get (tree t, int l, int r, int L, int R) {
	if (r == R && l == L) re t->value;
	int ans = 0;
	int c = (l + r) >> 1;
	if (L < c && t->l) ans += get (t->l, l, c, L, min(c, R));
	if (R > c && t->r) ans += get (t->r, c, r, max(c, L), R);
	return ans;
}

int main() {
	int n, m, x, l, r;
	scanf("%d%d", &n, &m);
	fo(i, n) {
		scanf("%d", &x);
		add(root, left, right, i, x);
	}
	fo(i, m) {
		scanf("%d%d", &l, &r);
		printf("%d\n", get(root, left, right, l - 1, r));
	}
	return 0;
}