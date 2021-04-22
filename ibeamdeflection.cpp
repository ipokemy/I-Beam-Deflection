// JEREMY CHOY (145923) 


#include<iostream>
#include<conio.h> // for getch() in line 54

// constants
#define h 0.1
#define b 0.005
#define t 0.008
#define P 3000
#define E 70000000000
#define L 2

using namespace std;

double inertia(double);   			// declare for function of second inertia in line 58
double deflection (double,double);  // declare for function of vertical deflection in line 66

int main()
{
	double x,y,n; // y = value of each subsections, n = number of subsections
	cout<<"[+] INERTIA AND VERTICAL DEFLECTION CALCULATOR OF AN I-BEAM [+]\n";
	cout << "\nPlease input the number of subsections: ";
	cin >> n;
    cout << "\nx (in m)\t\tInertia, I(x) \t\tVertical Deflection, V(x)\n"; // \t = tab

	{
        y=L/n; // to calculate value of each subsections, y
        x=0;
        cout.precision(4); // significant figures = 4
        for (int i=0;i<=n;i++)
        {   
            cout<<x<<"\t\t\t";
            
     	if (x>=0 && x<L/2) 
        { 
            double w=0.15;
            {
             cout << inertia(w) << "\t\t" << deflection(x,inertia(w)) << "\n";
            }
        }
      
        else 
        { 
            double w=0.09;
            {
             cout << inertia(w) << "\t\t" << deflection(x,inertia(w)) << "\n";
            }
        }
        x=x+y; // displaying list of "x"
        }
     }
     getch(); // pauses the screen until any user input is given
}

//function of second inertia
double inertia (double w)
{
      double i;
   	  i =(w*h*h*h-(h-2*t)*(h-2*t)*(h-2*t)*(w-b))/12;
	  return(i);
}

//function of vertical deflection
double deflection (double x,double i)
{
	  double v;
  	  v=((P*x*x)*(3*L-x))/(E*i);
	  return(v);
}
