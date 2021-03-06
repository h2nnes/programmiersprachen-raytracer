// -----------------------------------------------------------------------------
// Copyright  : (C) 2014-2017 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
//
// Renderer
// -----------------------------------------------------------------------------

#ifndef BUW_RENDERER_HPP
#define BUW_RENDERER_HPP

#include "color.hpp"
#include "pixel.hpp"
#include "shape.hpp"
#include "ray.hpp"
#include "scene.hpp"
#include "ppmwriter.hpp"
#include <string>
#include <limits>
#include <vector>
#include <glm/glm.hpp>

class Renderer
{
public:
  Renderer(unsigned w, unsigned h, std::string const& file, Scene const& s);

  void render();
  void write(Pixel const& p);
  Color trace_ray(Ray const& ray) const;

  inline std::vector<Color> const& color_buffer() const
  {
    return color_buffer_;
  }

  Color shade(Shape const& obj, Ray const& ray, HitPoint const& hp) const;

  Color reflect(Ray const& ray, HitPoint const& hp, glm::vec3 const& normal) const;

  Color refract(Ray const& ray, HitPoint const& hp, glm::vec3 const& normal) const;

  void set_new_scene(Scene const& s);
  void set_filename(std::string const& fname);

  Color apply_anti_aliasing(unsigned pixel_pos_x, unsigned pixel_pos_y, unsigned num_of_subpixel,
                            float cam_distance, glm::mat4 const& cam_transform) const;


private:
  unsigned width_;
  unsigned height_;
  std::vector<Color> color_buffer_;
  std::string filename_;
  PpmWriter ppm_;
  Scene scene_;
};

#endif // #ifndef BUW_RENDERER_HPP
