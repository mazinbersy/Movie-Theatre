# Movie Theatre Simulation

This C++ program simulates the operation of a movie theatre, including ticket booking, snack ordering, and customer service queues. It consists of several classes representing different aspects of the theatre's operation, as well as a main function to drive the simulation.

## Classes

### `Movie`

The `Movie` class represents a movie being shown at the theatre. It contains the following attributes:
- `name`: The name of the movie.
- `times`: A vector of strings representing the showtimes for the movie.
- `sundayBooking` to `saturdayBooking`: Unordered maps representing the booking status for each day of the week. Each map contains vectors of vectors of boolean values indicating whether a seat is booked or not.

The class provides methods for various operations:
- `displayBookingInfo`: Displays the booking status for a given day and time.
- `reserveSeat`: Marks a seat as booked for a specific day and time.
- `cancelSeat`: Cancels a reservation for a seat on a specific day and time.
- `updateBookingInfo`: Reads booking information from files and updates the booking status accordingly.

### `Theatre`

The `Theatre` class manages the operation of the movie theatre. It includes the following attributes:
- `ticketWaitingTime` and `snackWaitingTime`: Integers representing the total waiting time for ticket and snack queues.
- `ticketCustomers` and `snackCustomers`: Integers representing the number of customers in the ticket and snack queues.
- `ticketQueue` and `snackQueue`: Queues representing the ticket and snack queues.
- `movies`: A vector containing instances of the `Movie` class representing the movies being shown at the theatre.

The class provides methods for various operations:
- `populateTicketQueue` and `populatesnackQueue`: Populates the ticket and snack queues with random numbers of customers.
- `joinTicketQueue` and `joinSnackQueue`: Adds a customer to the ticket or snack queue.
- `bookSeat` and `cancelReservation`: Allows customers to book seats or cancel reservations for a movie.
- `constructBookingFiles`: Creates booking files for each movie and day of the week.
- `serveTicketCustomer` and `serveSnackCustomer`: Serves customers in the ticket and snack queues.

## Main Function

The main function of the program drives the simulation of the movie theatre operation. It includes the following steps:
1. Creates instances of the `Movie` and `Theatre` classes.
2. Allows customers to join the ticket or snack queues.
3. Serves customers in the queues until they are empty.
4. Allows customers to book seats or cancel reservations.
5. Displays messages to prompt user interactions and simulate the theatre operation.

## How It Works

1. The program starts by creating instances of movies with specific showtimes and seating arrangements.
2. Customers can choose to join the ticket or snack queues.
3. Customers in the queues are served one by one until the queues are empty.
4. During service, customers may book seats for a chosen movie, day, and time, or cancel existing reservations.
5. The simulation continues until all customers have been served and all interactions are completed.

## Usage

To run the simulation, compile the program and execute the generated executable. Follow the prompts to interact with the simulation and observe the operation of the movie theatre.

```cpp
// Example usage
int main() {
    // Create instances of Movie and Theatre classes
    // Drive the simulation by allowing customers to join queues, serving customers, booking seats, etc.
    // ...
    return 0;
}
