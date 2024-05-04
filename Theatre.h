#ifndef Theatre_H
#define Theatre_H


#include <iostream>
#include <queue>
#include <cstdlib>
#include "Movie.h"
#include <fstream>
using namespace std;

class Theatre
{
private:
	int ticketWaitingTime;
	int snackWaitingTime;
	int ticketCustomers;
	int snackCustomers;
	queue<int> ticketQueue;
	queue<int> snackQueue;
	vector<Movie> movies;

	void randomize_seed()
	{
		unsigned int seed = static_cast<unsigned int>(time(nullptr));
		srand(seed);
	}


public:
	Theatre(vector<Movie>);
	void populateTicketQueue();
	void populatesnackQueue();
	int getTicketWaitingTime();
	int getTicketCustomers();
	int getSnackCustomers();
	int getSnackWaitingTime();
	queue<int> getTicketQueue();
	queue<int> getSnackQueue();
	void joinTicketQueue();
	void joinSnackQueue();
	void bookSeat();
	void cancelReservation();
	void constructBookingFiles();
	void serveTicketCustomer();
	void serveSnackCustomer();



};

#endif