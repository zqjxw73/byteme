//============================================================================
// Name        : 600b
// Date        : Fri Apr 12 14:54:23 CST 2019
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

int binary_search(vi& a, int k) {
  // a[lo] <= k < a[hi];
  int lo = -1, hi = sz(a);
  while (hi - lo > 1) {
    int mid = lo + (hi - lo) / 2;
    if (a[mid] <= k) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  return hi;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(all(a));
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    // int r = upper_bound(all(a), x) - a.begin();
    int r = binary_search(a, x);
    cout << r << (i == m - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

