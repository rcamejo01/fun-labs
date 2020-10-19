#include "library.h"

double const pi = acos(-1.0);

void line_and_turn(int const N, double const side, int const angle)
{
	if (N > 0)
	{
		draw_distance(side); note_position();
		turn_right_by_degrees(angle);
		line_and_turn(N - 1, side, angle);
	}
}

void draw_circle(double const x, double const y, double const radius)
{
	double const circumference = 2 * radius * 3.14;
	double const side = circumference / 360;
	set_heading_degrees(90);
	move_to(x, y - radius);
	start_shape();
	line_and_turn(360, side, 1);
	fill_shape();
	set_pen_color(0, 0, 0);
}

void rect(int const Xpos, int const Ypos, int const width, int const height)
{
	start_shape();
	move_to(Xpos, Ypos); note_position();
	set_heading_degrees(90);
	draw_distance(width); note_position();
	turn_right_by_degrees(90);
	draw_distance(height); note_position();
	turn_right_by_degrees(90);
	draw_distance(width); note_position();
	turn_right_by_degrees(90);
	draw_distance(height); note_position();
	fill_shape();
}
void stars()
{
	int r=random_in_range(0,1000);
	while(r>0)
	{
		int x;
		int y;
		x=random_in_range(0,1000);
		y=random_in_range(0,1000);
		set_pen_color(color::white);
		draw_point(x,y);
		r=r-1;
	}
}

void sky(int time)
{
	if (time >= 6 && time < 8)
	{
		set_pen_color_int(58, 73, 115);
		fill_rectangle(0,0,1000,1000);
		stars();
		set_pen_width(1);
	}
	else if (time >= 8 && time < 10) 
	{
		
		set_pen_color_int(118, 223, 255);
		fill_rectangle(0,0,1000,1000);
		set_pen_width(1);
	}
	else if (time >= 10 && time < 12)
	{
		
		set_pen_color_int(140, 223, 255);
		fill_rectangle(0,0,1000,1000);
		set_pen_width(1);
	}
	else if (time >= 12 && time <14) 
	{
		
		set_pen_color_int(120, 223, 255);
		fill_rectangle(0,0,1000,1000);
		set_pen_width(1);
	}
	else if (time >= 14 && time <16) 
	{
		
		set_pen_color_int(100, 213, 255);
		fill_rectangle(0,0,1000,1000);
		set_pen_width(1);
	}
	else if (time >= 16 && time <18)
	{
		
		set_pen_color_int(70, 203, 255);
		fill_rectangle(0,0,1000,1000);
		set_pen_width(1);
	}
	else if (time >= 18 && time <20) 
	{
		
		set_pen_color_int(70, 90, 180);
		fill_rectangle(0,0,1000,1000);
		stars();
		set_pen_width(1);
	}
	else 
	{
		
		set_pen_color_int(1, 23, 81);
		fill_rectangle(0,0,1000,1000);
		stars();
		set_pen_width(1);
	}
}

void sun_and_moon(int const time)
{
	if (time >= 6 && time <= 17)
	{ 
		set_pen_color(color::yellow);
		draw_circle(480, 150, 75);
	}

	else if (time >= 18 || time <= 5)
	{
		set_pen_color(color::light_grey);
		draw_circle(480, 150, 75);
	}
}

void cloud(int const n)
{
	if (n > 0 && n <= 6)
	{
		int const x = random_in_range(0, 820);
		int const y = random_in_range(0, 520);
		double const size = 160;
		set_pen_color_int(255, 255, 255);
		rect(x, y, 90, 30);
		rect(x + 40, y - 10, 160, 40);
		cloud(n - 1);
	}
}

void draw_clouds(int const time)
{
	if (time >= 1 && time<6) 
		cloud(random_in_range(0, 6));
	else if (time >= 12 && time<18) 
		cloud(random_in_range(0, 6));
	else if (time == 24) 
		cloud(random_in_range(0, 6));
	else 
		cloud(random_in_range(0, 8));
}

void window(int const Xpos, int const Ypos, int const width, int const height, int const red, int const green, int const blue)
{
	int const random_selection = random_in_range(0, 50);
	set_pen_color_int(red, green, blue);
	rect(Xpos, Ypos, width, height);
	if (random_selection <= 2) 
	{
		set_pen_color(color::red);
		rect(Xpos, Ypos, width / 3, height);
		rect(Xpos + 2 * (width / 3)+2, Ypos, width / 3, height);
	}
}

void draw_grass(int const time)
{
	int const n = random_in_range(45, 75);
	
	if (time >= 6 && time < 10) 
		set_pen_color_int(184, 203, 100);
	else if (time >= 10 && time<14) 
		set_pen_color_int(164, 203, 110);
	else if (time >= 14 && time<18) 
		set_pen_color_int(124, 203, 130);
	else set_pen_color_int(60, 100, 70);
		rect(0, 720 - n, 1000, n);
}

void draw_road(int const time, int const n)
{
	if (time >= 6 && time<10) 
		set_pen_color_int(122, 122, 122);
	else if (time >= 10 && time<14) 
		set_pen_color_int(160, 160, 160);
	else if (time >= 14 && time<18)
		set_pen_color_int(140, 140, 140);
	else
		set_pen_color_int(70, 70, 70);
	rect(-1, 720 - n, 1000, n);
}

void row_of_windows(int const rows, int const Xpos, int const Ypos, int const width, int const height, int const red, int const green, int const blue)
{
	int N = rows;
	int separation = width*(15/64.0);
	while (N > 0)
	{
		window( Xpos + separation, Ypos, width, height, red , green, blue);
		separation = separation + width + (width/3);
		N = N - 1;
	}
}

void block_of_windows(int const floors, int const rows, int const Xpos, int const Ypos, int const width, int const height, int const red, int const green, int const blue)
{
	int N = floors;
	int separation = height/2;
	while (N > 0)
	{
		row_of_windows(rows, Xpos, Ypos + separation, width, height, red, green, blue);
		separation = separation + 2*height;
		N = N - 1;
	}
}

void draw_block(int const floors, int const Xpos, int const Ypos, int const width, int const height, int const red, int const green, int const blue)
{
	if (width >= 25 && width < 50) 
	{
		int const rows = 1;
		int const win_width = (width / (rows))*(16 / 22.0); 
		int const win_height = height / (2 * floors); 
		block_of_windows(floors, rows, Xpos, Ypos - height, win_width, win_height, red, green, blue);
	}
	else if (width >= 50 && width < 100)
	{
		int const rows = random_in_range(1, 2);
		int const win_width = (width / (rows))*(16 / 22.0);
		int const win_height = height / (2 * floors);
		block_of_windows(floors, rows, Xpos, Ypos - height, win_width, win_height, red, green, blue);
	}
	else if (width >= 100 && width < 150)
	{
		int const rows = random_in_range(2, 3);
		int const win_width = (width / (rows))*(16 / 22.0);
		int const win_height = height / (2 * floors);
		block_of_windows(floors, rows, Xpos, Ypos - height, win_width, win_height, red, green, blue);
	}
	else if (width >= 150 && width < 250)
	{
		int const rows = random_in_range(3, 5);
		int const win_width = (width / (rows))*(16 / 22.0);
		int const win_height = height / (2 * floors);
		block_of_windows(floors, rows, Xpos, Ypos - height, win_width, win_height, red, green, blue);

	}
	else
	{
		int const rows = random_in_range(4, 7);
		if (rows < 5)
		{
			int const win_width = (width / (rows))*(8 / 11.0);
			int const win_height = height / (2 * floors);
			block_of_windows(floors, rows, Xpos, Ypos - height, win_width, win_height, red, green, blue);
		}
		else
		{
			int const win_width = (width / (rows))*(3 / 4.0);
			int const win_height = height / (2 * floors);
			block_of_windows(floors, rows, Xpos, Ypos - height, win_width, win_height, red, green, blue);
		}

	}
}

void row_of_windows_and_door(int const rows, int const Xpos, int const Ypos, int const width, int const height, int const red, int const green, int const blue, int const door_random)
{
	int N = rows;
	int separation = width*(15 / 64.0);
	while (N > 0)
	{
		if (N == door_random)
		{
			int const door_color = random_in_range(1, 2);
			if (door_color == 1) set_pen_color_int(random_in_range(140, 200), random_in_range(180, 240), random_in_range(80, 140));
			else if (door_color == 2) set_pen_color_int(random_in_range(180, 240), random_in_range(0, 60), random_in_range(0, 60));
			rect(Xpos + separation, Ypos, width, height*(3.1/2.0));
		}
		else window(Xpos + separation, Ypos, width, height, red, green, blue);
		separation = separation + width + (width / 3);
		N = N - 1;
	}
}

void block_of_house_windows(int const floors, int const rows, int const Xpos, int const Ypos, int const width, int const height, int const red, int const green, int const blue)
{
	int N = floors;
	int separation = height / 2;
	while (N > 0)
	{
		if (N == 1)
		{
			int const door_random = random_in_range(1, rows);
			row_of_windows_and_door(rows, Xpos, Ypos + separation, width, height, red, green, blue,door_random);

		}
		else
		{
			row_of_windows(rows, Xpos, Ypos + separation, width, height, red, green, blue);
			separation = separation + 2 * height;
		}
		N = N - 1;
	}
}

void draw_house(int const floors, int const Xpos, int const Ypos, int const width, int const height)
{
	int const color = random_in_range(100, 200);
	if (width < 150)
	{
		int const rows = 2;
		int const win_width = (width / (rows))*(16 / 22.0);
		int const win_height = height / (2 * floors);
		block_of_house_windows(floors, rows, Xpos, Ypos - height, win_width, win_height, color, color, color);
	}
	else
	{
		int const rows = 3;
		int const win_width = (width / (rows))*(16 / 22.0);
		int const win_height = height / (2 * floors);
		block_of_house_windows(floors, rows, Xpos, Ypos - height, win_width, win_height, color, color, color);
	}
}

void roof(int const Xpos, int const Ypos, int const width, int const height)
{
	int const random = random_in_range(1, 2);
	set_pen_color_int(148, 108, 73);
	int const extra_width = 15;
	int const tri_hi = 40;
	int const hype = sqrt((tri_hi*tri_hi) + (((width + 2*extra_width) / 2.0)*((width + 2*extra_width) / 2.0)));
	double const angle = tan(tri_hi / ((width + 2*extra_width) / 2.0))*(180 / acos(-1.0));
	if (random == 1)
	{
		set_pen_color_int(148, 108, 73);
		move_to(Xpos - extra_width, Ypos - height);
		start_shape();
		set_heading_degrees(90);
		turn_left_by_degrees(angle);
		move_distance(hype); note_position();
		turn_right_by_degrees(180 - 2 * (90 - angle)+1);
		move_distance(hype+6); note_position();
		turn_right_by_degrees(180 - angle);
		move_distance(width + 2 * extra_width); note_position();
		fill_shape();
	}
	else
	{
		set_pen_color_int(154, 155, 53);
		move_to(Xpos - extra_width, Ypos - height);
		start_shape();
		set_heading_degrees(90);
		turn_left_by_degrees(angle);
		draw_distance(hype); note_position();
		turn_right_by_degrees(180 - 2 * (90 - angle));
		draw_distance(hype); note_position();
		turn_right_by_degrees(180 - angle);
		draw_distance(width + 2 * extra_width); note_position();
		fill_shape();
	}
}

void chimney(int const Xpos, int const Ypos, int const width, int const height)
{
	set_pen_color_int(100, 102, 101);
	int const chim_width = width / 10;
	int const chim_height = height / 4;
	rect(Xpos+5, Ypos - height - chim_height, chim_width, chim_height);
}

void building_condition(int const Xpos, int const Ypos, int const width, int const height)
{ 
	int const red = random_in_range(0, 50);
	int const green = random_in_range(0, 50);
	int const blue = random_in_range(0, 50);
	set_pen_color_int(random_in_range(50, 200), random_in_range(50, 100), random_in_range(50, 200));
	rect(Xpos, Ypos - height, width, height);
	if (height >= 100 && height < 150)
	{
		int const randi = random_in_range(1, 3);
		if (randi == 1)
		{
			chimney(Xpos, Ypos, width, height);
			roof(Xpos, Ypos, width, height);
			int const floors = 1;
			draw_house(floors, Xpos, Ypos, width, height);
		}
	}
	else if (height >= 150 && height < 250)
	{	
		int const randi = random_in_range(1, 3);
		if (randi == 1)
		{
			chimney(Xpos, Ypos, width, height);
			roof(Xpos, Ypos, width, height);
			int const floors = 2;
			draw_house(floors, Xpos, Ypos, width, height);
		}
	}
	else if (height >= 250 && height < 300)
	{
		int const floors = random_in_range(3, 4);
		draw_block(floors, Xpos, Ypos, width, height, red, green, blue);
	}
	else if (height >= 300 && height < 400)
	{
		int const floors = random_in_range(4, 5);
		draw_block(floors, Xpos, Ypos, width, height, red, green, blue);
	}
	else if (height >= 400 && height < 500)
	{
		int const floors = random_in_range(5, 6);
		draw_block(floors, Xpos, Ypos, width, height, red, green, blue);
	}
	else
	{
		int const floors = random_in_range(6, 7);
		draw_block(floors, Xpos, Ypos, width, height, red, green, blue);
	}
}

void draw_tree(int const Xpos,int const Ypos)
{
	int const stem_height = random_in_range(100, 125);
	int const stem_width = random_in_range(10, 15);
	set_pen_color_int(141, 70, 19);
	rect(Xpos, Ypos-stem_height, stem_width, stem_height);

	int const leave_width = random_in_range(75, 100);
	int const leave_height = (stem_height)/2;
	int const X_lim_left = Xpos - leave_width / 2;
	int const X_lim_right = Xpos + leave_width / 2;
	int const y_lim_up = Ypos - stem_height - leave_height / 2;
	int const y_lim_down = Ypos - stem_height + leave_height / 2;
	int num_leaves = 1000;
	int red;
	int green;
	int blue;
	set_pen_width(10);

	while (num_leaves > 0)
	{
		red = random_in_range(35, 100);
		green = random_in_range(150, 250);
		blue = random_in_range(10, 50);
		set_pen_color_int(red, green, blue);
		move_to(random_in_range(X_lim_left, X_lim_right), random_in_range(y_lim_up, y_lim_down));
		draw_point();
		num_leaves = num_leaves - 1;
	}
}

void draw_trees(int const Xpos, int const Ypos)
{	
	int num_trees = random_in_range(0, 5); 
	int Xrange;
	while (num_trees > 0)
	{
		Xrange = random_in_range(80, 900);
		draw_tree(Xrange, Ypos);
		num_trees = num_trees - 1;
	}
}

void draw_building(int const Xpos, int const Ypos, int const width)
{
	if (width > 150) 
	{
		int const height = random_in_range(100, 620);
		building_condition(Xpos, Ypos, width, height);
	}
	else
	{   
		int const height = random_in_range(250, 620);
		building_condition(Xpos, Ypos, width, height);
	}
}

void city_scene(int const Xpos,int const Ypos)
{ 
	int separate = random_in_range(55, 70);
	int separator = separate;

	int width = random_in_range(25, 350);
	int Xdist = 1000-separate- Xpos;
	while (Xdist > width)
	{
		draw_building(Xpos + separator, Ypos, width);
		separator = separator + width+separate;
		Xdist = Xdist - width - separate;
		if (Xdist < 250) width = random_in_range(25, 120);
		else width = random_in_range(25, 300);
		separate = random_in_range(30, 70);
	}
}

void main()
{
	while(true)
	{
		cout << "Enter an hour (0-23): " << "\n";
		int time;
		int road_height = random_in_range(10, 40);
		cin >> time;
		make_window(1000, 720);
		sky(time);
		sun_and_moon(time);
		draw_clouds(time);
		draw_grass(time);
		city_scene(0,720 - road_height);
		draw_road(time, road_height);
		draw_trees(0,720 - road_height);
	}
}



