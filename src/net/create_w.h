#include <sstream>
#include <random>
#include <algorithm>
#include <ctime>
#include "prefim.h"
#include <chrono>
#include <vector>
#include <string>
#include <iterator>
#include "../pics/pics.h"
using namespace std;
using namespace chrono;
using namespace filesystem;
#include <filesystem>
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
//using namespace chrono;
const int maxszx = 32;
const int maxszy = 32;
char trash;
void takenames(vector<pair<spref, int>>& testim, const string& path, int val) {
    for (auto& entry : std::filesystem::directory_iterator(path)) {
        stringstream prom;
        // entry - string (name of file)
        //double cnterror = 0;
        //double cbnttrue = 0;
        //prom.clear();
        prom.str("");
        prom << entry;
        prom.flush();
        string pthe;
        prom >> trash;
        prom >> pthe;
        pthe.pop_back();
        //pthe.
        //prom.clear();
        //entry.path();
       // int sumb = 0;
       // int sumw = 0;
        QImage in = open_picture(pthe);
        scale(in);
        QImage casc = make_bw_picture(in);
        //spref ins(in);
        testim.push_back({ spref(casc),val });
    }
}
void cntweak(vector<double>& threshold,vector<pair<pair<int,int>,pair<int,int>>>&shab) {
    //srand(time(NULL));
    threshold.clear();
    const char* save = "D:/maybe_project/sources/teta.out";
    const char* savelog = "D:/maybe_project/sources/log.out";
    const string patht = "D:/weak_learning/true/";
    const string pathf = "D:/weak_learning/false/";
	vector<pair<spref, int>>testim; // {-1,1}
    takenames(testim, pathf, -1);
    const int cntsz = testim.size();
    takenames(testim, patht, 1);
    //shuffle(testim.begin(), testim.end(), rand);
    const double allsz = testim.size();
    //freopen(save, "w", stdout);
    freopen(save, "w", stdout);
    freopen(savelog, "w", stderr);
    //freopen()
    for (int i = 0; i < shab.size(); i++) {
        double ottsz = cntsz; // � ����� false ����� �������
        vector<pair<int, int>>res;
        for (int j = 0; j < testim.size(); j++) {
            int w = testim[j].first.query(0, 0, maxszx - 1, maxszy - 1);
            int b = testim[j].first.query(shab[i].first.first, shab[i].first.second, shab[i].second.first, shab[i].second.second);
            res.push_back({ w - b,testim[j].second });
        }
        double rate = 0;
        double resw = 0;
        sort(res.begin(), res.end());
        for (int j = 0; j < res.size(); j++) {
            if ((allsz - ottsz) / allsz > rate) {
                rate = (allsz - ottsz) / allsz;
                resw = res[j].first;
            }
            if (res[j].second == -1) ottsz--;
            else ottsz++;
        }
        threshold.push_back(resw);
        cout << resw << "\n";
        cerr << resw << " " << "rateerror: " << rate << "\n";
    }// sumw - sumb
}