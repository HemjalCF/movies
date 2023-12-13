#include <iostream>
#include "movies.hh"
#include "utilities.hh"

//#define DEBUG

#ifdef DEBUG
#define dout std::cout
#else
#define dout 0 && std::cout
#endif


int main()
{
    std::cout << "Welcome to the movies!" << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << std::endl << std::endl;
    std::map<std::string,std::map<std::string,std::map<std::string,std::map<std::string,std::string>>>> movies_ds; //DS for theater app

    Utilities utilities;
    Movies movies;
    std::string stored_filename = " ";
#ifdef DEBUG
    stored_filename = "test.txt";
#else
    std::cout << "Input file: ";
    getline(std::cin, stored_filename);
#endif
    movies_ds = movies.read_saved_movies_data(stored_filename);
    movies.print_movies_ds(movies_ds);

    while(1)
    {
        std::string line;
        std::cout << "the> ";
        getline(std::cin, line);
        std::vector<std::string> parts = utilities.split(line, ' ');
        if(parts.size() == 0)   // Allowing empty inputs
        {
            continue;
        }
        std::string command = parts.at(0);

        if(command == "multiplex")
        {
            movies.show_multiplex(movies_ds);
        }
        else if(command == "auditorium")
        {
            if(parts.size()>1)
            {
                std::cout<<WRONG_PARAMETERS<<std::endl;
                continue;
            }
            else movies.show_multiplex_halls(movies_ds);
        }
        else if(command == "multiplex_of_auditorium")
        {
            if(parts.size()<2)
            {
                std::cout<<WRONG_PARAMETERS<<std::endl;
                continue;
            }
            std::string auditorium_name = parts.at(1);
            dout<<"Getting name of the multiplex of auditorium:"<<auditorium_name<<std::endl<<std::endl;
            movies.get_multiplex_name_of_a_auditorium(movies_ds, auditorium_name);
        }

        else if(command == "movies_in_city")
        {
            if(parts.size() !=2)
            {
                std::cout<<WRONG_PARAMETERS<<std::endl;
                continue;
            }
            std::string movies_in_city = parts.at(1);
            dout<<"Getting movies in City: "<<movies_in_city<<std::endl<<std::endl;
            movies.get_movies_name_in_a_city(movies_ds,movies_in_city);
        }
        else if(command == "quit")
        {
            return EXIT_SUCCESS;
        }
        else
        {
            std::cout<<COMMAND_NOT_FOUND<<std::endl;
        }
    }

    return 0;
}
