#pragma once
#pragma once

#include<cmath>
#include<vector>
#include <array>
typedef std::array<double, 4> vec;
class Hamilton {
public:
    Hamilton(const vec &set_q0, const vec &set_p0, double set_start, double set_end) {
        q0 = set_q0;
        p0 = set_p0;
        start = set_start;
        end = set_end;
        t.push_back(set_start);
        p.push_back(p0);
        q.push_back(q0);
        t.reserve(100000);
        p.reserve(100000);
        q.reserve(100000);
    };

    ~Hamilton() = default;

    std::vector<vec > p;
    std::vector<vec > q;
    std::vector<double> t;

    void solve(double step);

private:
    const int dim=4;
    vec q0{};
    vec p0{};
    double start;
    double end;

    vec dp(const vec &q);

    vec dq(const vec &p);
};
