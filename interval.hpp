#ifndef INTERVAL_HPP
#define INTERVAL_HPP

#include <iostream>

using namespace std;

class interval;
class point;
class segment;

bool in_the_interval(double left,double right,bool include_left,bool include_right, double x);

class interval
{
private:
	double left;
	double right;
protected:
	virtual bool in_interval(segment s1,point p1)=0;
public:
	double get_left();
	double get_right();
	interval(double l,double r):left(l),right(r)
	{}
	virtual ~interval()
	{}
};

class point:public interval
{
public:
	point(double x): interval(x,x)
	{}
	bool in_interval(segment s1,point p1);
	double get_point();
	~point()
	{}
};

class segment:public interval
{
private:
	bool include_left;
	bool include_right;
public:
	segment(double l,double r,bool include_l,bool include_r):interval(l,r),include_left(include_l),include_right(include_r)
	{}
	bool in_interval(segment s1,point p1);
	double get_left();
	double get_right();
	bool get_include_left();
	bool get_include_right();
	~segment()
	{}
};

#endif
