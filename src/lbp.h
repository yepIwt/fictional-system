#include <QtGui>
#include <vector>

#include <bitset>
#include <string>

#define _USE_MATH_DEFINES
#include <cmath>

class matrix {
    public:
        std::vector < std::vector < QColor > > coordinate;
        void create(int matrix_length) {
            coordinate.resize(matrix_length);
            for (int i = 0; i < matrix_length; i++) {
                coordinate[i].resize(matrix_length); // this will allow you to now just use [][] to access stuff

            };
        };
};

class LBP {

    struct g {
        int x;
        int y;
        int color;
    };

    int P;
    int R;
    int max;
    g gc;

    unsigned int width, height;
    int matrix_length;
    QImage pic;

public:

    LBP(QImage picture, int P, int R) {
        /* Параметры LBP */
        this->P = P;
        this->R = R;
        this->matrix_length = R * 2 + 1;
        this->pic = picture;

        /* Параметры фото */
        const QSize sizeImage = pic.size();
        this->width = sizeImage.width(); this->height = sizeImage.height();
        this->max = (this->width * this->height) / pow(matrix_length, 2);
    }

    QImage create_circle_lbp() {

        QImage custom_picture(QSize(width, height), QImage::Format_Grayscale8);

        std::vector<matrix> pic_in_matrix = create_matrix_from_picture();

        /*
            Весь алгоритм взят из этой статьи
            https://core.ac.uk/download/pdf/231150157.pdf
        */

        for (int num = 0; num < max; num++) {
            g gc;
            gc.x = R; gc.y = R; gc.color = pic_in_matrix[num].coordinate[gc.x][gc.y].rgb();

            long int value_lbp = this->calculate_circle_lbp(gc, pic_in_matrix[num]);

            for (int i = 0; i < matrix_length; i++) {
                for (int j = 0; j < matrix_length; j++) {
                    pic_in_matrix[num].coordinate[i][j] = QColor(value_lbp, value_lbp, value_lbp);
                }
            }
        }

        /* Сборка матрицы с LBP */
        return assemble_matrix_into_picture(pic_in_matrix);
    }

    QImage create_simple_lbp() {
        std::vector<matrix> array_of_matrix = create_matrix_from_picture();

        int matrix_middle = matrix_length / 2;
        for (int k = 0; k < max; k++) {
            int etalon_in_rgb = array_of_matrix[k].coordinate[matrix_middle][matrix_middle].rgb();
            std::string lbp_var = "";

            for (int i = 0; i < matrix_length; i++) {
                for (int j = 0; j < matrix_length; j++) {

                    int value_in_rgb = array_of_matrix[k].coordinate[i][j].rgb();

                    /*
                        Это дебильная конструкция, но ничего умнее мне пока не нужно
                        В проде обязательно исправить
                    */

                    if (i == matrix_middle && j == matrix_middle) {
                        continue;
                    }
                    else {
                        lbp_var += value_in_rgb <= etalon_in_rgb ? std::to_string(0) : std::to_string(1);
                    }
                }

            }
            long int lbp = std::bitset<32>(lbp_var).to_ulong();
            for (int i = 0; i < matrix_length; i++) {
                for (int j = 0; j < matrix_length; j++) {
                    array_of_matrix[k].coordinate[i][j] = QColor(lbp, lbp, lbp);
                }
            }
        }


        return assemble_matrix_into_picture(array_of_matrix);

    }

private:

    bool s(int x) {
        if (x >= 0) {
            return 1;
        }
        else {
            return 0;
        }

    }

    QImage assemble_matrix_into_picture(std::vector<matrix> matrixes) {

        QImage custom_picture(QSize(width, height), QImage::Format_Grayscale8);

        for (int num = 0; num < max; num++) {
            for (int ci = 0; ci < (R * 2 + 1); ci++) {
                for (int cj = 0; cj < (R * 2 + 1); cj++) {
                    int i = ci + (num / (width / matrix_length)) * matrix_length;
                    int j = cj + (num % (width / matrix_length)) * matrix_length;
                    custom_picture.setPixelColor(i, j, matrixes[num].coordinate[ci][cj]);
                }
            }
        }
        return custom_picture;
    }


    std::vector<matrix> create_matrix_from_picture() {

        /* Разбиение на матрицы */

        std::vector<matrix> array_of_matrix(max);

        for (unsigned int i = 0; i < width; i++) {
            for (unsigned int j = 0; j < height; j++) {
                long int num = (i / matrix_length) * (width / matrix_length) + (j / matrix_length);
                long int ci = i - (num / (width / matrix_length)) * matrix_length;
                long int cj = j - (num % (height / matrix_length)) * matrix_length;

                QColor pixelcolor = pic.pixelColor(QPoint(i, j));
                array_of_matrix[num].create(this->matrix_length);
                array_of_matrix[num].coordinate[ci][cj] = pixelcolor; // Цвет в RGB
            }
        }
        return array_of_matrix;
    }

    long int calculate_circle_lbp(g gc, matrix m) {
        long int value;
        for (int p = 0; p < P - 1; p++) {
            value = 0;
            g gp;
            gp.x = gc.x + R * cos((2 * M_PI * p) / P);
            gp.y = gc.y + R * sin((2 * M_PI * p) / P);
            gp.color = m.coordinate[gp.x][gp.y].rgb();

            value += this->s(gp.color - gc.color) * pow(2, p);
        }
        return value;
    }
};
