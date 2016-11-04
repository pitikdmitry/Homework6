#include "interval.hpp"
bool point::in_interval(segment s1,point p1)
{
	double l=s1.get_left();
	double r=s1.get_right();
	bool include_l=s1.get_include_left();
	bool include_r=s1.get_include_right();

	double x=p1.get_point();

	if(!in_the_interval(l,r,include_l,include_r,x))
	{
		cout<<"Error";
		return false;
	}

	return true;
}

bool segment::in_interval(segment s1,point p1)
{
	double x=p1.get_point();
	double l=s1.get_left();
	double r=s1.get_right();

	if(!in_the_interval(l,r,s1.include_left,s1.include_right,x))
	{
		cout<<"Error";
		return false;
	}
	return true;
}
		
bool in_the_interval(double left,double right,bool include_left,bool include_right, double x)
{
	if(include_left==true && include_right==false)
	{
		if(left<x && right> x)
		{
			cout<<"point"<<"X="<<x<<" is in interval "<<"["<<left<<","<<right<<")"<<endl;
		}
		else
		{
			cout<<"point"<<"X="<<x<<" is NOT in interval "<<"["<<left<<","<<right<<")"<<endl;
		}
		return true;
	}
	if(include_left==false && include_right==true)
	{
		if(left<x && right>= x)
		{
			cout<<"point"<<"X="<<x<<" is in interval "<<"("<<left<<","<<right<<"]"<<endl;
		}
		else
		{
			cout<<"point"<<"X="<<x<<" is NOT in interval "<<"("<<left<<","<<right<<"]"<<endl;
		}
		return true;
	}
	if(include_left==true && include_right==true)
	{
		if(left<=x && right>= x)
		{
			cout<<"point"<<"X="<<x<<" is in interval "<<"["<<left<<","<<right<<"]"<<endl;
		}
		else
		{
			cout<<"point"<<"X="<<x<<" is NOT in interval "<<"["<<left<<","<<right<<"]"<<endl;
		}
		return true;
	}
	if(include_left==false && include_right==false)
	{
		if(left<x && right> x)
		{
			cout<<"point"<<"X="<<x<<" is in interval "<<"("<<left<<","<<right<<")"<<endl;
		}
		else
		{
			cout<<"point"<<"X="<<x<<" is NOT in interval "<<"("<<left<<","<<right<<")"<<endl;
		}
		return true;
	}
}

double interval::get_left()
{
	return left;
}

double interval::get_right()
{
	return right;
}

double point::get_point()
{
	return (interval::get_left());
}

double segment::get_left()
{
	return (interval::get_left());
}

double segment::get_right()
{
	return (interval::get_right());
}

bool segment::get_include_left()
{
	return include_left;
}

bool segment::get_include_right()
{
	return include_right;
}