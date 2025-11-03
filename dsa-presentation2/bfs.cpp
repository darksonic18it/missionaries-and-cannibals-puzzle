#include "Solver.h"
#include <iostream>
#include <vector>
using namespace std;

// BOAT CAPACITY - CHANGE THIS NUMBER ONLY!
const int BOAT_CAPACITY = 2;  // Change to 3, 4, 5... whatever you want!

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

    vector<State> nextStates;

if (current.boatOnLeft) {
    // Generate all possible moves (prioritize cannibals first)
    for (int total = BOAT_CAPACITY; total >= 1; total--) {
        for (int m = 0; m <= total; m++) {  // now prioritizes C's first
            int c = total - m;

            if (c < 0) continue;

            State newState;
            string moveDesc = "";

            if (current.boatOnLeft) {
                // Left to Right
                newState = State(current.mLeft - m, current.cLeft - c,
                                 current.mRight + m, current.cRight + c, false, "");

                for (int i = 0; i < m; i++) moveDesc += "M ";
                for (int i = 0; i < c; i++) moveDesc += "C ";
                moveDesc += "cross to Right";
            } else {
                // Right to Left
                newState = State(current.mLeft + m, current.cLeft + c,
                                 current.mRight - m, current.cRight - c, true, "");

                for (int i = 0; i < m; i++) moveDesc += "M ";
                for (int i = 0; i < c; i++) moveDesc += "C ";
                if(total == 1){
                    moveDesc += "returns to Left";
                }else{
                    moveDesc += "return to Left";
                }
            }

            newState.move = moveDesc;

            if (newState.isValid()) {
                nextStates.push_back(newState);
            }
        }
    }
}else {
        // For returning to left, prioritize 1 person first (total from 1 to BOAT_CAPACITY), then 2, etc., but allow up to capacity
        for (int total = 1; total <= BOAT_CAPACITY; total++) {
            for (int m = 0; m <= total; m++) {
                int c = total - m;
                if (c < 0) continue;
                State newState = State(current.mLeft + m, current.cLeft + c,
                                       current.mRight - m, current.cRight - c, true, "");
                string moveDesc = "";
                for (int i = 0; i < m; i++) moveDesc += "M ";
                for (int i = 0; i < c; i++) moveDesc += "C ";
                if(total == 1){
                    moveDesc += "returns to Left";
                }else{
                    moveDesc += "return to Left";
                }
                newState.move = moveDesc;
                if (newState.isValid()) {
                    nextStates.push_back(newState);
                }
            }
        }
    }

    // Try all valid moves
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
