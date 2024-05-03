#ifndef Movie_H
#define Movie_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;



class Movie
{
private:

	int rows; //Number of rows in viewing hall
	int columns; //Number of columns in viewing hall
	string name;
	vector<string> times;
	unordered_map<string, vector<vector<bool>>> sundayBooking;
	unordered_map<string, vector<vector<bool>>> mondayBooking;
	unordered_map<string, vector<vector<bool>>> tuesdayBooking;
	unordered_map<string, vector<vector<bool>>> wednesdayBooking;
	unordered_map<string, vector<vector<bool>>> thursdayBooking;
	unordered_map<string, vector<vector<bool>>> fridayBooking;
	unordered_map<string, vector<vector<bool>>> saturdayBooking;






public:
	Movie(string, int , int);
	Movie(string, vector<string>, int , int);
	string getName();
	vector<string> getTimes();
	void displayBookingInfo(string, int);
	unordered_map<string, vector<vector<bool>>> getSundayBooking();
	unordered_map<string, vector<vector<bool>>> getMondayBooking();
	unordered_map<string, vector<vector<bool>>> getTuesdayBooking();
	unordered_map<string, vector<vector<bool>>> getWednesdayBooking();
	unordered_map<string, vector<vector<bool>>> getThursdayBooking();
	unordered_map<string, vector<vector<bool>>> getFridayBooking();
	unordered_map<string, vector<vector<bool>>> getSaturdayBooking();
	void setBooking(string day, string time, vector<vector<bool>> bookings);
	int getRows();
	int getCols();
	void updateBookingInfo();
	void reserveSeat(string, int, string);
	bool isBooked(string,int, string);
	~Movie();

};



#endif // !Movie_H
