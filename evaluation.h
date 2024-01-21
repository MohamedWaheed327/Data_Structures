#ifndef evaluate_h
#define evaluate_h
#include "infixToPostfix.h"

double calc(double x, double y, char sign) {
    if (sign == '+') {
        return x + y;
    }
    if (sign == '-') {
        return x - y;
    }
    if (sign == '*') {
        return x * y;
    }
    if (sign == '/') {
        return x / y;
    }
    if (sign == '%') {
        return (int)x % (int)y;
    }
    if (sign == '^') {
        return pow(x, y);
    }
    return 0;
}

double evaluate(string expression) {
    expression = InfixToPostfix(expression);
    stack<double> st(100);
    for (int i = 0; i < expression.size(); i++) {
        if (isdigit(expression[i])) {
            st.push(expression[i] - '0');
        }
        else {
            double op2 = st.pop();
            double op1 = st.pop();
            st.push(calc(op1, op2, expression[i]));
        }
    }
    return st.pop();
}

#endif