#include <QtWidgets>
#include <QApplication>
#include <QtGui>

#include "src/pics.h"

int main(int argc, char *argv[]){

    /* Example using */

    QImage pic = open_picture("human.png");

    pic = lead_to_a_common_denominator(pic);

    QImage bw_pic = make_bw_picture(pic);
    save_picture(bw_pic, "bw_albcvr.png");

    QImage lbp_pic = lbp(bw_pic);
    save_picture(lbp_pic, "picture_with_lbp.png");

    return 0;
}