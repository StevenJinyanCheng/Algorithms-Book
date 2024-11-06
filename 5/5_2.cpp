#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

// A simple absolute value function
int _abs(int n) {
    return (n > 0) ? n : -n;
}

// The Ducci sequence transformation
vector<int> ducci(const vector<int>& l) {
    vector<int> newlist;
    int len = l.size();
    for (int i = 0; i < len - 1; ++i) {
        newlist.push_back(_abs(l[i + 1] - l[i]));
    }
    newlist.push_back(_abs(l[len - 1] - l[0])); // last to first
    return newlist;
}

// Solve the problem
void solve_problem() {
    int n;
    cin >> n;
    vector<int> l;
    set<vector<int>> s;
    string k;

    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        l.push_back(temp);
    }

    while (true) {
        if (s.find(l) != s.end()) {
            // Check if all elements in the sequence are zero
            if (all_of(l.begin(), l.end(), [](int x){ return x == 0; })) {
                cout << "ZERO" << endl;
            } else {
                cout << "LOOP" << endl;
            }
            break;
        }
        s.insert(l);
        l = ducci(l);
    }
}

int main() {
    solve_problem();
    return 0;
}
