#include <array>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#define BASE 100000000  // Base 10^8
#define DIGIT_LENGTH 8  // Each element in the array represents 8 digits
#define MAX_FIB_SIZE 100000
#define MAX_FIB_DIGIT 20900

class ArrayWrapper {
public:
    std::array<int, 2613> a;

    // Constructor that initializes all elements to 0
    ArrayWrapper() {
        a.fill(0);
    }

    // Set the value of the ArrayWrapper to a given unsigned integer
    void set_value(unsigned int value) {
        a.fill(0);
        a[0] = value;
    }

    // Addition with another ArrayWrapper
    void add(const ArrayWrapper &other) {
        int64_t carry = 0;
        for (size_t i = 0; i < a.size(); ++i) {
            int64_t sum = static_cast<int64_t>(a[i]) + static_cast<int64_t>(other.a[i]) + carry;
            if (sum >= BASE) {
                carry = sum / BASE;
                sum %= BASE;
            } else {
                carry = 0;
            }
            a[i] = static_cast<int>(sum);
        }
    }

    // Swap the values of two ArrayWrapper objects
    void swap(ArrayWrapper &other) {
        std::swap(a, other.a);
    }

    // Convert the ArrayWrapper to a string
    std::string to_string() const {
        std::string result;
        bool leading = true;
        for (int i = a.size() - 1; i >= 0; --i) {
            if (leading && a[i] == 0) continue;
            leading = false;
            if (result.empty()) {
                result = std::to_string(a[i]);
            } else {
                result += std::to_string(a[i] + BASE).substr(1);  // Ensures leading zeros are maintained
            }
        }
        return leading ? "0" : result;
    }

    // Compare the ArrayWrapper with a string
    bool starts_with(const std::string &s) const {
        return to_string().substr(0, s.size()) == s;
    }
};

int main() {
    int T, cscnt = 1;
    std::cin >> T;

    char s[50];
    ArrayWrapper now, last;
    last.set_value(1);

    while (T--) {
        int found = 0;
        std::memset(s, 0, sizeof(s));
        std::cin >> s;
        std::string target(s);
        std::cout << "Case #" << cscnt << ": ";

        for (int i = 0; i <= MAX_FIB_SIZE; i++) {
            if (i > 1) {
                now.add(last);
                now.swap(last);
            } else if (i == 1) {
                now.set_value(1);
            }

            if (last.starts_with(target)) {
                std::cout << i << std::endl; // Found the matching Fibonacci number
                found = 1;
                break;
            }
        }

        if (!found) {
            std::cout << "-1" << std::endl;
        }

        now.set_value(0);
        last.set_value(1);
        cscnt++;
    }

    return 0;
}
