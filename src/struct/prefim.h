#include <vector>
#include <string>

#ifndef __PREFIM__
#define _PREFIM_
#include <QString>
#include <QColor> // QRgb
class spref { 
private:
    int n = 0;
    int m = 0;
    std::vector<std::vector<double>> pref;
public:
    int query(int x1, int y1, int x2, int y2);

    spref(QImage& picture_obj);
};
#endif
