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



public:
	Theatre(vector<Movie>);
	void populateTicketQueue();
	void populatesnackQueue();
	int getTicketWaitingTime();
	int getSnackWaitingTime();
	void joinTicketQueue();
	void joinSnackQueue();
	void bookSeat();
	void cancelReservation();
	void constructBookingFiles();

};

#endif