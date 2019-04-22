#ifndef ACID_RAIN_H_
#define ACID_RAIN_H_

#include <vector>

void init();

void add_segment(int l, int r, int s);

std::vector<int> drop_a_drop(int x, int a);

std::vector<std::vector<int>> drop_many_drops(std::vector<int> xs, std::vector<int> as);

#endif
