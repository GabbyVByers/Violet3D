
/*
	main.cpp
*/

#include "Window.h"
#include "Demo.h"

#include "Map.h"

int main() {
	
    Map::init_planets();
    
	Vi::demo_application();

	return 0;
}

