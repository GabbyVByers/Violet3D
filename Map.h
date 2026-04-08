
#pragma once
#include "Log.h"
#include "Types.h"
#include <vector>
#include <fstream>

struct Planet {
    std::string name;
    Vi::Vec3d in_pos;
    Vi::Vec3d in_vel;
    std::vector<Planet> moons;
};

class Map {
public:

    static void init_planets() {
        std::ifstream file = std::ifstream("JPL/planets_orbital.txt");
        Vi::Log::assert_concern(file.is_open());

        std::stringstream ss;
        ss << file.rdbuf();

        std::string token;
        bool header = true;
        while (ss >> token) {
            if (token == "PLANETS")
                header = false;
            if (header)
                continue;
            if (token == "PLANETS") {
                header = false;
                while (ss >> token) {
                    if (token == "MOONS")
                        break;
                    Planet planet;
                    planet.name = token;
                    ss >> token; Vi::Log::assert_concern(token == "px");
                    ss >> token; planet.in_pos.x = std::stod(token);
                    ss >> token; Vi::Log::assert_concern(token == "py");
                    ss >> token; planet.in_pos.y = std::stod(token);
                    ss >> token; Vi::Log::assert_concern(token == "pz");
                    ss >> token; planet.in_pos.z = std::stod(token);
                    ss >> token; Vi::Log::assert_concern(token == "vx");
                    ss >> token; planet.in_vel.x = std::stod(token);
                    ss >> token; Vi::Log::assert_concern(token == "vy");
                    ss >> token; planet.in_vel.y = std::stod(token);
                    ss >> token; Vi::Log::assert_concern(token == "vz");
                    ss >> token; planet.in_vel.z = std::stod(token);
                    planets.push_back(planet);
                }
            }
            Vi::Log::assert_concern(token == "MOONS");
            while (ss >> token) {
                Planet* parent_planet = nullptr;
                for (size_t i = 0; i < planets.size(); i++) {
                    Planet& planet = planets[i];
                    if (planet.name == token) {
                        parent_planet = &planets[i];
                    }
                }
                
                if (parent_planet == nullptr) {
                    Vi::Log::assert_concern(false, Vi::GENERIC, "parent_planet is nullptr");
                    break;
                }

                while (ss >> token) {
                    if (token == "END")
                        break;
                    Planet moon;
                    moon.name = token;
                    ss >> token; Vi::Log::assert_concern(token == "px");
                    ss >> token; moon.in_pos.x = std::stod(token);
                    ss >> token; Vi::Log::assert_concern(token == "py");
                    ss >> token; moon.in_pos.y = std::stod(token);
                    ss >> token; Vi::Log::assert_concern(token == "pz");
                    ss >> token; moon.in_pos.z = std::stod(token);
                    ss >> token; Vi::Log::assert_concern(token == "vx");
                    ss >> token; moon.in_vel.x = std::stod(token);
                    ss >> token; Vi::Log::assert_concern(token == "vy");
                    ss >> token; moon.in_vel.y = std::stod(token);
                    ss >> token; Vi::Log::assert_concern(token == "vz");
                    ss >> token; moon.in_vel.z = std::stod(token);
                    parent_planet->moons.push_back(moon);
                }
            }
        }

        for (const Planet& planet : planets) {
            std::cout << planet.name << "\n";
            std::cout << "pos: x=" << planet.in_pos.x << " y=" << planet.in_pos.y << " z=" << planet.in_pos.z << "\n";
            std::cout << "vel: x=" << planet.in_vel.x << " y=" << planet.in_vel.y << " z=" << planet.in_vel.z << "\n";
            std::cout << "Num Moons: " << planet.moons.size() << "\n\n";
        }
    }


private:

    inline static std::vector<Planet> planets = {};




    Map() = delete;
    Map(const Map& other) = delete;
    Map& operator = (Map&& other) = delete;
};

