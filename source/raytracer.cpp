#include "parser.hpp"
#include <renderer.hpp>
#include <window.hpp>

#include <GLFW/glfw3.h>
#include <thread>
#include <utility>
#include <cmath>

//now single threaded again
int main(int argc, char* argv[])
{
  unsigned const image_width = 800;
  unsigned const image_height = 600;
  std::string const filename = "./checkerboard.ppm";
  std::string t_sdf_filepath{"D:/Ernst des Lebens/Uni/Informatik/Semester 2/Programmiersprachen/�bung/Raytracer/materials.sdf"};
  std::string h_sdf_filepath{"D:/Nextcloud/Bauhaus Uni Weimar/SoSe_2021/Programmiersprachen/Belege/Beleg_6/materials.sdf"};

  Scene scene;
  SDFParser::parse_scene(h_sdf_filepath,scene);

  Renderer renderer{image_width, image_height, filename, scene};

  renderer.render();

  Window window{{image_width, image_height}};

  while (!window.should_close()) {
    if (window.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      window.close();
    }
    window.show(renderer.color_buffer());
  }

  return 0;
}
