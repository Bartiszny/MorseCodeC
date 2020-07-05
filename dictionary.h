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

std::istream& operator>>(std::istream& is, Dictionary& d)
    {
            char ch1 =0;
            char ch2 =0;
            char ch3 =0;
            char ch4 =0;
            Dictionary dd;

            if (is >> ch1 >> dd.letter
                >> ch2 >> dd.cap_letter
                >> ch3 >> dd.code >> ch4)
            {
                if (ch1!= '(' || ch2!= ',' ||
                    ch3!= ':' || ch4!= ')')
                {
                    is.clear(std::ios_base::failbit);
                    return is;
                }
            }
            else
                return is;
            d = dd;
            return is;
    }