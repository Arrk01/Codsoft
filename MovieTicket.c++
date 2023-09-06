// /*Develop a program that simulates a movie ticket booking system. Allow users to view movie listings, select seats, make bookings,
// and calculate the total cost. Consider implementing seat availability and seat selection validation.
// */

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Movie   // Declare the `Movie` class.
{
private:
    string title;    // The title of the movie.
    double price;   // The price of the movie ticket.
    int seatsAvailable;// The number of seats available for the movie.

public:
    // Constructor
    Movie(const string &_title, double _price, int _seatsAvailable)
        : title(_title), price(_price), seatsAvailable(_seatsAvailable) {}

    const string &getTitle() const   // Get the title of the movie.
    {
        return title;
    }

    double getPrice() const   // Get the price of the movie ticket.
    {
        return price;
    }

    int getSeatsAvailable() const  // Get the number of seats available for the movie.
    {
        return seatsAvailable;
    }

    void bookSeats(int numSeats)  // Book a seat for the movie.
    {
        if (numSeats <= seatsAvailable)
        {
            seatsAvailable -= numSeats;
            cout << numSeats << " seat booked successfully.\n";
        }
        else
        {
            cout << "Insufficient seats available.\n";
        }
    }

    double getTotalPrice(int numSeats) const
    {
        int total;

        return price * numSeats;
    }
};

// Declare the `BookingSystem` class.
class BookingSystem
{
private:
    vector<Movie> movies;  // A list of movies.

public:
    void addMovie(const Movie &movie)  // Add a movie to the list of movies.
    {
        movies.push_back(movie);
    }

    void showMovieList() const     // Show the list of movies.
    {
        cout << "\nMovie Listings:\n";
        for (size_t i = 0; i < movies.size(); ++i)
        {
            cout << i + 1 << ". " << movies[i].getTitle()
                 << " | Price: Rs. " << movies[i].getPrice()
                 << " | Seats Available: " << movies[i].getSeatsAvailable()
                 << "\n";
            cout << "\n";
        }
    }

    void bookTickets(size_t movieIndex, int numSeats)    // Book tickets for a movie.
    {
        if (movieIndex >= 0 && movieIndex < movies.size())
        {
            double totalPrice = movies[movieIndex].getTotalPrice(numSeats);
            cout << "\nThe total price of the tickets is Rs. " << totalPrice << ".\n";
            cout << "Do you want to book the tickets (Y/N)? ";
            char choice;
            cin >> choice;
            if (choice == 'Y' || 'y')
            {
                movies[movieIndex].bookSeats(numSeats);
            }
        }
        else
        {
            cout << "Invalid movie selection.\n";
        }cout<<"\n/--------------------Thank You---------------------/";
    } 
};

// The main function.
int main()
{
    BookingSystem bookingSystem;   // Create an instance of the `BookingSystem` class.
    
     // Add some movies to the list of movies.
    bookingSystem.addMovie(Movie("OMG-2", 250, 60));
    bookingSystem.addMovie(Movie("Oppenheimer", 300, 70));
    bookingSystem.addMovie(Movie("Barbie", 300, 50));

    int choice;
    cout << "\n//---------MOVIE TICKET BOOKING SYSTEM----------// \n";
    do
    {

        cout << "\n\n1. Show Movie List\n";
        cout << "2. Book Tickets\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bookingSystem.showMovieList();  // Show the list of movies.
            break;
        case 2:
        {
            size_t movieIndex;
            int numSeats;
            cout << "Enter movie number: ";
            cin >> movieIndex;
            cout << "Enter number of seats to book: ";
            cin >> numSeats;
            bookingSystem.bookTickets(movieIndex - 1, numSeats);
            break;
        }
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
            break;
        }
    } while (choice != 3);
    return 0;
}


//