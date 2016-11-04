//Homework6 Var1
#include <iostream>
#include "interval.hpp"
using namespace std;

int main()
{
	double l;
	double r;
	bool include_l;
	bool include_r;

	cout<<"Enter left side of interval: ";
	cin>>l;
	cout<<"include left point in interval? If yes enter 1; if No enter 0: ";
	cin>>include_l;
	cout<<"Enter right side of interval: ";
	cin>>r;
	cout<<"include right point in interval? If yes enter 1; if No enter 0: ";
	cin>>include_r;

	if(r<l)
	{
		int temp;
		temp=l;
		l=r;
		r=temp;
		int bool_temp;
		bool_temp=include_l;
		include_l=include_r;
		include_r=bool_temp;
	}

	double a;
	cout<<"Enter point : ";
	cin>>a;

	point p1(a);
	segment s1(l,r,include_l,include_r);

	s1.in_interval(s1,p1);
	p1.in_interval(s1,p1);

	return 0;
}