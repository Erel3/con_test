#include "auction.h"
#include <vector>

std::vector<int> auction(const std::vector<int> &rar) {
	std::vector<int> ret;
	int n = (int)rar.size();
	for (int i = 0; i < n; ++i) {
		ret.push_back(0);
	}
	return ret;
}
