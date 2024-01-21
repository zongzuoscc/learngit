/*自定义一个日期时间类DateTimeType，它含有类DateType与类TimeType的类对象作为其数据成员，并具有所列的其他几个成员函数。
  而后编制主函数，说明DateTimeType的类对象，并对其成员函数以及二对象成员所属类的公有成员函数进行使用。
  class DateTimeType {  //自定义的日期时间类 DateTimeType
  DateType date; //类 DateType 的类对象 date 作为其数据成员
  TimeType time; //类 TimeType 的类对象 time 作为其另一个数据成员
  public:
  DateTimeType(int y0=1, int m0=1, int d0=1, int hr0=0, int mi0=0, int se0=0);
//构造函数，设定 DateTimeType 类对象的日期时间，并为各参数设置了默认值
  DateType& GetDate(){ return date; } //返回本类的私有数据对象 data
  TimeType& GetTime(){ return time; } //返回本类的私有数据对象 time
  void IncrementSecond(int s);  //增加若干秒，注意“进位”问题
  void PrintDateTime(); //屏幕输出日期时间对象的有关数据
  };
  注意，每一个DateTimeType类对象中总包含有一个DateType类对象（对象成员）
  以及一个TimeType类对象（对象成员），编制与实现本程序时，也必须包含DateType与TimeType自定义类（类型）。
  之所以设置了公有的类成员函数GetDate与GetTime，是为类外如主函数处使用该类的私有数据成员date与time提供方便
  （否则的话，类外无法直接访问该类的私有数据成员）。
  【输入格式】
  输入多行。第一行为输入数据行数，后续每行输入依次为：年、月、日、时、分、秒
  【输出格式】
  输出多行。输出各个日期对象的相关信息，注意：第二行日期是第一行日期增加30秒得到的日期；第四行日期是第三行日期增加30秒得到的日期，多行情况下依次类推。
  【样例输入】
2
2023 10 8 15 29 36
1999 12 31 23 59 59 
  【样例输出】
  2023-10-8 15:29:36
  2023-10-8 15:30:6
  1999-12-31 23:59:59
  2000-1-1 0:0:29*/
#include <iostream>
using namespace std;

class DateType
{
private:
	int year;
	int month;
	int day;
	
public:
	DateType(int y, int m, int d) : year(y), month(m), day(d) {}
	
	void IncrementDay(int d) 
	{
		day += d;
		while (day > DaysInMonth()) 
		{
			day -= DaysInMonth();
			month++;
			if (month > 12) 
			{
				month = 1;
				year++;
			}
		}
	}
	
	void Display()
	{
		cout << year << "-" << month << "-" << day;
	}
	
	bool IsLeapYear() 
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			return true;
		else
			return false;
	}
	
	int DaysInMonth()
	{
		if (month == 2) 
		{
			if (IsLeapYear()) return 29;
			else return 28;
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) 
		{
			return 30;
		}
		else 
		{
			return 31;
		}
	}
};

class TimeType 
{
public:
	int hour;
	int minute;
	int second;
	
public:
	TimeType(int h, int m, int s) : hour(h), minute(m), second(s) {}
	
	void IncrementSecond(int s) 
	{
		second += s;
		minute += second / 60;
		second %= 60;
		hour += minute / 60;
		minute %= 60;
	}
	
	void Display() 
	{
		cout << " " << hour << ":" << minute << ":" << second << endl;
	}
};

class DateTimeType 
{
private:
	DateType date;
	TimeType time;
	
public:
	DateTimeType(int y0 = 1, int m0 = 1, int d0 = 1, int hr0 = 0, int mi0 = 0, int se0 = 0)
	: date(y0, m0, d0), time(hr0, mi0, se0) {}
	
	DateType& GetDate() 
	{ 
		return date; 
	}
	
	TimeType& GetTime() 
	{ 
		return time; 
	}
	
	void IncrementSecond(int s) 
	{
		time.IncrementSecond(s);
		
		while (time.hour >= 24) 
		{
			time.hour -= 24;
			date.IncrementDay(1);
		}
	}
	
	void PrintDateTime()
	{
		date.Display();
		time.Display();
	}
};

int main() 
{
	int n;
	cin >> n;
	
	for (int i = 0; i < n; ++i) 
	{
		int y, m, d, h, mi, s;
		cin >> y >> m >> d >> h >> mi >> s;
		DateTimeType dateTime(y, m, d, h, mi, s);
		dateTime.PrintDateTime();
		dateTime.IncrementSecond(30);
		dateTime.PrintDateTime();
	}
	return 0;
}

