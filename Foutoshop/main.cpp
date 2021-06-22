#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void resize_and_crop(Mat img)
{
    
    //--- TRANSFORMATION DE L'IMAGE POUR LA RÉDUIRE ET LA REDIMENSIONNER --

    Mat imgResize, imgCrop;

    //cout << img.size() << endl;
    resize(img, imgResize, Size(),0.5,0.5);

    Rect roi(200, 100, 300, 300);
    imgCrop = img(roi);

    imshow("Image Resize", imgResize);
    imshow("Image Crop", imgCrop);
}

Mat transform_and_filter(Mat img, Mat imgTransform)
{
    //--- TRANSFORMATION DE L'IMAGE AVEC FILTRES --

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

void draw_and_text(Mat img)
{
    //--- TRANSFORMATION DE L'IMAGE AVEC TEXT ET FORME --

    // Faire un cercle
    circle(img, Point(256, 256), 155, Scalar(52, 52, 52),FILLED);
    
    // Faire un rectangle
    rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED);
    
    // Faire une ligne
    line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);

    
    // Mettre du texte
    putText(img, "Foutoshop", Point(200, 262), FONT_HERSHEY_DUPLEX, 0.75, Scalar(52, 52, 52),2);

    imshow("Image with draw and text", img);
}

void rotate(Mat img){
    
    //--- FAIRE UNE ROTATION DE L'IMAGE --
    
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
    cout << "Bienvenue sur le logiciel Foutoshop, un logiciel pour vous permettre d'éditer vos images." << endl;
    
    //Récupération de l'image dans le dossier (à modifier)
    string path = "Resources/ambiance.jpg";
    Mat img = imread(path);
    
    if (img.empty())
    {
        cout << "Impossible d'ouvrir l'imagine, merci de vérifier le chemin" << endl;
        cin.get();
        return -1;
    }
    
    cout << "Nous avons bien trouvé votre image, nous allons vous proposer différentes fonctionnalités." << endl;
    
    imshow("Image d'origine", img);
    
    Mat imgTransform;
    
    // Fonction pour l'ajout de filtres et de flou
    cout << "Souhaitez-vous ajouter un filtre sur votre image (y/n) ? " << endl;
    String isTransform;
    cin >> isTransform;
    if (isTransform == "y")
    {
        imgTransform= transform_and_filter(img, imgTransform);
        imshow("Image édité", imgTransform);
    }
//    resize_and_crop(img);
//    draw_and_text(img);
//    rotate(img);
    waitKey(0);
}
