#include <iostream>
#include "neuron_net.h"
#include <random>
using std::rand;
int main()
{
	srand(time(NULL));
	neuron_net net(2,2,1);
	char c;
	while (1) {
		int x = rand() % 2;
		int y = rand() % 2;
		int ans = x ^ y;
		vector<double>cur;
		cur.push_back(x);
		cur.push_back(y);
		vector<double>ansar = net.start(cur);
		for (auto& c : ansar) {
			std::cout << "out net: " << c << "\n";
		}
		std::cout << "res: " << ans << "\n";
		std::cin >> c;
	}
}