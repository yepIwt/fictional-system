#include <QtWidgets>
#include <QApplication>
#include <QtGui>
#include <iostream>
#include "src/pics.h"
#include "src/lbp.h"
#include "net/gist.h"
#include "net/shab.h"
const int P = 8;
const int R = 1;

int main(int argc, char *argv[]){

    /* Example using */

    /* Step 1 */
    //QImage pic = open_picture("human.png");
    QImage pic = open_picture("a_b0416f14.png");
    if (!pic.isNull()) std::cout << "picload\n";
    else std::cout << "pic unload";
    gist gi;
    QImage res = gi.build(pic);
    save_picture(res, "gisto.png");
    res = generate(0, 0, 5, 5, 32, 32);
    save_picture(res, "testhaar.png");
    ///* Step 2 */
    //pic = lead_to_a_common_denominator(pic, R);

    ///* Step 3 */
    //QImage bw_pic = make_bw_picture(pic);
    //save_picture(bw_pic, "BW.png");

    ///* Step 4 */
    //LBP lbp_algorithm(bw_pic, P, R);
    //QImage lbp_result = lbp_algorithm.create_circle_lbp();

    ///* Step 5 */
    //save_picture(lbp_result, "LBP.png");
    //gist img;
    //img.set_n(10.0);
    //QImage resg = img.build(pic);
    ////img.build("LBP.png");
    return 0;
}