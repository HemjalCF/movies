#include "movies.hh"

static bool compareFunction (std::string a, std::string b) {return a<b;}   // should return string compared

Movies::Movies()
{

}

Movies::movies_ds_t Movies::read_saved_movies_data(std::string file_name)
{
    movies_ds_t movies_ds;
    std::ifstream file_object(file_name);

    if ( not file_object ) {
        std::cout << FILE_ERROR << std::endl;
        return movies_ds;
    }

    std::string line;
    std::vector<std::string> line_strs;
    int line_number = 1;
    size_t i = 0;

    while ( getline(file_object, line) ) {
        // dout<<"Parsing line ["<<line_number<<"]: "<<line<<std::endl;
        line_strs = utilities.split(line, ';');
        for (i = 0; i < line_strs.size(); i++) {
           // std::cout << line_strs[i] << " ";
        }
       // std::cout<<std::endl;

        if(line_strs.size()!=5 )
        {
            std::cout<<EMPTY_FIELD<<line_number<<std::endl;
            return movies_ds;
        }

        for (auto i = line_strs.begin(); i != line_strs.end(); i++) {
            std::string buf = *i;
            if(buf.find_first_not_of(' ') != std::string::npos)
            {

            } else
            {
                std::cout<<EMPTY_FIELD<<line_number<<std::endl;
                return movies_ds;
            }
        }

        line_number++;

        if(auto search = movies_ds.find(line_strs[0]); search !=movies_ds.end()){
           // std::cout<<"Found city: "<<line_strs[0];
            std::map<std::string,std::map<std::string,std::map<std::string,std::string>>> tmp = search->second;
            if(auto search2 = tmp.find(line_strs[1]); search2 !=tmp.end()){
                //std::cout<<"  : Cinema Hall : "<<line_strs[1];
                std::map<std::string,std::map<std::string,std::string>> tmp2 = search2->second;
                if(auto search3 = tmp2.find(line_strs[2]); search3 !=tmp2.end()){
                   // std::cout<<"  : Movie : "<<line_strs[2]<<std::endl;
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
    file_object.close();
    return movies_ds;
}

void Movies::print_movies_ds(movies_ds_t movies_ds)
{
    for (auto it1 = movies_ds.begin(); it1 != movies_ds.end(); it1++) {
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

void Movies::show_multiplex(movies_ds_t movies_ds_tmp)
{
    std::vector < std::string > multiplex_names;
    for (auto it1 = movies_ds_tmp.begin(); it1 != movies_ds_tmp.end(); it1++) {
        auto multiplex_data = it1->second;
        for (auto it2 = multiplex_data.begin(); it2 != multiplex_data.end(); it2++) {
            multiplex_names.push_back(it2->first);
        }
    }
    sort(multiplex_names.begin(),multiplex_names.end(),compareFunction);
    for (auto it=multiplex_names.begin(); it!=multiplex_names.end(); ++it)
        std::cout << *it<<std::endl;
}

void Movies::show_multiplex_halls(movies_ds_t movies_ds_tmp)
{
    std::set<std::string> auditorium_names;
    for (auto it1 = movies_ds_tmp.begin(); it1 != movies_ds_tmp.end(); it1++) {
        auto multiplex_data = it1->second;
        for (auto it2 = multiplex_data.begin(); it2 != multiplex_data.end(); it2++) {
            auto auditorium_data = it2->second;
            for (auto it3 = auditorium_data.begin(); it3 != auditorium_data.end(); it3++) {
                std::string buf = it3->first;
                auditorium_names.insert(buf);
            }
        }
    }
    for (auto it=auditorium_names.begin(); it!=auditorium_names.end(); ++it)
        std::cout << *it<< std::endl;

}

void Movies::get_multiplex_name_of_a_auditorium(movies_ds_t movies_ds_tmp, std::string auditorium_name)
{
    bool found_target_multiplex=false;
    std::map<std::string, std::set< std::string>> multiplex_of_auditorium_names;
    std::set<std::string> auditorium_names;
    for (auto it1 = movies_ds_tmp.begin(); it1 != movies_ds_tmp.end(); it1++) {
        auto m1 = it1->second;
        for (auto it2 = m1.begin(); it2 != m1.end(); it2++) {
            auto m2 = it2->second;
            auditorium_names.clear();
            for (auto it3 = m2.begin(); it3 != m2.end(); it3++) {
                auditorium_names.insert(it3->first);
                multiplex_of_auditorium_names [it2->first] = auditorium_names;
            }
        }
    }
    for (auto it=multiplex_of_auditorium_names.begin(); it!=multiplex_of_auditorium_names.end(); ++it)
    {
        auto m1 = it->second;
        for (auto it2 = m1.begin(); it2 != m1.end(); it2++) {
            if( *it2 == auditorium_name)
            {
                std::cout << it->first<<std::endl<<std::endl;
                found_target_multiplex = true;
            }
        }

    }
    if(not found_target_multiplex)  std::cout<<Auditorium_NOT_FOUND<<std::endl;
}

void Movies::get_movies_name_in_a_city(movies_ds_t movies_ds_tmp, std::string city_name)
{
    std::map<std::string,std::map<std::string,std::map<std::string, std::string>>> movies_in_city;
    std::vector<std::string> movies_names;
    bool found= false;
    for (auto it1 = movies_ds_tmp.begin(); it1 != movies_ds_tmp.end(); it1++) {
        auto m1 = it1->second;
        for (auto it2 = m1.begin(); it2 != m1.end(); it2++) {
            auto m2 = it2->second;
            for (auto it3 = m2.begin(); it3 != m2.end(); it3++) {
                std::string buf = it3->first;        // movie name
                auto m3 = it3->second;
                movies_names.clear();
                for (auto it4 = m3.begin(); it4 != m3.end(); it4++) {
                    std::string buf2 = it4->first;
                    std::string buf3 = it4->second;
                    if(buf3 == "none") continue;
                    movies_names.push_back(buf3);
                    movies_in_city[it1->first] [it2->first][buf] = buf3;
                }
            }
        }
    }

    for (auto it=movies_in_city.begin(); it!=movies_in_city.end(); ++it)
    {
        auto m1 = it->second;
        for (auto it2 = m1.begin(); it2 != m1.end(); it2++) {
            auto m2 = it2->second;
            for (auto it3 = m2.begin(); it3 != m2.end(); it3++) {
                if( it->first == city_name )
                {
                    std::cout<<it2->first<<" : "<<it3->first<<" : "<<it3->second<<std::endl;
                    found=true;
                }
            }
        }
    }
    if(not found)  std::cout<< CITY_NOT_FOUND <<std::endl;
}
