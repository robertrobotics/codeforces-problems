#include <bits/stdc++.h>

using namespace std;

vector<int> get_integers_from_string(string str);

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string line;
    int n = 0, k = 0, q = 0;
    int iteration = 0;
    vector<int> scores;
    while (getline(cin, line)) {
        auto numbers = get_integers_from_string(line);
        if (iteration == 0 && numbers.size() >= 2) {
            k = numbers[1];
            n = numbers[0];
        } else if (iteration == 1 && numbers.size() >= n) {
            scores = numbers;
        } else {
            break;
        }
        iteration++;
    }

    // Sort in descending order
    sort(scores.begin(), scores.end(), greater<int>());
    auto min_value_to_qualify = scores[k-1];
    for (auto&& score: scores) {
        if (score >= min_value_to_qualify &&
            0 != min_value_to_qualify) {
            q++;
        } else if (0 == min_value_to_qualify) {
            if (score > 0) {
                q++;
            }
        }
    }

    cout << q << endl;

    return 0;
}

vector<int> get_integers_from_string(string str) {
    vector<int> numbers;
    stringstream ss;
    ss << str;

    string word;
    int number;
    while (!ss.eof()) {
        ss >> word;
        if (stringstream(word) >> number) {
            numbers.push_back(number);
        }

        word = "";
    }

    return numbers;
}