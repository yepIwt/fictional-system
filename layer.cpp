#include "layer.h"
#include <vector>
using std::vector;
layer::layer(int x, int y) {
	neurons.resize(x);
	next_layrsz = y;
	layer_sz = x;
	for (int i = 0; i < x; i++) {
		neuron cur(y);
		neurons[i] = cur;
	}
}
//void layer::set_cur(int x) {
//	cur = x;
//}
vector<double>& layer::next(int x) { // x - кол - во в след слое // возвращает вектор суммирования
	//vector<double>next(x);
	nextv.assign(x, 0);
	vector<double>next1;
	for (auto& c : neurons) {
		next1 = c.propagate(x);
		for (int i = 0; i < next1.size(); i++) {
			nextv[i] += next1[i];
		}
	}
	//cur = 0;
	return nextv;
}
void layer::in_neuron(int i, double x) {
	neurons[i].set_actual(x);
}
void layer::activate_neuron(int i, double x) {
	neurons[i].set_actual(sigmoid(x));
}
double layer::get_neuron_actual(int i) {
	return neurons[i].get_actual();
}
layer& layer::operator=(const layer& a) {
	neurons.resize(a.neurons.size());
	for (int i = 0; i < a.neurons.size(); i++) {
		neurons[i] = a.neurons[i];
	}
	//cur = a.cur;
	layer_sz = a.layer_sz;
	next_layrsz = a.next_layrsz;
	return *this;
}
