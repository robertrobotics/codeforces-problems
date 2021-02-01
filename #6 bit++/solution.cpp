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

    regex preinc_regex = std::regex("^\\+\\+[x,X]");
    regex predec_regex = std::regex("^\\-\\-[x,X]");
    regex posinc_regex = std::regex("^[x,X]\\+\\+");
    regex posdec_regex = std::regex("^[x,X]\\-\\-");
    string numberOfStatementsString;
    getline(cin, numberOfStatementsString);
    auto numberOfStatementsLeft = stoi(numberOfStatementsString);

    string line;
    int number = 0;
    while(getline(cin, line) && numberOfStatementsLeft > 0) {
        if (regex_match(line, preinc_regex)) {
            ++number;
        } else if (regex_match(line, posinc_regex)) {
            number++;
        } else if (regex_match(line, predec_regex)) {
            --number;
        } else if (regex_match(line, posdec_regex)) {
            number--;
        }
        numberOfStatementsLeft--;
    }

    cout << number << endl;

    return 0;
}