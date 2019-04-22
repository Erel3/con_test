#include "acid-rain.h"

void init() {}

void add_segment(int l, int r, int s) {}

std::vector<int> drop_a_drop(int x, int a) {
	return std::vector<int>();
}

std::vector<std::vector<int>> drop_many_drops(std::vector<int> xs, std::vector<int> as) {
	std::vector<std::vector<int>> ret;
	for (int i = 0; i < (int) xs.size(); ++i) {
		ret.push_back(drop_a_drop(xs[i], as[i]));
	}
	return ret;
}
