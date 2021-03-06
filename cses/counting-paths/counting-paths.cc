/* created   : 2020-12-13 20:01:52
 * accepted  : 2020-12-13 22:06:20
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

struct Tree {
  vector<vector<int>> g;
  vector<vector<int>> f;
  vector<int> enter;
  vector<int> leave;
  vector<int> depth;
  vector<int> pre;
  int cnt;
  int n;
  int h;

  Tree(int n_) : n(n_) {
    cnt = 0;
    g.resize(n);
    pre.resize(n, -1);
    enter.resize(n);
    leave.resize(n);
    depth.resize(n);
  }

  bool isancestor(int u, int v) {
    return (enter[u] <= enter[v] && leave[v] <= leave[u]);
  }

  void add_edge(int u, int v) {
    g[u].push_back(v);
  }

  void dfs(int u) {
    enter[u] = cnt++;
    for (int v : g[u]) {
      if (v == pre[u]) continue;
      pre[v] = u;
      depth[v] = depth[u] + 1;
      dfs(v);
    }
    leave[u] = cnt;
  }

  int ceil_pow2(int x) {
    int t = 0;
    while ((1ll << t) <= x) {
      t++;
    }
    return t;
  }

  void build_lca() {
    dfs(0);
    int max_depth = *max_element(depth.begin(), depth.end());
    h = ceil_pow2(max_depth);
    f.resize(n, vector<int>(h, -1));
    for (int i = 0; i < n; i++) {
      f[i][0] = pre[i];
    }
    for (int i = 1; i < h; i++) {
      for (int u = 0; u < n; u++) {
        int p = f[u][i - 1];
        f[u][i] = (p < 0 ? -1 : f[p][i - 1]);
      }
    }
  }

  int lca(int u, int v) {
    assert(0 <= u && u < n);
    assert(0 <= v && v < n);
    if (isancestor(u, v)) {
      return u;
    }
    else if (isancestor(v, u)) {
      return v;
    }
    else {
      for (int i = h - 1; i >= 0; i--) {
        if (f[u][i] > 0 && !isancestor(f[u][i], v)) {
          u = f[u][i];
        }
      }
      return f[u][0];
    }
  }
};

void solve() {
  int N, Q; cin >> N >> Q;
  Tree tree(N);
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    tree.add_edge(u, v);
    tree.add_edge(v, u);
  }
  tree.build_lca();
  vector<int> f(N);
  for (int i = 0; i < Q; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    f[u]++;
    f[v]++;
    int c = tree.lca(u, v);
    f[c]--;
    if (c != 0) {
      f[tree.pre[c]]--;
    }
  }
  std::function<void(int, int)> dfs = [&](int u, int p) {
    for (int v : tree.g[u]) {
      if (v == p) continue;
      dfs(v, u);
      f[u] += f[v];
    }
  };
  dfs(0, -1);
  for (int i = 0; i < N; i++) {
    cout << f[i] << (i == N - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
