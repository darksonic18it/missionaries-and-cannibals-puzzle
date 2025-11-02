#include "Solver.h"
#include <iostream>
#include <vector>
using namespace std;

vector<State> solution;
bool found = false;

bool isInPath(vector<State> &path, State s) {
    for (int i = 0; i < path.size(); i++) {
        if (path[i].isEqual(s))
            return true;
    }
    return false;
}

void dfsHelper(State current, vector<State> &path) {
    if (found) return;
    
    if (current.isGoal()) {
        solution = path;
        found = true;
        return;
    }
    
    // Generate next states in correct order for 9-move solution
    vector<State> nextStates;
    
    if (current.boatOnLeft) {
        // Boat on Left Bank → Move people to Right
        // (Order matters — this order yields the 11-move path)
        State s1(current.mLeft, current.cLeft - 2, current.mRight, current.cRight + 2, false, "C C cross to Right");
        State s2(current.mLeft - 2, current.cLeft, current.mRight + 2, current.cRight, false, "M M cross to Right");
        State s3(current.mLeft - 1, current.cLeft - 1, current.mRight + 1, current.cRight + 1, false, "M C cross to Right");
        State s4(current.mLeft, current.cLeft - 1, current.mRight, current.cRight + 1, false, "C cross to Right");
        State s5(current.mLeft - 1, current.cLeft, current.mRight + 1, current.cRight, false, "M cross to Right");
        
        // Push only valid states
        if (s1.isValid()) nextStates.push_back(s1);
        if (s2.isValid()) nextStates.push_back(s2);
        if (s3.isValid()) nextStates.push_back(s3);
        if (s4.isValid()) nextStates.push_back(s4);
        if (s5.isValid()) nextStates.push_back(s5);
    } else {
        // Boat on Right Bank → Return people to Left
        State s1(current.mLeft, current.cLeft + 1, current.mRight, current.cRight - 1, true, "C returns to Left");
        State s2(current.mLeft + 1, current.cLeft + 1, current.mRight - 1, current.cRight - 1, true, "M C return to Left");
        State s3(current.mLeft + 1, current.cLeft, current.mRight - 1, current.cRight, true, "M returns to Left");
        State s4(current.mLeft, current.cLeft + 2, current.mRight, current.cRight - 2, true, "C C return to Left");
        State s5(current.mLeft + 2, current.cLeft, current.mRight - 2, current.cRight, true, "M M return to Left");
        
        if (s1.isValid()) nextStates.push_back(s1);
        if (s2.isValid()) nextStates.push_back(s2);
        if (s3.isValid()) nextStates.push_back(s3);
        if (s4.isValid()) nextStates.push_back(s4);
        if (s5.isValid()) nextStates.push_back(s5);
    }
    
    for (int i = 0; i < nextStates.size(); i++) {
        if (!isInPath(path, nextStates[i])) {
            path.push_back(nextStates[i]);
            dfsHelper(nextStates[i], path);
            if (found) return;
            path.pop_back();
        }
    }
}

void Solver::solveDFS() {
    State initial(3, 3, 0, 0, true, "");
    vector<State> path;
    path.push_back(initial);
    
    found = false;
    solution.clear();
    
    dfsHelper(initial, path);
    
    if (!found) {
        cout << "No solution found!" << endl;
        return;
    }
    
    cout << "Initial State:" << endl;
    solution[0].printState();
    cout << endl;
    
    for (int i = 1; i < solution.size(); i++) {
        cout << "Move " << i << ": " << solution[i].move << endl;
        solution[i].printState();
        cout << endl;
    }
    
    cout << "Goal reached!" << endl;
    cout << "All missionaries and cannibals are safely on the right bank." << endl;
}
