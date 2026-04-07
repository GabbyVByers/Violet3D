
#pragma once
#include <vector>
#include <string>


struct Planet {
    std::string name;
    double radius;
    double mass;
    double inclination;
    std::vector<Planet> moons;
};

namespace dontmatter {
    static std::vector<Planet> planets = {
        {
            .name = "Mercury",
            .radius = 3.3,
            .mass = 1.0,
            .inclination = 5.0
            {
                
            }
        }
    };
}

