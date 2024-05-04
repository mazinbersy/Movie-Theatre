#include "Theatre.h"

Theatre::Theatre(vector<Movie> m)
{
	movies = m;
	constructBookingFiles();
	populateTicketQueue();
	populatesnackQueue();

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

int Theatre::getTicketCustomers()
{
	return ticketCustomers;
}

int Theatre::getSnackCustomers()
{
	return snackCustomers;
}

int Theatre::getSnackWaitingTime()
{
	return snackWaitingTime;
}

queue<int> Theatre::getTicketQueue()
{
	return ticketQueue;
}

queue<int> Theatre::getSnackQueue()
{
	return snackQueue;
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
		cout << i + 1 << ": " << movies[i].getName() << endl;
	}
	int n;

	do
	{
		cin >> n;
		if (n > movies.size() || n < 1) cout << "Invalid Input" << endl;
	} while (n > movies.size() || n < 1);
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


	cout << "Choose Time - Enter Corresponding Number: " << endl;
	for (int i = 0; i < movies[n - 1].getTimes().size(); i++)
	{
		cout << i + 1 << ": " << movies[n - 1].getTimes()[i] << endl;

	}
	int t;
	cin >> t;
	string time;
	time = movies[n - 1].getTimes()[t - 1];

	int numSeats;
	cout << "How Many Seats Would You Like to Book: " << endl;
	cin >> numSeats;


	// Construct file name
	string fileName = movies[n - 1].getName() + "_" + to_string(d) + ".txt";

	// Open file for reading and appending
	ifstream inputFile(fileName);
	ofstream outputFile(fileName, ios::app);
	if (!inputFile.is_open() || !outputFile.is_open()) {
		cout << "Error opening file " << fileName << endl;
		return;
	}

	for (int i = 0; i < numSeats; i++)
	{
		movies[n - 1].displayBookingInfo(time, d);
		string seat;
		bool seatBooked = true; // Initialize as true to enter the loop
		while (seatBooked) {
			cout << "Choose Seat to Book: ";
			cin >> seat;

			// Read file line by line
			string booking = seat + " " + time;
			string line;
			seatBooked = false; // Reset to false for each iteration
			inputFile.clear(); // Clear error flags
			inputFile.seekg(0, std::ios::beg); // Move file pointer to the beginning
			while (getline(inputFile, line)) {
				// Check if the line contains the time
				if (line == booking) {
					cout << "This seat is already booked for the selected time. Pick a different Seat" << endl;
					seatBooked = true;
					break; // Exit loop if seat is booked
				}
			}
			if (!seatBooked)
			{
				outputFile << booking << endl;
				movies[n - 1].reserveSeat(time, d, seat);
				cout << "Seat Booked Successfully!" << endl;
			}
		}
	}

	// Close input file
	inputFile.close();
	outputFile.close();
}

void Theatre::cancelReservation()
{
	cout << "Choose Movie You Wish to Cancel Reservation For - Enter Corresponding Number: " << endl;
	for (int i = 0; i < movies.size(); i++)
	{
		cout << i + 1 << ": " << movies[i].getName() << endl;
	}
	int n;

	do
	{
		cin >> n;
		if (n > movies.size() || n < 1) cout << "Invalid Input" << endl;
	} while (n > movies.size() || n < 1);
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


	cout << "Choose Time - Enter Corresponding Number: " << endl;
	for (int i = 0; i < movies[n - 1].getTimes().size(); i++)
	{
		cout << i + 1 << ": " << movies[n - 1].getTimes()[i] << endl;

	}
	int t;
	cin >> t;
	string time;
	time = movies[n - 1].getTimes()[t - 1];

	movies[n - 1].displayBookingInfo(time, d);
	string seat;
	cout << "Choose Seat to Cancel: ";
	cin >> seat;

	// Construct file name
	string fileName = movies[n - 1].getName() + "_" + to_string(d) + ".txt";

	ifstream inputFile(fileName);
	ofstream tempFile("temp.txt"); // Temporary file to store non-cancelled reservations

	if (!inputFile.is_open()) {
		cout << "Error: Unable to open file." << endl;
		return;
	}

	bool found = false;
	string line;
	while (getline(inputFile, line)) {
		// Check if the line contains the booking information
		if (line == (seat + " " + time)) {
			found = true;
			continue; // Skip this line (don't write to temp file)
		}
		// Write the line to the temporary file
		tempFile << line << endl;
	}

	inputFile.close();
	tempFile.close();

	if (found) {
		// Remove the original file
		remove(fileName.c_str());
		// Rename the temporary file to the original file name
		rename("temp.txt", fileName.c_str());
		movies[n - 1].cancelSeat(time, d, seat);
		cout << "Reservation cancelled successfully." << endl;
	}
	else {
		cout << "Reservation not found." << endl;
	}
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

void Theatre::serveTicketCustomer() {
	if (!ticketQueue.empty()) {
		int ticketServiceTime = ticketQueue.front();
		ticketQueue.pop();
		ticketWaitingTime -= ticketServiceTime;
		cout << "Serving Customer. Remaining Customers Ahead: " << ticketQueue.size()-1 << endl;
	}
	else {
		cout << "No Customers in the Queue." << endl;
	}
}

void Theatre::serveSnackCustomer() {
	if (!snackQueue.empty()) {
		int snackServiceTime = snackQueue.front();
		snackQueue.pop();
		snackWaitingTime -= snackServiceTime;
		cout << "Serving Customer. Remaining Customers Ahead: " << snackQueue.size()-1 << endl;
	}
	else {
		cout << "No Customers in the Queue." << endl;
	}
}

