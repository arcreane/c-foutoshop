	//
//  functions.h
//  Foutoshop
//
//  Created by Noémie Rochard on 22/06/2021.
//

#pragma once

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

class Effect
{
    public :
    Mat crop(Mat &imgTransform);
    Mat transform_and_filter(Mat img, Mat &imgTransform);
    Mat draw_and_text(Mat &imgTransform);
    Mat rotate(Mat &imgTransform);
};



