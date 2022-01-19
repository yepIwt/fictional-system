#include <vector>
#include <QtWidgets>
#include <QApplication>
#include <QString>
#include <string>
#include "prefim.h"
#include <iostream>
using namespace std;
//#define double long double
//const int maxszx = 32;
//const int maxszy = 32;
double logn(double v) {
	return log(v);
}
void adaboost(vector<pair<spref,int>>& testim, vector<pair<pair<int, int>, pair<int, int>>>& shab,vector<double>&teta,int epoch) {
//  1 - true 0 - false
	double m = testim.size();
	vector<double>d(m);
	for (int i = 0; i < m; i++) {
		d[i] = 1ll / m;
	}
	for (int ep = 0; ep < epoch; ep++) {
		int T = shab.size();
		const double z = 0.1;
		const double cntall = m;
		vector<double>alphas;
		vector <double> tets;
		for (int i = 0; i < T; i++) {
			double error = 0.99999;
			double incnt = 0;
			double valcost = 1e18;
			vector<pair<int, int>>res;
			for (int j = 0; j < m; j++) {
				double w = testim[j].first.query(0, 0, maxszx - 1, maxszy - 1);
				double b = testim[j].first.query(shab[i].first.first, shab[i].first.second, shab[i].second.first, shab[i].second.second);
				res.push_back({ w - b,testim[j].second });
				if (testim[j].second == 1 && d[j] >= incnt) {
					incnt = d[j];
					valcost = min(w - b, valcost);
				}
			}
			double cntfalse = 0;
			for (int j = 0; j < m; j++) {
				if ((res[j].first >= valcost && res[j].second == -1) || (res[j].first < valcost && res[j].second == 1)) {
					cntfalse++;
				}
			}
			//error = min(error, cntfalse / cntall);
			double alpha = (logn((1 - error) / (error))) / 2;
			for (int j = 0; j < m; j++) {
				if ((res[j].first >= valcost && res[j].second == -1) || (res[j].first < valcost && res[j].second == 1)) { // >= valcost - лицо
					d[j] = d[j] * ((sqrt((1 - error) / (error))) / z); // false
				}
				else {
					d[j] = d[j] * ((sqrt((error) / (1 - error))) / z); // true
				}
			}
			alphas.push_back(alpha);
			tets.push_back(valcost);
		}
		freopen("log_learn.out", "w", stdout);
		freopen("costs_im.out", "w", stderr);
		cerr << "epoch: " << ep << "\n";
		cout << "epoch: " << ep << "\n";
		for (auto& c : d) {
			cerr << c << " ";
		}
		cerr << "\n";
		cout << "alphas:\n";
		for (auto& c : alphas) {
			cout << c << " ";
		}
		cout << "\n";
		cout << "tets:\n";
		for (auto& c : tets) {
			cout << c << " ";
		}
		cout << "\n";
	}
}