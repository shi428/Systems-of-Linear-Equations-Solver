#include <iostream>
#include <cstdlib>
#include "elimination.h"
//#include <Windows.h>
using namespace std;
int main()
{
  matrix mobj;
  elimination eobj(mobj);
  eobj.gaussJordanElimination();
  eobj.printSolution();
  //Sleep(10000);
  return EXIT_SUCCESS;
}
