#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string numberOfLinesString;
    getline(cin, numberOfLinesString);
    auto numberOfLinesLeft = stoul(numberOfLinesString);

    string line;
    vector<string> lines;
    while (getline(cin, line) && numberOfLinesLeft-- > 0) {
        regex wordRegex("^[0-1 ]+");
        if (regex_match(line, wordRegex)) {
            lines.push_back(line);
        }
    }

    // iterate over lines
    int numberOfProblemsSolved = 0;
    for (const string& line : lines) {
        if (count(line.begin(), line.end(), '1') > 1) {
            numberOfProblemsSolved++;   
        }
    }
    
    cout << numberOfProblemsSolved << endl;

    return 0;
}