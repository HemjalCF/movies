#ifndef UTILITIES_HH
#define UTILITIES_HH
#include <string>
#include <vector>
#include <map>
#include <iostream>


class Utilities
{
public:
    Utilities();
    std::vector<std::string> split(const std::string& str, char delim);
    bool compareFunction (std::string a, std::string b) {return a<b;}   // should return string compared
    bool replace_str(std::string& str, const std::string& from, const std::string& to);
    static void print_map(std::map<std::string,std::map<std::string,std::map<std::string,std::map<std::string,std::string>>>>target_map); // Printing map for debug purpose

};

#endif // UTILITIES_HH
