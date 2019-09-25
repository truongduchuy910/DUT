#include <iostream>
int lastDayOf[] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int lastMonth = 12;
class Time {
	public:
		int day;
		int month;
		int year;
		void set(const int day, const int month, const int year) {
			this->day = day;
			this->month = month;
			this->year = year;
		};
		Time nextDay() {
			lastDayOf[2] = 28 + isLeapYear(this->year);
			int lastDay = lastDayOf[this->month];

			Time next;
			next.day = this->day + 1;
			next.month = this->month;
			next.year = this->year;
			
			if (next.day > lastDay) {
				next.day = 1;
				next.month++;
			};
			if (next.month > lastMonth) {
				next.month = 1;
				next.year++;
			}
			return next;
		};
		Time previousDay() {
			lastDayOf[2] = 28 + isLeapYear(this->year);
			int lastDay = lastDayOf[this->month];

			Time previous;
			previous.day = this->day - 1;
			previous.month = this->month;
			previous.year = this->year;

			if (!previous.day) {
				previous.month--;
				previous.day = lastDayOf[previous.month];
			};
			if (!previous.month) {
				previous.year--;
				previous.month = 12;
				previous.day = 31;
			};
			return previous;
		}
	private:
		int isLeapYear(int year) {
			return ( ( year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
		};


};
class Console {
	public:
		void out(Time time);
		Time in(Time time);
};
void Console::out(Time time) {
	std::cout << time.day << ":" << time.month << ":" << time.year << std::endl;
};
Time Console::in(Time time) {
	std::cout << "Input you time with format: dd mm yy ";
	int day, month, year;
	std::cin >> day >> month >> year;
	if (month > lastMonth) month = 12;
	if (day > lastDayOf[month]) day = lastDayOf[month];
	std::cout << "Your time is "  << day << ":" << month << ":" << year << std::endl;
	Time result;
	result.set(day, month, year);
	return result;
};
Console c;

int main () {
	Time time;
	time = c.in(time);
	c.out(time.nextDay());
	c.out(time.previousDay());
}
