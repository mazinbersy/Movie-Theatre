#include <iostream>
#include "Theatre.h"
#include "Movie.h"

using namespace std;

int main() {
    // Create Movie objects
    vector<string> times1 = { "10:00 AM", "1:00 PM", "4:00 PM" };
    Movie movie1("Movie 1", times1, 5, 10); // Example parameters for rows and columns

    vector<string> times2 = { "11:00 AM", "2:00 PM", "5:00 PM" };
    Movie movie2("Movie 2", times2, 6, 12); // Example parameters for rows and columns

    // Create a vector of Movie objects
    vector<Movie> movies = { movie1, movie2 };

    // Create a Theatre object with the vector of Movie objects
    Theatre theatre(movies);

    // Call the bookSeat function
    theatre.bookSeat();

    return 0;
}
