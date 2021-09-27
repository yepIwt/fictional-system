#include <QtWidgets>
#include <QApplication>
#include <QtGui>
#include <QString>

#include <string>

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

void save_image(QImage picture_obj, std::string filename){
    QString qfilename = filename.c_str();
    picture_obj.save(qfilename);
};