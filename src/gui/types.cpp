#include <sstream>
#include "gui/types.hpp"


Gui::Color &Gui::Color::operator+=(std::vector<u_int8_t> v)
{
    this->argb.r = (this->argb.r <= 255 - v[0] ? this->argb.r + v[0] : 255);
    this->argb.g = (this->argb.g <= 255 - v[1] ? this->argb.g + v[1] : 255);
    this->argb.b = (this->argb.b <= 255 - v[2] ? this->argb.b + v[2] : 255);
    this->argb.a = (this->argb.a <= 255 - v[3] ? this->argb.a + v[3] : 255);

    return *this;
}

Gui::Color &Gui::Color::operator-=(std::vector<u_int8_t> v)
{
    this->argb.r = (this->argb.r >= v[0] ? this->argb.r - v[0] : 0);
    this->argb.g = (this->argb.g >= v[1] ? this->argb.g - v[1] : 0);
    this->argb.b = (this->argb.b >= v[2] ? this->argb.b - v[2] : 0);
    this->argb.a = (this->argb.a >= v[3] ? this->argb.a - v[3] : 0);
    return *this;
}
void Gui::Color::copyFrom(std::vector<u_int8_t> v)
{
    this->argb.r = v[0];
    this->argb.g = v[1];
    this->argb.b = v[2];
    this->argb.a = v[3];
}

bool Gui::Area::contains(Gui::Point p)
{
    return this->rect.x <= p.x &&
           this->rect.y <= p.y &&
           (this->rect.x + this->rect.w) >= p.x &&
           (this->rect.y + this->rect.h) >= p.y;
}
