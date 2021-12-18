//#ifndef gist
#include <QtWidgets>
#include <QApplication>
#include <QString>
#include <string>
#include "shab.h"
#include <string>
#include <iostream>
//#define double long double
using namespace std;
std::string converti_s(int x) {
	std::string ans = "";
	while (x) {
		char b = '0' + (x % 10);
		ans += b;
		x /= 10;
	}
	std::reverse(ans.begin(), ans.end());
	return ans;
}
void gen(const int szx, const int szy, int maxw, int maxh) { // {szx,szy} - im, {maxw,maxh} - shab
	freopen("shabk.out", "w", stdout);
	std::string start = "cascades/haar";
	int cnt = 0;
	for (int x = 0; x < szx; x++) {
		for (int y = 0; y < szy; y++) {
			for (int w = 0; w <= maxw; w++) {
				for (int h = 0; h <= maxh; h++) {
					//QImage res = generate(x, y, w, h, szx, szy);
					if (x + w <= szx && y + h <= szy) {
						cout << x << " " << y << " " << x + w << " " << y + h << "\n"; // ������� - ������������ (xl,yl,xr,yr)
					}
					/*if (!res.isNull()) {
						std::string curs = start;
						curs = curs + converti_s(cnt++) + ".png";
						save_picture(res, curs);
					}
					else break;*/
				}
			}
		}
	}
}