#ifndef prefim
#define prefim
#include <vector>
#include <QtWidgets>
#include <QApplication>
#include <QString>
#include <string>
using namespace std;
struct spref { // в ней придётся делать индексацию 1-ю, но запросы нужно делать в индексации 0-й
    int m = 33;
    int n = 33;
    vector<vector<double>>pref;
    spref(QImage& picture_obj) {
        QSize sizeImage = picture_obj.size();
        //int m = sizeImage.width(), n = sizeImage.height();
        pref.assign(n + 1, vector<double>(m + 1, 0));
        QRgb color;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                color = picture_obj.pixel(i, j);
                pref[i + 1][j + 1] = pref[i][j + 1] + pref[i + 1][j] - pref[i][j] + qRed(color);
            }
        }
    }
    int query(int x1, int y1, int x2, int y2) { // отрезок [] и [] индексация 0 
        x1++; y1++; x2++; y2++;
        return pref[x2][y2]
            - pref[x1 - 1][y2]
            - pref[x2][y1 - 1]
            + pref[x1 - 1][y1 - 1];
    }
 //   int n = 0;
};
#endif
