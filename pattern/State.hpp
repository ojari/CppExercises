#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum State {
    LOCKED,
    DIGITS,
    FAILED,
    OPEN
};

class CombinationLock {
    vector<int> combination;
public:
    string status;
    State state;
    int digits_entered;

    CombinationLock(const vector<int> &combination) : 
        combination(combination),
        status("LOCKED"),
        state(LOCKED) {
    }

    void enter_digit(int digit) {
        switch (state) {
            case LOCKED:
                state = (digit == combination[0]) ? DIGITS : FAILED;
                digits_entered = 1;
                status = to_string(digit);
                break;
            case DIGITS:
                status += to_string(digit);
                if (digit == combination[digits_entered]) {
                    digits_entered++;
                    if (digits_entered == combination.size()) {
                        toOpenState();
                    }
                }
                else {
                    toFailedState();
                }
                break;
            case FAILED:
                status += to_string(digit);
                digits_entered++;
                if (digits_entered == combination.size()) {
                    toFailedState();
                }
                break;
            case OPEN:
                break;
        }
    }
private:
    void toFailedState() {
        state = FAILED;
        status = "FAILED";
    }
    void toOpenState() {
        state = OPEN;
        status = "OPEN";
    }
};