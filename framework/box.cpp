#include "box.hpp"

Box::Box(glm::vec3 const& min, glm::vec3 const& max) :
        Shape("Box",Color{0.2f,0.2f,0.2f}),
        min_{min},
        max_{max} {}

Box::Box(std::string const& str, std::shared_ptr<Material> material, glm::vec3 const& min, glm::vec3 const& max) :
        Shape(str,material),
        min_{min},
        max_{max} {}

float Box::area() const {
  float length = max_.x - min_.x;
  float width = max_.y - min_.y;
  float height = max_.z - min_.z;
  float area = 2 * ( (length * width) + (length * height) + (width * height) );
  return area;
}

float Box::volume() const {
  float length = max_.x - min_.x;
  float width = max_.y - min_.y;
  float height = max_.z - min_.z;
  float volume = length * width * height;
  return volume;
}

std::ostream& Box::print(std::ostream& os) const {
  Shape::print(os);
  os << "min: {" << min_.x << ", " << min_.y << ", " << min_.z << "}" << std::endl;
  os << "max: {" << max_.x << ", " << max_.y << ", " << max_.z << "}" << std::endl;
  return os;
}

HitPoint Box::intersect(Ray const& ray) const {
  return HitPoint;
}