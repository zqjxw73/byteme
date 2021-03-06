/* created   : 2020-12-14 23:26:29
 * accepted  : 2020-12-15 00:02:15
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

// Zero-index based
template <class T>
class Bit {
 public:
  Bit(int n) : n_(n) { t_.resize(n_ + 1); }

  void add(int x, T d) {
    for (++x; x <= n_; x += lowbit(x)) {
      t_[x] += d;
    }
  }

  // Query sum of interval [0...x).
  T query(int x) {
    T ans = 0;
    for (; x > 0; x -= lowbit(x)) {
      ans += t_[x];
    }
    return ans;
  }

  // Query sum of interval [l...r).
  T query(int l, int r) { return query(r) - query(l); }

 private:
  int lowbit(int x) { return x & -x; }
  int n_;
  vector<T> t_;
};

void solve() {
  int N, Q; cin >> N >> Q;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<vector<int>> g(N);
  Graphviz gv;
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
    gv.gvAddEdge(u, v);
  }
  gv.gvDrawGraph();
  vector<int> enter(N);
  vector<int> leave(N);
  int cnt = 0;
  std::function<void(int, int)> dfs = [&](int u, int p) {
    enter[u] = cnt++;
    for (int v : g[u]) {
      if (v == p) continue;
      dfs(v, u);
    }
    leave[u] = cnt++;
  };
  dfs(0, -1);
  Bit<ll> bit(cnt);
  for (int i = 0; i < N; i++) {
    bit.add(enter[i], A[i]);
  }
  trace(cnt, enter, leave);
  for (int i = 0; i < Q; i++) {
    int op; cin >> op;
    if (op == 1) {
      int s; ll x; cin >> s >> x;
      s--;
      s = enter[s];
      bit.add(s, x - bit.query(s, s + 1));
    }
    else {
      int s; cin >> s;
      s--;
      cout << bit.query(enter[s], leave[s] + 1) << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
