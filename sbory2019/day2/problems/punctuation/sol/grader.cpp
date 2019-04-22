#include "punctuation.h"
#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// BEGIN_USER_CUT
string SECRET = "Oxford comma rules.";
// END_USER_CUT

class TInteractor {
    int n, k;
    int query_count, query_limit;
    vector<int> distances;
    int error_code;
public:
    
    TInteractor(int n = 0, vector<int> commas = {})
        : n(n)
        , k(commas.size())
        , query_count(0)
        , query_limit(n)
        , distances(n, n)
        , error_code(0)
    {
        for (int x: commas) distances[x] = 0;
        for (int i = 0; i < n - 1; ++i) distances[i + 1] = min(distances[i + 1], distances[i] + 1);
        for (int i = n - 2; i >= 0; --i) distances[i] = min(distances[i], distances[i + 1] + 1);
    }

    int get_distance(int i) {
        if (++query_count > query_limit) {
            error_code = 1;
            return -1;
        }
        if (i < 0 || i >= n) {
            error_code = 2;
            return -1;
        }
        return distances[i];
    }

    int get_query_count() const {
        return query_count;
    }

    int get_error_code() const {
        return error_code;
    }

    int get_k() const {
        return k;
    }
};

static TInteractor inter;

void finalize(int res) {
// BEGIN_USER_CUT
    cout << SECRET << '\n';
// END_USER_CUT
		cout << inter.get_k() << ' ' << res << '\n';
    exit(0);
}

int get_distance(int i) {
    int res = inter.get_distance(i - 1);
    if (inter.get_error_code()) finalize(-inter.get_error_code());
    return res;
}

int main() {
    int n, k;
    assert(scanf("%d%d", &n, &k) == 2);
    vector<int> C(k);
    for (int i = 0; i < k; i++) {
        assert(scanf("%d", &C[i]) == 1);
        --C[i];
    }
    sort(C.begin(), C.end());

    inter = TInteractor(n, C);
    vector<int> ans = punctuation(n);
    sort(ans.begin(), ans.end());
    for (int &x: ans) --x;
    if (ans != C) finalize(-3);

    finalize(inter.get_query_count());
}
