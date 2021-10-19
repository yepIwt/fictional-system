#ifndef neuron_net
#include "layer.h"
class neuron_net {
public:
	vector<double>ansar;
	vector<layer>net;
	int levelsz;
	neuron_net(int insz, int x, int outsz); //x - ���-�� ������� insz - ����������� ������� ������
	vector<double>& start(vector<double>&in);
	void back_propagate(double ans);
};
#endif // !neuron_net
