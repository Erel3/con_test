#include <cstdio>
#include <cstdlib>

using namespace std;
int a[233];
int main(int argc, char **argv) {

    FILE *fin = fopen(argv[1], "r");
	FILE *fout = fopen(argv[3], "r");

    int n;
    fscanf(fin, "%d", &n);

    for(int i = 0; i < n; i++) {	
	    fscanf(fin, "%d", &a[i]);
    }
	int A, B;
	fscanf(fout, "%d", &B);
	if (n == B) {
		for(int i = 0; i < n; i++) {
			int bi;		
			fscanf(fout, "%d", &bi);
			if (a[i] != bi) {		
				fprintf(stderr, "WA\n");
				printf("0.0\n");
				return 0;
			}
		}
        int q;
        fscanf(fout, "%d", &q);
        if(n <= 4) {
            fprintf(stderr, "Sub 1: %d queries, ", q);
            fprintf(stderr, "ok\n");
            printf("1.0\n");
            
        } else {
            fprintf(stderr, "Sub 2: %d queries", q);
            if(q <= 15) {
                fprintf(stderr, ", ok\n");
                printf("1.0\n");
            } else if(q <= 40) {
                int y = 84 - 2 * (q - 16);
                printf("%.10lf\n", 1.0 * y / 94); //94*x=y
            } else if(q <= 50) {
            	printf("0.372340426\n");  
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
