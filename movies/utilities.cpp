#include "utilities.hh"

Utilities::Utilities()
{

}

std::vector<std::string> Utilities::split(const std::string &str, char delim)
{
    std::vector<std::string> result = {""};
    bool inside_quotation = false;
    for(char current_char : str)
    {
        if(current_char == '"')
        {
            inside_quotation = not inside_quotation;
        }
        else if(current_char == delim and not inside_quotation)
        {
            result.push_back("");
        }
        else
        {
            result.back().push_back(current_char);
        }
    }
    return result;
}

bool Utilities::replace_str(std::string &str, const std::string &from, const std::string &to)
{
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;

}

void Utilities::print_map(std::map<std::string,std::map<std::string,std::map<std::string,std::map<std::string,std::string>>>> tm)
{
    for (auto it1 = tm.begin(); it1 != tm.end(); it1++) {
        std::cout<<it1->first<<std::endl;
        auto m1 = it1->second;
        for (auto it2 = m1.begin(); it2 != m1.end(); it2++) {
            std::cout<<"\t"<<it2->first<<std::endl;
            auto m2 = it2->second;
            for (auto it3 = m2.begin(); it3 != m2.end(); it3++) {
                std::cout<<"\t\t"<<it3->first<<std::endl;
                auto m3 = it3->second;
                for (auto it4 = m3.begin(); it4 != m3.end(); it4++) {
                    std::cout<<"\t\t\t"<<it4->first<<" ";
                    std::cout<<"\t\t\t"<<it4->second<<std::endl;
                }
            }
        }
    }
}

