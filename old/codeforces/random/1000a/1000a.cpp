//============================================================================
// Name        : 1000a
// Date        : Fri Apr 26 16:12:11 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<typename T> void output(T t) { cout << t << "\n"; }
template<typename T, typename U, typename... Args>
void output(T t, U u, Args... args) { cout << t << " "; output(u, args...); }

#ifndef _has_trace
#define trace(...)
#define dbstream ostream
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;

void solve() {
  int n;
  cin >> n;
  map<string, int> a, b;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    a[s]++;
  }
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    b[s]++;
  }
  trace(a, b);
  int ret = n;
  for (auto it : a) {
    ret -= min(it.y, b[it.x]);
  }
  output(ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

