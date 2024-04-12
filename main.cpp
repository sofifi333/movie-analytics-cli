#include<iostream>
#include<iomanip> //use for setprecision
#include<string>
#include<fstream>
#include<vector>
#include <cctype>

using namespace std;
//makes a string all lowercase
string tolower();

string tolower(string word) {

    string fixedWord = word;
    int i = 0;

    //goes letter by letter in word
    for (char letter : word) {
        //if the character is in the alphabet make it lowercase if not keep it
        if (isalpha(letter))
            fixedWord[i] = tolower(letter);
        i++;
    }

    return fixedWord;
}

class movieInfo {
public:

    //enum is created to limit users input for rating
    enum Rating {
        PG, PG13, R
    };

    //objects --storing all information in one place
    //struct info stores all movie information/variables
    struct Info {
        Rating rating;
        int runtime;
        int year;
        string director;
        long long budget;
        long long boxOfficeRevenue;
    };


    //default constructor
    movieInfo() {}
    //constructor initializes all variables to provided name, genre, & info
    movieInfo(string name, string genre, Info info) {
        this->name = name;
        this->genre = genre;
        this->info = info;
    }


    //getters
    string getRating();

    string getName();
    string getGenre();
    int getRuntime();
    int getYear();
    string getDirector();
    long long getBudget();
    long long getBoxOfficeRevenue();

    //setters
    void setRating(string rating);
    void setName(string name);
    void setGenre(string genre);
    void setRuntime(int runtime);
    void setYear(int year);
    void setDirector(string director);
    void setBudget(long long budget);
    void setBoxOfficeRevenue(long long boxOfficeRevenue);


private:
    //main variables
    string name;
    string genre;
    Info info;
};

//a method of the "Movie" class. A function getRating() is created using members of the movie class...class function
//it returns strings to the output when



//All getters
string movieInfo::getName() { return this->name; }
string movieInfo::getGenre() { return this->genre; }
int movieInfo::getRuntime() { return this->info.runtime; }
int movieInfo::getYear() { return this->info.year; }
string movieInfo::getDirector() { return this->info.director; }
long long movieInfo::getBudget() { return this->info.budget; }
long long movieInfo::getBoxOfficeRevenue() { return this->info.boxOfficeRevenue; }

string movieInfo::getRating() {
    switch (info.rating) {
    case Rating::PG:
        return "PG";
    case Rating::PG13:
        return "PG-13";
    case Rating::R:
        return "R";
    default:
        return "unknown";
    }
}

//All setters -> you can change the values of the private variables using these functions
void movieInfo::setName(string name) { this->name = name; }
void movieInfo::setGenre(string genre) { this->genre = genre; }
void movieInfo::setRuntime(int runtime) { this->info.runtime = runtime; }
void movieInfo::setYear(int year) { this->info.year = year; }
void movieInfo::setDirector(string director) { this->info.director = director; }
void movieInfo::setBudget(long long budget) { this->info.budget = budget; }
void movieInfo::setBoxOfficeRevenue(long long boxOfficRevenue) { this->info.boxOfficeRevenue = boxOfficRevenue; }

void movieInfo::setRating(string rating) {

    bool correct = false;

    rating = tolower(rating);

    while (!correct) {
        if (rating == "pg" || "PG") {
            info.rating = Rating::PG;
            correct = true;
        }
        else if (rating == "pg-13" || rating == "pg13" || rating == "PG13" || rating == "PG-13") {
            info.rating = Rating::PG13;
            correct = true;
        }
        else if (rating == "r" || "R") {
            info.rating = Rating::R;
            correct = true;
        }
        else {
            cout << "Please enter a valid rating" << endl;
            cin >> rating;
            rating = tolower(rating);
        }
    }

}


class Movies {

public:

    //we define the vector here, bc the funcitons UMI and INM need to be able to access the vector and info inside it
    vector<movieInfo> moviesList;

    void extractText();
    void printMovies();
    void printSpecificMovie(string name);
    void printSpecificGenre(string genre);
    //functions umi and inm are of vector movies
    void updateMovieInfo(string name);
   
    void exportMovie();

};



void Movies::printSpecificMovie(string name) {

    bool inVector = false;

    //makes names dummy proof and gives proper grammar
    name[0] = toupper(name[0]);

    for (int i = 1; i < name.length(); i++) {

        // checks if character is in alphabet and if is makes it lowercase
        if (isalpha(name[i]))
            name[i] = tolower(name[i]);
    }



    for (movieInfo movie : moviesList) {
        //if the name is ever the same you print it
        if (name == movie.getName()) {
            cout << "\nMovie: " << movie.getName() << ", Released in: " << movie.getYear() << ", Genre: " << movie.getGenre() << ", runtime: " << movie.getRuntime() << ", director " << movie.getDirector() << ", budget: " << movie.getBudget() << ", Made " << movie.getBoxOfficeRevenue() << " in box office." << endl << endl;

            inVector = true;
        }

    }

    if (!inVector)
        cout << "Not a movie in list!" << endl;



}




void Movies::printMovies() {

    int count = 1;



    for (movieInfo movie : moviesList) {

        cout << count << ". Movie: " << movie.getName() << ",Rating: " << movie.getRating() << ", Released in: " << movie.getYear() << ", Genre: " << movie.getGenre() << ", runtime: " << movie.getRuntime() << ", director " << movie.getDirector() << ", budget: " << movie.getBudget() << ", Made " << movie.getBoxOfficeRevenue() << " in box office." << endl << endl;

        count++;
    }


}

void Movies::printSpecificGenre(string genre) {

    bool inVector = false;
    int count = 1;

    for (movieInfo movie : moviesList) {
        //if the name is ever the same you print it
        if (tolower(genre) == tolower(movie.getGenre())) {

            cout << endl << count << ". " << " Movie: " << movie.getName() << ", Rating: " << movie.getRating() << ", Released in: " << movie.getYear() << ", Genre: " << movie.getGenre() << ", runtime: " << movie.getRuntime() << "minutes, director " << movie.getDirector() << ", budget: " << movie.getBudget() << ", Made " << movie.getBoxOfficeRevenue() << " in box office." << endl << endl;

            inVector = true;
            count++;
        }

    }

    if (!inVector)
        cout << "No genre with that name in list" << endl;



}


//export function to new text file
void Movies::exportMovie() {

    //print the vector out to the file -- vector holds all updated and old movie info and names



}

void Movies::updateMovieInfo(string name) {

    bool inVector = false;

    //to handle the 4 potential data types
    char update;
    string update2;
    int update3;
    long long update4;


    for (movieInfo& movie : moviesList) {


        if (tolower(name) == tolower(movie.getName())) {

            cout << "Would you like to change the name?(y/n)" << endl;
            cin >> update;
            update = tolower(update);

            if (update == 'y') {
                cout << "Input new name: ";
                cin >> update2;
                movie.setName(update2);

            }

            cout << "what about the year?(y/n)" << endl;

            cin >> update;
            update = tolower(update);

            if (update == 'y') {
                cout << "Input new year: ";
                cin >> update3;
                movie.setYear(update3);
            }

            cout << "genre?(y/n)" << endl;

            cin >> update;
            update = tolower(update);

            if (update == 'y') {
                cout << "Input new genre: ";
                cin >> update2;
                movie.setGenre(update2);
            }

            cout << "runtime?(y/n)" << endl;

            cin >> update;
            update = tolower(update);

            if (update == 'y') {
                cout << "Input new runtime: ";
                cin >> update3;
                movie.setRuntime(update3);
            }

            cout << "director?(y/n)" << endl;

            cin >> update;
            update = tolower(update);

            if (update == 'y') {
                cout << "Input new director: ";
                cin >> update2;
                movie.setDirector(update2);
            }

            cout << "budget?(y/n)" << endl;

            cin >> update;
            update = tolower(update);

            if (update == 'y') {
                cout << "Input new budget: ";
                cin >> update4;
                movie.setBudget(update4);
            }

            cout << "box office revenue?(y/n)" << endl;

            cin >> update;
            update = tolower(update);

            if (update == 'y') {
                cout << "Input new revenue: ";
                cin >> update4;
                movie.setBoxOfficeRevenue(update4);
            }





            inVector = true;
        }


    }

    if (!inVector)
        cout << "No movie with that name in list" << endl;

}



//read all info from file as a member function, so the Movie members are initialized

void Movies::extractText() {
    ifstream inFile("movieInfo.txt"); // Open the file

    if (!inFile.is_open()) { // Check if file is successfully opened
        cout << "Error opening file!" << endl;
        return;
    }

    while (!inFile.eof()) {
        // Read from file into temporary variables
        string name, genre, director, ratingStr;
        int year, runtime;
        long long budget, boxOfficeRevenue;

        inFile >> name >> year >> genre >> ratingStr >> runtime >> director >> budget >> boxOfficeRevenue;

        // Convert rating string to enum
        movieInfo::Rating rating;
        if (ratingStr == "PG") {
            rating = movieInfo::PG;
        }
        else if (ratingStr == "PG13") {
            rating = movieInfo::PG13;
        }
        else if (ratingStr == "R") {
            rating = movieInfo::R;
        }
        else {
            // Handle invalid rating string
            cout << "Unknown " << ratingStr << endl;
            continue; // Skips iteration and moves on to next line of file
        }

        // Create a new Info object with the extracted information
        movieInfo::Info movieData = {
            rating,               // rating
            runtime,              // runtime
            year,                 // year
            director,             // director
            budget,               // budget
            boxOfficeRevenue      // box office revenue
        };

        //Makes a new object of movieInfo to push into movieList
        movieInfo myMovie(name, genre, movieData);

        //puts it into the vector
        moviesList.push_back(myMovie);
    }

    inFile.close(); // Close the file
}
class MenuUtils {
public:
    int convertCommand(string command);
    void printMenu();
    void printAll(Movies list);
    void printOne(Movies list);
    void printGenre(Movies list);
    //need to pass this one by reference
    void updateMovie(Movies& list);
    void insertNewMovie(Movies& list);
    void outputFile(Movies list);
};

int MenuUtils::convertCommand(string command) {
    if (command == "help") return 1;
    else if (command == "pam") return 2;
    else if (command == "mi") return 3;
    else if (command == "pgi") return 4;
    else if (command == "umi") return 5;
    else if (command == "inm") return 6;
    else if (command == "e") return 7;
    else if (command == "exit") return 8;
    else return 0;
}

void MenuUtils::printMenu() {
    cout << "\nSelect from the following commands:\n\n\t\thelp\tDisplays all command options.\n\t\tpam\t\tPrints all movie names and info."
        << "\n\t\tmi\t\tPrints out movie and info.\n\t\tpgi\t\tPrints genre info.\n\t\tumi\t\tUpdates movie info.\n\t\tinm\t\t" <<
        "Inserts new movie.\n\t\te\t\tExport File.\n\t\texit\tExits movie buff\n" << endl;
}

void MenuUtils::printAll(Movies list) {
    list.printMovies();
}

void MenuUtils::printOne(Movies list) {
    string inputtedName;
    cout << "What movie are you searching for? ";
    getline(cin, inputtedName);
    list.printSpecificMovie(inputtedName);
}

void MenuUtils::printGenre(Movies list) {
    string inputtedGenre;
    cout << "What genre are you looking for? ";
    getline(cin, inputtedGenre);
    list.printSpecificGenre(inputtedGenre);
}

void MenuUtils::updateMovie(Movies& list) {
    string inputtedName;
    cout << "What movie are you looking to update? ";
    getline(cin, inputtedName);
    list.updateMovieInfo(inputtedName);
}

void MenuUtils::insertNewMovie(Movies& list) {

    movieInfo::Rating rating;
    string name, genre, director, ratingStr;
    int year, runtime;
    long long budget, boxOfficeRevenue;

    cout << "What is the name of your movie? ";
    getline(cin,name);

    cout << "year? ";
    cin >> year;

    cout << "genre? ";
    cin >> genre;

    cout << "rating? ";
    cin >> ratingStr;
    ratingStr = tolower(ratingStr);

    if (ratingStr == "pg") {
        rating = movieInfo::PG;
    }
    else if (ratingStr == "pg13" || ratingStr == "pg-13") {
        rating = movieInfo::PG13;
    }
    else if (ratingStr == "r") {
        rating = movieInfo::R;
    }

    cout << "runtime? ";
    cin >> runtime;
    cout << "director? ";
    cin >> director;
    cout << "budget? ";
    cin >> budget;
    cout << "earned in box office? ";
    cin >> boxOfficeRevenue;

    movieInfo::Info movieData = {
        rating,               // rating
        runtime,              // runtime
        year,                 // year
        director,             // director
        budget,               // budget
        boxOfficeRevenue      // box office revenue
    };

    //Makes a new object of movieInfo to push into movieList
    movieInfo myMovie(name, genre, movieData);


    list.moviesList.push_back(myMovie);

}

void MenuUtils::outputFile(Movies list) {

    cout << "Exporting to file..." << endl;

    ofstream fout;

    fout.open("output.txt", ios::out);

    if (fout.is_open()) {

        int count = 1;

        for (movieInfo movie : list.moviesList) {

            fout << count << ". Movie: " << movie.getName() <<", Rating: "<<movie.getRating()<< ", Released in: " << movie.getYear() << ", Genre: " << movie.getGenre() << ", runtime: " << movie.getRuntime() << ", director " << movie.getDirector() << ", budget: " << movie.getBudget() << ", Made " << movie.getBoxOfficeRevenue() << " in box office." << endl << endl;

            count++;
        }

        fout.close();
    }
    else {
        cerr << "Unable to open file" << endl;
    }
}




int main() {


    // here...  u can say welcome to movie buff blajh blah blah enter menu to see the menu opptions
    //be descro\iptive say pam =  print all movires etc...
    cout << "---------------------------------------------------------" << endl << endl;
    cout << "\t\tWelcome to movie buff!" << endl << endl;
    cout << "---------------------------------------------------------" << endl;

    //AN object of Movies class (pretty much the vector that allows u to access the vector itself)
    // initialize the constructor Movies & vector of movies and member functions

    Movies myList;
    myList.extractText();


    string command;
    MenuUtils menu;

    menu.printMenu();

    while (true) {
        cout << "<moviebuff> ";
        getline(cin, command);
        int commandS = menu.convertCommand(command);



        switch (commandS) {
        case 1:
            menu.printMenu();
            break;
        case 2:
            menu.printAll(myList);
            break;
        case 3:
            menu.printOne(myList);
            break;
        case 4:
            menu.printGenre(myList);
            break;
        case 5:
            menu.updateMovie(myList);
            break;
        case 6:
            menu.insertNewMovie(myList);
            break;
        case 7:
            menu.outputFile(myList);
            break;
        case 8:
            return 0;
        }

    }

    return 0;
}
