#include<iostream>

using namespace std;

class Date {

    int _day, _month, _year;

public:
    Date(int day = 0, int month = 0, int year = 0) : _day(day), _month(month), _year(year) {};

    Date operator+(int days) {
        Date date = Date (_day, _month, _year); //make local copy

        //add days
        date._day += days;

        //handle overflow in days
        int daysInMonth = 30; // Assuming each month has 30 days
        if (date._day > daysInMonth) {
            date._month += date._day / daysInMonth;
            date._day %= daysInMonth;
        }

        //handle overflow in months
        int monthsInYear = 12; // Assuming 12 months in a year
        if (date._month > monthsInYear) {
            date._year += date._month / monthsInYear;
            date._month %= monthsInYear;
        }

        return date;
    }


    friend ostream &operator<<(ostream &os, const Date &dt);
};

ostream& operator<<(ostream& os, const Date& dt){
    os << dt._day << "." << dt._month << "." << dt._year;
    return os;
}


int main(int argc, char *argv[]) {
    Date begin_task = Date(26, 10, 2023);
    cout << "Die Aufgabe beginnt am " << begin_task << endl;
    Date end_task = begin_task + 6;
    cout << "Die Aufgabe endet am " << end_task << endl;
    Date one_year_and_one_month_later = begin_task + 390;
    cout << "Ein Jahr und ein Monat nach Aufgabenbeginn ist der " << one_year_and_one_month_later << endl;
    Date three_years_and_eleven_months_later = begin_task + 1410;
    cout << "Drei Jahre und 11 Monate nach Aufgabenbeginn ist der " << three_years_and_eleven_months_later << endl;
}

