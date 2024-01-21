#include <iostream>
using namespace std;
class Date 
{
public:
	int year;
	int month;
	int day;

	Date() {}
	void setDate(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
	
	bool isLeapYear()
	{
		if (year % 4 != 0)
			return false;
		else if (year % 100 != 0)
			return true;
		else if (year % 400 != 0)
			return false;
		else
			return true;
	}
	
	int getDaysInMonth() 
	{
		if (month == 2) {
			if (isLeapYear())
				return 29;
			else
				return 28;
		} else if (month == 4 || month == 6 || month == 9 || month == 11) {
			return 30;
		} else {
			return 31;
		}
	}
	
	int getSkip(Date o) {
		int result = 0;
		Date temp = *this;
		
		if (temp.year == o.year && temp.month == o.month && temp.day == o.day) {
			return 0;
		} else if (o < temp) {
			swap(temp, o);
		}
		
		while (!(temp.year == o.year && temp.month == o.month && temp.day == o.day)) {
			result++;
			temp.day++;
			if (temp.day > temp.getDaysInMonth()) {
				temp.month++;
				temp.day = 1;
				if (temp.month > 12) {
					temp.year++;
					temp.month = 1;
				}
			}
		}
		
		return result;
	}
	
	bool operator<(const Date& o) {
		if (year < o.year)
			return true;
		else if (year > o.year)
			return false;
		else {
			if (month < o.month)
				return true;
			else if (month > o.month)
				return false;
			else {
				if (day < o.day)
					return true;
				else
					return false;
			}
		}
	}
};

int main() {
	Date d1, d2;
	int y, m, d;
	
	cin >> y >> m >> d;
	d1.setDate(y, m, d);
	
	cin >> y >> m >> d;
	d2.setDate(y, m, d);
	
	if (d1.isLeapYear())
		cout << d1.year << " is leap year." << endl;
	else
		cout << d1.year << " is not leap year." << endl;
	
	if (d2.isLeapYear())
		cout << d2.year << " is leap year." << endl;
	else
		cout << d2.year << " is not leap year." << endl;
	
	cout << "The skip of two date is " << d1.getSkip(d2) << "." << endl;
	
	return 0;
}
