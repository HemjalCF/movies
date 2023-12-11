#include "movies.hh"
#include "utilities.hh"
#include <utility>
#include <algorithm>
#include <set>

static bool compareFunction (std::string a, std::string b) {return a<b;}   // should return string compared
Utilities utilities;

Movies::Movies()
{

}

void Movies::show_multiplex(movies_ds movies_ds_tmp)
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

void Movies::show_multiplex_halls(movies_ds movies_ds_tmp)
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
