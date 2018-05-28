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
 
class lnum{
private:
    vi v;
    int mod = (int) 1e9;
public:
    int size() const {
        re v.size();
    }
    lnum (char *s) {
        for(int i = strlen(s); i > 0; i -= 9) {
            s[i] = 0;
            v.pb(atoi(i >= 9 ? s + i - 9 : s));
        }
        while(v.size() > 1 && v.back() == 0) v.pop_back();
    }
    lnum (int x) {
        v.pb(x);
    }
    lnum () {
    	///
    }
    void operator += (const lnum& a) {
        int carry = false;
        for(int i = 0; i < max(this->size(), a.size()) || carry; ++i) {
            if (this->size() == i) v.pb(0);
            v[i] += carry + (i < a.size() ? a.v[i] : 0);
            carry = v[i] >= mod;
            if (carry) v[i] -= mod;
        }
    }
    void operator -= (const lnum& a) {
        bool carry = false;
        for(int i = 0; i < a.size() || carry; ++i) {
            v[i] -= carry + (i < a.size() ? a.v[i] : 0);
            carry = v[i] < 0;
            if (carry) v[i] += mod;
        }
        while(v.size() > 1 && v.back() == 0) v.pop_back();
    }
    bool operator < (const lnum& a) const {
        if (this->size() < a.size()) re true;
        if (this->size() > a.size()) re false;
        ro(i, a.size()) {
            if (a.v[i] == v[i]) continue;
            re v[i] < a.v[i];
        }
        re false;
    }
    bool operator > (const lnum &a) const {
        if (this->size() < a.size()) re false;
        if (this->size() > a.size()) re true;
        ro(i, a.size()) {
            if (a.v[i] == v[i]) continue;
            re v[i] > a.v[i];
        }
        re false;
    }
    bool operator == (const lnum &a) const {
    	if (a.v == this->v) re true;
    	re false;
    }
    void mul(const lnum& a, const lnum& b) {
        v.clear();
        v.resize(a.size() + b.size());
        fo(i, a.size()) {
            for(int j = 0, carry = 0; j < b.size() || carry; ++j) {
                ll cur = v[i + j] + a.v[i] * 1ll * (j < b.size() ? b.v[j] : 0) + carry;
                v[i + j] = (int) (cur % mod);
                carry = (int) (cur / mod);
            }
        }
        while(v.size() > 1 && v.back() == 0) v.pop_back();
    }
    void operator *= (int a){
        int carry = 0;
        for(int i = 0; i < (int)v.size() || carry; ++i) {
            if ((int)v.size() == i) v.pb(0);
            ll cur = v[i] * 1ll * a + carry;
            v[i] = (int) (cur % mod);
            carry = (int) (cur / mod);
        }
        while(v.size() > 1 && v.back() == 0) v.pop_back();
    }
    void pow(lnum& a, int n) {
        char s[10]; s[0] = '1'; s[1] = 0;
        *this = lnum(s);
        while(n) {
            if (n & 1) {
                lnum x = *this;
                this->mul(x, a);
            }
            lnum x = a;
            a.mul(x, x);
            n >>= 1;
        }
    }
    void print() {
        printf("%d", v.empty() ? 0 : v.back());
        for(int i = (int)v.size() - 2; i >= 0; --i) printf("%09d", v[i]);
    }
};

int main() {
	re 0;
}