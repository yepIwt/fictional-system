#include <iostream>

#include <QImage>
#include <QSize>
#include <QColor>

using namespace std;
int cnt(string& shabname, string&imagename, int sposx, int sposy) {
	QImage pic = open_picture(shabname);
	QImage im = open_picture(imagename);

	QSize sz = pic.size();
	QRgb color;

	//QSize sz1 = im.size();
	int w = sz.width(); int h = sz.height(); sz = im.size();
	int w1 = sz.width(); int h1 = sz.height();

	double sumblack = 0;
	double sumwhite = 0;

	if (sposx + w >= w1 || sposy + h >= h1) return 0;

	for (int i = sposx; i < sposx + w; i++) {
		for (int j = sposy; j < sposy + h; j++) {
			color = im.pixel(i, j);
		}
	}

	if (sumblack > sumwhite) return 1; else return 2;
}
