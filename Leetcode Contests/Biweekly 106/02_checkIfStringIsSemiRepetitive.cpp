#include <iostream>
#include <unordered_map>
using namespace std;

    bool isAtMostOneNumberRepeatedTwice(const int charCount[]) {
        int countTwice = 0;
        bool hasMoreThanTwo = false;

        for (int i = 0; i < 26; i++) {
            if (charCount[i] == 2) {
                countTwice++;
                if (countTwice > 1) {
                    return false;
                }
            } else if (charCount[i] > 2) {
                hasMoreThanTwo = true;
            }
        }

        return !hasMoreThanTwo;
    }

    void solve(const string& s, string& currentSubstring, int index, int charCount[], int& maxLength) {
        if (index == s.length()) {
            for (auto i : currentSubstring) {
                charCount[i - 'a']++;
            }
            if (isAtMostOneNumberRepeatedTwice(charCount)) {
                maxLength = max(maxLength, static_cast<int>(currentSubstring.size()));
            }
            for (auto i : currentSubstring) {
                charCount[i - 'a']--;
            }
            return;
        }

        currentSubstring.push_back(s[index]);
        solve(s, currentSubstring, index + 1, charCount, maxLength);
        currentSubstring.pop_back();
        solve(s, currentSubstring, index + 1, charCount, maxLength);
    }

    int longestSemiRepetitiveSubstring(const string& s) {
        int charCount[26] = {0};
        int index = 0;
        string currentSubstring;
        int maxLength = 0;
        solve(s, currentSubstring, index, charCount, maxLength);
        return maxLength;
    }

int main() {
    string s = "0010";
    cout << longestSemiRepetitiveSubstring(s);
    return 0;
}
