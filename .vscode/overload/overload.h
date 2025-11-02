#include <iostream>
using namespace std;

class Distance{
  private:
    int feet;
    float inches;
  public:
    Distance();
    Distance(int ft, float in);
    void showDistance();
    void setFeet(int);
    void setInches(float);

    int getFeet(){
      return feet;
    }
    int getInches(){
      return inches;
    }

    Distance operator+(Distance &) const;
    Distance operator-(Distance &) const;
    Distance operator*(Distance &) const;
    Distance operator/(Distance &) const;

    bool operator==(Distance &) const;
    bool operator!=(Distance &) const;
    bool operator<(Distance &) const;
    bool operator>(Distance &) const;
};