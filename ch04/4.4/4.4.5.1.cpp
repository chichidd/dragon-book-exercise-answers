#include <iostream>

/*

ref: meribold @ https://cs.stackexchange.com/questions/32749/recursive-descent-parser-with-backtracking-for-the-grammar-s-rightarrow-asa

*/


char* next;    
bool term(char token) {
    if (*next != '\0')
        return *next++ == token;
    else
        return false;
}

bool s();    
bool s1() {
    return term('a') && s() && term('a');
}    
bool s2() {
    return term('a') && term('a');
}    
bool s() {
    auto save = next;
    return s1() or (next = save, s2());
}    

int main(int argc, char* argv[]) {
    next = "aaaaaa";
    if (s() && *next == '\0') {
        std::cout << "match";
    }
    else
        std::cout << "no match";
}