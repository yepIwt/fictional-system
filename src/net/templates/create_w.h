#include <random>
#include <vector>
#include <string>
#include <sstream>
#include <time.h>
#include <algorithm> // random_shuffle

// directory iterator required
#include <fstream>
#include <iostream>
#include <filesystem>

void takenames(std::vector<std::pair <std::string, int>>& testim, std::string& path, int val) {

    const std::filesystem::path iter_path{path};

    for(auto& entry : std::filesystem::recursive_directory_iterator(iter_path)){
        std::stringstream prom;
        // entry - string (name of file)
        //double cnterror = 0;
        //double cbnttrue = 0;
        //prom.clear();
        prom.str("");
        prom << entry;
        prom.flush();
        std::string pthe;

        // where was "trash" - why?

        prom >> pthe;
        pthe.pop_back();
        //prom.clear();
        //entry.path();
       // int sumb = 0;
       // int sumw = 0;
      //  QImage casc = open_picture(pthe);
        testim.push_back({ pthe,val });
    }
}

void cntweak(
        std::vector<double>& threshold, 
        std::vector<
            std::pair<
                std::pair<int, int>,
                std::pair<int, int>
            >
        > shab // это пиздец.
    ) {
    srand(time(NULL));
    
    std::string patht = "D:/weak_learning/true/";
    std::string pathf = "D:/weak_learning/false/";
	
    std::vector< 
        std::pair <std::string, int>
    > testim; // {-1,1}

    takenames(testim, patht, 1);
    takenames(testim, pathf, -1);
    
    // was std::random_shuffle(takenames.begin(), takenames.end()); idk its bullshit
    std::random_shuffle(testim.begin(), testim.end());

    // tommorow, i go to sleep
    // OK
}