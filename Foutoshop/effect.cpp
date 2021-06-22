//
//  effect.cpp
//  Foutoshop
//
//  Created by Noémie Rochard on 22/06/2021.
//

#include "effect.h"
#include <iostream>

using namespace std;

Mat Effect::crop(Mat &imgTransform)
{	

    Mat imgCrop;

    // Réduire la taille de l'image
    //    resize(imgTransform, imgTransform, Size(),0.5,0.5);

    
    //startX ,startY, width, height
    Rect roi(500, 300, 300, 300);
    imgCrop = imgTransform(roi);
    
    imgTransform = imgCrop;
    
    return (imgTransform);
}

Mat Effect::transform_and_filter(Mat img, Mat &imgTransform)
{

    // Noir et blanc
    cout << "Souhaitez-vous mettre l'image en noir & blanc (y/n) ? " << endl;
    String isBlackAndWhite;
    cin >> isBlackAndWhite;
    if ( isBlackAndWhite == "y")
    {
        cvtColor(img, imgTransform, COLOR_BGR2GRAY);
    }
    else if (isBlackAndWhite == "n")
    {
        // Sépia
        cout << "Souhaitez-vous mettre l'image en sépia (y/n) ? " << endl;
        String isSepia;
        cin >> isSepia;
        if ( isSepia == "y")
        {
            Mat kernel =
                (cv::Mat_<float>(3, 3)
                    <<
                    0.272, 0.534, 0.131,
                    0.349, 0.686, 0.168,
                    0.393, 0.769, 0.189);
            transform(img, imgTransform, kernel);
        }
    }

    // Flou
    cout << "Souhaitez-vous mettre l'image en flou (y/n) ? " << endl;
    String isBlur;
    cin >> isBlur;
    if ( isBlur == "y")
    {
        GaussianBlur(imgTransform, imgTransform, Size(7, 7), 5, 0);
    }
    
//    Autres fonctions d'édition d'image
    
    //    // Noir et blanc tracé
    //    Canny(imgBlur, imgCanny, 25,75);
    //
    //    Mat kernel = getStructuringElement(MORPH_RECT, Size(10, 10));
    //
    //    // Noir et blanc tracé avec traits + épais
    //    dilate(imgCanny, imgDilate, kernel);
    //
    //    // Noir et blanc tracé avec traits - épais
    //    erode(imgDilate, imgErode, kernel);

    
    return (imgTransform);
}

Mat Effect::draw_and_text(Mat &imgTransform)
{

    cout << "Souhaitez-vous dessiner un cercle sur l'image (y/n) ? " << endl;
    String isCircle;
    cin >> isCircle;
    if (isCircle == "y")
    {
        circle(imgTransform, Point(1000, 1500), 400, Scalar(52, 52, 52),FILLED);
    }
    
    // Faire un rectangle
    // rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED);
    
    // Faire une ligne
    //  line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);

    
    cout << "Souhaitez-vous ajouter du texte (y/n) ? " << endl;
    String isText;
    cin >> isText;
    if (isText == "y")
    {
        cout << "Quel texte souhaitez-vous mettre (y/n) ? " << endl;
        String whatText;
        cin >> whatText;
        putText(imgTransform, whatText, Point(200, 262), FONT_HERSHEY_DUPLEX, 0.75, Scalar(52, 52, 52),2);
    }

    return (imgTransform);
}

Mat Effect::rotate(Mat &imgTransform){
    
    cout << "Merci de saisir l'inclinaison de rotation ? " << endl;
    int whatAngle;
    cin >> whatAngle;
    
    Point2f pt(imgTransform.cols/2., imgTransform.rows/2.);
    Mat r = getRotationMatrix2D(pt, whatAngle, 1.0);
    warpAffine(imgTransform, imgTransform, r, Size(imgTransform.cols, imgTransform.rows));
    
    return (imgTransform);
}
