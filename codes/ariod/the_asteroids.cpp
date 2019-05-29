#include<fstream>
#include<iostream>
#include<random>
#include<time.h>
#include"Hamilton.h"
const double PI = 3.14159265358979323846, Ms = 4 * PI * PI, Mj = Ms / 1047.56;
using namespace std;

const auto n = 20000;
int main()
{
    time_t systiem = time(nullptr);
    struct tm *pTm;
    pTm = gmtime(&systiem);
    //std::random_device rd; Fuck gcc.
    auto seed = systiem;
	std::mt19937_64 e(seed);
	std::uniform_real_distribution<double> u(-0.1, 0.1);
    //std::uniform_int_distribution<int> year(6000, 8000);
    int years = 2000;
    char input_file[256]={0};
    char output_file[256]={0};
    sprintf(input_file, "IV%d-%d-%d%d-[(%d)_(%d)].txt", 1+pTm->tm_mon, pTm->tm_mday,pTm->tm_hour,pTm->tm_min, years, n);
    sprintf(output_file,"DATA%d-%d-%d%d-[(%d)_(%d)].txt", 1+pTm->tm_mon, pTm->tm_mday,pTm->tm_hour,pTm->tm_min, years, n);

    //double r = u(e);
	//std::vector<double> q0 = { 5.4588, 0, r, 0 };
	//std::vector<double> p0 = { 0, 2.62267, 0, sqrt(4 * PI * PI / r) };
	//Hamilton H(q0, p0, 0, 2000);
	//H.solve(1.0 / 16.0);


	ofstream outinv(input_file);
	double bias = u(e);
	for (double i = 0; i < n; i++)
	{
	    //outinv << 2+bias<<endl;
		outinv << 2 + i / (n - 1) * 1.5 + bias << endl;
	}
	cout << "Output Initial Value Finished!" << endl;

	cout << "Will end at "<<n<<endl;

	ifstream in_data(input_file);
	ofstream outdata(output_file);
	for (int i = 0; i < n; i++)
	{
		double r;
		in_data >> r;
		if (r==0)
		{
			return -1;
		}
		std::vector<double> q0 = { 5.4588, 0, r, 0 };
		std::vector<double> p0 = { 0, 2.62267, 0, sqrt(4 * PI * PI / r) };
		Hamilton H(q0, p0, 0, years);
		H.solve(1.0 / 16.0);
		double xj = (H.q).back()[0];
		double yj = (H.q).back()[1];
		double xa = (H.q).back()[2];
		double ya = (H.q).back()[3];
		double vxa = (H.p).back()[2];
		double vya = (H.p).back()[3];
		//cout<<xj<<endl<<yj<<endl;
		double E = 0.5 * (vxa * vxa + vya * vya) - Ms / sqrt(xa * xa + ya * ya) - Mj/sqrt((xa-xj) * (xa-xj) + (ya-yj) * (ya-yj));
		outdata << -2*PI*PI / E << endl;
		if (i%10==0)
			cout << i << " ";
	}
	cout << "Output Result Finished!" << endl;
	return 0;
}