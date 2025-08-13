#include <iostream>
#include <stack>
#include <map>
using namespace std;

map<char,int> outP =
    {{'+',2},{'-',2},{'*',4},{'/',4},{'^',8},{'(',9},{')',1}};
map<char,int> inP =
    {{'+',3},{'-',3},{'*',5},{'/',5},{'^',7},{'(',0}};

string infix2postfix(string &infix) {
    //  infix:   1+2*(3+4)^(5+6)^7-((8+9)*3/4)
    //  postfix: 1234+56+7^^*+89+3*4/-
    int n = infix.length();
    string postfix(n, ' ');
    stack<char> s;
    int j = 0;
    for (int i=0; i<n; i++) {
        char token = infix[i];
        if (outP[token] == 0) {
            postfix[j++] = token;   // token is operand
        } else {
            int p = outP[token];
            while( !s.empty() && inP[s.top()] >= p ) {
                postfix[j++] = s.top(); s.pop();
            }
            if (token == ')') s.pop(); else s.push(token);
        }
    }
    while(!s.empty()) {
        postfix[j++] = s.top(); s.pop();
    }
    return postfix;
}

int main() {
    string infix;
    while(true) {
        cout << "infix  : ";
        cin >> infix;
        if (infix == ".") break;
        string postfix = infix2postfix(infix);
        cout << "postfix: " << postfix << endl;
    }
    return 0;
}
