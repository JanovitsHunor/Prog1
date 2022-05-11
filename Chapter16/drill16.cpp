#include "Graph.h"
#include "GUI.h"
#include "Simple_window.h"
#include "Window.h"

using namespace Graph_lib;

struct Lines_window : Window {
	Lines_window(Point xy, int w, int h, const string& title);
private:
    // 4. feladathoz szükséges
    Open_polyline lines;

    // widgets
    Button next_button; // következő koordináta
    Button quit_button;	// kilépés gomb
    In_box next_x;
    In_box next_y;
    Out_box xy_out;

    Menu color_menu; // színek
    Button comenu_button;
    Menu style_menu; // stílusok
    Button stmenu_button;

    void change(Color c) { lines.set_color(c); }
	void change_style(Line_style s) { lines.set_style(s); }

	void hide_comenu() { color_menu.hide(); comenu_button.show(); }
	void hide_stmenu() { style_menu.hide(); stmenu_button.show(); }

	// visszahívással előidézett műveletek:
	void red_pressed() { change(Color::red); hide_comenu(); }
	void blue_pressed() { change(Color::blue); hide_comenu(); }
	void black_pressed() { change(Color::black); hide_comenu(); }

	void comenu_pressed() { comenu_button.hide(); color_menu.show(); }
	

	void dot_pressed() { change_style(Line_style::dot); hide_stmenu(); }
	void dash_pressed() { change_style(Line_style::dash); hide_stmenu(); }
	void solid_pressed() { change_style(Line_style::solid); hide_stmenu(); }

	void stmenu_pressed() { stmenu_button.hide(); style_menu.show(); }

	void next();
	void quit();

	// az alábbiak a callback (visszahívott) függvények
	// A visszahívott függvény egy olyan function, amely egy argumentumként szerepel egy másik függvényben.
	static void cb_red(Address,Address);
    static void cb_blue(Address,Address);
    static void cb_black(Address,Address);
    static void cb_comenu(Address,Address);
    static void cb_solid(Address,Address);
    static void cb_dash(Address,Address);
    static void cb_dot(Address,Address);
    static void cb_stmenu(Address,Address);
    static void cb_next(Address,Address);
    static void cb_quit(Address,Address);

};



// kézreszabott GUI létrehozása:
Lines_window::Lines_window(Point xy, int w, int h, const string& title)		
	:Window{xy,w,h,title},
	next_button{Point{x_max()-150,0}, 70, 20, "Next point",
		[](Address, Address pw) {reference_to<Lines_window>(pw).next();}},
	quit_button{Point{x_max()-70,0}, 70, 20, "Quit",
		[](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},
	next_x{Point{x_max()-310,0}, 50, 20, "next x:"},
	next_y{Point{x_max()-210,0}, 50, 20, "next y:"},
	xy_out{Point{100,0}, 100, 20, "current (x,y):"},
	color_menu{Point{x_max()-70,40},70,20,Menu::vertical,"color"},
	comenu_button{Point{x_max()-80,30}, 80, 20, "color menu",
		[](Address, Address pw) {reference_to<Lines_window>(pw).comenu_pressed();}},
	style_menu{Point{x_max()-70,115},70,20,Menu::vertical,"style"},
	stmenu_button{Point{x_max()-80,105}, 80, 20, "style menu",
		[](Address, Address pw) {reference_to<Lines_window>(pw).stmenu_pressed();}}
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    xy_out.put("no point");

    color_menu.attach(new Button(Point(0,0),0,0,"red",cb_red));
    color_menu.attach(new Button(Point(0,0),0,0,"blue",cb_blue));
    color_menu.attach(new Button(Point(0,0),0,0,"black",cb_black));
    attach(color_menu);
    color_menu.hide();
    attach(comenu_button);

    style_menu.attach(new Button(Point(0,0),0,0,"solid",cb_solid));
    style_menu.attach(new Button(Point(0,0),0,0,"dashed",cb_dash));
    style_menu.attach(new Button(Point(0,0),0,0,"dotted",cb_dot));
    attach(style_menu);
    style_menu.hide();
    attach(stmenu_button);
    attach(lines);
}

void Lines_window::quit(){ // kilépés
	hide(); 
}

void Lines_window::cb_next(Address, Address pw)
{
    reference_to<Lines_window>(pw).next();
}

void Lines_window::cb_quit(Address, Address pw)
{
    reference_to<Lines_window>(pw).quit();
}


void Lines_window::next(){ // következő ablak
	int x = next_x.get_int();
	int y = next_y.get_int();
	lines.add(Point{x,y});

	ostringstream ss;
	ss << '(' << x << ',' << y << ')';
	xy_out.put(ss.str());
	redraw();
}



void Lines_window::cb_red(Address, Address pw)
{
    reference_to<Lines_window>(pw).red_pressed();
}

void Lines_window::cb_blue(Address, Address pw)
{
    reference_to<Lines_window>(pw).blue_pressed();
}

void Lines_window::cb_black(Address, Address pw)
{
    reference_to<Lines_window>(pw).black_pressed();
}

void Lines_window::cb_comenu(Address, Address pw)
{
    reference_to<Lines_window>(pw).comenu_pressed();
}

void Lines_window::cb_solid(Address, Address pw)
{
    reference_to<Lines_window>(pw).solid_pressed();
}

void Lines_window::cb_dash(Address, Address pw)
{
    reference_to<Lines_window>(pw).dash_pressed();
}

void Lines_window::cb_dot(Address, Address pw)
{
    reference_to<Lines_window>(pw).dot_pressed();
}

void Lines_window::cb_stmenu(Address, Address pw)
{
    reference_to<Lines_window>(pw).stmenu_pressed();
}




int main(){
try{
	Lines_window win {Point{100,100},600,400,"lines"};
	return gui_main();
}
catch(exception& e){
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...){
	cerr << "Some exception\n";
	return 2;
}	

}
