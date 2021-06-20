#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void resize_and_crop(String path)
{
    
    //--- TRANSFORMATION DE L'IMAGE POUR LA RÉDUIRE ET LA REDIMENSIONNER --

    Mat img = imread(path);
    Mat imgResize, imgCrop;

    //cout << img.size() << endl;
    resize(img, imgResize, Size(),0.5,0.5);

    Rect roi(200, 100, 300, 300);
    imgCrop = img(roi);

//    imshow("Image", img);
    imshow("Image Resize", imgResize);
    imshow("Image Crop", imgCrop);
}

void transform_and_filter(String path)
{
    //--- TRANSFORMATION DE L'IMAGE AVEC FILTRES --
    
    Mat img = imread(path);
    
    //Création des différentes images
    Mat imgGray, imgBlur, imgCanny, imgDilate, imgErode;
    
    // Noir et blanc
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    
    // Flou
    GaussianBlur(imgGray, imgBlur, Size(7, 7), 5, 0);
    
    // Noir et blanc tracé
    Canny(imgBlur, imgCanny, 25,75);

    Mat kernel = getStructuringElement(MORPH_RECT, Size(10, 10));
    
    // Noir et blanc tracé avec traits + épais
    dilate(imgCanny, imgDilate, kernel);
    
    // Noir et blanc tracé avec traits - épais
    erode(imgDilate, imgErode, kernel);

    imshow("Image", img);
    imshow("Image Gray", imgGray);
    imshow("Image Blur", imgBlur);
    imshow("Image Canny", imgCanny);
    imshow("Image Dilation", imgDilate);
    imshow("Image Erode", imgErode);
}

void draw_and_text(String path)
{
    //--- TRANSFORMATION DE L'IMAGE AVEC TEXT ET FORME --
    
    Mat img = imread(path);

    // Faire un cercle
    circle(img, Point(256, 256), 155, Scalar(52, 52, 52),FILLED);
    
    // Faire un rectangle
    rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED);
    
    // Faire une ligne
    line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);

    
    // Mettre du texte
    putText(img, "Foutoshop", Point(200, 262), FONT_HERSHEY_DUPLEX, 0.75, Scalar(52, 52, 52),2);

    imshow("Image", img);
}

void rotate(String path){
    
    //--- FAIRE UNE ROTATION DE L'IMAGE --
    
    Mat img = imread(path);
    
    // Changer l'angle de rotation
    double angle = 90;
    
    Point2f pt(img.cols/2., img.rows/2.);
    Mat r = getRotationMatrix2D(pt, angle, 1.0);
    warpAffine(img, img, r, Size(img.cols, img.rows));
    
    imshow("Image rotate", img);
}
/////////////// Basic Functions //////////////////////

int main()
{
    //Récupération de l'image dans le dossier
    string path = "Resources/ambiance.jpg";
    Mat img = imread(path);
    

    transform_and_filter(path);
    resize_and_crop(path);
    draw_and_text(path);
    rotate(path);
    waitKey(0);
}
