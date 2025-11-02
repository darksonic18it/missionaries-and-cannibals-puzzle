#include "overload.h"

int main(){


  Distance d1;
  d1.setFeet(20);
  d1.setInches(5.6);
  Distance d2(5, 10.5);
  Distance d3;
  cout << "\nFirst distance: ";
  d1.showDistance();
  cout << "Second distance: ";
  d2.showDistance();
  d3 = d1 + d2;
  cout << "\nAfter Addition: ";
  d3.showDistance();
  d3 = d1 - d2;
  cout << "After Subtraction: ";
  d3.showDistance();
  d3 = d1 * d2;
  cout << "After Multiplication: ";
  d3.showDistance();
  d3 = d1 / d2;
  cout << "After Division: ";
  d3.showDistance();
  if(d1 == d2)
    cout << "\nDistances are equal." << endl;
  else
    cout << "\nDistances are not equal." << endl;
  if(d1 != d2)
    cout << "Distances are not equal." << endl;
  else
    cout << "Distances are equal." << endl;
  if(d1 < d2)
    cout << "First distance is less than second distance." << endl;
  else
    cout << "First distance is not less than second distance." << endl;
  if(d1 > d2)
    cout << "First distance is greater than second distance." << endl;
  else
    cout << "First distance is not greater than second distance." << endl;

  return 0;
}