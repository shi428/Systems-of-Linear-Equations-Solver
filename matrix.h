class matrix
{
  public:
  void setDimensions(int *, int *);
  double **initCoefMatrix();
  double *rightSide();
  void printConfiguration();
  private:
  int rows;
  int cols;
  double **coeffs;
  double *rightColumn;
};
