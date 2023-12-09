#ifndef MOVIES_HH
#define MOVIES_HH
#include <string>

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
};

#endif // MOVIES_HH
