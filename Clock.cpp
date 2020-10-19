#include "library.h"
const double pi = acos(-1.0);
string month(int m)
{
	if(m==1)
		return("January");
	if(m==2)
		return("February");
	if(m==3)
		return("March");
	if(m==4)
		return("April");
	if(m==5)
		return("May");
	if(m==6)
		return("June");
	if(m==7)
		return("July");
	if(m==8)
		return("August");
	if(m==9)
		return("September");
	if(m==10)
		return("October");
	if(m==11)
		return("November");
	if(m==12)
		return("December");
}
string day(int d)
{
	if(d==1)
		return("st");
	else if(d==2 || d==22)
		return("nd");
	else if(d==21 || d==31)
		return("st");
	else if(d==23)
		return("rd");
	else 
		return("th");
}
int readYear()
{
	int year=(get_calendar_date())/10000;
	return year;
}
int readMonth()
{
	int month=((get_calendar_date()))/100%100;
	return month;
}
int readDay()
{
	int day=(get_calendar_date())%100;
	return day;
}
int readHour()
{
	int hour=(get_clock_time())/10000;
	return hour;
}
int readMinute()
{
	int minute=((get_clock_time())/100)%100;
	return minute;
}
int readSecond()
{
	int second=(get_clock_time())%100;
	return second;
}
int AMorPM()
{
	int hour = readHour();
	if(hour==0)
		return 12;
	if(hour>0 && hour<12)
		return hour;
	else 
		return(hour%12);
}
void monroeDoctrine()
{
	cout << "Year: " << readYear() << endl;
	cout << "Month: " << readMonth() << endl;
	cout << "Day: " << readDay() << endl;
	cout << "Hour: " << AMorPM();
	if((readHour() >= 0) && (readHour() < 12))
		cout << "AM";
	else 
		cout << "PM";
	cout << endl;
	cout << "Minute: " << readMinute() << endl;
	cout << "Second: " << readSecond() << endl;
}

void digitalClock()
{
	set_font_size(30);
	move_to(200,475);
	write_string(AMorPM());
	write_string(":");
	if(readMinute()>=10)
		write_string(readMinute());
	else if(readMinute()<10)
	{
		write_string("0");
		write_string(readMinute());
	}
	write_string(" ");
	if((readHour() >= 0) && (readHour() < 12))
	{
		write_string("AM");
		move_to(140,500);
	}
	else
	{
		write_string("PM");
		move_to(140,500);
	}
	write_string(readDay());
	write_string(day(readDay()));
	write_string(" ");
	write_string(month(readMonth()));
	write_string(" ");
	write_string(readYear());
}
void hourHand()
{
	move_to(250,300);
	double degree=30.0*((AMorPM())+(readMinute())/60.0 +(readSecond())/3600.0);
	set_heading_degrees(degree);
	set_pen_width(5);
	draw_distance(75);
}

void minuteHand()
{
	move_to(250,300);
	double degree=(6.0*((readMinute())+((readSecond())/60.0)));
	set_heading_degrees(degree);
	set_pen_width(3);
	draw_distance(100);
}
void secondHand()
{
	move_to(250,300);
	double degree = (6.0*readSecond());
	set_heading_degrees(degree);
	set_pen_width(1);
	set_pen_color(color::red);
	draw_distance(110);
	set_pen_color(color::black);
}
void drawCircle(int a, int radians)
{
   if(a<=363)
   {
   set_pen_width(2);
   double arcd=pi*(1.0/180.0)*radians;
   draw_distance(arcd);
   double x= get_x_position();
   double y= get_y_position();
   int hd=get_heading_degrees();
   if(0==(hd%30))
	   {
	   set_pen_width(6);
	   turn_left_by_degrees(90);
	   draw_distance(-10);
	   draw_distance(20);
	   move_to(x,y);
	   set_heading_degrees(hd);
	   set_pen_width(2);
	   }
   if(0==(hd%6))
	   {
	   set_pen_width(4);
	   turn_left_by_degrees(90);
	   draw_distance(-20);
	   move_to(x,y);
	   set_heading_degrees(hd);
	   set_pen_width(2);
	   }
   turn_right_by_degrees(1);
   drawCircle(a+1,radians);
   }
}
void clock(double x,int y,double rad)
{
    move_to(x , y - rad);
	set_heading_degrees(90);
    drawCircle(0,rad);
}
void main()
{
	make_window(500,600);
	set_pen_color(color::black);
	clock(250,298,150);
	while(1)
	{
		digitalClock();
		hourHand();
		minuteHand();
		secondHand();
		wait(0.01);
		set_pen_color(color::white);
		set_pen_width(230);
		draw_point(250,300);
		fill_rectangle(70,449,300,70);
		set_pen_color(color::black);
	}
}

