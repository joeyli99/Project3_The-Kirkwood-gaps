#include<fstream>
#include<iostream>
#include<random>
#include<time.h>
#include <omp.h>
#include"Hamilton.h"

const double PI = 3.14159265358979323846, Ms = 4 * PI * PI, Mj = Ms / 1047.56;
const auto n = 100000;
const auto years = 2000;
using namespace std;

int main() {
    //get the system time, and seed to the random number generator.
    time_t systime = time(nullptr);
    struct tm *pTm;
    pTm = gmtime(&systime);
    //std::random_device rd; Fuck gcc.
    auto seed = systime;
    std::mt19937_64 e(seed);
    std::uniform_real_distribution<double> u(0.000001, 2 * PI);
    char input_file[256] = {0};
    char output_file[256] = {0};
    sprintf_s(input_file, "IV%d-%d-%d%d-[(%d)_(%d)]randangle.txt", 1 + pTm->tm_mon, pTm->tm_mday, pTm->tm_hour,
              pTm->tm_min, years, n);
    sprintf_s(output_file, "DATA%d-%d-%d%d-[(%d)_(%d)]randangle.txt", 1 + pTm->tm_mon, pTm->tm_mday, pTm->tm_hour,
              pTm->tm_min, years, n);

    ofstream outinv(input_file);
    for (double i = 0; i < n; i++) {
        outinv << 2 + i / (n - 1) * 1.5 << " " << u(e) << endl;
    }
    cout << "Output Initial Value Finished!" << endl;

    cout << "Will end at " << n << endl;

    ifstream in_data(input_file);
    ofstream outdata(output_file);
    //#pragma omp parallel for
    for (int i = 0; i < n; i++) {
        double r, phi;
        in_data >> r >> phi;
        //cout<<phi<<endl;
        std::vector<double> q0 = {5.458104, 0, r * cos(phi), r * sin(phi)};
        std::vector<double> p0 = {0, sqrt(Ms * (1 - 0.048912) / 5.458104), -sqrt(4 * PI * PI / r) * sin(phi),
                                  sqrt(4 * PI * PI / r) * cos(phi)};
        Hamilton H(q0, p0, 0, years);
        H.solve(1.0 / 16.0);

        double xj = (H.q).back()[0];
        double yj = (H.q).back()[1];
        double xa = (H.q).back()[2];
        double ya = (H.q).back()[3];
        double vxa = (H.p).back()[2];
        double vya = (H.p).back()[3];
        //cout<<xj<<endl<<yj<<endl;
        double E = 0.5 * (vxa * vxa + vya * vya) - Ms / sqrt(xa * xa + ya * ya) -
                   Mj / sqrt((xa - xj) * (xa - xj) + (ya - yj) * (ya - yj));
        outdata << -2 * PI * PI / E << endl;
        if (i % 10 == 0)
            cout << i << " ";
    }
    cout << "Output Result Finished!" << endl;
    return 0;
}