
/*
	main.cpp
*/

#include "Window.h"
#include "Demo.h"

struct Planet {
    double px = 0.0;
    double py = 0.0;
    double pz = 0.0;
    double vx = 0.0;
    double vy = 0.0;
    double vz = 0.0;
};



int main() {
	
    std::vector<Planet> planets;

    std::ifstream file = std::ifstream("planets.txt");
    if (!file) {
        std::cerr << "you forgor the file bozo\n";
    }

    std::stringstream sstream;
    sstream << file.rdbuf();

    std::string token;
    while (sstream >> token) {
        std::cout << token << std::endl;
    }

    Vi::Window window = Vi::Window("Application", 1920, 1080);

    while (window.is_open()) {
        window.poll_events();
        window.clear(Vi::Color::blue());
        window.display();
    }

	return 0;
}

