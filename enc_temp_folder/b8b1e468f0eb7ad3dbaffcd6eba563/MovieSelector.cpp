// MovieSelector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list> 
#include <string>
#include <iterator> 
#include<iostream>
#include<string>
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
        cout << "Title: "<< title << "\n" << "Genre" << genre << "\n";
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
};

ListOfMovies new_movie(ListOfMovies loM)
{
    std::list <std::string> loP;
    std::string title, genre, person, answer;
    std::cout << "What is the title of the movie? ";
    cin.ignore();
    getline(cin, title);
    std::cout << "What is the genre of the movie? ";
    getline(cin, genre);
    bool done = false;
    while (!done)
    {
        std::cout << "Who likes this movie? ";
        getline(cin, person);
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
    loM.show_list();
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
