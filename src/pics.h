#include <QtWidgets>
#include <QApplication>
#include <QtGui>
#include <QString>

#include <string>

#include <iostream>

QImage open_picture(std::string pic_name){
    QImage image;
    QString qpic_name = pic_name.c_str();
    image.load(qpic_name);
    return image;
};

QImage crop_picture(QImage picture_obj, int x1, int y1, int x2, int y2){
    QImage cropped_picture_obj;
    cropped_picture_obj = picture_obj.copy(x1,y1,x2,y2);
    return cropped_picture_obj;
};

QImage make_bw(QImage picture_obj){
    QSize sizeImage = picture_obj.size();
    int width = sizeImage.width(), height = sizeImage.height();
    QRgb color;
    int value;
    for (int f1=0; f1<width; f1++) {
        for (int f2=0; f2<height; f2++) {
            color = picture_obj.pixel(f1,f2);
            int gray = (qRed(color) + qGreen(color) + qBlue(color))/3;
            picture_obj.setPixel(f1, f2, qRgb(gray, gray, gray));
        }
    };
    return picture_obj;

};

void lgb(QImage picture_obj){
    QSize sizeImage = picture_obj.size();
    int width = sizeImage.width(), height = sizeImage.height();
    int max = (width * height) / 9;
    int answ[max][3][3];

    int counter=0;
    //std::cout<<width<<" "<<height<<"\n";
    for (int i=0; i<width; i++){
        for (int j=0; j<height; j++){
            int num = (i/3) * (width/3) + (j/3);
           // int ci = i - (num / 3) * 3;
           // int cj = j - (num % 3) * 3;
            int ci = i - (num / (width / 3))*3;
            int cj = j - (num % (width / 3))*3;
            int color =  picture_obj.pixel(i,j);
            answ[num][ci][cj] = qRed(color) + qGreen(color) + qBlue(color);
        }
    }
    

    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            std::cout << answ[0][i][j];
            std::cout << " | ";
        }
        std::cout << "\n";
    }
    std::cout << "\n\n";

    // for (int i=0; i < width; i++){
    //     for (int j=0; j < height; j++){
    //         int num = (i/3) * (width/3) * (j/3);
    //         std::cout << ""
    //     }
    // }


}

void save_image(QImage picture_obj, std::string filename){
    QString qfilename = filename.c_str();
    picture_obj.save(qfilename);
};