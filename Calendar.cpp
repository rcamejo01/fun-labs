#include "library.h"
int monthLength(const int year, const int month){
        if (month==1||month==3||month==5||month==7||month==8||month==10||month==12)
                return 31;
        else if(month==4||month==6||month==9||month==11)
                return 30;
        else if(month==2){
                if(year==0){
                        return 29;
                }
                if(year%400==0){
                        return 29;
                }if(year%100!=0&&year%4==0){
                        return 29;
                }
                else
                        return 28;
        }
        else
                return 0;
}

int dayOfYear(int year, int month, int day){
        int days=day;
        int start=1;
        if(month!=1){
                while(start<month){
                        days+=monthLength(year,start);
                        start++;
                }
                return days;
        }else{
                return days;
        }
}
int daysInAYear(int year){
        int month=12;
        int days=0;
        while (month>0){
                days+=monthLength(year,month);
                month--;
        }
        return days;
}
int dayOfCentury(int year, int month, int day){
int days=dayOfYear(year,month,day);
        if(year!=2000){
                while(year>=2000){
                        days+=daysInAYear(year-1);
                        year--;
                }
                return days;
        }else{
                return days;
        }
}
int dayOfForever(int year, int month, int day){
        int days=dayOfYear(year,month,day);
        if(year!=0){
                while(year>=0){
                        days+=daysInAYear(year-1);
                        year--;
                }
                return (days-daysInAYear(0)+1);
        }else{
                return days;
        }
}
int dayofWeek(const int year, const int month, const int day){
        int dayForever=dayOfForever(year,month,day)-dayOfForever(0,12,31)-1;
        if(dayForever%7==0){
                return 0;
        }else if(dayForever%7==1){
                return 1;
        }else if(dayForever%7==2){
                return 2;
        }else if(dayForever%7==3){
                return 3;
        }else if(dayForever%7==4){
                return 4;
        }else if(dayForever%7==5){
                return 5;
        }else if(dayForever%7==6){
                return 6;
        }else
                return 0;

}

string nameDays(const int year, const int month, const int day)
{
        if(dayofWeek(year,month,day)==0)
                return "Sunday";
        else if (dayofWeek(year,month,day)==1)
                return "Monday";
        else if (dayofWeek(year,month,day)==2)
                return "Tuesday";
        else if(dayofWeek(year,month,day)==3)
                return "Wednesday";
        else if(dayofWeek(year,month,day)==4)
                return "Thursday";
        else if(dayofWeek(year,month,day)==5)
                return "Friday";
        else if(dayofWeek(year,month,day)==6)
                return "Saturday";
        else
                return "Wrong";
}
void nameofMonth(int month)
{
  if(month==1)
   cout << "     January";
  else if(month==2)
   cout << "     February";
  else if(month==3)
   cout << "     March";
  else if(month==4)
   cout << "     April";
  else if(month==5)
   cout << "     May";
  else if(month==6)
   cout << "     June";
  else if(month==7)
   cout << "     July";
  else if(month==8)
   cout << "     August";
  else if(month==9)
   cout << "     September";
  else if(month==10)
   cout << "     October";
  else if(month==11)
  cout << "      November";
else if(month==12)
  cout<<  "      December";
}
void print_numbers(int num_days, int w){
        int day=1;
        int block=0;
        while(block<w){
                cout<<"   ";
                block++;
        }
        while(block<num_days+w){
                if(block%7==0&&block!=0){
                        cout<<endl;
                }
                if(day<10){
                        cout<<" "<<day<<" ";
                }else{
                        cout<<day<<" ";
                }
                block++;
                day++;
        }
        cout<<endl;
}
void main_calendar(int yr, int m){
        int d=monthLength(yr,m);
        int w=dayofWeek(yr,m,1);
        nameofMonth(m);
        cout<<" "<<yr<<endl;
        cout << "Mo Tu We Th Fr Sa Su" << endl;
        print_numbers(d,w);
}

int main()
{
        int year, month, day;
        cout<<"Enter a year:"<<endl;
        cin>>year;
        cout<<"Enter a month:"<<endl;
        cin>>month;
        main_calendar(year,month);
}
