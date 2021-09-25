#ifndef neuron_net
#include "layer.h"
class neuron_net {
public:
	vector<layer>net;
	int levelsz;
	neuron_net(int insz, int x); //x - кол-во уровней insz - размерность входных данных
	double start(vector<double>&in);
};
#endif // !neuron_net
