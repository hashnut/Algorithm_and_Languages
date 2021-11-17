/*
 *	이 세상은 객체로 이루어져 있다
 *
 *	객체란, 변수들과 참고 자료들로 이루어진 소프트웨어 덩어리이다
 *
 * 
 */

#include <iostream>

using namespace std;

class Date
{
	int year_;
	int month_;
	int day_;

public:
	void SetDate(int year, int month, int date);
	void AddDay(int inc);
	void AddMonth(int inc);
	void AddYear(int inc);

	void ShowDate();
};

void Date::SetDate(int year, int month, int date)
{
	year_ = year; month_ = month; day_ = date;
}

void Date::AddDay(int inc)
{	
	int total_days;
	int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int month[13] = {0,};

	month[0] = days[0];
	for (int i = 1; i < 12; i++)
		month[i] = month[i-1] + days[i];
	month[12] = 1 << 10; // In order to find December

	total_days = (month[month_-2] + day_ + inc) % 365;

	printf("Total days : %d\n", total_days);

	int n_month, n_day;
	for (int i = 0; i < 12; i++)
	{
		if (month[i] < total_days && total_days < month[i+1])
		{
			n_month = i+2;
			n_day = total_days - month[i];
			break;
		}
	}

	printf("n_month : %d\n", n_month);
	printf("n_day : %d\n", n_day);

	month_ = n_month;
	day_ = n_day;


}

void Date::AddMonth(int inc)
{ month_ += inc % 12; }

void Date::AddYear(int inc)
{ year_ += inc; }

void Date::ShowDate()
{
	printf("YYYY/MM/DD : %d/%d/%d\n", year_, month_, day_);
}

int main()
{
	Date myDate;

	myDate.SetDate(2019, 2, 28);

	myDate.ShowDate();

	myDate.AddDay(3);

	myDate.ShowDate();

}
