#include "spatial.h"
#include <initializer_list>
#include <vector>

namespace AyxCppTest
{

class Polygon: public Area
{
private:
    std::vector<Point> pts;
    double border;
public:
    Polygon(std::initializer_list<Point> temp);
    bool Contains(const Point &pt);
};
}
