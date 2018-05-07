#include"polygon.h"

namespace AyxCppTest
{

Polygon::Polygon(std::initializer_list<Point> temp)
{
    pts=temp;
}


bool Polygon::Contains(const Point &pt)
{
    int counter=0;
    X_min();
    for(int i=pt.m_x;i>=border;++i)
    {
        if(pt.m_x==pts[i].m_x)
        {
            counter++;
        }
    }

    if(counter%2==0)
    {
        return true;
    }

    return false;
}

void Polygon::X_min()
{
    border=pts[0].m_x;
    for(int i=0; i<pts.size()-1;++i)
    {
        if(pts[i+1].m_x<pts[i].m_x)
        {
            border=pts[i+1].m_x;
        }
    }
}
}
