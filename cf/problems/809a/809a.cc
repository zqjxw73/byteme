/* created   : 2020-03-01 21:14:56
 * accepted  : 2020-03-01 22:27:37
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

namespace modnum_t {
template <int mod_>
struct Modnum {
  static constexpr int mod = mod_;
  static_assert(mod_ > 0, "mod must be positive");

  typedef Modnum MD;

 private:
  using ll = long long;
  int v;

  static int inv(int a, int m) {
    a %= m;
    assert(a);
    return a == 1 ? 1 : int(m - ll(inv(m, a)) * ll(m) / a);
  }

 public:
  Modnum() : v(0) {}

  Modnum(ll v_) : v(int(v_ % mod)) {
    if (v < 0) {
      v += mod;
    }
  }

  explicit operator int() const { return v; }

  friend std::ostream& operator<<(std::ostream& out, const MD& n) {
    return out << int(n);
  }

  friend std::istream& operator>>(std::istream& in, MD& n) {
    ll x;
    in >> x;
    n = MD(x);
    return in;
  }

  friend bool operator==(const MD& a, const MD& b) { return a.v == b.v; }
  friend bool operator!=(const MD& a, const MD& b) { return a.v != b.v; }

  MD inv() const {
    MD res;
    res.v = inv(v, mod);
    return res;
  }

  MD neg() const {
    MD res;
    res.v = v ? mod - v : 0;
    return res;
  }

  MD operator-() const { return neg(); }

  MD operator+() const { return MD(*this); }

  MD& operator++() {
    v++;
    if (v == mod) v = 0;
    return *this;
  }

  MD& operator--() {
    if (v == 0) v = mod;
    v--;
    return *this;
  }

  MD& operator+=(const MD& o) {
    v += o.v;
    if (v >= mod) v -= mod;
    return *this;
  }

  MD& operator-=(const MD& o) {
    v -= o.v;
    if (v < 0) v += mod;
    return *this;
  }

  MD& operator*=(const MD& o) {
    v = int(ll(v) * ll(o.v) % mod);
    return *this;
  }

  MD& operator/=(const MD& o) { return *this *= o.inv(); }

  friend MD operator++(MD& a, int) {
    MD r = a;
    ++a;
    return r;
  }
  friend MD operator--(MD& a, int) {
    MD r = a;
    --a;
    return r;
  }
  friend MD operator+(const MD& a, const MD& b) { return MD(a) += b; }
  friend MD operator-(const MD& a, const MD& b) { return MD(a) -= b; }
  friend MD operator*(const MD& a, const MD& b) { return MD(a) *= b; }
  friend MD operator/(const MD& a, const MD& b) { return MD(a) /= b; }
};

template <int mod>
struct Combina {
  vector<Modnum<mod>> fact;
  vector<Modnum<mod>> fact_inv;

  explicit Combina(int n) {
    fact.resize(n + 1);
    fact_inv.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
      fact[i] = fact[i - 1] * i;
    }
    for (int i = n; i >= 0; --i) {
      fact_inv[i] = fact[i].inv();
    }
  }

  // Choose k from total n items without permutation
  int nck(int n, int k) { return (*this)(n, k); }

  // Choose k from total n items with permutation
  int npk(int n, int k) {
    // nPk = nCk * k!
    Modnum<mod> ret = nck(n, k);
    ret *= fact[k];
    return (int)ret;
  }

  int operator()(int n, int k) {
    if (k < 0 || n < k) {
      return int(Modnum<mod>(0));
    }
    return int(fact[n] * fact_inv[k] * fact_inv[n - k]);
  }
};

struct CombinaSmall {
  // Compute cominatrics for a relative small range up to 10^3
  vector<vector<int>> dp;

  // c(n, k) = c(n - 1, k) + c(n - 1, k - 1);
  explicit CombinaSmall(int n) {
    dp.resize(n + 1, vector<int>(n + 1));
    for (int i = 0; i <= n; i++) {
      dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
      for (int k = 1; k <= i; k++) {
        dp[i][k] = dp[i - 1][k] + dp[i - 1][k - 1];
      }
    }
  }

  // Choose k from total n items without permutation
  int nck(int n, int k) { return (*this)(n, k); }

  // Choose k from total n items without permutation
  int operator()(int n, int k) { return dp[n][k]; }
};
}  // namespace modnum_t

using namespace modnum_t;

using Num = Modnum<(int) 1e9 + 7>;

Num power(Num a, ll b) {
  Num res(1);
  while (b > 0) {
    if (b & 1) {
      res = res * a;
    }
    a = a * a;
    b >>= 1;
  }
  return res;
}

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(all(a));
  Num ans = 0;
  Num y = a[0];
  Num x = 0;
  for (int i = 1; i < n; i++) {
    x = (power(Num(2), i) - 1) * a[i];
    ans += x - y;
    y = 2 * y + a[i];
    trace(x, y, ans);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
