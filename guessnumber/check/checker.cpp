#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv) {

    FILE *fin = fopen(argv[1], "r");
	FILE *fres = fopen(argv[2], "r");
	FILE *fout = fopen(argv[3], "r");

    int n, hid, sub;
    fscanf(fin, "%d%d%d", &n, &hid, &sub);

	int a, b;
	fscanf(fres, "%d", &a);
	fscanf(fout, "%d", &b);

	if (a == b) {
        int q;
        fscanf(fout, "%d", &q);
        if(sub == 1) {
            fprintf(stderr, "Sub 1: %d queries, ", q);
            if(q <= 5) {
                fprintf(stderr, "ok\n");
                printf("1.0\n");
            } else {
                fprintf(stderr, "too many queries\n");
                printf("0.0\n");
            }
        } else if(sub == 2) {
            fprintf(stderr, "Sub 2: %d queries", q);
            if(q <= 10) {
                fprintf(stderr, ", ok\n");
                printf("1.0\n");
            } else if(q <= 50) {
                int y = 95 - 2 * (q - 10);
                printf("%.10lf\n", 1.0 * y / 95); //95*x=y
            } else {
                printf("0.0\n");
            }
        }
	} else {
		fprintf(stderr, "WA\n");
		printf("0.0\n");
	}

	return 0;

}
