#include <iostream>
#include <string>
#include <limits>
#include <math.h>


class Dictionary {
    
public:
    Dictionary(char letter='0', char cap_letter='0', std::string code="0") 
    : letter(letter), cap_letter(cap_letter), code(code) {}
    
    char letter;
    char cap_letter;
    std::string code;
    
};