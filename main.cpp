#include <QtWidgets>
#include <QApplication>
#include <QtGui>

#include "src/pics.h"

int main(int argc, char *argv[]){
    /* Example using src/pics.h */
    QImage pic = open_picture("pic.png");
    QImage cropped_pic = crop_picture(pic,0,0,128,128);
    save_image(cropped_pic, "cropped_pic.png");
    return 0;
}