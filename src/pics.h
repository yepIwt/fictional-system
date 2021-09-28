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

QImage make_bw(QImage picture_obj){
    // QImage bw_pic = picture_obj;
    // bw_pic.applyColorTransform(QImage::Format_Grayscale8);
    // return bw_pic;
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

void save_image(QImage picture_obj, std::string filename){
    QString qfilename = filename.c_str();
    picture_obj.save(qfilename);
};