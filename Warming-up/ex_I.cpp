#include <iostream>
#include <string>
#include <stack>

using namespace std;
int main() {
    string s;
    stack<char> stack;

    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            stack.push(s[i]);
        else if (!stack.empty() &&
                ((s[i] == ')' && stack.top() == '(') ||
                 (s[i] == '}' && stack.top() == '{') ||
                 (s[i] == ']' && stack.top() == '[')))
                 stack.pop();
        else {
            cout << "no" << endl;
            return 0;
        }
    }
    if (stack.empty())
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}
// DONE
