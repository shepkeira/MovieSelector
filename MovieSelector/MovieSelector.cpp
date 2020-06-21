// MovieSelector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list> 
#include <string>
#include <iterator> 
#include<iostream>
#include<string>
#include <algorithm>
using namespace std;

class Movie {
    std::string title, genre;
    std::list <std::string> people;
public:
    void set_values(std::string t, std::string g, std::list <std::string> loP)
    {
        title = t;
        genre = g;
        people = loP;
    }
    void print()
    {
        cout << "Title: "<< title << "\n" << "Genre: " << genre << "\n";
    }
    string get_genre()
    {
        return genre;
    }
    list <string> get_people()
    {
        return people;
    }
};

void print_list(list <Movie> loM)
{
    list <Movie> ::iterator it;
    for (it = loM.begin(); it != loM.end(); ++it)
    {
        Movie m = *it;
        m.print();
    }
    cout << '\n';
};

class ListOfMovies {
    std::list <Movie> loM;
public:
    ListOfMovies() = default;
    void add_movie(Movie m)
    {
        list <Movie> ::iterator it = loM.end();
        loM.insert(it, m);
    }
    void add_movie(string title, string genre, list <string> loP)
    {
        Movie m;
        m.set_values(title, genre, loP);
        list <Movie> ::iterator it = loM.end();
        loM.insert(it, m);
    }
    void show_list()
    {
        print_list(loM);
    }
    void show_list(string genre) {
        std::list <Movie> loM_genre;

        list <Movie> ::iterator it;
        list <Movie> ::iterator it_genre = loM_genre.end();
        for (it = loM.begin();
            it != loM.end();
            it++)
        {
            Movie m = *it;
            if (m.get_genre() == genre) {
                loM_genre.insert(it_genre, m);
            }
        }
        cout << "\n";
        print_list(loM_genre);
    }
    void show_list(list <string> loP_watching) {
        std::list <Movie> loM_P;
        list <string> people_who_like_movie;

        list <Movie> ::iterator it_loM;
        list <Movie> ::iterator it_people = loM_P.end();
        for (it_loM = loM.begin();
            it_loM != loM.end();
            it_loM++)
        {
            Movie m = *it_loM;
            bool peeps = true;
            people_who_like_movie = m.get_people();
            list <string> ::iterator it_loP; //= loP_watching.begin();
            for (it_loP = loP_watching.begin(); it_loP != loP_watching.end(); it_loP++) {
                list <string>::iterator it_str;
                string person = *it_loP;
                it_str = std::find(people_who_like_movie.begin(), people_who_like_movie.end(), person);

                if (it_str != people_who_like_movie.end()) {
                    peeps = peeps;
                }
                else {
                    peeps = false;
                }
            }

            if (peeps) {
                loM_P.insert(it_people, m);
            }
        }
        cout << "\n";
        print_list(loM_P);
    }
};

ListOfMovies new_movie(ListOfMovies loM)
{
    std::list <std::string> loP;
    std::string title, genre, person, answer;
    person = "";
    std::cout << "What is the title of the movie? ";
    cin.ignore();
    getline(cin, title);
    std::cout << "What is the genre of the movie? ";
    getline(cin, genre);
    bool done = false;
    while (!done)
    {
        //cin.get();
        std::cout << "Who likes this movie? ";
        //getchar(cin, letter);
        getline(cin >> ws, person);
        loP.push_back(person);
        std::cout << "More people? (Y/N) ";
        std::cin >> answer;
        if (answer == "N") {
            done = true;
        }
    }
    Movie m;
    m.set_values(title, genre, loP);

    loM.add_movie(m);
    //loM.add_movie(title, genre, loP);
    return loM;
}

void pick_movie(ListOfMovies loM)
{
    //loM.show_list();
    int num;
    std::cout << "How are you picking your movie?\n";
    std::cout << "1 - By Genre\n";
    std::cout << "2 - By Who is Watching\n";
    std::cin >> num;

    if (num == 1) {
        string genre;
        std::cout << "What genre are you picking? ";
        std::cin >> genre;
        loM.show_list(genre);
    }
    else if (num == 2) {
        std::list <string> loP;
        std::string person;
        std::string answer;
        bool done = false;
        std::list <string> loP_watching;
        while (!done)
        {
            std::string person;
            std::string answer;
            std::cout << "Who is watching? ";
            getchar();
            getline(cin, person);
            loP_watching.push_back(person);
            std::cout << "More people? (Y/N) \n";
            std::cin >> answer;
            if (answer == "N") {
                done = true;
            }
        }
        loM.show_list(loP_watching);
    }
    else {
        system("CLS");
        std::cout << "I don't know that command please try again\n\n";
    }
}

int main()
{
    bool done = false;
    ListOfMovies loM;
    loM = ListOfMovies();
    while (!done)
    {
        int num;
        std::cout << "What do you want to do?\n";
        std::cout << "1 - Add a new movie\n";
        std::cout << "2 - pick a movie\n";
        std::cin >> num;

        if (num == 1) {
            loM = new_movie(loM);
        }
        else if (num == 2) {
            pick_movie(loM);
        }
        else
        {
            system("CLS");
            std::cout << "I don't know that command please try again\n\n";
        }
    }
    
    
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
