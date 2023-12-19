#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using namespace std;

// Copying code from last week for local run
void loadImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int& width, unsigned int& height) {
  // TODO: implement image loading
  ifstream file;

  file.open(filename);

  if (!file.is_open())
  {
    throw std::runtime_error("Failed to open "+ filename);
  }
  

  //header info
  string type = "";
  int RGB;
  file >> type;
  if (type != "P3" && type != "p3")
  {
    throw std::runtime_error("Invalid type " + type);
  }
  file >> width;
  file >> height;

  //check loading
  //cout << type << width << height << RGB;

  // if (type != "P3" && type != "p3")
  // {
  //   throw std::runtime_error("Invalid type " + type);
  // }
  
  if (file.fail())
  {
    throw std::runtime_error("Invalid dimensions");
  }
  
  if ((width > MAX_WIDTH || height > MAX_HEIGHT)) {
    throw std::runtime_error("Invalid dimensions");
  }
  if ((width < 0 || height < 0))
  {
    throw std::runtime_error("Invalid dimensions");
  }
  
  
  file >> RGB;

  if (RGB > 255)
  {
    throw std::runtime_error("Invalid color value");
  }
  

  for (unsigned int row = 0; row < height; row++)
  {
    for (unsigned int col = 0; col < width; col++)
    {
      short r;
      short g;
      short b;
      if(!(file >> r >> g >> b)) {
        throw std::runtime_error("Invalid color value");
      }
      if (file.fail())
      {
        throw  std::runtime_error("Failed to open "+ filename);
      }
      
      if (r < 0 || r > RGB || g < 0 || g > RGB || b < 0 || b > RGB)
      {
        throw std::runtime_error("Invalid color value");
      }
      
      image[col][row] = {r, g, b};
    }
    
  }

  string exT;
  file >> exT;

  if (exT != "" )
  {
    throw std::runtime_error("Too many values");
  }


  file.close();
  
}


void outputImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height) {
  // TODO: implement writing image to file
  ofstream file;
  file.open(filename);

  if (file.is_open())
  {
    file << "P3" << endl;
    file << width << " " << height << endl;
    file << "255" << endl;

      
    for (unsigned int row = 0; row < height; row++)
    {
      for (unsigned int col = 0; col < width; col++)
      {
        Pixel pxl = image[col][row];
        file << (pxl.r) << " ";
        file << (pxl.g) << " ";
        file << (pxl.b) << " ";

      }
      file << endl;
    }

  }
  else {
    throw std::runtime_error("Failed to open "+ filename);
  }

  file.close();
  
}

double map_coordinates(unsigned int source_dimension, unsigned int target_dimension, unsigned int pixel_coordinate){
  // TODO: implement mapping function.
  double scale_factor = static_cast<double>(source_dimension - 1) / static_cast<double>(target_dimension - 1);
  double mappedCrd = pixel_coordinate * scale_factor;
  return mappedCrd;
  
}

Pixel bilinear_interpolation(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height, double x, double y) {
  // TODO: Implement bilinear interpolation
  int x0 = static_cast<int>(floor(x));
  int x1 = x0 + 1;
  int y0 = static_cast<int>(floor(y));
  int y1 = y0 + 1;

  double x_frac = x - x0;
  double y_frac = y - y0;

  if (x < 0 || x >= width || y < 0 || y >= height) {
    x_frac = max(0.0, min(x_frac, 1.0));
    y_frac = max(0.0, min(y_frac, 1.0));
  } else {
    x_frac = max(0.0, min(x_frac, 1.0));
    y_frac = max(0.0, min(y_frac, 1.0));
  }

  Pixel p_0 = image[x0][y0];
  Pixel p_1 = image[x0][y1];
  Pixel p1_ = image[x1][y0];
  Pixel p11 = image[x1][y1];

  Pixel intrpltd = {0,0,0};
  intrpltd.r = static_cast<short>((1 - x_frac) * (1 - y_frac) * p_0.r + x_frac * (1 - y_frac) * p1_.r + (1 - x_frac) * y_frac * p_1.r + x_frac * y_frac * p11.r);
  intrpltd.g = static_cast<short>((1 - x_frac) * (1 - y_frac) * p_0.g + x_frac * (1 - y_frac) * p1_.g + (1 - x_frac) * y_frac * p_1.g + x_frac * y_frac * p11.g);
  intrpltd.b = static_cast<short>((1 - x_frac) * (1 - y_frac) * p_0.b + x_frac * (1 - y_frac) * p1_.b + (1 - x_frac) * y_frac * p_1.b + x_frac * y_frac * p11.b);

  return intrpltd;
}

