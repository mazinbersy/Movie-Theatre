#include "Theatre.h"

Theatre::Theatre(vector<Movie> m)
{
	movies = m;
	constructBookingFiles();

}

void Theatre::populateTicketQueue()
{
	srand(time(NULL));
	ticketCustomers = rand() % 10;
	for (int i = 0; i < ticketCustomers; i++)
	{
		int service = rand() % 5 + 1;
		ticketQueue.push(service);
		ticketWaitingTime += service;
	}
}

void Theatre::populatesnackQueue()
{
	srand(time(NULL));
	snackCustomers = rand() % 10;
	for (int i = 0; i < snackCustomers; i++)
	{
		int service = rand() % 5 + 1;
		snackQueue.push(service);
		snackWaitingTime += service;
	}
}

int Theatre::getTicketWaitingTime()
{
	return ticketWaitingTime;
}

int Theatre::getSnackWaitingTime()
{
	return snackWaitingTime;
}

void Theatre::joinTicketQueue()
{
	ticketQueue.push(0); //No waiting time applies to customer standing in this position
}

void Theatre::joinSnackQueue()
{
	snackQueue.push(0); //No waiting time applies to customer standing in this position
}

void Theatre::bookSeat()
{
	cout << "Choose Movie You Wish to Book - Enter Corresponding Number: " << endl;
	for (int i = 0; i < movies.size(); i++)
	{
		cout << i + 1 << ": " << movies[i].getName()<<endl;
	}
	int n;
	
	do
	{
		cin >> n;
		if (n > movies.size() || n < 1) cout << "Invalid Input" << endl;
	}
		while (n > movies.size() || n < 1); 
	cout << "Choose Day - Enter Corresponding Number: " << endl;
	cout << "1: Sunday" << endl;
	cout << "2: Monday" << endl;
	cout << "3: Tuesday" << endl;
	cout << "4: Wednesday" << endl;
	cout << "5: Thursday" << endl;
	cout << "6: Friday" << endl;
	cout << "7: Saturday" << endl;

	int d;
	cin >> d;
	cout << "Number of movies: " << movies.size() << endl;
	cout << "Value of n: " << n << endl;


	cout << "Choose Time - Enter Corresponding Number: " << endl;
	for (int i = 0; i < movies[n - 1].getTimes().size(); i++)
	{
		cout << i + 1 << ": " << movies[n-1].getTimes()[i]<<endl;

	}
	int t;
	cin >> t;
	string time;
	time = movies[n - 1].getTimes()[t - 1];


	movies[n - 1].displayBookingInfo(time, d);
	string seat;
	cout << "Choose Seat to Book: ";		
	cin >> seat;

	// Construct file name
	string fileName = movies[n - 1].getName() + "_" + to_string(d) + ".txt";

	// Open file for reading and appending
	ifstream inputFile(fileName);
	ofstream outputFile(fileName, ios::app);
	if (!inputFile.is_open() || !outputFile.is_open()) {
		cout << "Error opening file " << fileName << endl;
		return;
	}

	// Read file line by line
	string booking = seat + " " + time;
	string line;
	bool seatBooked = false;
	while (getline(inputFile, line)) {
		// Check if the line contains the time
		if (line == booking) {
			cout << "This seat is already booked for the selected time." << endl;
			seatBooked = true;
			return;
		}
	}
	if (!seatBooked)
	{
		outputFile << booking << endl;
		movies[n - 1].reserveSeat(time, d, seat);
	}

	// Close input file
	inputFile.close();
	outputFile.close();
	
}

void Theatre::cancelReservation()
{
}

void Theatre::constructBookingFiles() {
	for (int i = 0; i < movies.size(); i++) {
		string movieName = movies[i].getName();
		for (int day = 1; day <= 7; day++) {
			string fileName = movieName + "_" + to_string(day) + ".txt";
			ofstream outputFile(fileName, ios::app);
			if (!outputFile.is_open()) {
				cout << "Error creating file " << fileName << endl;
			}
		}
	}
}

