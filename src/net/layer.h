#ifndef LAYER_H
#define LAYER_H

#include "neuron.h"

class layer {
	private:
		vector<neuron>neurons;
		//int cur = 0;
		vector<double>nextv;
	public:
		int layer_sz;
		int next_layrsz;
		layer(int x = 0, int y = 0);
		//void set_cur(int x);

		vector<double>& next(int x);
		layer& operator=(const layer& a);
		void in_neuron(int i, double x);
		void activate_neuron(int i, double x);
		double get_neuron_actual(int i);
};

#endif // !input_layer