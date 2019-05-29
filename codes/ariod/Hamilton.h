#pragma once
#pragma once
#include<cmath>
#include<vector>
class Hamilton
{
public:
	Hamilton(const std::vector<double>& set_q0, const std::vector<double>& set_p0, double set_start, double set_end)
	{
		dim = static_cast<int>(set_q0.size());
		q0 = set_q0;
		p0 = set_p0;
		start = set_start;
		end = set_end;
		t.push_back(set_start);
		p.push_back(p0);
		q.push_back(q0);
	};
	~Hamilton() = default;
	std::vector<std::vector<double> > p;
	std::vector<std::vector<double> > q;
	void solve(double step);

private:
	int dim;
	std::vector<double> q0;
	std::vector<double> p0;
	std::vector<double> t;
	double start;
	double end;
	std::vector<double> dp(const std::vector<double> &q);
	std::vector<double> dq(const std::vector<double> &p);
};
