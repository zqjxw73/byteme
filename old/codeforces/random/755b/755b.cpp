//============================================================================
// Name        : 755b
// Date        : Fri Apr 12 10:15:29 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include "bits/stdc++.h"
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mst(x, y) memset(x, y, sizeof(x))
#define pvar(x) cout << #x << ": "
#define output(v) cout << (v) << '\n'
#define fori(i, a, b) for (int i = a; i < b; ++i)
#define jam(x, n) cout << "Case #" << x << ": " << n << "\n"
#define prt(x, a, n) { cout << x[a]; if (a < n - 1) cout << " "; }
#define par(x, s, n, v) if(v) pvar(x); fori(y, s, n) prt(x, y, n) cout << "\n"
template<class T> inline void amin(T &x, const T &y) { if (y < x) x = y; }
template<class T> inline void amax(T &x, const T &y) { if (x < y) x = y; }

#ifndef _has_trace
#define trace(...)
#define dbstream ostream
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

void solve() {
  int n, m;
  cin >> n >> m;
  set<string> a;
  for (int i = 0; i < n; ++i) {
    string x;
    cin >> x;
    a.insert(x);
  }
  vector<string> b;
  int both = 0;
  for (int i = 0; i < m; ++i) {
    string x;
    cin >> x;
    if (!a.count(x)) {
      b.pb(x);
    } else {
      ++both;
    }
  }
  int x = sz(a) - both, y = sz(b);
  x += (both & 1 ? both / 2 + 1 : both / 2);
  y += both / 2;
  output(x > y ? "YES" : "NO");
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

