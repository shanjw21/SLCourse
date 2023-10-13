#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

int minModification(string brackets) {
    stack<char> st;
    unordered_map<char, char> matchingPairs = {
        {'<', '>'},
        {'{', '}'},
        {'[', ']'},
        {'(', ')'}
    };
    int modificationCount = 0;

    for (char bracket : brackets) {
        if (bracket == '<' || bracket == '{' || bracket == '[' || bracket == '(') {
            st.push(bracket);
        } else {
            if (st.empty() || bracket != matchingPairs[st.top()]) {
                // Modify the bracket to make it matching
                modificationCount++;
            } else {
                st.pop();
            }
        }
    }

    // Add the modification count required for unmatched opening brackets
    modificationCount += st.size();

    return modificationCount;
}

int main() {
    string brackets;
    cin >> brackets;

    int result = minModification(brackets);
    cout << result << endl;

    return 0;
}
