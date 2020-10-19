#include "library.h"

double pi = acos(-1.0);

double height(double v, double a,double t)
{
	return v*t*cos(a) - (1.0/2.0)*32.174*t*t;
}

void projectile(double v, double a, double ti, double tf, double can_x, double can_y,double r, double g, double b)
{
	if (ti<=tf)
	{
		if(r>=1)
		{
			r=0;
		}
		if(g>=1)
		{
			g=0;
		}
		if(b>=1)
		{
			b=0;
		}
		double x=can_x+v*ti*sin(a);
		set_pen_width(10);
		set_pen_color(r,g,b);
		draw_point(x,get_window_height()-height(v,a,ti)-can_y);
		projectile(v,a,ti+0.01,tf,can_x,can_y,r+0.0001, g+0.002, b+0.003);
	}
}

double get_xe(double x, double y, double L1, double L2, double w1,double w2, double radius, double a){
	double xc=x;
	double yc=y-radius;
	double const b=a*sin((w1-w2)/2/(L1+L2));
	double xp=xc-L1*sin(a-b);
	double yp=yc+L1*cos(a-b);
	double len=(L1+L2)*cos(b);
	double const d=sqrt(len*len+w1*w1/4);
	double g=a*sin(w1/2/d);
	double xe=xp+d*sin(a-g);
	double ye=yp-d*cos(a-g);
	return xe;
}
double get_ye(double x, double y, double L1, double L2, double w1,double w2, double radius, double a){
	double xc=x;
	double yc=y-radius;
	double const b=a*sin((w1-w2)/2/(L1+L2));
	double xp=xc-L1*sin(a-b);
	double yp=yc+L1*cos(a-b);
	double len=(L1+L2)*cos(b);
	double const d=sqrt(len*len+w1*w1/4);
	double g=a*sin(w1/2/d);
	double xe=xp+d*sin(a-g);
	double ye=yp-d*cos(a-g);
	return ye;
}

void draw_main_cannon_body(double x, double y, double L1, double L2, double w1, double w2, double radius, double a)
{
	double xc=x;
	double yc=y-radius;
	double const b=a*sin((w1-w2)/2/(L1+L2));
	double xp=xc-L1*sin(a-b);
	double yp=yc+L1*cos(a-b);
	double len=(L1+L2)*cos(b);¬¬¬¬¬¬¬
	double const d=sqrt(len*len+w1*w1/4);
	double g=a*sin(w1/2/d);
	double xe=xp+d*sin(a-g);
	double ye=yp-d*cos(a-g);
	set_pen_width(10);
	set_pen_color(color::black);
	set_pen_width(radius);
	draw_point(xc,yc);
	set_pen_color(color::white);
	set_pen_width(radius-5);
	draw_point(xc,yc);
	set_pen_color(color::black);
	move_to(xp, yp);
	set_pen_width(10);
	set_heading_radians(0);
	turn_right_by_radians(a);
	turn_left_by_radians(b);
	draw_distance(L1 - radius);
	move_distance(2*radius);
	draw_distance(L2-radius);
	turn_left_by_radians(pi/2.0);
	draw_distance(w2);
	turn_right_by_radians(pi/2.0 + b);
	turn_left_by_radians(pi);
	draw_distance(L1 + L2);
	turn_left_by_radians(pi/2.0);
	draw_distance(w1);
}
int target(){
	int centerX=random_in_range(get_window_width()/2,get_window_width());
	set_pen_color(color::black);
	set_pen_width(150);
	draw_point(centerX,get_window_height());
	set_pen_color(color::white);
	set_pen_width(140);
	draw_point(centerX,get_window_height());
	set_pen_color(color::black);
	return centerX;
}
double game(){
	double v,t_final, viy, start_a,start_arad,range;
	cout << "Please enter the initial velocity of the cannon ball: ";
	cin >> v;
	cout<<"Please enter the angle of the cannon:";
	cin>>start_a;
	start_arad=(start_a*pi)/180.0;
	viy=v*cos(start_arad);
	double can_x=get_xe(90,495,60,180,25,50,60,start_arad);
	double can_y=get_window_height()-get_ye(90,495,60,180,25,50,60,start_arad);
	draw_main_cannon_body(90,495,60,180,25,50,60,start_arad);
	t_final=((-viy-sqrt(viy*viy-4*-0.5*32.174*can_y))/-32.174);
	range=v*t_final*sin(start_arad)+can_x;
	projectile(v,start_arad,0, t_final,can_x,can_y,0,0,0);
	return range;
}
void main()
{
	make_window(1000,500);
	int centerX=target();
	int rightX=centerX+75;
	int leftX=centerX-75;
	double firstA=game();
	cout<<endl;
	if((firstA<=rightX)&&(firstA>=leftX)){
		cout<<"BOOOOOOM! #Winner"<<endl;
	}else{
		cout<<"Try harder"<<endl;
		double secondA=game();
		if((secondA<=rightX)&&(secondA>=leftX)){
			cout<<"BOOOOOOM! #Winner"<<endl;
		}else{
			cout<<"Think wisely you only got ONE MORE TRY!"<<endl;
			double thirdA=game();
			if((thirdA<=rightX)&&(thirdA>=leftX)){
				cout<<"BOOOOOOM! #Winner"<<endl;
			}else{
				cout<<"YOU LOST!"<<endl;
			}
		}
	}
}


