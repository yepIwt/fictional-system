#include <QtWidgets>
#include <QApplication>
#include <QtGui>
#include <QString>

#include <string>

#include <iostream> // Пока дебажу он подключен

#include <bitset>

QImage open_picture(std::string pic_name){
    QString qpic_name = pic_name.c_str();
    QImage picture_obj; picture_obj.load(qpic_name);
    
    return picture_obj;
};

QImage crop_picture(QImage picture_obj, int x1, int y1, int x2, int y2){
    return picture_obj.copy(x1,y1,x2,y2);
};

QImage lead_to_a_common_denominator(QImage picture_obj){
    /* Исправляет большую часть SF. Изображение может потерять максимум 2 пикселя по краям  */
    QSize sizeImage = picture_obj.size();
    int width = sizeImage.width(), height = sizeImage.height();

    while (width % 3 != 0){
        width--;
    }
    while (height % 3 != 0){
        height--;
    }

    return crop_picture(picture_obj,0,0,width,height);
}

QImage make_bw_picture(QImage picture_obj){
    /* 
        Я написал этот код, когда не знал как форматировать пикчи, 
        после написал код в две строчки, но он выдает предупреждение
        о глубине цвета пикчи. Оставлю свой рабочий код
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

QImage lbp(QImage picture_obj){
    QSize sizeImage = picture_obj.size();
    unsigned long long int width = sizeImage.width(), height = sizeImage.height();

    QImage custom_picture(QSize(width, height),QImage::Format_Grayscale8); // Этот фикс создает пустое изображение с размерами picture_obj   
    unsigned long long int max = (width * height) / 9;
    
    QColor array_of_matrix[max][3][3];

    std::cout << "INFO " << width << "x" << height << ". arrays=" << max << std::endl;

    /* Разбиение на матрицы */
    for (unsigned long long int i=0; i<width; i++){
        for (unsigned long long int j=0; j<height; j++){
            long long int num = (i/3) * (width/3) + (j/3);
            long long int ci = i - (num / (width / 3))*3;
            long long int cj = j - (num % (width / 3))*3;

            QColor pixelcolor = picture_obj.pixelColor(QPoint(i,j));
            array_of_matrix[num][ci][cj] = pixelcolor; // Цвет в RGB
        }
    }

    /* Подсчет LBP */
    for (int k=0; k < max; k++){
        int etalon_in_rgb = array_of_matrix[k][1][1].rgb();
        std::string lbp_var = "";
        
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                
                int value_in_rgb = array_of_matrix[k][i][j].rgb();
                
                /*
                    Это дебильная конструкция, но ничего умнее мне пока не нужно
                    В проде обязательно исправить
                */

                if (i == 1 && j == 1){
                    continue;
                } else {
                    lbp_var += value_in_rgb <= etalon_in_rgb ? std::to_string(0) : std::to_string(1);
                }
            }
                
        }
        long int lbp = std::bitset<32>(lbp_var).to_ulong();
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                array_of_matrix[k][i][j] = QColor(lbp, lbp, lbp);
            }
        }
    }

    /* Сборка матрицы с LBP */
    for (int num=0; num<max; num++ ){
        for (int ci=0; ci<3; ci++){
            for (int cj=0; cj<3; cj++){
                int i = ci + (num / (width / 3))*3;
                int j = cj + (num % (width / 3))*3;
                custom_picture.setPixelColor(i,j,array_of_matrix[num][ci][cj]);
            }
        }
    }

    return custom_picture;
};


void save_picture(QImage picture_obj, std::string filename){
    QString qfilename = filename.c_str();
    picture_obj.save(qfilename);
};