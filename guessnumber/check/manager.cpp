
#include <cstdio>
#include <cstdlib>
#include <signal.h>

using namespace std;

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
	signal(SIGPIPE, SIG_IGN);

	FILE *fin, *fout, *fifo_in, *fifo_out;

	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");
	fifo_in = fopen(argv[1], "w");
	fifo_out = fopen(argv[2], "r");

	fscanf(fin, "%d %d", &n, &hidden_number);
	fprintf(fifo_in, "%d\n", n);
	fflush(fifo_in);
	fscanf(fifo_out, "%d", &res);
	fprintf(fout, "%d\n", res);
	fflush(fout);

	if (a+b == res) {
		fprintf(stderr, "A-ha, you're the best adding program I've ever met!\n");
		printf("1.0\n");
	} else {
		fprintf(stderr, "How dreadful, never met anyone as dumb as you...\n");
		printf("0.0\n");
	}

	fclose(fin);
	fclose(fout);
	fclose(fifo_in);
	fclose(fifo_out);

}
