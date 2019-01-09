
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

namespace {
    const int maxn = 1000;
    const int maxq = 8000;
    int numq = 0;
    int n;
    int hidden_number;
    void wrong_answer(const char *MSG) {
        printf("0.0\n", MSG);
        // printf("Wrong answer: %s\n", MSG);
        exit(0);
    }
}

string ask(int x) {
    if(++numq > maxq) wrong_answer("too many queries");
    if(x < 1 || x > n) wrong_answer("invalid ask");
    if(x < hidden_number) return "<";
    if(x == hidden_number) return "=";
    if(x > hidden_number) return ">";
}

int main(int argc, char **argv) {

	FILE *fifo_in, *fifo_out;
	fifo_in = fopen(argv[2], "r");
	fifo_out = fopen(argv[1], "w");

	int a, b;
	assert(fscanf(fifo_in, "%d %d", &a, &b) == 2);
	fprintf(fifo_out, "%d\n", add(a, b));
	fflush(fifo_out);

	fclose(fifo_in);
	fclose(fifo_out);

	return 0;

}
