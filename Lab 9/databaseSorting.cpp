#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <time.h>
#include <sys/resource.h> 
using namespace std;

double get_cpu_time()
{
struct rusage ruse;
getrusage(RUSAGE_SELF, &ruse);
return ruse.ru_utime.tv_sec+ruse.ru_utime.tv_usec/1000000.0 +
ruse.ru_stime.tv_sec+ruse.ru_stime.tv_usec/1000000.0; 
}

struct information
{
	string firstname;
	string lastname;
	int year;
	int month;
	int day;
	string state;
	int social;
	double balance;
};

bool comparison(string s1,string s2)
{
transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
if(s1.compare(s2)==0)
{
return true;
}
else
{
	return false;
}
}

int dob(int year, int month, int day) 
{
    int t1=1;
	while(t1<=month)
		{
		t1*=100;
		}
	int sum=year*t1 +month;
	int t2=1;
	while(t2<=day)
		{
		t2*=100;
		}
	int d=sum*t2 +day;
    return d;	
} 

void namesearch(string searchname,information info[],int size)
{
	for(int j=0;j<size;j++)
	{
		if((comparison(searchname,info[j].firstname))||(comparison(searchname,info[j].lastname)))
		{
			cout << info[j].firstname <<"  "<< info[j].lastname << "  " << info[j].year << "   ";
			cout << info[j].month << "  " << info[j].day << "  " << info[j].state << "  " << info[j].social << "  ";
			cout << info[j].balance << endl;
		}
	}
}
void outputdata(information info[], int num, int size)
{
	ofstream output;
	stringstream file_name;
	file_name<<"output"<<num<<".txt";
	string file;
	file_name>>file;
	output.open(file);
	if(output.is_open())
	{
	for(int j=0;j<size;j++)
	{
		output << info[j].firstname << "  " << info[j].lastname <<"  "<< info[j].year <<"  "<< info[j].month <<"  "<< info[j].day <<"  "<< info[j].state <<"  "<< info[j].social <<"  "<< info[j].balance <<"  "<< endl;
	}
	}
	output.close();
}
void oldest(information info[],int size, int files)
{
	double time1=get_cpu_time();
	double time2;
	for(int i=0; i<size; i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(dob(info[i].year,info[i].month,info[i].day)<dob(info[j].year,info[j].month,info[j].day))
			{
				information p=info[i];
				info[i]=info[j];
				info[j]=p;
			}
		}
	}
	time2=get_cpu_time();
	cout << (time2-time1) << endl;
	outputdata(info,files,size);
}

void firstFile()
{
	ifstream file;
	file.open("data1.txt");
	int i=0;
	information info[1000];
	if(file.is_open())
	{
		while(file>>info[i].firstname>>info[i].lastname>>info[i].year>>info[i].month>>info[i].day>>info[i].state>>info[i].social>>info[i].balance)
		{
			i++;
		}
	}
	oldest(info,1000,1);
	file.close();
}

void secondFile()
{
	ifstream file;
	file.open("data2.txt");
	int i=0;
	information info[2000];
	if(file.is_open())
	{
		while(file>>info[i].firstname>>info[i].lastname>>info[i].year>>info[i].month>>info[i].day>>info[i].state>>info[i].social>>info[i].balance)
		{
			i++;
		}
	}
	oldest(info,2000,2);
	file.close();
}

void thirdFile()
{
	ifstream file;
	file.open("data3.txt");
	int i=0;
	information info[3000];
	if(file.is_open())
	{
		while(file>>info[i].firstname>>info[i].lastname>>info[i].year>>info[i].month>>info[i].day>>info[i].state>>info[i].social>>info[i].balance)
		{
			i++;
		}
	}
	oldest(info,3000,3);
	file.close();
}

void fifthFile()
{
	ifstream file;
	file.open("data5.txt");
	int i=0;
	information info[5000];
	if(file.is_open())
	{
		while(file>>info[i].firstname>>info[i].lastname>>info[i].year>>info[i].month>>info[i].day>>info[i].state>>info[i].social>>info[i].balance)
		{
			i++;
		}
	}
	oldest(info,5000,5);
	file.close();
}

void tenthFile()
{
	ifstream file;
	file.open("data10.txt");
	int i=0;
	information info[10000];
	if(file.is_open())
	{
		while(file>>info[i].firstname>>info[i].lastname>>info[i].year>>info[i].month>>info[i].day>>info[i].state>>info[i].social>>info[i].balance)
		{
			i++;
		}
	}
	oldest(info,10000,10);
	file.close();
}

void File20()
{
	ifstream file;
	file.open("data20.txt");
	int i=0;
	information info[20000];
	if(file.is_open())
	{
		while(file>>info[i].firstname>>info[i].lastname>>info[i].year>>info[i].month>>info[i].day>>info[i].state>>info[i].social>>info[i].balance)
		{
			i++;
		}
	}
	oldest(info,20000,20);
	file.close();
}

void File30()
{
	ifstream file;
	file.open("data30.txt");
	int i=0;
	information info[30000];
	if(file.is_open())
	{
		while(file>>info[i].firstname>>info[i].lastname>>info[i].year>>info[i].month>>info[i].day>>info[i].state>>info[i].social>>info[i].balance)
		{
			i++;
		}
	}
	oldest(info,30000,30);
	file.close();
}

void File50()
{
	ifstream file;
	file.open("data50.txt");
	int i=0;
	information info[50000];
	if(file.is_open())
	{
		while(file>>info[i].firstname>>info[i].lastname>>info[i].year>>info[i].month>>info[i].day>>info[i].state>>info[i].social>>info[i].balance)
		{
			i++;
		}
	}
	oldest(info,50000,50);
	file.close();
}

void File100()
{
	ifstream file;
	file.open("data100.txt");
	int i=0;
	information info[100000];
	if(file.is_open())
	{
		while(file>>info[i].firstname>>info[i].lastname>>info[i].year>>info[i].month>>info[i].day>>info[i].state>>info[i].social>>info[i].balance)
		{
			i++;
		}
	}
	oldest(info,100000,100);
	file.close();
}

int main()
{
	firstFile();
	secondFile();
	thirdFile();
	fifthFile();
	tenthFile();
	File20();
	File30();
	File50();
	File100();

	return 1;
}


