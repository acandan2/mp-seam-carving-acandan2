#include "seam_carver.hpp"

// implement the rest of SeamCarver's functions here

const ImagePPM& SeamCarver::GetImage() const {
  return image_;
}

int SeamCarver::GetHeight() const {
  return height_;
}

int SeamCarver::GetWidth() const {
  return width_;
}

int SeamCarver::GetEnergy(int row, int col) const {

  if ((row > 0) && (row < GetHeight() - 1) && (col > 0) && (col < GetWidth() - 1)) {
    return GetEnergyMostPixels(row, col);
  } else if (row == 0 && col == 0) {
    return GetEnergyFor00();
  } else if (row == 0 && col == GetWidth() - 1) {
    return GetEnergyFor0Width();
  } else if (row == GetHeight() - 1 && col == 0) {
    return GetEnergyForHeight0();
  } else if (row == GetHeight() - 1 && col == GetWidth() - 1) {
    return GetEnergyForHeightWidth();
  } else if (col == 0) {
    return GetEnergyForLeftEdge(row);
  } else if (col == GetWidth() - 1){
    return GetEnergyForRightEdge(row);
  } else if (row == 0) {
    return GetEnergyForUpperEdge(col);
  } else  {
    return GetEnergyForLowerEdge(col);
  }
}

int SeamCarver::GetEnergyMostPixels(int row, int col) const{

  Pixel px_c_1 = image_.GetPixel(row, col - 1);
  Pixel px_c_2 = image_.GetPixel(row, col + 1);
  Pixel px_r_1 = image_.GetPixel(row - 1, col);
  Pixel px_r_2 = image_.GetPixel(row + 1, col);

  int red1 = (px_c_1.GetRed() - px_c_2.GetRed()) * (px_c_1.GetRed() - px_c_2.GetRed());
  int red2 = (px_r_1.GetRed() - px_r_2.GetRed()) * (px_r_1.GetRed() - px_r_2.GetRed());

  int green1 = (px_c_1.GetGreen() - px_c_2.GetGreen()) * (px_c_1.GetGreen() - px_c_2.GetGreen());
  int green2 = (px_r_1.GetGreen() - px_r_2.GetGreen()) * (px_r_1.GetGreen() - px_r_2.GetGreen());

  int blue1 = (px_c_1.GetBlue() - px_c_2.GetBlue()) * (px_c_1.GetBlue() - px_c_2.GetBlue());
  int blue2 = (px_r_1.GetBlue() - px_r_2.GetBlue()) * (px_r_1.GetBlue() - px_r_2.GetBlue());

  int energy = red1 + red2 + green1 + green2 + blue1 + blue2;
  
  return energy;

}

int SeamCarver::GetEnergyFor00() const{

  Pixel px_c_1 = image_.GetPixel(0, GetWidth() - 1);
  Pixel px_c_2 = image_.GetPixel(0, 1);
  Pixel px_r_1 = image_.GetPixel(GetHeight() - 1, 0);
  Pixel px_r_2 = image_.GetPixel(1, 0);

  int red1 = (px_c_1.GetRed() - px_c_2.GetRed()) * (px_c_1.GetRed() - px_c_2.GetRed());
  int red2 = (px_r_1.GetRed() - px_r_2.GetRed()) * (px_r_1.GetRed() - px_r_2.GetRed());

  int green1 = (px_c_1.GetGreen() - px_c_2.GetGreen()) * (px_c_1.GetGreen() - px_c_2.GetGreen());
  int green2 = (px_r_1.GetGreen() - px_r_2.GetGreen()) * (px_r_1.GetGreen() - px_r_2.GetGreen());

  int blue1 = (px_c_1.GetBlue() - px_c_2.GetBlue()) * (px_c_1.GetBlue() - px_c_2.GetBlue());
  int blue2 = (px_r_1.GetBlue() - px_r_2.GetBlue()) * (px_r_1.GetBlue() - px_r_2.GetBlue());

  int energy = red1 + red2 + green1 + green2 + blue1 + blue2;
  
  return energy;
  
}

int SeamCarver::GetEnergyFor0Width() const{

  Pixel px_c_1 = image_.GetPixel(0, GetWidth() - 2);
  Pixel px_c_2 = image_.GetPixel(0, 0);
  Pixel px_r_1 = image_.GetPixel(GetHeight() - 1, GetWidth() - 1);
  Pixel px_r_2 = image_.GetPixel(1, GetWidth() - 1);

  int red1 = (px_c_1.GetRed() - px_c_2.GetRed()) * (px_c_1.GetRed() - px_c_2.GetRed());
  int red2 = (px_r_1.GetRed() - px_r_2.GetRed()) * (px_r_1.GetRed() - px_r_2.GetRed());

  int green1 = (px_c_1.GetGreen() - px_c_2.GetGreen()) * (px_c_1.GetGreen() - px_c_2.GetGreen());
  int green2 = (px_r_1.GetGreen() - px_r_2.GetGreen()) * (px_r_1.GetGreen() - px_r_2.GetGreen());

  int blue1 = (px_c_1.GetBlue() - px_c_2.GetBlue()) * (px_c_1.GetBlue() - px_c_2.GetBlue());
  int blue2 = (px_r_1.GetBlue() - px_r_2.GetBlue()) * (px_r_1.GetBlue() - px_r_2.GetBlue());

  int energy = red1 + red2 + green1 + green2 + blue1 + blue2;
  
  return energy;

}

int SeamCarver::GetEnergyForHeight0() const{

  Pixel px_c_1 = image_.GetPixel(GetHeight() - 1, GetWidth() - 1);
  Pixel px_c_2 = image_.GetPixel(GetHeight() - 1, 1);
  Pixel px_r_1 = image_.GetPixel(GetHeight() - 2, 0);
  Pixel px_r_2 = image_.GetPixel(0, 0);

  int red1 = (px_c_1.GetRed() - px_c_2.GetRed()) * (px_c_1.GetRed() - px_c_2.GetRed());
  int red2 = (px_r_1.GetRed() - px_r_2.GetRed()) * (px_r_1.GetRed() - px_r_2.GetRed());

  int green1 = (px_c_1.GetGreen() - px_c_2.GetGreen()) * (px_c_1.GetGreen() - px_c_2.GetGreen());
  int green2 = (px_r_1.GetGreen() - px_r_2.GetGreen()) * (px_r_1.GetGreen() - px_r_2.GetGreen());

  int blue1 = (px_c_1.GetBlue() - px_c_2.GetBlue()) * (px_c_1.GetBlue() - px_c_2.GetBlue());
  int blue2 = (px_r_1.GetBlue() - px_r_2.GetBlue()) * (px_r_1.GetBlue() - px_r_2.GetBlue());

  int energy = red1 + red2 + green1 + green2 + blue1 + blue2;
  
  return energy;

}

int SeamCarver::GetEnergyForHeightWidth() const{

  Pixel px_c_1 = image_.GetPixel(GetHeight() - 1, GetWidth() - 2);
  Pixel px_c_2 = image_.GetPixel(GetHeight() - 1, 0);
  Pixel px_r_1 = image_.GetPixel(GetHeight() - 2, GetWidth() - 1);
  Pixel px_r_2 = image_.GetPixel(0, GetWidth() - 1);

  int red1 = (px_c_1.GetRed() - px_c_2.GetRed()) * (px_c_1.GetRed() - px_c_2.GetRed());
  int red2 = (px_r_1.GetRed() - px_r_2.GetRed()) * (px_r_1.GetRed() - px_r_2.GetRed());

  int green1 = (px_c_1.GetGreen() - px_c_2.GetGreen()) * (px_c_1.GetGreen() - px_c_2.GetGreen());
  int green2 = (px_r_1.GetGreen() - px_r_2.GetGreen()) * (px_r_1.GetGreen() - px_r_2.GetGreen());

  int blue1 = (px_c_1.GetBlue() - px_c_2.GetBlue()) * (px_c_1.GetBlue() - px_c_2.GetBlue());
  int blue2 = (px_r_1.GetBlue() - px_r_2.GetBlue()) * (px_r_1.GetBlue() - px_r_2.GetBlue());

  int energy = red1 + red2 + green1 + green2 + blue1 + blue2;
  
  return energy;

}

int SeamCarver::GetEnergyForLeftEdge(int row) const{

  Pixel px_c_1 = image_.GetPixel(row, GetWidth() - 1);
  Pixel px_c_2 = image_.GetPixel(row, 1);
  Pixel px_r_1 = image_.GetPixel(row - 1, 0);
  Pixel px_r_2 = image_.GetPixel(row + 1, 0);

  int red1 = (px_c_1.GetRed() - px_c_2.GetRed()) * (px_c_1.GetRed() - px_c_2.GetRed());
  int red2 = (px_r_1.GetRed() - px_r_2.GetRed()) * (px_r_1.GetRed() - px_r_2.GetRed());

  int green1 = (px_c_1.GetGreen() - px_c_2.GetGreen()) * (px_c_1.GetGreen() - px_c_2.GetGreen());
  int green2 = (px_r_1.GetGreen() - px_r_2.GetGreen()) * (px_r_1.GetGreen() - px_r_2.GetGreen());

  int blue1 = (px_c_1.GetBlue() - px_c_2.GetBlue()) * (px_c_1.GetBlue() - px_c_2.GetBlue());
  int blue2 = (px_r_1.GetBlue() - px_r_2.GetBlue()) * (px_r_1.GetBlue() - px_r_2.GetBlue());

  int energy = red1 + red2 + green1 + green2 + blue1 + blue2;
  
  return energy;

}

int SeamCarver::GetEnergyForRightEdge(int row) const{

  Pixel px_c_1 = image_.GetPixel(row, GetWidth() - 2);
  Pixel px_c_2 = image_.GetPixel(row, 0);
  Pixel px_r_1 = image_.GetPixel(row - 1, GetWidth() - 1);
  Pixel px_r_2 = image_.GetPixel(row + 1, GetWidth() - 1);

  int red1 = (px_c_1.GetRed() - px_c_2.GetRed()) * (px_c_1.GetRed() - px_c_2.GetRed());
  int red2 = (px_r_1.GetRed() - px_r_2.GetRed()) * (px_r_1.GetRed() - px_r_2.GetRed());

  int green1 = (px_c_1.GetGreen() - px_c_2.GetGreen()) * (px_c_1.GetGreen() - px_c_2.GetGreen());
  int green2 = (px_r_1.GetGreen() - px_r_2.GetGreen()) * (px_r_1.GetGreen() - px_r_2.GetGreen());

  int blue1 = (px_c_1.GetBlue() - px_c_2.GetBlue()) * (px_c_1.GetBlue() - px_c_2.GetBlue());
  int blue2 = (px_r_1.GetBlue() - px_r_2.GetBlue()) * (px_r_1.GetBlue() - px_r_2.GetBlue());

  int energy = red1 + red2 + green1 + green2 + blue1 + blue2;
  
  return energy;

}

int SeamCarver::GetEnergyForUpperEdge(int col) const{

  Pixel px_c_1 = image_.GetPixel(0, col - 1);
  Pixel px_c_2 = image_.GetPixel(0, col + 1);
  Pixel px_r_1 = image_.GetPixel(GetHeight() - 1, col);
  Pixel px_r_2 = image_.GetPixel(1, col);

  int red1 = (px_c_1.GetRed() - px_c_2.GetRed()) * (px_c_1.GetRed() - px_c_2.GetRed());
  int red2 = (px_r_1.GetRed() - px_r_2.GetRed()) * (px_r_1.GetRed() - px_r_2.GetRed());

  int green1 = (px_c_1.GetGreen() - px_c_2.GetGreen()) * (px_c_1.GetGreen() - px_c_2.GetGreen());
  int green2 = (px_r_1.GetGreen() - px_r_2.GetGreen()) * (px_r_1.GetGreen() - px_r_2.GetGreen());

  int blue1 = (px_c_1.GetBlue() - px_c_2.GetBlue()) * (px_c_1.GetBlue() - px_c_2.GetBlue());
  int blue2 = (px_r_1.GetBlue() - px_r_2.GetBlue()) * (px_r_1.GetBlue() - px_r_2.GetBlue());

  int energy = red1 + red2 + green1 + green2 + blue1 + blue2;
  
  return energy;

}

int SeamCarver::GetEnergyForLowerEdge(int col) const{

  Pixel px_c_1 = image_.GetPixel(GetHeight() - 1, col - 1);
  Pixel px_c_2 = image_.GetPixel(GetHeight() - 1, col + 1);
  Pixel px_r_1 = image_.GetPixel(GetHeight() - 2, col);
  Pixel px_r_2 = image_.GetPixel(0, col);

  int red1 = (px_c_1.GetRed() - px_c_2.GetRed()) * (px_c_1.GetRed() - px_c_2.GetRed());
  int red2 = (px_r_1.GetRed() - px_r_2.GetRed()) * (px_r_1.GetRed() - px_r_2.GetRed());

  int green1 = (px_c_1.GetGreen() - px_c_2.GetGreen()) * (px_c_1.GetGreen() - px_c_2.GetGreen());
  int green2 = (px_r_1.GetGreen() - px_r_2.GetGreen()) * (px_r_1.GetGreen() - px_r_2.GetGreen());

  int blue1 = (px_c_1.GetBlue() - px_c_2.GetBlue()) * (px_c_1.GetBlue() - px_c_2.GetBlue());
  int blue2 = (px_r_1.GetBlue() - px_r_2.GetBlue()) * (px_r_1.GetBlue() - px_r_2.GetBlue());

  int energy = red1 + red2 + green1 + green2 + blue1 + blue2;
  
  return energy;

}

int* SeamCarver::GetHorizontalSeam() const {

  int** two_d_array = new int*[GetHeight()];

  for (int row = 0; row < GetHeight(); row++) {
    two_d_array[row] = new int[GetWidth()];
    for (int col = 0; col < GetWidth(); col++) {
      two_d_array[row][col] = GetEnergy(row, col);
    }
  }

  for (int col = GetWidth() - 2; col > -1; col--) {
    for (int row = 0; row < GetHeight(); row++) {
      two_d_array[row][col] += HorizontalMinValue(two_d_array, row, col);
    }
  }
  return HorizontalSeamHelper(two_d_array);
}

int SeamCarver::HorizontalMinValue(int** two_d_array, int row, int col) const {
  int min_value = 0;
  if (row == 0) {
    min_value = two_d_array[row][col + 1];
    if (min_value > two_d_array[row + 1][col + 1]) {
      min_value = two_d_array[row + 1][col + 1];
    }
  } else if (row == GetHeight() - 1) {
    min_value = two_d_array[row][col + 1];
    if (min_value > two_d_array[row - 1][col + 1]) {
      min_value = two_d_array[row - 1][col + 1];
    }
  } else {
    min_value = two_d_array[row][col + 1];
    if (min_value > two_d_array[row - 1][col + 1]) {
      min_value = two_d_array[row - 1][col + 1];
      if (min_value > two_d_array[row + 1][col + 1]) {
        min_value = two_d_array[row + 1][col + 1];
      }
    } else if (min_value > two_d_array[row + 1][col + 1]) {
      min_value = two_d_array[row + 1][col + 1];
    }
  }
  return min_value;
}

int SeamCarver::HorizontalMinValueIndex(int** two_d_array, int min_value, int row, int col) const {
  int index = 0;
  if (row == 0) {
    if (min_value == two_d_array[row][col + 1]) {
      index = row;
    } else if (min_value == two_d_array[row + 1][col + 1]) {
      index = row +1;
    }
  } else if (row == GetHeight() - 1) {
    if (min_value == two_d_array[row][col + 1]) {
      index = row;
    } else if (min_value == two_d_array[row - 1][col + 1]) {
      index = row - 1;
    } 
  } else {
    if (min_value == two_d_array[row][col + 1]) {
      index = row;
    } else if (min_value == two_d_array[row - 1][col + 1]) {
      index = row - 1;
    } else if (min_value == two_d_array[row + 1][col + 1]) {
      index = row + 1;
    } 
  }
  return index;
}

int* SeamCarver::HorizontalSeamHelper(int** two_d_array) const {
  int index = 0, array_index = 0;
  int min_value = two_d_array[0][0];
  int* array = new int[GetWidth()];

  for (int row = 0; row < GetHeight(); row++) {
    if (two_d_array[row][0] < min_value) {
      index = row;
    }
  }
  array[array_index] = index;
  array_index++;

  while (array_index != GetWidth()) {
    index = HorizontalMinValueIndex(two_d_array, 
    HorizontalMinValue(two_d_array, index, array_index), 
    index, 
    array_index);
    array[array_index] = index;
    array_index++;
  }
  return array;
}

int* SeamCarver::GetVerticalSeam() const {
  int** two_d_array = new int*[GetHeight()];

  for (int row = 0; row < GetHeight(); row++) {
    two_d_array[row] = new int[GetWidth()];
    for (int col = 0; col < GetWidth(); col++) {
      two_d_array[row][col] = GetEnergy(row, col);
    }
  }

  for (int col = GetWidth() - 2; col > -1; col--) {
    for (int row = 0; row < GetHeight(); row++) {
      two_d_array[row][col] += HorizontalMinValue(two_d_array, row, col);
    }
  }
  return HorizontalSeamHelper(two_d_array);
}

// int SeamCarver::VerticalMinValue(int** two_d_array, int row, int col) const {
// }

// int SeamCarver::VerticalMinValueIndex(int** two_d_array, int min_value, int row, int col) const {

// }

// int* SeamCarver::VerticalSeamHelper(int** two_d_array) const {

// }

void SeamCarver::RemoveHorizontalSeam() {
  
}

void SeamCarver::RemoveVerticalSeam() {
}


// given functions below, DO NOT MODIFY

SeamCarver::SeamCarver(const ImagePPM& image): image_(image) {
  height_ = image.GetHeight();
  width_ = image.GetWidth();
}

void SeamCarver::SetImage(const ImagePPM& image) {
  image_ = image;
  width_ = image.GetWidth();
  height_ = image.GetHeight();
}
