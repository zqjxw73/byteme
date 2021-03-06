/* created   : 2020-06-20 16:45:21
 * accepted  : 2020-06-20 17:18:40
 */
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

#define TreeMultiSet tree<                     \
  pair<T, int>, null_type, less<pair<T, int>>, \
  rb_tree_tag,                                 \
  tree_order_statistics_node_update>

template<class T>
struct OrderedMultiSet : public TreeMultiSet {
  using TreeMultiSet::find_by_order;
  using TreeMultiSet::insert;
  using TreeMultiSet::lower_bound;
  using TreeMultiSet::order_of_key;
  using TreeMultiSet::size;

  using iterator = typename TreeMultiSet::iterator;
  using const_iterator = typename TreeMultiSet::const_iterator;

  int id = 0;

  void insert(T x) {
    insert({x, id++});
  }

  T at(int index) {
    assert(0 <= index && index < (int) size());
    return find_by_order(index)->first;
  }

  // Get the `index`th element.
  const_iterator att(int index) const {
    assert(0 <= index && index < (int) size());
    return find_by_order(index);
  }

  iterator att(int index) {
    assert(0 <= index && index < (int) size());
    return find_by_order(index);
  }

  // Get the index of a specific key `x`.
  int index(int x) {
    return order_of_key({x, 0});
  }

  void erase(iterator it) {
    TreeMultiSet::erase(it);
  }

  void erase(int index) {
    erase(att(index));
  }

  // O(logc + count(x))
  void erase_all(T x) {
    int lo = lower_bound(x);
    int hi = upper_bound(x);
    int cnt = hi - lo;
    for (int i = 0; i < cnt; i++) {
      erase(lo);
    }
  }

  int lower_bound(T x) {
    return order_of_key({x, 0});
  }

  int upper_bound(T x) {
    return order_of_key({x + 1, 0});
  }

  int count(T x) {
    int d = upper_bound(x) - lower_bound(x);
    // assert(d >= 1);
    return d;
  }
};

void solve() {
  int n, m; cin >> n >> m;
  vector<int> a(n);
  for (auto& x : a) {
    cin >> x;
  }
  vector<int> b(m);
  for (auto& x : b) {
    cin >> x;
  }
  OrderedMultiSet<int> st;
  int k = 0;
  for (auto x : a) {
    st.insert(x);
    while (k < m && (int) st.size() == b[k]) {
      cout << st.at(k++) << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
