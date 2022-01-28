#ifndef __algen__
#define __algen__
#include <string>

#include <QString>
#include <QImage> // QImage

#include "shab.h"

//#define double long double // g++ sucks

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
						curs += converti_s(cnt++) + ".png";

						// Save picture
						QString qfilename = curs.c_str();
    					res.save(qfilename);
					}
					else break;
				}
			}
		}
	}
}
#endif