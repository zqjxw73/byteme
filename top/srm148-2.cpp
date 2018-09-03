#include<bits/stdc++.h>
using namespace std;

        fori(i, 0, n) \
          fori(j, 0, m) \
            fori(k, 0, c) \
              x[i][j][k] = v
const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class MNS {
public:
  int res;
  vi nums;
  vi new_nums;
  int visit[9];
  set<ll> st; 

  bool check() {
    ll bits = 0;
    fori(i, 0, 9) {
      bits <<= 4;
      bits |= new_nums[i] & 0xf;
    }
    if (st.count(bits)) {
      return false;
    }
    st.insert(bits);

    // Check row 
    int sum = 0;
    fori(i, 0, 3) {
      int r = 0;
      r = new_nums[3*i + 0] + new_nums[3*i + 1] + new_nums[3*i + 2];
      if (i == 0)
        sum = r;
      else if (r != sum)
        return false;
    }
    // Check column
    fori(i, 0, 3) {
      int r = 0;
      r = new_nums[i] + new_nums[i + 3] + new_nums[i + 6];
      if (r != sum)
        return false;
    }
    return true;
  }

  void dfs(int idx) {
    if (idx == 9) {
      if (check())
        res++;
      return;
    }
    fori(i, 0, 9) {
      if (!visit[i]) {
        visit[i] = 1;
        new_nums[idx] = nums[i];
        dfs(idx+1);
        visit[i] = 0;
      }
    }
  }

  int combos(vi aa) {
    nums = aa;
    mst(visit, 9, 0);
    new_nums.resize(9);
    res = 0;
    dfs(0);
    return res;
  }

  // int combos(vi aa) {
  //   res = 0;
  //   new_nums = aa;
  // Note: we must sort fist in order to get all permutations.
  //   sort(all(new_nums));
  //   do {
  //     if (check())
  //       res++;
  //   } while (next_permutation(all(new_nums))); 

  //   return res;
  // }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  MNS go;
  vi aa = {1,2,3,3,2,1,2,2,2};
  cout << go.combos(aa) << '\n';
  // aa = {4,4,4,4,4,4,4,4,4};
  // cout << go.combos(aa) << '\n';
  // aa = {1,5,1,2,5,6,2,3,2};
  // cout << go.combos(aa) << '\n';
  return 0;
}