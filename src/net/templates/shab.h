#include <string>

#include <QColor> // Qt::white
#include <QImage> // QImage


//#define double long double // g++ sucks

QImage generate(int x, int y, int w, int h, int maxx, int maxh) {
	
	if ((x + w >= maxx) || (y + h >= maxh)) return QImage();

	QImage res(maxx, maxh, QImage::Format_Grayscale8);

	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			res.setPixelColor(i, j, Qt::white);
		}
	}

	for (int i = x; i < x + w; i++) {
		for (int j = y; j < y + h; j++) {
			res.setPixelColor(i, j, Qt::black);
		}
	}

	return res;
}