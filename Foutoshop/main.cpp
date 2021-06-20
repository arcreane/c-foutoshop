#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/////////////// Basic Functions //////////////////////

int main() {
    
    //Récupération de l'image dans le dossier
    string path = "Resources/test.png";
    Mat img = imread(path);
    

    //--- TRANSFORMATIONS DE L'IMAGE AVEC FILTRES --
    
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
    waitKey(0);
}
