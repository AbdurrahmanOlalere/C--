#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using namespace std;

int counter = 0;

void initializeImage(Pixel image[][MAX_HEIGHT]) {
  // iterate through columns
  for (unsigned int col = 0; col < MAX_WIDTH; col++) {
    // iterate through rows
    for (unsigned int row = 0; row < MAX_HEIGHT; row++) {
      // initialize pixel
      image[col][row] = {0, 0, 0};
    }
  }
}

void loadImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int& width, unsigned int& height) {
  // TODO: implement image loading
  ifstream file;
  file.open(filename);

  if (!file.is_open())
  {
    throw std::runtime_error("Failed to open " + filename);
  }

  string type = "";
  string RGB = "";

  file >> type >> width >> height >> RGB;

  if (type != "P3" && type != "p3")
  {
    throw std::runtime_error("Invalid type " + type);
  }
  
  if ((width > MAX_HEIGHT || height > MAX_HEIGHT) || (width < 0 || height < 0))
  {
    throw std::runtime_error("Invalid dimensions");
  }
  
  for (unsigned int col = 0; col < MAX_WIDTH; col++) {
    // iterate through rows
    for (unsigned int row = 0; row < MAX_HEIGHT; row++) {
      // initialize pixel
        short r;
        short g;
        short b;
        file >> r >> g >> b;

      if ((r < 0 || r > 256) || (g < 0 || g > 256) || (b < 0 || b > 256))
      {
        throw std::runtime_error("Invaid color value");
      }

      image[col][row] = {r, g, b};
    }
  }

  if (!(file.eof()))
  {
    throw std::runtime_error("Too many values");
  }
}


void outputImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height) {
  // TODO: implement writing image to file
  ofstream newFile;
  newFile.open(counter+"_new" +filename);
  counter++;

  if (newFile.is_open())
  {
    newFile << "P3" << endl;
    newFile << width << height << endl;
    newFile <<"255" << endl;

    for (unsigned int row = 0; row < height; row++)
    {
      for (unsigned int col = 0; col < width; col++)
      {
        Pixel pxl = image[col][row];
        newFile << static_cast<int>(pxl.r) << endl;
        newFile << static_cast<int>(pxl.g) << endl;
        newFile << static_cast<int>(pxl.b) << endl;

      }

      newFile <<endl;
      
    }
    
  }
  
  
  newFile.close();



  

}

double map_coordinates(unsigned int source_dimension, unsigned int target_dimension, unsigned int pixel_coordinate){
  // TODO: implement mapping function.
  
}
 
Pixel bilinear_interpolation(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height, double x, double y) {
  // TODO: Implement bilinear interpolation

}

void scale_image(Pixel sourceImage[][MAX_HEIGHT], unsigned int sourceWidth, unsigned int sourceHeight,
                   Pixel targetImage[][MAX_HEIGHT], unsigned int targetWidth, unsigned int targetHeight){
  // TODO: add loops to calculate scaled images

}