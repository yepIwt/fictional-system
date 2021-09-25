#include "neuron_net.h"
neuron_net::neuron_net(int insz,int x) {
	net.resize(x + 1);
	layer cur(insz,x);
	net[0] = cur;
	levelsz = x;
	for (int i = 1; i <= x; i++) {
		layer cur(x, x);
		net[i] = cur;
	}
}
double neuron_net::start(vector<double>&in) { // in.size() = insz
	for (int i = 0; i < in.size(); i++) {
		net[0].in_neuron(i, in[i]);
	}
	for (int i = 0; i < levelsz; i++) {
		vector<double>a=net[i].next(net[i].next_layrsz);
		for (int j = 0; j < net[i + 1].next_layrsz; j++) {
			net[i + 1].activate_neuron(j, a[j]);
		}
	}
	double ans = 0;
	int sz = net.size() - 1;
	for (int i = 0; i < net[sz].layer_sz; i++) {
		ans += net[sz].get_neuron_actual(i);
	}
	return sigmoid(ans);
}