#include "routing.h"
#include <cstdio>
#include <vector>
#include <cassert>

// BEGIN_USER_CUT
#define SECRET "AepaeC4ePuweiquu"
// END_USER_CUT



int main() {
  int n;
  assert(scanf("%d", &n) == 1);
  std::vector<std::vector<int> > r(n), u(n);
  
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int m;
    assert(scanf("%d", &m) == 1);
    r[i].resize(m);
    u[i].resize(m);
    
    for (int j = 0; j < m; j++) {
      assert(scanf("%d%d", &r[i][j], &u[i][j]) == 2);
    }

  }
  ans = number_of_pairs(n, r, u);
  // BEGIN_USER_CUT
  printf("%s\n", SECRET);
  // END_USER_CUT
  printf("%lld\n", ans);
  return 0;
}
