#include "interactive.h"
using namespace std;

vector<int> guess(int n) {
	vector <int> ans;
	for (int i = 1; i <= n; i++) {
		ans.push_back(ask(i));
	}
	return ans;
}
