/* created   : 2020-11-29 08:07:45
 * accepted  : 2020-11-29 09:25:02
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

template <class S, S (*op)(S, S), S (*e)()>
class Segtree {
 public:
  explicit Segtree(int n) : Segtree(std::vector<S>(n, e())) {}

  explicit Segtree(const std::vector<S>& v) : n_(int(v.size())) {
    log_ = ceil_pow2(n_);
    size_ = 1 << log_;
    d_ = std::vector<S>(2 * size_, e());
    for (int i = 0; i < n_; i++) {
      d_[size_ + i] = v[i];
    }
    for (int i = size_ - 1; i >= 1; i--) {
      update(i);
    }
  }

  void debug() {
    for (int i = 1; i <= log_ + 1; i++) {
      int p = (1 << (i - 1));
      int l = (1 << (i - 1));
      vector<S> tmp;
      for (int j = 0; j < l; j++) {
        tmp.push_back(d_[p + j]);
      }
      trace(tmp);
      (void)tmp;
    }
  }

  int ceil_pow2(int x) {
    int t = 1, c = 0;
    while (t < x) {
      t <<= 1;
      c++;
    }
    return c;
  }

  void set(int p, S x) {
    assert(0 <= p && p < n_);
    p += size_;
    d_[p] = x;
    for (int i = 1; i <= log_; i++) {
      update(p >> i);
    }
  }

  S query(int l, int r) {
    assert(0 <= l && l <= r && r <= n_);
    S sml = e(), smr = e();
    l += size_;
    r += size_;
    while (l < r) {
      if (l & 1) sml = op(sml, d_[l++]);
      if (r & 1) smr = op(d_[--r], smr);
      l >>= 1;
      r >>= 1;
    }
    return op(sml, smr);
  }

 private:
  void update(int k) { d_[k] = op(d_[2 * k], d_[2 * k + 1]); }
  int n_, size_, log_;
  std::vector<S> d_;
};

struct S {
  ll mx;
  ll prefix;
  ll suffix;
  ll sum;
};

ostream& operator<<(ostream& os, const S& s) {
  return os << "(" << s.mx << " " << s.prefix << " " << s.suffix
            << " " << s.sum << ")";
}

S op(S a, S b) {
  S c;
  c.mx = max({a.mx, b.mx, a.suffix + b.prefix});
  c.prefix = max({a.prefix, a.sum + b.prefix});
  c.suffix = max({b.suffix, b.sum + a.suffix});
  c.sum = a.sum + b.sum;
  return c;
}

S e() {
  const ll INF = 10;
  return S{-INF, -INF, -INF, 0};
}

void solve() {
  int N, Q;
  cin >> N >> Q;
  Segtree<S, op, e> seg(N);
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    seg.set(i, S{x, x, x, x});
  }
  // trace(seg);
  seg.debug();
  for (int i = 0; i < Q; i++) {
    int k, x;
    cin >> k >> x;
    k--;
    seg.set(k, S{x, x, x, x});
    cout << max(seg.query(0, N).mx, 0ll) << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
