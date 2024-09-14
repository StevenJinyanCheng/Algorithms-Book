#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// Function to convert a string of form "{a:1, b:2}" to a dictionary (unordered_map)
unordered_map<string, int> str2dict(string s) {
    unordered_map<string, int> dict;
    // Remove the starting and ending curly braces
    if (s.front() == '{' && s.back() == '}') {
        s = s.substr(1, s.size() - 2);
    }
    if (s.empty()) {
        return dict;
    }
    
    stringstream ss(s);
    string token;

    while (getline(ss, token, ',')) {
        token.erase(remove(token.begin(), token.end(), ' '), token.end()); // Remove spaces
        size_t colon_pos = token.find(':');
        string key = token.substr(0, colon_pos);
        int value = stoi(token.substr(colon_pos + 1));
        dict[key] = value;
    }

    return dict;
}

// Function to compare two dictionaries and return the changes
string solve_problem(unordered_map<string, int>& d1, unordered_map<string, int>& d2) {
    vector<string> adds, dels, mods;
    vector<string> d1keys, d2keys;

    for (const auto& pair : d1) {
        d1keys.push_back(pair.first);
    }
    for (const auto& pair : d2) {
        d2keys.push_back(pair.first);
    }

    // Check for added keys
    for (const auto& key : d2keys) {
        if (d1.find(key) == d1.end()) {
            adds.push_back(key);
        }
    }

    // Check for deleted keys
    for (const auto& key : d1keys) {
        if (d2.find(key) == d2.end()) {
            dels.push_back(key);
        }
    }

    // Check for modified keys
    for (const auto& key : d1keys) {
        if (d2.find(key) != d2.end() && d1[key] != d2[key]) {
            mods.push_back(key);
        }
    }

    // Sort all lists for consistent output
    sort(adds.begin(), adds.end());
    sort(dels.begin(), dels.end());
    sort(mods.begin(), mods.end());

    string result = "";

    // Format the result string
    if (!adds.empty()) {
        result += "+";
        for (size_t i = 0; i < adds.size(); ++i) {
            result += adds[i];
            if (i != adds.size() - 1) result += ",";
        }
        result += ";";
    }
    if (!dels.empty()) {
        result += "-";
        for (size_t i = 0; i < dels.size(); ++i) {
            result += dels[i];
            if (i != dels.size() - 1) result += ",";
        }
        result += ";";
    }
    if (!mods.empty()) {
        result += "*";
        for (size_t i = 0; i < mods.size(); ++i) {
            result += mods[i];
            if (i != mods.size() - 1) result += ",";
        }
        result += ";";
    }

    if (result.empty()) {
        result = "No changes";
    }

    return result;
}

int main() {
    string s1, s2;

    // Input two dictionary-like strings
    getline(cin, s1);
    getline(cin, s2);

    // Convert the strings to dictionaries
    unordered_map<string, int> d1 = str2dict(s1);
    unordered_map<string, int> d2 = str2dict(s2);

    // Print the result of the comparison
    cout << solve_problem(d1, d2) << endl;

    return 0;
}
