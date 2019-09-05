#include <iostream>
#include "elimination.h"
#include <cstdlib>
using namespace std;
elimination::elimination(matrix a)
  :newMatrix(a)
{
}
elimination::~elimination() {
  free(rightColumn);
  for (int i = 0; i < rows; i++)
  {
    free(coefficients[i]);
  }
  free(coefficients);
}
void elimination::swap(double **a, double **b, double *c, double *d)
{
  double *tempArr = (double *)malloc(rows * sizeof(double));
  double temp;
  tempArr = *a;
  *a = *b;
  *b = tempArr;
  temp = *c;
  *c = *d;
  *d = temp;
  free(tempArr);
}

void elimination::sort()
{
  for (int i = 0; i < rows - 1; i++)
  {
    for (int j = 0; j < rows - i - 1; j++)
    {
      if (coefficients[j][j] > coefficients[j+1][j+1] || coefficients[j][j] == 0)
      {
        swap(&coefficients[j], &coefficients[j+1], &rightColumn[j], &rightColumn[j+1]);
      }
    }
  }
}

void elimination::gaussJordanElimination()
{
  int k;
  double temp; //number used to help eliminate the other number
  double temp2; //number being eliminated
  newMatrix.setDimensions(&rows, &cols);
  coefficients = newMatrix.initCoefMatrix();
  rightColumn = newMatrix.rightSide();
  sort();
  newMatrix.printConfiguration();
  for (int i = 1; i < rows; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (coefficients[i][j] == 0)
      {
        continue;
      }
      k = i;
      do
      {
        k--;
      }
      while (coefficients[k][j] == 0 && k > 0);
      double *tempRow = (double *)malloc(cols * sizeof(double));
      double tempElement;
      for (int counter = 0; counter < cols; counter++)
      {
        tempRow[counter] = coefficients[k][counter];
      }
      tempElement = rightColumn[k];
      temp = coefficients[k][j];
      temp2 = coefficients[i][j];
      if (temp < 0 && temp2 > 0) 
      {
        for (int current = 0; current < cols; current++)
        {
          coefficients[k][current] *= -temp2;
          coefficients[i][current] *= -temp;
        }
        rightColumn[k] *= -temp2;
        rightColumn[i] *= -temp;
      }
      else if ((temp > 0 && temp2 > 0) || (temp < 0 && temp2 < 0))
      {
        for (int current = 0; current < cols; current++)
        {
          coefficients[k][current] *= temp2;
          coefficients[i][current] *= temp;
        }
        rightColumn[k] *= temp2;
        rightColumn[i] *= temp;
      }
      if (temp > 0 && temp2 < 0)
      {
        for (int current = 0; current < cols; current++)
        {
          coefficients[i][current] *= -temp;
          coefficients[k][current] *= -temp2;
        }
        rightColumn[i] *= -temp;
        rightColumn[k] *= -temp2;
      }
      for (int current = 0; current < cols; current++)
      {
        coefficients[i][current] -= coefficients[k][current];
      }
      rightColumn[i] -= rightColumn[k];
      for (int counter = 0; counter < cols; counter++)
      {
        coefficients[k][counter] = tempRow[counter];
      }
      rightColumn[k] = tempElement;
      free(tempRow);
    }
  }
  for (int i = rows - 2; i>= 0; i--)
  {
    for (int j = cols - 1; j > i; j--)
    {
      if (coefficients[i][j] == 0)
      {
        continue;
      }
      k = i;
      do
      {
        k++;
      }
      while (coefficients[k][j] == 0 && k < rows - 1);
      temp = coefficients[k][j];
      temp2 = coefficients[i][j];
      double *tempRow = (double *)malloc(cols * sizeof(double));
      double tempElement;
      for (int counter = 0; counter < cols; counter++)
      {
        tempRow[counter] = coefficients[k][counter];
      }
      tempElement = rightColumn[k];
      if (temp < 0 && temp2 > 0) 
      {
        for (int current = 0; current < cols; current++)
        {
          coefficients[k][current] *= -temp2;
          coefficients[i][current] *= -temp;
        }
        rightColumn[k] *= -temp2;
        rightColumn[i] *= -temp;
      }
      else if ((temp > 0 && temp2 > 0) || (temp < 0 && temp2 < 0))
      {
        for (int current = 0; current < cols; current++)
        {
          coefficients[k][current] *= temp2;
          coefficients[i][current] *= temp;
        }
        rightColumn[k] *= temp2;
        rightColumn[i] *= temp;
      }
      if (temp > 0 && temp2 < 0)
      {
        for (int current = 0; current < cols; current++)
        {
          coefficients[i][current] *= -temp;
          coefficients[k][current] *= -temp2;
        }
        rightColumn[i] *= -temp;
        rightColumn[k] *= -temp2;
      }
      for (int current = 0; current < cols; current++)
      {
        coefficients[i][current] -= coefficients[k][current];
      }
      rightColumn[i] -= rightColumn[k];
      for (int counter = 0; counter < cols; counter++)
      {
        coefficients[k][counter] = tempRow[counter];
      }
      rightColumn[k] = tempElement;
      free(tempRow);
    }
  }
  for (int i = 0; i < rows; i++)
  {
    temp = coefficients[i][i];
    for (int col = 0; col < cols; col++)
    {
      coefficients[i][col] /= temp;
    }
    rightColumn[i] /= temp;
  }

}

void elimination::printSolution()
{
  cout << endl << endl << endl << "\t\t\tFinal Matrix Configuration" << endl << endl;
  for (int i = 0; i < rows; i++)
  {
    cout << "|";
    for (int j = 0; j < cols; j++)
    {
      if (coefficients[i][j] == 0)
      {
        cout << (unsigned)coefficients[i][j] << " ";
      }
      else
      {
        cout << coefficients[i][j] << " ";
      }
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
