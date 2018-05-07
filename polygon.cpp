#include"polygon.h"

namespace AyxCppTest
{

Polygon::Polygon(std::initializer_list<Point> temp)
{
    pts=temp;
}


bool Polygon::Contains(const Point &pt)
{

    return true;
}

void Polygon::X_min()
{
    border=pts[0].m_x;
    for(int i=0; i<pts.size();++i)
    {
        if(pts[i+1].m_x<pts[i])
        {

        }
    }
}
}
