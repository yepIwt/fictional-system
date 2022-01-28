#include <iostream>
#include <sstream>
#include <vector>
#include <QtWidgets>
#include <QApplication>
#include <QtGui>
//Libs
#include "src/learning.h"
#include "src/pics_set.h"
#include "src/struct.h"
//#include "src/learning/countmask.h"


// PICS methods
//#include "src/pics/set/pics.h"
//#include "src/pics/set/lbp.h"

// NET / STRUCTURE methods
//#include "src/struct/prefim.h"5

// NET / TEMPLATES methods
//#include "src/struct/algen.h"
//#include "src/learning/create_w.h"

// NET methods
//#include "src/learning/countmask.h"

#define pii pair<int,int>

using namespace std;
using namespace filesystem;

const int P = 8;
const int R = 1;
const int szimx = 32;
const int szimy = 32;

const char* wayshab = "D:/maybe_project/sources/shabk.out";

void init(
    vector<pair<pii, pii>>& shab) {
    freopen(wayshab, "r", stdin);
    int xl, yl, xr, yr;

    while (cin >> xl >> yl >> xr >> yr) {
        shab.push_back({ {xl,yl},{xr,yr} });
    }
}

int main(int argc, char *argv[]){
    
    vector<pair<pii, pii>> shab;
    vector<double> threshold;
    init(shab);
    std::cout << "Something works";
    //cntweak(threshold, shab);
    //freopen("rest")
    //gen(szimx, szimy,szimx,szimy);
    //const string waycasc = "D:/maybe_project/cascades/";
    //const string waytestim = "D:/faces_aligned_small_mirrored_co_aligned_cropped_cleaned/M/";
    //map<string, pair<double,double>>mp;
    //for (auto& entry : directory_iterator(waycasc)) {
    //    stringstream prom;
    //    // entry - string (name of file)
    //    //double cnterror = 0;
    //    //double cbnttrue = 0;
    //    //prom.clear();
    //    prom.str("");
    //    prom << entry;
    //    prom.flush();
    //    string pthe;
    //    prom >> trash;
    //    prom >> pthe;
    //    pthe.pop_back();
    //    //prom.clear();
    //    //entry.path();
    //    int sumb = 0;
    //    int sumw = 0;
    //    QImage casc = open_picture(pthe);
    //    //map<int, int>bar;
    //    for (auto& entryim : directory_iterator(waytestim)) {
    //        stringstream prom;
    //        prom.str("");
    //        string pthim;
    //        prom << entryim;
    //        prom.flush();
    //        prom >> trash;
    //        prom >> pthim;
    //        pthim.pop_back();
    //        QImage im = open_picture(pthim);
    //        QImage imbw = make_bw_picture(im);
    //        spref image(imbw);
    //        QRgb colorrgb;
    //        QColor color;
    //        QColor chw;
    //        for (int j = 0; j < szimx; j++) {
    //            for (int i = 0; i < szimy; i++) {
    //                colorrgb = casc.pixel(i, j);
    //                color = colorrgb;
    //                //chw = Qt::black;
    //                if (color == Qt::black) {
    //                    sumb += image.query(j, i, j, i);
    //                }
    //                else sumw += image.query(j, i, j, i);
    //            }
    //        }
    //        int br = sumw - sumb;
    //        bar.push_back(br);
    //        if (bar.size() == maxszbar) break;
    //       // cout << sumw << " " << sumb << "\n";
    //    }
    //    break;
    //}
    //int n = bar.size();
    //sort(bar.begin(), bar.end());
    //cout << bar[n / 2] << "\n";
    //return 0;
}