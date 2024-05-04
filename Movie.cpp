#include "Movie.h"

Movie::Movie(string n, int r, int c)
{
	name = n;
    rows = r;
    columns = c;
}

Movie::Movie(string n, vector<string> x, int r, int c)
{
    name = n;
    rows = r;
    columns = c;
    times = x;
    // Initialize booked vector with size rows and each row having columns
    vector<vector<bool>> booked(rows, vector<bool>(columns, false));

    // Initialize booking maps for each day with the booked vector
    for (int i = 0; i < x.size(); i++)
    {
        sundayBooking[x[i]] = booked;
        mondayBooking[x[i]] = booked;
        tuesdayBooking[x[i]] = booked;
        wednesdayBooking[x[i]] = booked;
        thursdayBooking[x[i]] = booked;
        fridayBooking[x[i]] = booked;
        saturdayBooking[x[i]] = booked;
    }
    updateBookingInfo();
}


string Movie::getName()
{
	return name;
}

vector<string> Movie::getTimes()
{
	return times;
}

void Movie::displayBookingInfo(string time, int day) {
    // Get the corresponding booking map based on the day
    unordered_map<string, vector<vector<bool>>>* bookingMap;
    switch (day) {
    case 1: bookingMap = &sundayBooking; break;
    case 2: bookingMap = &mondayBooking; break;
    case 3: bookingMap = &tuesdayBooking; break;
    case 4: bookingMap = &wednesdayBooking; break;
    case 5: bookingMap = &thursdayBooking; break;
    case 6: bookingMap = &fridayBooking; break;
    case 7: bookingMap = &saturdayBooking; break;
    default:
        cout << "Invalid day." << endl;
        return;
    }

    // Get the booking status for the given time
    vector<vector<bool>>& bookings = (*bookingMap)[time];

    // Display the booking status
    string dayString;
    switch (day) {
    case 1: dayString = "Sunday"; break;
    case 2: dayString = "Monday"; break;
    case 3: dayString = "Tuesday"; break;
    case 4: dayString = "Wednesday"; break;
    case 5: dayString = "Thursday"; break;
    case 6: dayString = "Friday"; break;
    case 7: dayString = "Saturday"; break;
    }
    cout << "Booking status for " << dayString << " at time " << time << ":" << endl;
    
    cout << "---------------------------------------" << endl << "              SCREEN" << endl;
    cout << "   ";
    for (int i = 0; i < columns; i++)
    {
        cout <<i + 1 << "  ";
    }
    cout << endl;

    char row = 'A';
    for (int i = 0; i < rows; ++i) {
        cout << row++ << " ";
        for (int j = 0; j < columns; ++j) {
            cout << (bookings[i][j] ? " X" : " #") << " "; // Use '#' for empty chair
        }
        cout << endl;
    }
}

unordered_map<string, vector<vector<bool>>> Movie::getSundayBooking()
{
    return sundayBooking;
}

unordered_map<string, vector<vector<bool>>> Movie::getMondayBooking()
{
    return mondayBooking;
}

unordered_map<string, vector<vector<bool>>> Movie::getTuesdayBooking()
{
    return tuesdayBooking;
}

unordered_map<string, vector<vector<bool>>> Movie::getWednesdayBooking()
{
    return wednesdayBooking;
}

unordered_map<string, vector<vector<bool>>> Movie::getThursdayBooking()
{
    return thursdayBooking;
}

unordered_map<string, vector<vector<bool>>> Movie::getFridayBooking()
{
    return fridayBooking;
}

unordered_map<string, vector<vector<bool>>> Movie::getSaturdayBooking()
{
    return saturdayBooking;
}

int Movie::getRows()
{
    return rows;
}

int Movie::getCols()
{
    return columns;
}

void Movie::updateBookingInfo() {
    for (int i = 1; i <= 7; i++) {
        string fileName = name + "_" + to_string(i) + ".txt";

        // Open file for reading
        ifstream inputFile(fileName);
        if (!inputFile.is_open()) {
            continue; // Skip to the next day if file cannot be opened
        }

        // Read file line by line
        string line;
        while (getline(inputFile, line) && !inputFile.eof()) {
            // Extract seat and time information from the line
            istringstream iss(line);
            string seat, time;
            if (!(iss >> seat >> time)) {
                cout << "Invalid line format in file " << fileName << ": " << line << endl;
                continue; // Skip to the next line if the line format is invalid
            }

            int row = seat[0] - 'A';
            string substr = seat.substr(1);
            int col = stoi(substr)-1;

            // Update the corresponding booking map based on the day
            switch (i) {
            case 1:  sundayBooking[time][row][col] = true; break;
            case 2:  mondayBooking[time][row][col] = true; break;
            case 3:  tuesdayBooking[time][row][col] = true; break;
            case 4:  wednesdayBooking[time][row][col] = true; break;
            case 5:  thursdayBooking[time][row][col] = true; break;
            case 6: fridayBooking[time][row][col] = true; break;
            case 7:  saturdayBooking[time][row][col] = true; break;
            }
        }
       
        // Close the input file
        inputFile.close();
    }
}


bool Movie::isBooked(string t, int date, string seat)
{
    int row = seat[0] - 'A';
    string substr = seat.substr(1);
    int col = stoi(substr);
    switch (date)
    {
    case 1: return sundayBooking[t][row][col];
    case 2: return mondayBooking[t][row][col];
    case 3: return tuesdayBooking[t][row][col];
    case 4: return wednesdayBooking[t][row][col];
    case 5: return thursdayBooking[t][row][col];
    case 6:return fridayBooking[t][row][col];
    case 7: return saturdayBooking[t][row][col];
    }
}

void Movie::reserveSeat(string t, int d, string seat)
{
    int row = seat[0] - 'A';
    string substr = seat.substr(1);
    int col = stoi(substr) -1;
    switch(d)
    {
    case 1: sundayBooking[t][row][col] = true; break;
    case 2:mondayBooking[t][row][col] = true; break;
    case 3:tuesdayBooking[t][row][col] = true; break;
    case 4:wednesdayBooking[t][row][col] = true; break;
    case 5:thursdayBooking[t][row][col] = true; break;
    case 6:fridayBooking[t][row][col] = true; break;
    case 7:saturdayBooking[t][row][col] = true; break;
    }
}

void Movie::cancelSeat(string t, int d, string seat)
{
    int row = seat[0] - 'A';
    string substr = seat.substr(1);
    int col = stoi(substr) - 1;
    switch (d)
    {
    case 1: sundayBooking[t][row][col] = false; break;
    case 2:mondayBooking[t][row][col] = false; break;
    case 3:tuesdayBooking[t][row][col] = false; break;
    case 4:wednesdayBooking[t][row][col] = false; break;
    case 5:thursdayBooking[t][row][col] = false; break;
    case 6:fridayBooking[t][row][col] = false; break;
    case 7:saturdayBooking[t][row][col] = false; break;
    }
}
void Movie::setBooking(string day, string time, vector<vector<bool>> bookings) {
    // Set the booking information for the specified day and time
    if (day == "Sunday") sundayBooking[time] = bookings;
    else if (day == "Monday") mondayBooking[time] = bookings;
    else if (day == "Tuesday") tuesdayBooking[time] = bookings;
    else if (day == "Wednesday") wednesdayBooking[time] = bookings;
    else if (day == "Thursday") thursdayBooking[time] = bookings;
    else if (day == "Friday") fridayBooking[time] = bookings;
    else if (day == "Saturday") saturdayBooking[time] = bookings;
    else cout << "Invalid day." << endl;
}

Movie::~Movie()
{
}
