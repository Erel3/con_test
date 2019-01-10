#include <cstdio>
#include <cstdlib>
#include <cassert>

using namespace std;

namespace {
    const int maxn = 1000;
    const int maxq = 1000;
    int numq = 0;
    int n;
    int hidden_number;
    void wrong_answer(const char *MSG) {
        printf("Wrong answer: %s\n", MSG);
        exit(0);
    }
}

char ask(int x) {
    if (++numq > maxq) wrong_answer("too many queries");
    if (x < 1 || x > n) wrong_answer("invalid query");
    if (x < hidden_number) return '<';
    else if (x > hidden_number) return '>';
    else return '=';
}

int guess_number(int n);

int main() {
    scanf("%d %d", &n, &hidden_number);
    if (n > maxn) {
        printf("Wrong constraints\n");
        exit(0);
    }
    int g = guess_number(n);
    if (g == hidden_number) {
        printf("Correct: answer found in %d queries\n", numq);
        exit(0);
    } else {
        wrong_answer("answer not found");
    }
    return 0;
}
