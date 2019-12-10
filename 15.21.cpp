#include <cmath>
#include <string>

static const double PI =
    3.1415926536;  // TODO: substitute double with float_type?

class Shape {
 public:
  using float_type = double;
  virtual std::string shape_name() const = 0;
  virtual ~Shape() {}
};

class Shape2D : public Shape {
 public:
  Shape2D() = default;
  Shape2D(float_type center_x, float_type center_y)
      : center_x_(center_x), center_y_(center_y) {}

  virtual float_type area() const = 0;
  virtual float_type circumference() const = 0;

  virtual ~Shape2D() override {}

 private:
  float_type center_x_ = 0.;
  float_type center_y_ = 0.;
};

class Shape3D : public Shape {
 public:
  Shape3D() = default;
  Shape3D(float_type center_x, float_type center_y, float_type center_z)
      : center_x_(center_x), center_y_(center_y), center_z_(center_z) {}

  virtual float_type volume() const = 0;
  virtual float_type surface_area() const = 0;

  virtual ~Shape3D() override {}

 private:
  float_type center_x_ = 0.;
  float_type center_y_ = 0.;
  float_type center_z_ = 0.;
};

class Box : public Shape3D {
 public:
  Box() = default;
  explicit Box(float_type edge_length)
      : Box(edge_length, edge_length, edge_length) {}
  Box(float_type length_x, float_type length_y, float_type length_z)
      : length_x_(length_x), length_y_(length_y), length_z_(length_z) {}
  Box(float_type edge_length,
      float_type center_x,
      float_type center_y,
      float_type center_z)
      : Box(edge_length,
            edge_length,
            edge_length,
            center_x,
            center_y,
            center_z) {}
  Box(float_type length_x,
      float_type length_y,
      float_type length_z,
      float_type center_x,
      float_type center_y,
      float_type center_z)
      : Shape3D(center_x, center_y, center_z),
        length_x_(length_x),
        length_y_(length_y),
        length_z_(length_z) {}

  std::string shape_name() const override { return "Box"; }
  float_type volume() const override {
    return length_x_ * length_y_ * length_z_;
  }
  float_type surface_area() const override {
    return 2. * (length_x_ * length_y_ + length_y_ * length_z_ +
                 length_z_ * length_x_);
  }

 private:
  float_type length_x_ = 1.;
  float_type length_y_ = 1.;
  float_type length_z_ = 1.;
};

class Circle : public Shape2D {
 public:
  Circle() = default;
  Circle(float_type radius) : radius_(radius) {}
  Circle(float_type radius, float_type center_x, float_type center_y)
      : Shape2D(center_x, center_y), radius_(radius) {}

  std::string shape_name() const override { return "Circle"; }
  float_type area() const override { return PI * radius_ * radius_; }
  float_type circumference() const override { return 2. * PI * radius_; }

 private:
  float_type radius_ = 1.;
};

class Sphere : public Shape3D {
 public:
  Sphere() = default;
  Sphere(float_type radius) : radius_(radius) {}
  Sphere(float_type radius,
         float_type center_x,
         float_type center_y,
         float_type center_z)
      : Shape3D(center_x, center_y, center_z), radius_(radius) {}

  std::string shape_name() const override { return "Sphere"; }
  float_type volume() const override {
    return 4. / 3. * PI * radius_ * radius_ * radius_;
  }
  float_type surface_area() const override {
    return 4. * PI * radius_ * radius_;
  }

 private:
  float_type radius_ = 1.;
};

class Cone : public Shape3D {
 public:
  Cone() = default;
  Cone(float_type radius, float_type height) : radius_(radius), height_(height) {}
  Cone(float_type radius,
       float_type height,
       float_type center_x,
       float_type center_y,
       float_type center_z)
      : Shape3D(center_x, center_y, center_z),
        radius_(radius),
        height_(height) {}

  std::string shape_name() const override { return "Cone"; }
  float_type volume() const override {
    return PI * radius_ * radius_ * height_ / 3.;
  }
  float_type surface_area() const override {
    return PI * radius_ *
           (radius_ + std::sqrt(height_ * height_ + radius_ * radius_));
  }

 private:
  float_type radius_ = 1.;
  float_type height_ = 1.;
};
