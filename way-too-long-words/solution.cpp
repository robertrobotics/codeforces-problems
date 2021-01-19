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

    int t;
    cin >> t;

    vector<string> lines;
    while ( t-- ) {
        string line;
        cin >> line;

        // only words are allowed (not digits etc.)
        regex wordRegex("\\w+");
        if (regex_match(line, wordRegex)) {
            lines.push_back(line);
        }
    }

    // iterate over lines
    int index = 0;
    for (const string& line : lines) {
        if (line.length() > 10) {
            // length longer than 10 -> convert into required format
            stringstream ss;
            ss << line[0] << line.length() - 2 << line[line.length() - 1];
            lines[index++] = ss.str();
        } else {
            // if words contains less than 10 chars then don't change
            lines[index++] = line;
        }
    }

    // output every line
    for (const string& line : lines) {
        cout << line << endl;
    }

    return 0;
}