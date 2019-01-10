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
        fscanf(fres, "%d", &q);
        if(sub == 1) {
            fprintf(stderr, "Sub1: %d queries, ", q);
            if(q <= 5) {
                fprintf(stderr, "ok\n");
                printf("1.0\n");
            } else {
                fprintf(stderr, "Sub1: too many queries\n");
                printf("0.0\n");
            }
        } else if(sub == 2) {
            fprintf(stderr, "Sub2: %d queries, ", q);
            if(q <= 10) {
                fprintf(stderr, "ok\n");
                printf("1.0\n");
            } else if(q <= 12) {
                printf("0.736842105263157\n"); //95*x=70
            } else  if(q <= 20) {
                printf("0.526315789473684\n"); //95*x=50
            } else {
                printf(".1052631578947368\n"); //95*x=10
            }
        }
	} else {
		fprintf(stderr, "WA\n");
		printf("0.0\n");
	}

	return 0;

}
