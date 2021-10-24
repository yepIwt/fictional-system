#pragma once
#include <QtWidgets>
#include <QApplication>
#include <QString>

#include <string>
    QImage open_picture(std::string pic_name) {
        QString qpic_name = pic_name.c_str();
        QImage picture_obj; picture_obj.load(qpic_name);

        return picture_obj;
    }

    QImage crop_picture(QImage picture_obj, int x1, int y1, int x2, int y2) {
        return picture_obj.copy(x1, y1, x2, y2);
    }

    QImage lead_to_a_common_denominator(QImage picture_obj, int R) {

        /* Исправляет большую часть SF. Изображение может потерять несного пикселей по краям  */

        QSize sizeImage = picture_obj.size();
        int width = sizeImage.width(), height = sizeImage.height();
        int matrix_length = R * 2 + 1;
        width -= width % matrix_length;
        /*while (width % matrix_length != 0) {
            width--;
        }*/
        height -= height % matrix_length;
        /*while (height % matrix_length != 0) {
            height--;
        }*/

        return crop_picture(picture_obj, 0, 0, width, height);
    }

    QImage make_bw_picture(QImage picture_obj) {
        /*
            Я написал этот код, когда не знал как форматировать пикчи,
            после написал код в две строчки, но он выдает предупреждение
            о глубине цвета. Оставлю свой рабочий код
        */

        QSize sizeImage = picture_obj.size();
        int width = sizeImage.width(), height = sizeImage.height();

        QRgb color;
        for (int f1 = 0; f1 < width; f1++) {
            for (int f2 = 0; f2 < height; f2++) {
                color = picture_obj.pixel(f1, f2);
                int gray = (qRed(color) + qGreen(color) + qBlue(color)) / 3;
                picture_obj.setPixel(f1, f2, qRgb(gray, gray, gray));
            }
        };
        return picture_obj;
    };

    void save_picture(QImage picture_obj, std::string filename) {
        QString qfilename = filename.c_str();
        picture_obj.save(qfilename);
    };

    size_t truncate(size_t value) {
        if (value < 0) return 0;
        if (value > 255) return 255;
        return value;
    };

    QImage contrast(QImage picture_obj, int contrast_value) {
        QSize sizeImage = picture_obj.size();
        int width = sizeImage.width(), height = sizeImage.height();

        float factor = (259.0 * (contrast_value + 255.0)) / (255.0 * (259.0 - contrast_value));

        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {

                QColor colour = picture_obj.pixelColor(QPoint(i, j));

                size_t newRed = truncate((size_t)(factor * (colour.red() - 128) + 128));
                size_t newGreen = truncate((size_t)(factor * (colour.green() - 128) + 128));
                size_t newBlue = truncate((size_t)(factor * (colour.blue() - 128) + 128));
                
                QColor new_color = QColor(newRed, newGreen, newBlue);
                picture_obj.setPixelColor(i,j,new_color);
            }

        }
        return picture_obj;
    }