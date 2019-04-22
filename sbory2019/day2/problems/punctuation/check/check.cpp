#include "testlib.h"
#include <sstream>

using namespace std;

int main(int argc, char * argv[])
{
    registerTestlibCmd(argc, argv);
    
    string secret = ouf.readLine();
    string secret_jury = ans.readLine();
    if (secret != secret_jury) {
        quitf(_wa, "WTF? Secret is wrong");
    }

    int k = ouf.readInt();
    int q = ouf.readInt();
    if (q < 0) {
        if (q == -1) quitf(_wa, "Too many queries");
        if (q == -2) quitf(_wa, "Invalid query");
        if (q == -3) quitf(_wa, "Wrong answer");
        quitf(_fail, "WTF?");
    }

    double C = 1.0 * q / k;
    int points;
    if (C > 15 + 1e-9) points = 10;
    else if (C > 6) points = 40;
    else if (C > 3 + 1e-9) points = 40 + 1.0 * (6 - C) / 3 * (100 - 40) + 0.5 + 1e-9;
    else points = 100;
    if (points == 100) quitf(_ok, "%d commas, %d queries", k, q);
    else quitf(_pc(points), "%d commas, %d queries", k, q);
}
