// #include "testlib.h"
#include <sstream>

using namespace std;

char buff[100];

void print(double d){
	printf("%.10lf", d);
	exit(0);
}

int main(int argc, char * argv[])
{
    // registerTestlibCmd(argc, argv);

    FILE *fin = fopen(argv[1], "r");
    FILE *fout = fopen(argv[3], "r");
    FILE *fjur = fopen(argv[2], "r");

    fscanf(fjur, "%s%*s%*s", buff);
    string secret_jury = string(buff);
    fscanf(fout, "%s%*s%*s", buff);
    string secret = string(buff);
    if (secret != secret_jury) {
        // quitf(_wa, "WTF? Secret is wrong");
        fprintf(stderr, "WA\n");
        print(0.0);
    }

    int k, q;
    fscanf(fout, "%d%d", &k, &q);
    if (q < 0) {
        //if (q == -1) quitf(_wa, "Too many queries");
        //if (q == -2) quitf(_wa, "Invalid query");
        //if (q == -3) quitf(_wa, "Wrong answer");
        fprintf(stderr, "WA\n");
        print(0.0);
        //quitf(_fail, "WTF?");
    }

    double C = 1.0 * q / k;
    int points;
    if (C > 15 + 1e-9) points = 10;
    else if (C > 6) points = 40;
    else if (C > 3 + 1e-9) points = 40 + 1.0 * (6 - C) / 3 * (100 - 40) + 0.5 + 1e-9;
    else points = 100;
    fprintf(stderr, "ok\n");
    print((points + 0.0) / 100);
    //if (points == 100) quitf(_ok, "%d commas, %d queries", k, q);
    //else quitf(_pc(points), "%d commas, %d queries", k, q);
}
