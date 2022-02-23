 /* g++ -w -Wall -std=c++14 ./GUI/Graph.cpp ./GUI/Window.cpp ./GUI/GUI.cpp ./GUI/Simple_window.cpp drill12.cpp `fltk-config --ldflags --use-images` -o a2.out */

#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main() {
	
	try {
	
	Point t1 {100, 100}; // Pont koordinátája x, y tengelyen (balról rajzol)!
	Simple_window win {t1, 600, 400, "My Window"}; // Ablak létrehozása!
	win.wait_for_button(); // Gomb létrehozása
	
	Axis xa(Axis::x, Point{20,300}, 280, 10, "X Axis"); // x tengelyen mozogva a 20. pixel lesz a kezdőpont, ami tart egészen 300-ig
					// a "280" a hossza, a 10 pedig a darabszámot/behúzást a tengelyen jelöli!
	win.attach(xa); // Tengely összefűzése az ablakra!
	
	win.set_label("X Axis"); // Tengely elnevezése!
	win.wait_for_button();
	
	Axis ya(Axis::y, Point{20,300}, 280, 10, "Y Axis");
	ya.set_color(Color::cyan); // set_color - színezés
	ya.label.set_color(Color::dark_red);
	
	win.attach(ya);
	win.wait_for_button();
	
	Function sine(sin, 0, 100, Point(20,150), 1000, 50, 50); // 1000 - részletes kirajzolás; 50 - 50: skálázás
	
	win.attach(sine);
	win.set_label("Sine Function");
	win.wait_for_buttin();
	
	Polygon poly;
	poly.add(Point(300,200));
	poly.add(Point(350,100));
	poly.add(Point(400,200));
	
	poly.set_color(Color::red);
	poly.set_style(Line_style::dash); // set_style = stílus megadása
	
	win.attach(poly);
	win.set_label("Polygon");
	win.wait_for_button();
	
	Rectangle r(Point(200,200), 100, 50); // szabályos téglalap
	win.attach(r);
	win.set_label("Valid Rectangle");
	win.wait_for_button();
	
	Closed_polyline poly_rect; // szintaktikailag nem ellenőrizhető alakzat
	poly.rect.add(Point(100,50));
	poly.rect.add(Point(200,50));
	poly.rect.add(Point(200,100));
	poly.rect.add(Point(100,100));
	poly.rect.add(Point(50,75));
	
	win.attach(poly_rect);
	win.set_label("Invalid Rectangle");
	win.wait_for_button();
	
	r.set_fill_color(Color::yellow); // set_fill_color = alakzat kitöltése megadott színnel!
	poly.rect.set_style(Line_style::(Line_style::dash, 2));
	poly.rect.set_fill_color(Color:green);
	
	win.set_label("Filled Rectangle");
	win.wait_for_button();
	
	Text t(Point(150,150), "Hello, graphical world!");
	win.attach(t);
	win.set_label("Creating a Text");
	win.wait_for_button();

	t.set_font(Font::times_bold); // betűtípus szerkesztése
	t.set_font_size(20); // betűméret beállítása
	win.set_label("Text");
	win.wait_for_button();

	Image ii{ Point(100,50), "badge.jpg" }; // 400x400 pixel nagyságú JPG
	win.attach(ii);
	win.set_label("Adding an Image");
	win.wait_for_button();

	ii.move(100, 200);
	win.set_label("Moving the Image");
	win.wait_for_button();

	Circe c {Point(100,200), 50 };
	Ellipse e { Point(100,200), 75, 25 };
	e.set_color(Color::dark_red);
	Mark m { Point(100,200), 'x' };

	ostringstream oss;
	oss << "Screen size: " << x_max() << "*" << y_max()
		<< "; Window size: " << win.x_max() << "*" << win.y_max();
	Test sizes { Point(100,20), oss.str() };

	Image cal { Point(225,225), "snow_cpp.gif" }; // 320*246 pixel nagyságú GIF
	cal.set_mask (Point(40, 40), 200, 150); // a kép középső részét jelzi ki

	win.attach(c);
	win.attach(e);
	win.attach(m);

	win.attach(sizes);
	win.attach(cal);
	win.set_label("Adding some Extras");
	win.wait_for_button();
	
	} catch(exceptionn& e) {
		cerr << "Exception: " << e.what() << '\n';
		return 1;
		
	} catch (...) {
		cerr << "ERROR!\n";
		return 2;
	}

}
