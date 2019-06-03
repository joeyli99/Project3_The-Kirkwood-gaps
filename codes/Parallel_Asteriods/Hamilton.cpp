#include<iostream>
#include "Hamilton.h"

constexpr double PI = 3.14159265358979323846, Ms = 4 * PI * PI;
constexpr double Mj = Ms / 1047.56;

void Hamilton::solve(double step) {
    const int total = int(ceil((start-end))/step);
    t.reserve(total);
    p.reserve(total);
    q.reserve(total);
    //solve the Hamilton system by Yoshida 8-order.
    double d[16] = {
            1.04242620869991,
            1.82020630970714,
            0.157739928123617,
            2.44002732616735,
            -0.0071698941970812,
            -2.44699182370524,
            -1.61582374150097,
            -1.7808286265894515,
            -1.61582374150097,
            -2.44699182370524,
            -0.0071698941970812,
            2.44002732616735,
            0.157739928123617,
            1.82020630970714,
            1.04242620869991,
            0.0
    };
    double c[16] = {
            0.521213104349955,
            1.4313162592035251,
            0.9889731189153784,
            1.2988836271454836,
            1.2164287159851346,
            -1.2270808589511606,
            -2.031407782603105,
            -1.6983261840452109,
            -1.6983261840452109,
            -2.031407782603105,
            -1.2270808589511606,
            1.2164287159851346,
            1.2988836271454836,
            0.9889731189153784,
            1.4313162592035251,
            0.521213104349955
    };

    //Youshiba 8
    //#pragma omp parallel for
    for (double time = start + step; time < end; time += step) {
        std::array<double, 4> q_now = q.back();
        std::array<double, 4> p_now = p.back();

        for (int i = 0; i < 16; i++) {
            PhaseVector dq_now = dq(p_now);
            double c_step = c[i];
            double d_step = d[i];
            for (int j = 0; j < dim; j++) {
                q_now[j] += c_step * step * dq_now[j];
            }
            PhaseVector dp_now = dp(q_now);
            for (int j = 0; j < dim; j++) {
                p_now[j] -= d_step * step * dp_now[j];
            }
        }
        p.push_back(p_now);
        q.push_back(q_now);
        t.push_back(time);
    }
    //std::cout << "Solve END" << std::endl;
}

PhaseVector Hamilton::dp(const PhaseVector &qarray) {
    double xj = qarray[0],
            yj = qarray[1],
            xa = qarray[2],
            ya = qarray[3],
            rj = sqrt(xj * xj + yj * yj),
            ra = sqrt(xa * xa + ya * ya),
            daj = sqrt((xa - xj) * (xa - xj) + (ya - yj) * (ya - yj));
    PhaseVector Hq = {Ms * xj / pow(rj, 3), Ms * yj / pow(rj, 3),
              Ms * xa / pow(ra, 3) + Mj * (xa - xj) / pow(daj, 3),
              Ms * ya / pow(ra, 3) + Mj * (ya - yj) / pow(daj, 3)};
    return Hq;
}

PhaseVector Hamilton::dq(const PhaseVector &parray) {
    return parray;
}
