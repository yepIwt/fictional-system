#include <QtWidgets>
#include <QApplication>
#include <QString>

#include <string>

QImage open_picture(std::string pic_name){
    QString qpic_name = pic_name.c_str();
    QImage picture_obj; picture_obj.load(qpic_name);
    
    return picture_obj;
}

QImage crop_picture(QImage picture_obj, int x1, int y1, int x2, int y2){
    return picture_obj.copy(x1,y1,x2,y2);
}

QImage lead_to_a_common_denominator(QImage picture_obj, int R) {

    /* Исправляет большую часть SF. Изображение может потерять несного пикселей по краям  */

    QSize sizeImage = picture_obj.size();
    int width = sizeImage.width(), height = sizeImage.height();
    int matrix_length = R * 2 + 1;

    while (width % matrix_length != 0) {
        width--;
    }
    while (height % matrix_length != 0) {
        height--;
    }

    return crop_picture(picture_obj, 0, 0, width, height);
}

QImage make_bw_picture(QImage picture_obj){
    /* 
        Я написал этот код, когда не знал как форматировать пикчи, 
        после написал код в две строчки, но он выдает предупреждение
        о глубине цвета. Оставлю свой рабочий код
    */

    QSize sizeImage = picture_obj.size();
    int width = sizeImage.width(), height = sizeImage.height();

    QRgb color;
    for (int f1=0; f1<width; f1++) {
        for (int f2=0; f2<height; f2++) {
            color = picture_obj.pixel(f1,f2);
            int gray = (qRed(color) + qGreen(color) + qBlue(color))/3;
            picture_obj.setPixel(f1, f2, qRgb(gray, gray, gray));
        }
    };
    return picture_obj;
};

void save_picture(QImage picture_obj, std::string filename){
    QString qfilename = filename.c_str();
    picture_obj.save(qfilename);
}
void scale(QImage& in) {
   QSize sz(32,32);
   QImage res=in.scaled(sz, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
   in = res;
   return;
}