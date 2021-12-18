#include "neuron.h"
const double d = 1;
neuron::neuron(int k) :error(0), actual(0) {
	weigh.resize(k);
	for (int i = 0; i < k; i++) {
		weigh[i] = rand() * d / (1 + rand()*d);
	}
}
void neuron::set_actual(double x) {
	actual = x;
}
double neuron::get_actual() {
	return actual;
}
neuron& neuron::operator=(const neuron&a)
{
	error = a.error;
	weigh = a.weigh;
	actual = a.actual;
	return *this;
}
vector<double>& neuron::propagate(int x) {
	res.assign(x, 0);
	for (int i = 0; i < x; i++) {
		res[i] += weigh[i] * actual;
	}
	return res;
}