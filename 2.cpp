#include <iostream>
#include <string>

using namespace std;

float calRotations(string directions[], int n) {
    int totalDegs = 0;
    for (int i = 0; i < n; i++) {
        if (directions[i] == "right") {
            totalDegs += 90; 
        } else if (directions[i] == "left") {
            totalDegs -= 90;
        }
    }

    float fullRotations = float(totalDegs) / 360;
    if (fullRotations < 0) {
        fullRotations = -fullRotations;
    }

    return fullRotations;
}

int main() {
    int n;
    cout << "Enter the number of directions: ";
    cin >> n;

    string directions[n]; 
    cout << "Enter directions (left or right): ";
    for (int i = 0; i < n; i++) {
        cin >> directions[i];
    }

    float rotations = calRotations(directions, n);
    cout << "Rotations made: " << rotations << endl;

    return 0;
}
