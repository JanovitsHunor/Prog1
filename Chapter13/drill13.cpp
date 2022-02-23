/* g++ -w -Wall -std=c++14 ./GUI/Graph.cpp ./GUI/Window.cpp ./GUI/GUI.cpp ./GUI/Simple_window.cpp drill13.cpp `fltk-config --ldflags --use-images` -o b2.out */

#include "Simple_window.h"
#include "Graph.h"

#include <stdio.h>
#include <string>
#include <iostream>

using namespace Graph_lib;

	double RNG() {
		std::random_device rd;	// véletlenszerû szám generálása a hardverrõl
		std::mt19937 eng(rd());	// véletlenszerû szám / seed hozzáadása az rng-hez (mersenne twister generator használata)
		std::uniform_int_distribution<> range(0, 7);	// meghatározni a hatáskörét

		return range(eng) * 100;	// véletlenszerû számok generálása
	}

int main()
{
	Simple_window win{ Point{100,0}, 800, 1000, "Chapter 13" };

	const double spaceSize = 100;
	const double gridSize = 800;

	Lines grid;
	for (double i = spaceSize; i < gridSize; i += spaceSize)
	{
		grid.add(Point{ i, 0 }, { Point(i, gridSize) });
		grid.add(Point{ 0, i }, { Point(gridSize, i) });
	}
	grid.set_color(Color::black);
	win.attach(grid);

	win.wait_for_button();

	// Egy téglalap létrehozása, majd visszakérése, aminek vannak alapértelmezett értékei a színvonalakhoz és kitöltéséhez.
	rect Rectangle(double x, double y, Color fillColour = Color::invisible, Color lineColour = Color::black)
	{
		rect r(Point{ x, y }, 100, 100);
		r.set_fill_color(fillColour);
		r.set_color(lineColour);
		return r;
	}
		// Piros téglalapok létrehozása
		vector<rect> v_rects;
		for (double i = 0; i < 800; i += 100)

			v_rects.push_back(makeRect(i, i, Color::red, Color::invisible));
		for (int i = 0; i < v_rects.size(); ++i)
			win.attach(v_rects[i]);
			win.wait_for_button();

		// 3 kép beszúrása
			Image i1 { Point{0, 300}, "gif.gif" }; 
			Image i2 { Point{300, 0}, "gif.gif" };
			Image i3 { Point{600, 300}, "gif.gif" };

			win.attach(i1);
			win.attach(i2);
			win.attach(i3);
	}

		// A kép, ami véletlenszerûen ugrál.
			double rngX = RNG()
			double rngY = RNG();
			Image i4{ Point{rngX, rngY}, "kep.jpg" };
			win.attach(i4);

			while (win.wait_for_button()) {
				rngX = RNG();
				rngY = RNG();
				i4.changePoint(rngX, rngY);
	}
}