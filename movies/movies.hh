#ifndef MOVIES_HH
#define MOVIES_HH

#include "utilities.hh"
#include <fstream>
#include <utility>
#include <algorithm>
#include <set>
#include <string>
#include <iostream>
#include <vector>
#include <map>

const std::string PROMPT = "movies> ";

// Error and other messages
const std::string EMPTY_FIELD = "Error: Empty field in line ";
const std::string FILE_ERROR = "Error: Input file cannot be opened";
const std::string WRONG_PARAMETERS = "Error: Wrong number of parameters";
const std::string Cinema_Hall_NOT_FOUND = "Error: Unknown Cinema Hall";
const std::string Movie_NOT_FOUND = "Error: Unknown Movie";
const std::string Auditorium_NOT_FOUND = "Error: Unknown Movie";
const std::string CITY_NOT_FOUND = "Error: Unknown City";
const std::string COMMAND_NOT_FOUND = "Error: Unknown command";
const std::string NOT_AVAILABLE = "No movies available";


class Movies
{
public:
    Movies();
    typedef std::map<std::string,std::map<std::string,std::map<std::string,std::map<std::string,std::string>>>> movies_ds_t; //DS for theater app
    movies_ds_t read_saved_movies_data(std::string file_name);
    void print_movies_ds(movies_ds_t movies_ds);
    void show_multiplex(movies_ds_t movies_ds_tmp);
    void show_multiplex_halls(movies_ds_t movies_ds_tmp);
    void get_multiplex_name_of_a_auditorium(movies_ds_t movies_ds_tmp,std::string auditorium_name );
    void get_movies_name_in_a_city(movies_ds_t movies_ds_tmp,std::string city_name );
private:
    Utilities utilities;
};

#endif // MOVIES_HH
