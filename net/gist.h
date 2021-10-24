//#ifndef gist
#include <QtWidgets>
#include <QApplication>
#include <QString>
#include <string>
#define double long double
class gist {
private: 
	QImage have;
	//QImage res;
	double border = 62.25;
	double EPS = 1e-6;
	//QColor colorb;
	//QColor colorw;
public:
	gist() {

	}
	void set_n(double n) {
		border = n;
	}
	QImage build(QImage& cur) {
		QRgb color;
		QSize sz = cur.size();
		int width = sz.width();
		int height = sz.height();
		//QImage::format = 24;
		QImage res(width, height, QImage::Format_Grayscale8);
		//res = res.scaled(sz);
		double curn;
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) { // Qimage.pixel(x,y)
				color = cur.pixel(i, j);
				curn = (0.216 * qRed(color)) + (0.7152 * qGreen(color)) + (0.0722 * qBlue(color));
				if (curn - border < EPS) {
					res.setPixelColor(i, j, Qt::black);
				}
				else {
					res.setPixelColor(i, j, Qt::white);
				}
			}
		}
		return res;
	}
};
//#endif // !gist
