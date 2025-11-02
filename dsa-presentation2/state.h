#include <string>
using namespace std;

class State {
public:
    int mLeft, cLeft;
    int mRight, cRight;
    bool boatOnLeft;
    string move;
    
    State();
    State(int ml, int cl, int mr, int cr, bool boat, string m);
    
    bool isValid();
    bool isGoal();
    bool isEqual(State other);
    void printState();
};