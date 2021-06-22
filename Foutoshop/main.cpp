#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "effect.h"


using namespace cv;
using namespace std;

/////////////// Basic Functions //////////////////////

int main()
{
    
    Effect applyImg;
    
    cout << "Bienvenue sur le logiciel Foutoshop, un logiciel pour vous permettre d'éditer vos images." << endl;
    
    //Récupération de l'image dans le dossier (à modifier)
    string path = "Resources/ambiance.jpg";
    Mat img = imread(path);
    
    if (img.empty())
    {
        cout << "Impossible d'ouvrir l'image, merci de vérifier le chemin" << endl;
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
        applyImg.transform_and_filter(img, imgTransform);

    }
    
    // Fonction pour recadrer l'image
    cout << "Souhaitez-vous recadrer votre image (y/n) ? " << endl;
    String isResize;
    cin >> isResize;
    if (isResize == "y")
    {
        applyImg.crop(imgTransform);
    }
    
    // Fonction pour ajouter du texte et des formes
    cout << "Souhaitez-vous ajouter du texte et des formes (y/n) ? " << endl;
    String isDraw;
    cin >> isDraw;
    if (isDraw == "y")
    {
        applyImg.draw_and_text(imgTransform);
    }
    
    
    // Fonction pour retourner l'image
    cout << "Souhaitez-vous effectuer une rotation de l'image (y/n) ? " << endl;
    String isRotate;
    cin >> isRotate;
    if (isRotate == "y")
    {
        applyImg.rotate(imgTransform);
    }
    
    imshow("Image édité", imgTransform);
    
    // Enregistrer l'image édité
    imwrite("Resources/edit.jpg", imgTransform);

    waitKey(0);
}
