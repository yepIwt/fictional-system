#include <QtWidgets>
#include <QApplication>
#include <QtGui>

#include "src/pics.h"
#include "src/lbp.h"

const int P = 8;
const int R = 1;

int main(int argc, char *argv[]){

    /* Example using */

    /* Step 1 */
    QImage pic = open_picture("human.png");

    /* Step 2 */
    pic = lead_to_a_common_denominator(pic, R);

    /* Step 3 */
    QImage bw_pic = make_bw_picture(pic);
    save_picture(bw_pic, "BW.png");

    /* Step 4 */
    LBP lbp_algorithm(bw_pic, P, R);
    QImage lbp_result = lbp_algorithm.create_circle_lbp();
    
    /* Step 5 */
    save_picture(lbp_result, "LBP.png");

    return 0;
}