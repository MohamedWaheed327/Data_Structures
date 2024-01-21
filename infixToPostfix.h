#ifndef InfixToPostfix_h
#define InfixToPostfix_h

#include "stack.h"
#include <math.h>

int precedence(char x) {
    if (x == '(') {
        return 1;
    }
    else if (x == ')') {
        return 2;
    }
    else if (x == '^') {
        return 5;
    }
    else if (x == '*' || x == '/' || x == '%') {
        return 4;
    }
    else if (x == '+' || x == '-') {
        return 3;
    }
    else {
        return 0;
    }
}

string InfixToPostfix(string infix) {
    string postfix;
    stack<char> st(100);
    infix = '(' + infix + ')';
    for (int i = 0; i < infix.size(); i++) {
        int x = precedence(infix[i]);
        if (x == 1) {
            st.push(infix[i]);
        }
        else if (x == 2) {
            while (st.top() != '(') {
                postfix += st.pop();
            }
            st.pop();
        }
        else if (3 <= x && x <= 5) {
            while (precedence(st.top()) >= x) {
                postfix += st.pop();
            }
            st.push(infix[i]);
        }
        else {
            postfix += infix[i];
        }
    }
    return postfix;
}

#endif