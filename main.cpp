#include <iostream>
#include "Theatre.h"
#include "Movie.h"
#include <chrono> 
#include <thread> 

using namespace std;


int main()
{
	// Create Movie objects
	vector<string> times1 = { "10:00AM", "1:00PM", "4:00PM" };
	Movie movie1("Movie 1", times1, 5, 10); // Example parameters for rows and columns

	vector<string> times2 = { "11:00AM", "2:00PM", "5:00PM" };
	Movie movie2("Movie 2", times2, 6, 12); // Example parameters for rows and columns

	vector<string> times3 = { "2:30PM", "7:00PM", "10:15PM" };
	Movie movie3("Movie 3", times3, 6, 12); // Example parameters for rows and columns

	vector<string> times4 = { "1:00PM", "6:10PM", "12:00AM" };
	Movie movie4("Movie 4", times2, 8, 12); // Example parameters for rows and columns

	// Create a vector of Movie objects
	vector<Movie> movies = { movie1, movie2, movie3, movie4 };

	// Create a Theatre object with the vector of Movie objects
	Theatre theatre(movies);
	
	
	int ticketORsnack, cancel;
	cout << "                                          WELCOME TO OUR MOVIE THEATRE!" << endl<<endl;
	cout << "To Enter the Ticket Queue Enter 0 - To Enter the Snack Queue Enter 1: ";
	do
	{
		cin >> ticketORsnack;
		if (ticketORsnack != 0 && ticketORsnack != 1) cout << "Invalid Input: Try Again." << endl;
	}
	while (ticketORsnack != 0 && ticketORsnack != 1);

	cout << endl;
	if (ticketORsnack == 1)
	{
		theatre.joinTicketQueue();
		cout << "There are " << theatre.getTicketCustomers() << " Waiting Ahead of You in Line - Approximate Waiting Time: " << theatre.getTicketWaitingTime() << " Minutes." << endl;

		cout << "Serving Customers:" << endl;
		// Simulate serving ticket customers until you are the only person left in the ticket queue
		while (theatre.getTicketQueue().size() > 1) {
			theatre.serveTicketCustomer();
			// Adds a time delay between serving customers
			//Sped up for the sake of the simulation, to not wait many minutes to serve a single customer
			this_thread::sleep_for(chrono::seconds(3));
		}
		cout << endl << endl;
		theatre.bookSeat();
		cout << endl << endl;
		cout << "Would You Like to Cancel a Reservation: Enter 0 for NO or Enter 1 for YES: ";
		do
		{
			cin >> cancel;
			if (cancel != 0 && cancel != 1) cout << "Invalid Input: Try Again." << endl;
		} while (cancel != 0 && cancel != 1);

		if (cancel == 1)
			theatre.cancelReservation();
		
		cout << endl << endl;

		cout << "Do You Want To Enter Snack Queue: Enter 0 for NO or Enter 1 for YES: ";
		do
		{
			cin >> ticketORsnack;
			if (ticketORsnack != 0 && ticketORsnack != 1) cout << "Invalid Input: Try Again." << endl;
		} while (ticketORsnack != 0 && ticketORsnack != 1);

	}



	if (ticketORsnack == 1)
	{
		theatre.joinSnackQueue();
		cout << "There are " << theatre.getSnackCustomers() << " Waiting Ahead of You in Line - Approximate Waiting Time: " << theatre.getSnackWaitingTime() << " Minutes." << endl;
		// Simulate serving snack customers until you are the only person left in the snack queue
		while (theatre.getSnackQueue().size() > 1) {
			theatre.serveSnackCustomer();
			// Adds a time delay between serving customers
			//Sped up for the sake of the simulation, to not wait many minutes to serve a single customer
			this_thread::sleep_for(chrono::seconds(3));
		}

		cout << "It's Your Turn, Go Ahead and Order and Enjoy Your Movie!" << endl;
	}

	cout << endl << endl;
	cout << "                              THANK YOU FOR CHOOSING OUR MOVIE THEATRE!" << endl;


	return 0;
}
