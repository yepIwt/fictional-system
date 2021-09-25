#ifndef neuron
#include "sigmoid.h"
#include <vector>
using std::vector;
class neuron {
private:
	double error;
	vector<double>weigh;
	double actual = 0;
	vector<double>res;
public:
	neuron(int k = 0); // кол - во связей от нейрона
	void set_actual(double x);
	double get_actual();
	vector<double>& propagate(int x);
	neuron& operator=(const neuron& a);
};
#endif
