#include <random>
void takenames(vector<string, int>& testim, string& path, int val) {
    for (auto& entry : directory_iterator(path)) {
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
        //prom.clear();
        //entry.path();
       // int sumb = 0;
       // int sumw = 0;
      //  QImage casc = open_picture(pthe);
        testim.pb({ pthe,val });
    }
}
void cntweak(vector<double>& threshold,vector<pair<pair<int,int>,pair<int,int>>shab) {
    srand(time(NULL));
    const string patht = "D:/weak_learning/true/";
    const string pathf = "D:/weak_learning/false/";
	vector<pair<string, int>>testim; // {-1,1}
    takenames(testim, patht, 1);
    takenames(testim, pathf, -1);
    std::random_shuffle(takenames.begin(), takenames.end());
}