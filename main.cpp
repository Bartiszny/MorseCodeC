#include <iostream>
#include <fstream>
#include <limits>
#include <math.h>
#include <string>
#include <windows.h>
#include "dictionary.h"
#include "source.h"
using namespace std;

void dict_init(std::vector<Dictionary> &dict)
{
    for (unsigned short i{0}; i< sizeof(letters); ++i)
    {
        dict.push_back(Dictionary(letters[i],
                                  cap_letters[i],
                                  morse_letters[i]));
    }
    for (unsigned short i{0}; i< sizeof(numbers); ++i)
    {
        dict.push_back(Dictionary(numbers[i],
                                  numbers[i],
                                  morse_numbers[i]));
    }
    for (unsigned short i{0}; i< sizeof(signs); ++i)
    {
        dict.push_back(Dictionary(signs[i],
                                  signs[i],
                                  morse_signs[i]));
    }
    dict.push_back(Dictionary(' ', ' ', "  "));
}
void dict_display(std::vector<Dictionary> &dict)
{
    std::cout<<"Ilosc pozycji w slowniku: "<<dict.size()<<std::endl;
    for (unsigned short i{0}; i<dict.size(); ++i)
        std::cout<<dict[i].letter<<" "<<dict[i].cap_letter<<
                                " "<<dict[i].code<<std::endl;
}

string encode_input_text(vector<Dictionary>& dict)
{
    string input{""}, output{""};
    cout<<"Wprowadz fraze do zakodowania:\n> ";
    while(cin>>input)
    {   if (input == "|")
            break;
        for (unsigned short i{0}; i < input.size(); ++i)
        {
            for (unsigned short j{0}; j < dict.size(); ++j)
            {
                if (dict[j].letter == input[i] || dict[j].cap_letter == input[i])
                    output = output + "   " + dict[j].code;
            }
        }
    }
    return output;
}
void save_code(std::string code)
{
    std::cout<<"\nZapisywanie danych do pliku..."<<std::endl;
    std::string out_name{"KOD.txt"};
    std::ofstream fs(out_name.c_str());
    if (!fs) 
    {
        std::cerr<<"Nie mozna otworzyc pliku wyjsciowego: "<<out_name<<std::endl;
        return;
    }
    fs <<code;
}

int main ()
{
    std::cout<<"\nWczytywanie slownika..."<<std::endl;
    std::string in_name{"KOD.txt"};
    vector<Dictionary> dict(0);
//    std::ifstream ifs(in_name.c_str());
//    if (ifs) 
//    {
//        ifs>>                             
//        
//    }
//    else
//    {
//        std::cerr<<"Nie mozna otworzyc pliku wyjsciowego: "<<out_name<<std::endl;
//        dict_init(dict);
//    }
//    //SetConsoleOutputCP(65001);
    dict_init(dict);
    dict_display(dict);
    std::string output{encode_input_text(dict)};
    
    cout<<"\nWynik: "<<output;
    save_code(output);
}
