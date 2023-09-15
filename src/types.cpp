#include <sstream>
#include <types.hpp>

Point Point::operator+(const Point& other) {
    return Point {
        x + other.x,
        y + other.y
    };
}

Color &Color::operator+=(std::vector<u_int8_t> v)
{
    this->r = (this->r <= 255 - v[0] ? this->r + v[0] : 255);
    this->g = (this->g <= 255 - v[1] ? this->g + v[1] : 255);
    this->b = (this->b <= 255 - v[2] ? this->b + v[2] : 255);
    this->a = (this->a <= 255 - v[3] ? this->a + v[3] : 255);

    return *this;
}

Color &Color::operator-=(std::vector<u_int8_t> v)
{
    this->r = (this->r >= v[0] ? this->r - v[0] : 0);
    this->g = (this->g >= v[1] ? this->g - v[1] : 0);
    this->b = (this->b >= v[2] ? this->b - v[2] : 0);
    this->a = (this->a >= v[3] ? this->a - v[3] : 0);
    return *this;
}

bool Color::operator==(const Color& other) {
  return (this->r == other.r) && (this->g == other.g) && (this->b == other.b) && (this->a == other.a);
}

std::ostream& operator<<(std::ostream& out, const Color& c) {
  out << "[" << (uint32_t)c.r << "," << (uint32_t)c.g << "," << (uint32_t)c.b << "|" << (uint32_t)c.a << "]";
  return out;
}
void Color::copyFrom(std::vector<u_int8_t> v)
{
    this->r = v[0];
    this->g = v[1];
    this->b = v[2];
    this->a = v[3];
}

bool Area::contains(Point p)
{
    return this->x <= p.x &&
           this->y <= p.y &&
           (this->x + this->w) >= p.x &&
           (this->y + this->h) >= p.y;
}
