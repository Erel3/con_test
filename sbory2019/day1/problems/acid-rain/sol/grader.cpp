#include "acid-rain.h"
#include <cstdio>
#include <vector>
#include <cassert>
#include <iostream>

// BEGIN_USER_CUT
#define SECRET "The world is changed. I feel it in the water. I feel it in the earth. I smell it in the air."
// END_USER_CUT

int main() {
  init();
  int type;
  assert(scanf("%d", &type) == 1);

  int q;
  assert(scanf("%d", &q) == 1);

  // BEGIN_USER_CUT
  std::vector<std::vector<int>> ans;
  // END_USER_CUT
  
  std::vector<int> reqs_coords, reqs_acidity;

  for (int i = 0; i < q; i++) {
    int t;
    assert(scanf("%d", &t) == 1);
    if (t == 1) {
      int l, r, s;
      assert(scanf("%d%d%d", &l, &r, &s) == 3);
      add_segment(l, r, s);
    } else {
      int x, a;
      assert(scanf("%d%d", &x, &a) == 2);
      if (type == 2) {
        reqs_coords.push_back(x);
        reqs_acidity.push_back(a);
      } else {
        std::vector<int> res = drop_a_drop(x, a);
        // BEGIN_USER_CUT
        ans.push_back(res);
#if 0
        // END_USER_CUT
        std::cout << res.size();
        for (int j = 0; j < (int) res.size(); ++j) {
          std::cout << " " << res[j];
        }
        std::cout << "\n";
        // BEGIN_USER_CUT
#endif
        // END_USER_CUT
      }
    }
  }

  if (type == 2) {
    std::vector<std::vector<int>> res = drop_many_drops(reqs_coords, reqs_acidity);
    // BEGIN_USER_CUT
    ans = res;
#if 0
    // END_USER_CUT
    for (int i = 0; i < (int) res.size(); ++i) {
      std::cout << res[i].size();
      for (int j = 0; j < (int) res[i].size(); ++j) {
        std::cout << " " << res[i][j];
      }
      std::cout << "\n";
    }
    // BEGIN_USER_CUT
#endif
    // END_USER_CUT
  }

  // BEGIN_USER_CUT
  printf("%s\n", SECRET);
  for (auto& v : ans) {
    std::cout << v.size();
    for (int num : v) {
      std::cout << " " << num;
    }
    std::cout << "\n";
  }
  // END_USER_CUT
  return 0;
}
