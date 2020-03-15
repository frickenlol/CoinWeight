//
//  x11graphics.hpp
//  CoinWeight
//
//  Created by Gian Cordana Sanjaya on 2020-02-28.
//  Copyright © 2020 -. All rights reserved.
//

#ifndef graphics_hpp
#define graphics_hpp

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <string>
#include <vector>

class X11Graphics {
	Display *display;
	Window window;
	int screen;
	GC gc;
    std::vector<unsigned long> colors;
	
public:
	X11Graphics();
	~X11Graphics();
	enum {White=0, Black, Red, Green, Blue, Gold, Max = Gold};
	static const int defaultFGColor = White;
	
	void drawString(int x_pos, int y_pos, const std::string &msg);
	void fillCircle(int x_pos, int y_pos, unsigned int radius, int color);
};

class X11GraphicsFailure{};

#endif
