#include"polygon.h"

namespace AyxCppTest
{

Polygon::Polygon(std::initializer_list<Point> temp)
{
    pts=temp;
}


bool Polygon::Contains(const Point &pt)
{
    int nvert = pts.size();
    bool c = false;

    for(int i = 0, j = nvert - 1; i < nvert; j = i++)
    {
        if( ( (pts[i].m_y >= pt.m_y ) != (pts[j].m_y >= pt.m_y) ) &&
                (pt.m_x <= (pts[j].m_x - pts[i].m_x) * (pt.m_y - pts[i].m_y) / (pts[j].m_y - pts[i].m_y) + pts[i].m_x)
                )
            c = !c;
    }

    return c;
}
}
