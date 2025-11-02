#include "State.h"
#include <iostream>
using namespace std;

State::State() {
    mLeft = 0;
    cLeft = 0;
    mRight = 0;
    cRight = 0;
    boatOnLeft = true;
    move = "";
}

State::State(int ml, int cl, int mr, int cr, bool boat, string m) {
    mLeft = ml;
    cLeft = cl;
    mRight = mr;
    cRight = cr;
    boatOnLeft = boat;
    move = m;
}

bool State::isValid() {
    if (mLeft < 0 || cLeft < 0 || mRight < 0 || cRight < 0)
        return false;
    
    if (mLeft > 0 && cLeft > mLeft)
        return false;
    
    if (mRight > 0 && cRight > mRight)
        return false;
    
    return true;
}

bool State::isGoal() {
    return mLeft == 0 && cLeft == 0 && mRight == 3 && cRight == 3;
}

bool State::isEqual(State other) {
    return mLeft == other.mLeft && cLeft == other.cLeft &&
           mRight == other.mRight && cRight == other.cRight &&
           boatOnLeft == other.boatOnLeft;
}

void State::printState() {
    cout << "Left Bank: ";
    for (int i = 0; i < mLeft; i++) 
        cout << "M ";
    for (int i = 0; i < cLeft; i++) 
        cout << "C ";
    
    if (mLeft == 0 && cLeft == 0) {
        // Empty left bank, show boat on right
        cout << endl;
        cout << "Right Bank: ";
        for (int i = 0; i < mRight; i++) 
            cout << "M ";
        for (int i = 0; i < cRight; i++) 
            cout << "C ";
        cout << "| Boat on Right";
    } else if (boatOnLeft) {
        cout << "| Boat on Left";
        cout << endl;
        cout << "Right Bank: ";
        for (int i = 0; i < mRight; i++) 
            cout << "M ";
        for (int i = 0; i < cRight; i++) 
            cout << "C ";
    } else {
        cout << "| Boat on Right";
        cout << endl;
        cout << "Right Bank: ";
        for (int i = 0; i < mRight; i++) 
            cout << "M ";
        for (int i = 0; i < cRight; i++) 
            cout << "C ";
    }
    cout << endl;
}