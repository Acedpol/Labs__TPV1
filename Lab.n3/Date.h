#include <iostream>

using namespace std;

#ifndef DATE_H_
#define DATE_H_

class Date {
private:
	int year;
	int month;
	int day;

public:
	Date() : year(0), month(0), day(0) {};
	Date(int y, int m, int d);
	Date(const Date& date);
	void operator++();
	void operator+=(int n);
	bool operator<(const Date& date) const;
	int diff(const Date& date) const;
	void print() const;
	friend istream& operator>>(istream& in, Date& d);
	friend ostream& operator<<(ostream& in, const Date& d);

private:
	int daysInMonth(int m) const;
	int calculateValue() const;
	bool correctDate() const;
};

#endif /* DATE_H_ */
