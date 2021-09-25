#include "neuron_net.h"
neuron_net::neuron_net(int insz,int x, int outsz) {
	net.resize(x + 1);
	layer cur(insz,x);
	net[0] = cur;
	levelsz = x;
	for (int i = 1; i < x - 1; i++) {
		layer cur(x, x);
		net[i] = cur;
	}
	{
		layer cur(x, outsz);
		net[x - 1] = cur;
	}
	layer cur1(outsz, 1);
	net[x] = cur1;
}
vector<double>& neuron_net::start(vector<double>&in) { // in.size() = insz
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
	ansar.clear();
	for (int i = 0; i < net[sz].layer_sz; i++) {
		ansar.push_back(net[sz].get_neuron_actual(i));
	}
	return ansar;
}
void neuron_net::back_propagate(double ans) {

}