
#include "library.h"

void draw_star(int x, int y, int length)
{
	move_to(x,y);
	set_pen_color(color::black);
	set_pen_width(3);
	start_shape();
	turn_right_by_degrees(18);
	draw_distance(length);
	note_position();
	turn_left_by_degrees(72);
	draw_distance(length);
	note_position();
	turn_right_by_degrees(144);
	draw_distance(length);
	note_position();
	turn_left_by_degrees(72);
	draw_distance(length);
	note_position();
	turn_right_by_degrees(144);
	draw_distance(length);
	note_position();
	turn_left_by_degrees(72);
	draw_distance(length);
	note_position();
	turn_right_by_degrees(144);
	draw_distance(length);
	note_position();
	turn_left_by_degrees(72);
	draw_distance(length);
	note_position();
	turn_right_by_degrees(144);
	draw_distance(length);
	note_position();
	turn_left_by_degrees(72);
	draw_distance(length);
	note_position();
	set_pen_color(color::white);
	fill_shape();
	set_heading_degrees(0);
}

void draw_row_of_six_stars(const int x, const int y, const int distance)
{
	draw_star(x,y,10);
	draw_star(x + distance,y,10);
	draw_star(x + (2 * distance), y, 10);
	draw_star(x + (3 * distance), y, 10);
	draw_star(x + (4 * distance), y, 10);
	draw_star(x + (5 * distance), y, 10);
}

void draw_row_of_five_stars(const int x, const int y, const int distance) 
{
	draw_star(x,y,10);
	draw_star(x + distance, y, 10);
	draw_star(x + (2* distance), y, 10);
	draw_star(x + (2 * distance), y, 10);
	draw_star(x + (3 * distance), y, 10);
	draw_star(x + (4 * distance), y, 10);
}


void stripes( int x, int y, int stripe_count)
{
	int x_fill = 900;
	int y_fill = 36;
	if (stripe_count > 0)
	{
		fill_rectangle(x,y,x_fill,y_fill,200);
		y += 72;
		stripe_count -= 1;
		stripes(x,y,stripe_count);
	}
}
	
void main()
{
	make_window(900,468);
	stripes(0,0,8);
	set_pen_color(color::blue);
	fill_rectangle(0,0,360,252);
	set_pen_color(color::white);
	draw_row_of_six_stars(25,30,60);
	draw_row_of_five_stars(55,50,60);
	draw_row_of_six_stars(25,80,60);
	draw_row_of_five_stars(55,100,60);
	draw_row_of_six_stars(25,130,60);
	draw_row_of_five_stars(55,150,60);
	draw_row_of_six_stars(25,180,60);
	draw_row_of_five_stars(55,200,60);
	draw_row_of_six_stars(25,230,60);
}

