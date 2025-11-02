#include "overload.h"
#include <iomanip>
#include <cmath>

Distance::Distance(){
  feet = 0;
  inches = 0.0;
}
Distance::Distance(int ft, float in){
  feet = ft;
  inches = in;
}
void Distance::setFeet(int f){
  feet = f;
}
void Distance::setInches(float i){
  inches = i;
}
void Distance::showDistance(){
  cout << feet << "' - " << inches << "\"" << endl;
}
Distance Distance::operator+(Distance &d2) const{
  int ft = feet + d2.feet;
  float in = inches + d2.inches;
  while(in >= 12.0){
    in -= 12.0;
    ft++;
  }
  return Distance(ft, in);
}
Distance Distance::operator-(Distance &d2) const{
  int ft = feet - d2.feet;
  float in = inches - d2.inches;
  while(in < 0.0){
    in += 12.0;
    ft--;
  }
  return Distance(ft, in);
}
Distance Distance::operator*(Distance &d2) const{
  float total1 = feet * 12 + inches;
  float total2 = d2.feet * 12 + d2.inches;

  float result = total1 * total2 / 12;
  int ft = static_cast<int> (result / 12);
  float in = result - (ft * 12);

  cout << fixed << setprecision(2);
  return Distance(ft, in);
}
Distance Distance::operator/(Distance &d2) const{
  if(feet == 0 || d2.feet == 0){
    cout << "Error: Division by zero." << endl;
    return Distance(0, 0.0);
  }
  int ft = feet / d2.feet;
  float in = inches / d2.inches;

  ft = round(ft * 100.0) / 100.0;
  in = round(in * 100.0) / 100.0;
  return Distance(ft, in);
}
bool Distance::operator==(Distance &d2) const{
  return (feet == d2.feet && inches == d2.inches);
}
bool Distance::operator!=(Distance &d2) const{
  return (feet != d2.feet || inches != d2.inches);
}
bool Distance::operator<(Distance &d2) const{
  double result1 = feet + inches;
  double result2 = d2.feet + d2.inches;
  return result1 < result2;
}
bool Distance::operator>(Distance &d2) const{
  double result1 = feet + inches;
  double result2 = d2.feet + d2.inches;
  return result1 > result2;
}


