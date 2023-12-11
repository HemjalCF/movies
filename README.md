# movies
--------------


### Goal: Demo application to demonstrate the use of STL container such as map,vector,set and use of C++ files.

------------

The main data structure and the csv file that saves the data should look like this:

```
  <city>;<multiplex_name>;<auditorium>;<movie_name>;<number_of_free_seats>

```

```
Dhaka
    Blcokbusters
        Rockers
            Love and War     50
            Spartacus        none
        Poppers
            Logan            5
            The Godfather    40
            The Departed     90
        The Grand Dhaka
            Conan            20
            Barbarians       none
    Star Cineplex
        Hall of Illusions
            Love in the sky  28
            Ammajan          17
        Divine Hall
            Fight Club       34
            Batman           5
Rajshahi
    Raj movies
        The Grand Raj HAll
            Gladiator        7
            Crash            34
            Gold Digger      2
        The Padma Hall
            Friday           2
            Titanic          3

```

## Commands and outputs
-----------

| Command               | Expected Output                   |  Example CMDS |
| --------              | -------                           | --------      |
| quit                  | quit the program                  |  quit         |
| multiplex             | Name of the multiplexes           |  multiplex    |
| auditorium            | Name of the auditoriums           |  auditorium   |
| movies                | Movies currently showing          |  movies       |
| movies_of_the_Hall*   | movies in a particular Hall       |
| movies_in_a_cineplex* | Movies in a particular cineplex   |
| movies_in_a_city*     | Movies in a particular city       |
| free_tickets*         | Free tickets available            |
| **anything**          | Unknown Command                   |