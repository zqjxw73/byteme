//============================================================================
// Name        : c
// Date        : Sat Feb 16 21:45:54 CST 2019
// Author      : landcold7
// Copyright   : Your copyright notice
// Description : None
//============================================================================
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pvar(x) cout << #x << ": "
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = a; i < b; ++i)
#define ford(i, a, b) for (int i = a; i > b; --i)
#define output(v) cout << (v) << '\n'
#define codejam(ix, v) cout << "Case #" << (ix) << ": " << (v) << '\n'
#define prt(x, a, n) { cout << x[a]; if (a < n - 1) cout << " "; }
#define pvi(x, v) if(v) pvar(x); fora(a, x) cout << a << " "; cout << '\n'
#define par(x, s, n, v) if(v) pvar(x); fori(a, s, n) prt(x, a, n) cout << '\n'

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _f(const char* name, T&& arg) {
    cout << fixed << name << ": " << arg << '\n';
}

template <typename T, typename... Args>
void _f(const char* names, T&& arg, Args&&... args) {
    const char* split = strchr(names + 1, ',');
    cout.write(names, split - names) << ": " << arg << " |";
    _f(split, args...);
}

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

// Ref: https://www.quora.com/How-do-I-find-the-number-of-trailing-zeroes-of-N-factorial-in-Base-B
// Ref: https://janmr.com/blog/2010/10/prime-factors-of-factorial-numbers/
map<ll, ll> fact;
void solve() {
    ll n, b;
    cin >> n >> b;
    for (ll i = 2; i * i <= b; ++i) {
        while (b % i == 0) {
            fact[i]++;
            b /= i;
        }
    }
    if (b > 1) fact[b]++;

    ll ret = numeric_limits<ll>::max();
    fora (f, fact) {
        ll p = f.first, y = f.second;
        ll x = 0, m = n;
        while (m) {
            x += m / p;
            m /= p;
        }
        ret = min(ret, x / y);
    }
    output(ret);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

