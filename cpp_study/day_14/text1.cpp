#include <iostream>

using namespace std;

class Data {
public:
    Data(int year, int month, int day) : _year(year), _month(month), _day(day) {} // Added constructor for initialization

    // Copy constructor
    Data(const Data &d) : _year(d._year), _month(d._month), _day(d._day) {}

    // Less-than operator
    bool operator<(const Data &d) const {
        return _year < d._year || (_year == d._year && _month < d._month) ||
               (_year == d._year && _month == d._month && _day < d._day);
    }

    // Prefix increment operator
    Data& operator++() {
        ++_day;
        if (_day > daysInMonth(_month, _year)) {
            _day = 1;
            ++_month;
            if (_month > 12) {
                _month = 1;
                ++_year;
            }
        }
        return *this;
    }

    // Not-equal-to operator
    bool operator!=(const Data &d) const {
        return _year != d._year || _month != d._month || _day != d._day;
    }

    // Subtraction operator
    int operator-(const Data &d) const {
        Data max = *this;  // Copy constructor
        Data min = d;
        int flag = 1;

        if (*this < d) {
            max = d;
            min = *this;
            flag = -1; // Corrected scope of flag
        }

        int daysDifference = 0;
        while (min != max) {
            ++min;
            ++daysDifference;
        }

        return flag * daysDifference;
    }

private:
    int _year;
    int _month;
    int _day;

    // Determine if a year is a leap year
    bool isLeapYear(int year) const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    // Get the number of days in a month
    int daysInMonth(int month, int year) const {
        switch (month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                return 31;
            case 4: case 6: case 9: case 11:
                return 30;
            case 2:
                return isLeapYear(year) ? 29 : 28;
            default:
                return 0;
        }
    }
};
