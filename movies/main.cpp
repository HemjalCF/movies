#include <iostream>
#include "movies.hh"
#include "utilities.hh"

using namespace std;

int main()
{
    cout << "Welcome to the movies!" << endl;
    cout << "----------------------" << endl;
    cout << "----------------------" << endl;
    cout << endl << endl;
    map<string,map<string,map<string,map<string,string>>>> tm; //DS for theater app
    string stored_filename = " ";
    cout << "Input file: ";
    getline(cin, stored_filename);
    return 0;
}
