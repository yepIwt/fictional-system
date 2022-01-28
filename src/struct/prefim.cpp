#include "prefim.h"
int spref::query(int x1, int y1, int x2, int y2) {
    x1++; y1++; x2++; y2++;
    return pref[x2][y2]
        - pref[x1 - 1][y2]
        - pref[x2][y1 - 1]
        + pref[x1 - 1][y1 - 1];
}
spref::spref(QImage& picture_obj) {
    QSize sizeImage = picture_obj.size();
    int m = sizeImage.width(), n = sizeImage.height();
    pref.assign(n + 1, std::vector<double>(m + 1, 0));
    QRgb color;

    for (int i = 0; i < m; i++) {

        for (int j = 0; j < n; j++) {
            color = picture_obj.pixel(i, j);
            pref[i + 1][j + 1] = pref[i][j + 1] + pref[i + 1][j] - pref[i][j] + qRed(color);
        }

    }
}