#include "matrix.h"
#include <iostream>
#include <cstdlib>
using namespace std;
void matrix::setDimensions(int *r, int *c)
{
  do
  {
    cout << "Enter the amount of rows -> ";
    cin >> *r;
    rows = *r;
    cout << "Enter the amount of columns -> ";
    cin >> *c;
    cols = *c;
    if (*r != *c)
    {
      cout << "The number of columns and rows have to be the same! Please try again." << endl;
    }
  }
  while (*r != *c);
}

double **matrix::initCoefMatrix()
{
  coeffs = (double **)malloc(rows * sizeof(double *));
  for (int i = 0; i < cols; i++)
  {
    coeffs[i] = (double *)malloc(cols * sizeof(double));
  }
  for (int i = 0; i < rows; i++)
  {
    switch (i)
    {
      case 0: cout << "Enter the " << i + 1 <<"st row" << endl;
              break;
      case 1: cout << "Enter the " << i + 1 <<"nd row" << endl;
              break;
      case 2: cout << "Enter the " << i + 1 <<"rd row" << endl;
              break;
      default: cout << "Enter the " << i + 1 <<"th row" << endl;
    }
    for (int j = 0; j < cols; j++)
    {
      cin >> coeffs[i][j];
    }
  }
  return coeffs;
}

double *matrix::rightSide()
{
  rightColumn = (double *)malloc(rows * sizeof(double *));
  cout << "Enter everything on the right side" << endl;
  for (int i = 0; i < rows; i++)
  {
    cin >> rightColumn[i];
  }
  return rightColumn;
}

void matrix::printConfiguration()
{
  cout << "\t\t\tFinal Matrix Configuration" << endl << endl;
  for (int i = 0; i < rows; i++)
  {
    cout << "|";
    for (int j = 0; j < cols; j++)
    {
      cout << coeffs[i][j] << " ";
    }
    if (i == rows / 2)
    {
      cout << " |x = |" << rightColumn[i] << "|" << endl;
    }
    else
    {
      cout << " |    |" << rightColumn[i] << "|" << endl;
    }
  }
}
