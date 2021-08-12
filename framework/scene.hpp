#ifndef SCENE_HPP
#define SCENE_HPP

#include "material.hpp"
#include "box.hpp"
#include "sphere.hpp"
#include "light.hpp"
#include "camera.hpp"
#include <map>
#include <sstream>


struct Scene {
    std::map<std::string,std::shared_ptr<Material>> material_cont;
    std::map<std::string,std::shared_ptr<Shape>> shape_cont;
    std::map<std::string,std::shared_ptr<Light>> light_cont;
    Color ambient = {0.2f,0.2f,0.2f};
    Color background_color = { 0.85f, 0.85f, 0.85f };
    Camera camera = {50.0f};
};

#endif // #ifndef SCENE_HPP