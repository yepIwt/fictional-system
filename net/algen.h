//#ifndef gist
#include <QtWidgets>
#include <QApplication>
#include <QString>
#include <string>
#include "shab.h"
#include <string>
#define double long double
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
void gen(const int szx, const int szy, int maxw, int maxh) {
	std::string start = "cascades/haar";
	int cnt = 0;
	for (int x = 0; x < szx; x++) {
		for (int y = 0; y < szy; y++) {
			for (int w = 1; w <= maxw; w++) {
				for (int h = 1; h <= maxh; h++) {
					QImage res = generate(x, y, w, h, szx, szy);
					if (!res.isNull()) {
						std::string curs = start;
						curs = curs + converti_s(cnt++) + ".png";
						save_picture(res, curs);
					}
					else break;
				}
			}
		}
	}
}