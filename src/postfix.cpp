// Copyright DB 2021

#include "postfix.h"
#include "MyStack.h"

bool isOperator(char c) {
    return (!isalpha(c) && !isdigit(c));
}
int priority(char c) {
    if (c == '-' || c == '+')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '^')
        return 3;
    return 0;
}
std::string infix2postfix(std::string inf) {
    inf = '(' + inf + ')';
    int l = inf.size();
    MyStack<char> char_stack(l);
    std::string output;
    for (int i = 0; i < l; i++) {
        if (inf[i] != ' ') {
            if (isdigit(inf[i])) {
                output += inf[i];
                output += " ";
            }
            else if (inf[i] == '.') {
                output = output.substr(0, output.size() - 1);
                output += inf[i];
            }
            else if (output[output.size()] == '.') {
                output += inf[i];
                output += " ";
            }
            else if (inf[i] == '(') {
                char_stack.push('(');
            }
            else if (inf[i] == ')') {
                while (char_stack.get() != '(') {
                    output += char_stack.get();
                    output += " ";
                    char_stack.pop();
                }
                char_stack.pop();
            }
            else {
                if (isOperator(char_stack.get())) {
                    while (priority(inf[i])
                        <= priority(char_stack.get())) {
                        output += char_stack.get();
                        output += " ";
                        char_stack.pop();
                    }
                    char_stack.push(inf[i]);
                }
            }
        }
    }
    output = output.substr(0, output.size() - 1);
    return output;
}