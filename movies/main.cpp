#include <iostream>
#include <fstream>
#include <set>
#include <utility>
#include <algorithm>
#include "movies.hh"
#include "utilities.hh"



#define DEBUG

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
    stored_filename = "t.txt";
#else
    std::cout << "Input file: ";
    getline(std::cin, stored_filename);
#endif
    std::ifstream file_object(stored_filename);

    if ( not file_object ) {
        std::cout << FILE_ERROR << std::endl;
        return EXIT_FAILURE;
    }

    std::string line;
    std::vector<std::string> line_strs;
    int line_number = 1;
    size_t i = 0;

    while ( getline(file_object, line) ) {
       // dout<<"Parsing line ["<<line_number<<"]: "<<line<<std::endl;
        line_strs = utilities.split(line, ';');
        for (i = 0; i < line_strs.size(); i++) {
            dout << line_strs[i] << " ";
        }
        dout<<std::endl;

        if(line_strs.size()!=5 )
        {
            std::cout<<EMPTY_FIELD<<line_number<<std::endl;
            return EXIT_FAILURE;
        }

        for (auto i = line_strs.begin(); i != line_strs.end(); i++) {
            std::string buf = *i;
            if(buf.find_first_not_of(' ') != std::string::npos)
            {

            } else
            {
                std::cout<<EMPTY_FIELD<<line_number<<std::endl;
                return EXIT_FAILURE;
            }
        }

        line_number++;

        if(auto search = movies_ds.find(line_strs[0]); search !=movies_ds.end()){
            dout<<"Found city: "<<line_strs[0];
            std::map<std::string,std::map<std::string,std::map<std::string,std::string>>> tmp = search->second;
            if(auto search2 = tmp.find(line_strs[1]); search2 !=tmp.end()){
                dout<<"  : Cinema Hall : "<<line_strs[1];
                std::map<std::string,std::map<std::string,std::string>> tmp2 = search2->second;
                if(auto search3 = tmp2.find(line_strs[2]); search3 !=tmp2.end()){
                    dout<<"  : Movie : "<<line_strs[2]<<std::endl;
                    std::map<std::string,std::string> tmp3 = search3->second;
                    tmp3[line_strs[3]] = line_strs[4];
                    movies_ds[line_strs[0]][line_strs[1]][line_strs[2]]=tmp3;
                }
                else{
                    tmp2[line_strs[2]][line_strs[3]] = line_strs[4];
                    movies_ds[line_strs[0]][line_strs[1]]=tmp2;
                }
            }
            else{
                tmp[line_strs[1]][line_strs[2]][line_strs[3]] = line_strs[4];
                movies_ds[line_strs[0]]=tmp;
            }
        }
        else
        {
            movies_ds[line_strs[0]][line_strs[1]][line_strs[2]][line_strs[3]] = line_strs[4];
        }
    }
    utilities.print_map(movies_ds);
    file_object.close();
    dout<<std::endl<<"*********  Data structure saved   *********"<<std::endl<<std::endl;
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
