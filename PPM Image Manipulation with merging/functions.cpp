#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using namespace std;

void loadCorners(std::string filename, Corner imageCorners[MAX_CORNERS], unsigned int& numberOfCorners){
    // Read load corners file
    ifstream file;
    file.open(filename);
    
    if (!file.is_open())
    {
    throw std::runtime_error("Failed to open "+ filename);
    }

    numberOfCorners = 0;
    int cornrX, cornrY;
    int i = 0;
    while (file >> cornrX >> cornrY )
    {
        if (numberOfCorners >= MAX_CORNERS)
        {
            throw std::runtime_error("Too many Corners");
        }
        imageCorners[i].x = cornrX;
        imageCorners[i].y = cornrY;
        numberOfCorners++;
        i++;
        
    }
    
    
    

}

double errorCalculation(Pixel image1[][MAX_HEIGHT], const unsigned int width1, const unsigned int height1,
                      Corner image1corner,
                      Pixel image2[][MAX_HEIGHT], const unsigned int width2, const unsigned int height2,
                      Corner image2corner){
            
    const int neighBrSize = ERROR_NEIGHBORHOOD_SIZE;

    double err = 0.0;

    // Error calculation
    int sliceStartX1 = image1corner.x - (neighBrSize - 1)/2;
    int sliceStartY1 = image1corner.y - (neighBrSize - 1)/2;

    int sliceStartX2 = image2corner.x - (neighBrSize - 1)/2;
    int sliceStartY2 = image2corner.y - (neighBrSize - 1)/2;

    // if (sliceStartX1 < 0 || sliceStartY1 < 0 || sliceStartX1 + neighBrSize > width1 || sliceStartY1 + neighBrSize > height1)
    // {
    //     return INFINITY;
    // }

    // if (sliceStartX2 < 0 || sliceStartY2 < 0 || sliceStartX2 + neighBrSize > width2 || sliceStartY2 + neighBrSize > height2)
    // {
    //     return INFINITY;
    // }
    
    for (int row = 0; row < neighBrSize; row++)
    {
        for (int col = 0; col < neighBrSize; col++)
        {
            unsigned int x1 = sliceStartX1 + col;
            unsigned int y1 = sliceStartY1 + row;
            unsigned int x2 = sliceStartX2 + col;
            unsigned int y2 = sliceStartY2 + row;

            if (x1 < width1 && y1 < height1 &&
                x2 < width2 && y2 < height2)
            {
                Pixel pxl1 = image1[x1][y1];
                Pixel pxl2 = image2[x2][y2];

                int diffR = abs(pxl1.r - pxl2.r);
                int diffG = abs(pxl1.g - pxl2.g);
                int diffB = abs(pxl1.b - pxl2.b);

                err += diffR + diffG + diffB;
            }
            else
            {
                return INFINITY;
            }
        }
    }

    return err;

    
}

void matchCorners(CornerPair matchedPairs[MAX_CORNERS], unsigned int &matched_count,
                  Pixel image1[][MAX_HEIGHT], const unsigned int width1, const unsigned int height1,
                  Corner image1corners[], unsigned int image1CornerCount,
                  Pixel image2[][MAX_HEIGHT], const unsigned int width2, const unsigned int height2,
                  Corner image2corners[], unsigned int image2CornerCount){

    CornerPair originalMatchedPairs[MAX_CORNERS];
    for (unsigned int i = 0; i < MAX_CORNERS; i++) {
    originalMatchedPairs[i] = matchedPairs[i];
    }

    // Greedy corner matching goes here
    if (image1CornerCount == 0 || image2CornerCount == 0) 
    {
        return;
    }

    matched_count = 0;

    for (unsigned int i = 0; i < image1CornerCount; i++)
    {   
        if (image1corners[i].used)
        {
            continue;
        }
        
        
        int minErrorPos = 0;
        double minErr = INFINITY;
        for (unsigned int j = 0; j < image2CornerCount; j++)
        {
            if (image2corners[j].used)
            {
                continue;
            }
            
            double currErr = errorCalculation(image1, width1, height1, image1corners[i],image2, width2, height2, image2corners[j]);
            
            if (currErr < minErr)
            {
                minErr = currErr;
                minErrorPos = j;

            }
            
        }

        if (minErr < INFINITY)
        {
            matchedPairs[matched_count].image1Corner = image1corners[i];
            matchedPairs[matched_count].image2Corner = image2corners[minErrorPos];
            matchedPairs[matched_count].error = minErr;
            matched_count++;

            image1corners[i].used = true;
            image2corners[minErrorPos].used = true;
            
        }
        
        

    }

    if (matched_count >= 5)
    {
        cout << "1st Pair - Image1 Corner: (" << matchedPairs[0].image1Corner.x << ", " << matchedPairs[0].image1Corner.y << "), "
            << "Image2 Corner: (" << matchedPairs[0].image2Corner.x << ", " << matchedPairs[0].image2Corner.y << "), "
            << "Error: " << matchedPairs[0].error << endl;
        cout << "2nd Pair - Image1 Corner: (" << matchedPairs[1].image1Corner.x << ", " << matchedPairs[1].image1Corner.y << "), "
            << "Image2 Corner: (" << matchedPairs[1].image2Corner.x << ", " << matchedPairs[1].image2Corner.y << "), "
            << "Error: " << matchedPairs[1].error << endl;
        cout << "3rd Pair - Image1 Corner: (" << matchedPairs[2].image1Corner.x << ", " << matchedPairs[2].image1Corner.y << "), "
            << "Image2 Corner: (" << matchedPairs[2].image2Corner.x << ", " << matchedPairs[2].image2Corner.y << "), "
            << "Error: " << matchedPairs[2].error << endl;
        cout << "4th Pair - Image1 Corner: (" << matchedPairs[3].image1Corner.x << ", " << matchedPairs[3].image1Corner.y << "), "
            << "Image2 Corner: (" << matchedPairs[3].image2Corner.x << ", " << matchedPairs[3].image2Corner.y << "), "
            << "Error: " << matchedPairs[3].error << endl;
        cout << "5th Pair - Image1 Corner: (" << matchedPairs[4].image1Corner.x << ", " << matchedPairs[4].image1Corner.y << "), "
            << "Image2 Corner: (" << matchedPairs[4].image2Corner.x << ", " << matchedPairs[4].image2Corner.y << "), "
            << "Error: " << matchedPairs[4].error << endl;
        
    }
    
    


}

void mapCoordinates(const double H[3][3], unsigned int x, unsigned int y,
                    double& mapped_x, double& mapped_y){
    double tx = (H[0][0] * x ) + (H[0][1] * y ) + (H[0][2]);
    double ty = (H[1][0] * x ) + (H[1][1] * y ) + (H[1][2]);
    double tz = (H[2][0] * x ) + (H[2][1] * y ) + (H[2][2]);

    mapped_x = tx/tz;
    mapped_y = ty/tz;
    // Mapping function for this week

}
int limit(int value, int minValue, int maxValue) {
    if (value < minValue) {
        return minValue;
    } else if (value > maxValue) {
        return maxValue;
    } else {
        return value;
    }
}

Pixel mergePixels(const Pixel& pixel1, const Pixel& pixel2) {
    Pixel mergedPixel;
    mergedPixel.r = (pixel1.r + pixel2.r) / 2;
    mergedPixel.g = (pixel1.g + pixel2.g) / 2;
    mergedPixel.b = (pixel1.b + pixel2.b) / 2;

    // Clamp each component to the range [0, 255]
    mergedPixel.r = limit(mergedPixel.r, 0, 255);
    mergedPixel.g = limit(mergedPixel.g, 0, 255);
    mergedPixel.b = limit(mergedPixel.b, 0, 255);

    return mergedPixel;
}

void mergeImages( Pixel image1[][MAX_HEIGHT], unsigned int &width1, unsigned int &height1,
                  Pixel image2[][MAX_HEIGHT], const unsigned int width2, const unsigned int height2,
                  double H[3][3] ){
        
    // Similar to image scaling function from last week with some additional steps.
    unsigned int mWidth = width1;
    unsigned int mHeight = height1;
    
    Pixel mergeImage[MAX_WIDTH][MAX_HEIGHT];
    Pixel undefinedPixel = {0, 0, 0};
    Pixel I1_pixel;
    Pixel I2_pixel;
    
    for (unsigned int col = 0; col < MAX_WIDTH; col++) {
        for (unsigned int row = 0; row < MAX_HEIGHT; row++) {
            double mappedX;
            double mappedY;
            
            mapCoordinates(H, col, row, mappedX, mappedY);
            
            bool pixelTwoDef = false;
            bool pixelOnedef = false;
            


            if (mappedX >= 0 && mappedX < width2 && mappedY >= 0 && mappedY < height2) {
                I2_pixel = bilinear_interpolation(image2, width2, height2, mappedX, mappedY);
                pixelTwoDef = true;
            }
            
            if (col < mWidth && row < mHeight) {
                I1_pixel = image1[col][row];
                pixelOnedef = true;
            }
            
            Pixel newPixel;
            if (pixelOnedef && pixelTwoDef) {
                newPixel.r = (short)((I1_pixel.r + I2_pixel.r) / 2);
                newPixel.g = (short)((I1_pixel.g + I2_pixel.g) / 2);
                newPixel.b = (short)((I1_pixel.b + I2_pixel.b) / 2);
            } else if (pixelOnedef) {
                newPixel = I1_pixel;
            } else if (pixelTwoDef) {
                newPixel = I2_pixel;
            } else {
                newPixel = undefinedPixel;
            }
            
            image1[col][row] = newPixel;

        }
    }
    


    int testCol = 1;  // The column to test
    int testRow = 0;  // The row to test

    // Before the merge operation
    Pixel originalPixel = image1[testRow][testCol];
    Pixel mergedPixel = mergeImage[testRow][testCol];

    cout << "Original Pixel (Col " << testCol << ", Row " << testRow << "): R=" << originalPixel.r << " G=" << originalPixel.g << " B=" << originalPixel.b << endl;
    cout << "Merged Pixel (Col " << testCol << ", Row " << testRow << "): R=" << mergedPixel.r << " G=" << mergedPixel.g << " B=" << mergedPixel.b << endl;
    
    width1 = mWidth;
    height1 = mHeight;
}