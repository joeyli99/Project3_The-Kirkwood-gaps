#pragma once

#include<cmath>
#include<vector>
#include <array>
typedef std::array<double, 4> PhaseVector;
class Hamilton {
public:
    Hamilton(const PhaseVector &set_q0, const PhaseVector &set_p0, double set_start, double set_end) {
        q0 = set_q0;
        p0 = set_p0;
        start = set_start;
        end = set_end;
        t.push_back(set_start);
        p.push_back(p0);
        q.push_back(q0);
    };

    ~Hamilton() = default;

    std::vector<PhaseVector > p;
    std::vector<PhaseVector > q;
    std::vector<double> t;

    void solve(double step);

private:
    const int dim=4;
    PhaseVector q0{};
    PhaseVector p0{};
    double start;
    double end;

    PhaseVector dp(const PhaseVector &qarray);

    PhaseVector dq(const PhaseVector &parray);
};
