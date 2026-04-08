
/*
	main.cpp
*/

#include "Window.h"
#include "Demo.h"

#include "Map.h"

int main() {
	
    Map::init_planets();
    

    Vi::Window window = Vi::Window("Application", 1920, 1080);

    while (window.is_open()) {
        window.poll_events();
        window.clear(Vi::Color::blue());
        window.display();
    }

	return 0;
}

