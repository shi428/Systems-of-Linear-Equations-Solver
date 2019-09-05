#include "matrix.h"
class elimination
{
  public:
  elimination(matrix);
  ~elimination();
  void gaussJordanElimination();
  void printSolution();
  void sort();
  void swap(double **, double **, double *, double *);
  private:
  matrix newMatrix;
  int rows;
  int cols;
  double **coefficients;
  double *rightColumn;
};

