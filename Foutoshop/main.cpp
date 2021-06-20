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

/////////////// Basic Functions //////////////////////

int main()
{
    //Récupération de l'image dans le dossier
    string path = "Resources/test.png";
    Mat img = imread(path);
    
    transform_and_filter(path);
    resize_and_crop(path);
    waitKey(0);
}
