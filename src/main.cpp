  // Copyright DB 2021

#include <string>
#include "postfix.h"

int main() {
    std::string s1("5 - 1 * 2 / (3 - 5)");
    std::string s2 = infix2postfix(s1);
    std::cout << s2;
}
