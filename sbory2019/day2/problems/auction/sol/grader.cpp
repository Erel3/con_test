#include "auction.h"
#include <cstdio>
#include <vector>
#include <cassert>
#include <iostream>

// BEGIN_USER_CUT
#define SECRET "The world is changed. I feel it in the water. I feel it in the earth. I smell it in the air."
// END_USER_CUT

using namespace std;

int main() {
    int n;
    assert(scanf("%d", &n) == 1);
    std::vector<int> rar, res;
    for (int i = 0; i < n; i++)
    {
    	int x;
    	assert(scanf("%d", &x) == 1);
    	rar.push_back(x);
    }
    res = auction(rar);
// BEGIN_USER_CUT
    printf("%s\n", SECRET);
// END_USER_CUT
    for (auto v : res) {
    	printf("%d ", v);
    }
    printf("\n");
  return 0;
}
