#ifndef MOVIES_HH
#define MOVIES_HH
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

const std::string PROMPT = "movies> ";

// Error and other messages
const std::string EMPTY_FIELD = "Error: Empty field in line ";
const std::string FILE_ERROR = "Error: Input file cannot be opened";
const std::string WRONG_PARAMETERS = "Error: Wrong number of parameters";
const std::string Cinema_Hall_NOT_FOUND = "Error: Unknown Cinema Hall";
const std::string Movie_NOT_FOUND = "Error: Unknown Movie";
const std::string Actor_NOT_FOUND = "Error: Unknown Actor";
const std::string CITY_NOT_FOUND = "Error: Unknown City";
const std::string COMMAND_NOT_FOUND = "Error: Unknown command";
const std::string NOT_AVAILABLE = "No movies available";


class Movies
{
public:
    Movies();
    typedef std::map<std::string,std::map<std::string,std::map<std::string,std::map<std::string,std::string>>>> movies_ds; //DS for theater app
    void show_multiplex(movies_ds movies_ds_tmp);
    void show_multiplex_halls(movies_ds movies_ds_tmp);
};

#endif // MOVIES_HH
