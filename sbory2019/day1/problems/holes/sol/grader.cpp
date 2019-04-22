#include "holes.h"
#include <cstdio>
#include <vector>
#include <cassert>

// BEGIN_USER_CUT
#define SECRET "AepaeC4ePuweiquu"
// END_USER_CUT

int main() {
  int q;
  assert(scanf("%d", &q) == 1);

  // BEGIN_USER_CUT
  std::vector<int> ans;
  // END_USER_CUT

  for (int i = 0; i < q; i++) {
    int batch;
    assert(scanf("%d", &batch) == 1);
    std::vector<int> x(batch), y(batch);
    for (int j = 0; j < batch; j++) {
      assert(scanf("%d%d", &x[j], &y[j]) == 2);
    }
    std::vector<int> res = add(x, y);
    for (int x : res) {
      // BEGIN_USER_CUT
      ans.push_back(x);
#if 0
      // END_USER_CUT
      printf("%d\n", x); 
      // BEGIN_USER_CUT
#endif
      // END_USER_CUT
    }
  }

  // BEGIN_USER_CUT
  printf("%s\n", SECRET);
  for (int x : ans) {
    printf("%d\n", x);
  }
  // END_USER_CUT
  return 0;
}
