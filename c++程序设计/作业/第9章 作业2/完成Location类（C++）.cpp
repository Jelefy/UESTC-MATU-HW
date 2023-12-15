#include "Location.h"

Location &Location::operator +(Location &offset)
{
this->x += offset.x;
this->y += offset.y;
return *this;
}

Location &Location::operator-(Location &offset)
{
this->x -= offset.x;
this->y -= offset.y;
return *this;
}
