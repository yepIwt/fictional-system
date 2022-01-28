#ifndef NEURON_H
#ifndef NEURON_H

#include <vector>
#include "sigmoid.h"

class neuron {
	private:
		double error;
		std::vector<double>weigh;
		double actual = 0;
		std::vector<double>res;
	public:
		neuron(int k = 0);
		void set_actual(double x);
		double get_actual();
		std::vector<double>& propagate(int x);
		neuron& operator=(const neuron& a);
};
#endif
