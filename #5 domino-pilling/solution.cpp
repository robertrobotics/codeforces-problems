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

    const int single_domino_surface_area = 2;
    string line;
    getline(cin, line);
    auto board_dimension = get_integers_from_string(line);

    if (board_dimension.size() != 2) {
        return 0;
    }

    int m = board_dimension[0];
    int n = board_dimension[1];
    int max_number_of_placed_dominos_in_board = (m*n) / single_domino_surface_area;
    cout << max_number_of_placed_dominos_in_board << endl;
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