#include <vector>
#include <QtWidgets>
#include <QApplication>
#include <QString>
#include <string>
using namespace std;
struct spref { // в ней придётся делать индексацию 1-ю, но запросы нужно делать в индексации 0-й
    int query(int x1, int y1, int x2, int y2) { // отрезок [] и [] индексация 0 
        x1++; y1++; x2++; y2++;
        return pref[x2][y2]
            - pref[x1 - 1][y2]
            - pref[x2][y1 - 1]
            + pref[x1 - 1][y1 - 1];
    }
    int n = 0;
    int m = 0;
    vector<vector<int>>pref;
	spref(QImage& picture_obj) {
        QSize sizeImage = picture_obj.size();
        int m = sizeImage.width(), n = sizeImage.height();
        pref.assign(n, vector<int>(m, 0));
        QRgb color;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                color = picture_obj.pixel(j, m);
                pref[i + 1][j + 1] = pref[i][j + 1] + pref[i + 1][j] - pref[i][j] + qRed(color);
            }
        }
	}
};
//vector<vector<int>>pref;
//vector<vector<int>>& calc(QImage& im) {
//	QSize sizeImage = picture_obj.size();
//	int width = sizeImage.width(), height = sizeImage.height();
//	for (int i = 0; i < width; i++) {
//		for (int j = 0; j < height; j++) {
//
//		}
//	}
//	return pref;
//}