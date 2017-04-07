#include <iostream>
#include <cstdio>
#include <time.h>

void calculate(int t, int numbers, int *hrem, int *srem, int *mrem, int *tpernum, int *spernum);
void timesup();
void finished();

using namespace std;

class Time
{
	public:
	Time();
	
	int hour;
	int minute;
	int second;
};


Time::Time()
{
	hour=0;
	minute=0;
	second=0;
}


void main()
{
	clock_t asdf;
	int t, numbers,num,done, tbank,tbank2,fraction;
	tbank=0;tbank2=0;fraction=0;done=0;

	Time *remaining=new Time();
	Time *goal=new Time(); //#pernum
	Time *goal1=new Time(); //#pernum
	Time *elapsed=new Time();
	Time *elapsed2=new Time();
	
	system("cls");
	cout<<"##Brought to you by Kuzame##\n\n";
	cout<<"Total numbers: ";
	cin>>numbers;
	num=numbers;
	cout<<"Hours left: ";
	cin>>remaining->hour;
	cout<<"Mins left: ";
	cin>>remaining->minute;
	cout<<"Will begin after you press enter..\n";
	system("pause");
	
	t=remaining->hour*3600+remaining->minute*60;
	if (numbers>0) calculate(t, numbers, &remaining->hour, &remaining->minute, &remaining->second, &goal->minute, &goal->second);
	goal1->minute=goal->minute;goal1->second=goal->second;
	
	while (numbers>0)
	{
		asdf=clock();
		system("cls");

		cout<< "#################################\n";
		cout<< "#                               #\n";
		cout<< "#                               #\n";
		printf("#  Time remaining: %.2dh %.2dm %.2ds  #\n", remaining->hour, remaining->minute,remaining->second);
		cout<< "#                               #\n";
		printf("#  Total Num:      %.3d num      #\n", num);
		printf("#  Num remaining:  %.3d num      #\n", numbers);
		cout<< "#                               #\n";
		printf("#  Time goal: %.3dm/num %.2ds/num  #\n", goal1->minute, goal1->second);
		printf("#  (refresh): %.3dm/num %.2ds/num  #\n", goal->minute, goal->second);
		cout<< "#                               #\n";
		printf("#  Time elapsed:   %.2dh %.2dm %.2ds  #\n", elapsed2->hour, elapsed2->minute,elapsed2->second);
		printf("#  Total elapsed:  %.2dh %.2dm %.2ds  #\n", elapsed->hour, elapsed->minute,elapsed->second);
		cout<< "#                               #\n";
		cout<< "#                               #\n";
		cout<< "#################################\n"<<endl;
		
		cout<< "Press ENTER to refresh\n";
		cout<< "Number you've finished (max 9): ";
		done=getchar(); if (done=='\n'||(done<'0'||done>'9')) {done=0;} else done=done-'0';
		numbers-=done;
		t-=(clock()-asdf)/1000 + fraction/1000;
		tbank+=(clock()-asdf)/1000 + fraction/1000;
		elapsed->hour= (tbank-(tbank%3600))/3600; elapsed->minute=((tbank-(tbank%60))/60)%60; elapsed->second=tbank%60;
		if (t<0) numbers=0;
		if (numbers>0) calculate(t, numbers, &remaining->hour, &remaining->minute, &remaining->second, &goal->minute, &goal->second);
		if (done!=0) {tbank2=0; goal1->minute=goal->minute;goal1->second=goal->second;} else tbank2+=(clock()-asdf)/1000 + fraction/1000;
		elapsed2->hour= (tbank2-(tbank2%3600))/3600; elapsed2->minute=((tbank2-(tbank2%60))/60)%60; elapsed2->second=tbank2%60;
		if (fraction>1000) fraction-=1000; fraction+=(clock()-asdf)%1000;
	}
	
	if (t<0)
	{
		cout<<endl;
		timesup();
	}
	else
	{
		cout<<endl;
		finished();
	}
	system("pause");
}

void timesup()
{
	int i;
	cout<< "#################################\n";
	cout<< "#         TIME's UP!! D;        #\n";
	cout<< "#################################\n";
	for (i=0;i<7;i++)
	printf("\07");
}

void finished()
{
	cout<< "#################################\n";
	cout<< "#-----  YAY finished!!! :D -----#\n";
	cout<< "#################################\n";
}

void calculate(int t,int numbers, int *hrem, int *mrem, int *srem, int *mpernum, int *spernum)
{
	*hrem = (t-(t%3600))/3600;
	*mrem = (t%3600)/60;
	*srem = t%60;
	*mpernum= (t/numbers)/60;
	*spernum= (t/numbers)%60;
	
}

//Copyrighted by Adrian Harminto