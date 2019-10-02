#include <iostream>

using namespace std;

class Date{
	friend istream& operator>>(istream &_cin,Date &d);
	friend ostream& operator<<(ostream &_cout,Date &d);
private:
	int _year;
	int _month;
	int _day;
public:
	Date(int year = 2000,int month = 1,int day = 1):_year(year),_month(month),_day(day)
	{
		cout << "Date()" << endl;
	}

	~Date(){
		cout << "~Date()" << endl;
	}
};

istream& operator>>(istream &_cin,Date &d){
	_cin >> d._year;
	_cin >> d._month;
	_cin >> d._day;

	return _cin;
}
ostream& operator<<(ostream &_cout,Date &d){
	_cout << d._year << endl;
	_cout << d._month << endl;
	_cout << d._day << endl;

	return _cout;
}

int main(){
	Date d;
	cin >> d;
	cout << d;
	return 0;
}
