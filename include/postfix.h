// Copyright DB 2021

#ifndef INCLUDE_POSTFIX_H_
#define INCLUDE_POSTFIX_H_

#include <iostream>
#include <cstring>
#include <string>

bool isOperator(char c);
int priority(char c);
std::string infix2postfix(std::string infix);

#endif  // INCLUDE_POSTFIX_H_