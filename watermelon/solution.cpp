#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define scand(x) scanf("%d", &x)

string Solve(int weight);

int main() {
    int w;
    string answer;

    // Get the watermelon's weight
    scand(w);
    if (w >= 1 && w <= 100) {
        answer = Solve(w);
    } else {
        throw invalid_argument("Watermelon's weight has to be between 1 and 100 kg!");
    }

    cout << answer << endl;

    return 0;
}

string Solve(int weight) {
    const string correctAnswer = "YES";
    const string wrongAnswer = "NO";

    return weight > 2 && (weight - 2) % 2 == 0
        ? correctAnswer 
        : wrongAnswer;
}