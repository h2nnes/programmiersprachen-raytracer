#include "application.hpp"
#include "parser.hpp"

Application::Application(Renderer const& renderer) :
        renderer_{renderer} {}


void Application::createCameraRotAnim(unsigned num_frames) {
  float degree_per_frame = 360.0f / num_frames;

  // create SDF file for each frame
  for (unsigned current_frame = 1; current_frame <= num_frames; ++current_frame) {
    //SDFToolbox::write_scene
    SDFParser::write_scene(current_frame,"scene.sdf",degree_per_frame);
    Scene new_scene;
    SDFParser::parse_scene("D:/Nextcloud/Bauhaus Uni Weimar/SoSe_2021/Programmiersprachen/Belege/Beleg_6/materials.sdf",
                           new_scene);
    renderer_.set_new_scene(new_scene);
    std::string filename = std::string("../../frame_") + std::to_string(current_frame) + ".ppm";
    renderer_.set_filename(filename);
    renderer_.render();
  }
}