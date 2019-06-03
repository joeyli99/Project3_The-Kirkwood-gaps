#include<fstream>
#include<iostream>
#include<random>
#include<omp.h>
#include<fmt\time.h>
#include"Hamilton.h"

constexpr auto PI = 3.14159265358979323846, Ms = 4 * PI * PI, Mj = Ms / 1047.56;
const auto n = 1000;
const auto years = 2000;
using namespace std;

int main() {

    //the benchmark
    clock_t begin, finish;
    begin = clock();

    //get the system time, and seed to the random number generator.
    time_t systime = time(nullptr);

    //std::random_device rd; Fuck gcc.
    auto seed = systime;
    std::mt19937_64 e(seed); //seed the random generator by system time.
    std::uniform_real_distribution<double> u(0, 2 * PI); //uniform distribution phi.

    //using the time to name the data
    string input_file, output_file;
    input_file = fmt::format("IV{:%Y-%m-%d-%M-%S}-[n={},year={}].txt", *std::localtime(&systime), n, years);
    output_file = fmt::format("DATA{:%Y-%m-%d-%M-%S}-[n={},year={}].txt", *std::localtime(&systime), n, years);
    ofstream outinv(input_file);
    ofstream outdata(output_file);

    // Calculation Begin!
    std::array<double, n> rs = {};
    std::array<double, n> phis = {};
    std::array<double, n> as = {};
    for (int i = 0; i < n; i++) {
        phis[i] = u(e);
        rs[i] = 2 + ((double) i) / (n - 1) * 1.5;
        outinv << rs[i] << " " << phis[i] << endl;
    }
    cout << "Output Initial Value Finished!" << endl;

#pragma omp parallel for
    for (int i = 0; i < n; i++) {
        double r, phi;
        r = rs[i];
        phi = phis[i];
        PhaseVector q0 = {5.458104, 0, r * cos(phi), r * sin(phi)};
        PhaseVector p0 = {0, sqrt(Ms * (1 - 0.048912) / 5.458104),
                  -sqrt(4 * PI * PI / r) * sin(phi),
                  sqrt(4 * PI * PI / r) * cos(phi)};
        Hamilton H(q0, p0, 0, years);
        H.solve(1.0 / 16.0);

        double xj = (H.q).back()[0];
        double yj = (H.q).back()[1];
        double xa = (H.q).back()[2];
        double ya = (H.q).back()[3];
        double vxa = (H.p).back()[2];
        double vya = (H.p).back()[3];
        double E = 0.5 * (vxa * vxa + vya * vya) - Ms / sqrt(xa * xa + ya * ya) -
                   Mj / sqrt((xa - xj) * (xa - xj) + (ya - yj) * (ya - yj));
        as[i] = -2 * PI * PI / E;
        //if (i % 100 == 0) {
        //    cout << i << " ";
        //}
    }
    finish = clock();
    for (int j = 0; j < n; ++j) {
        outdata << as[j] << endl;
    }
    cout << "Output Result Finished! Total time: " << ((double) finish - begin) / CLOCKS_PER_SEC << endl;
    return 0;
}