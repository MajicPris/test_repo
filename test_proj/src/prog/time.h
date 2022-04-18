#include<iostream>
using namespace std;

#include<iostream>


using namespace std;

class time {
public:
	int hour;
	int minute;
	int seconds;
	void initTime();
};

void time::initTime()
{

	do
	{
		cout << "enter hours (from 0 to 23): " << endl;
		cin >> hour;
	} while (hour < 0 || hour > 23);

	do
	{
		cout << "enter minutes (from 0 to 59): " << endl;
		cin >> minute;
	} while (minute < 0 || minute > 59);

	do
	{
		cout << "enter seconds (from 0 to 59) : " << endl;
		cin >> seconds;
	} while (seconds < 0 || seconds > 59);
	
}

int main()
{
	time t;
	int sec;
	t.initTime();
	cout << "enter seconds: " << endl;
	cin >> sec;
	int res = ((t.hour * 3600) + (t.minute * 60) + t.seconds - sec);
	cout << "remainig second: " << res << endl;
	t.hour = res / 3600;
	t.minute = (res %= 3600) / 60;
	t.seconds = res % 60;
	cout << "remaining time: " << t.hour << ":" << t.minute << ":" << t.seconds << endl;
	time t1, t2;
	t1.initTime();
	t2.initTime();
	int res1 = ((abs(t1.hour - t2.hour) * 3600) - ((abs(t1.minute - t2.minute)) * 60) - abs(t1.seconds - t2.seconds));
	cout << "count of seconds between 2 dates: " << res1 << endl;
	return 0;
}