#include "spatial.h"
#include <cmath>
#include <thread>

namespace AyxCppTest
{
// used for detecting memory leaks
int dbg_count_Points{ 0 };

Point::Point(double x, double y)
    : m_x(x)
    , m_y(y)
{
    ++dbg_count_Points;
}
Point::Point(const Point &pt)
    : m_x(pt.m_x)
    , m_y(pt.m_y)
{
    ++dbg_count_Points;
}
Point::~Point()
{
    --dbg_count_Points;
}
/*static*/ bool Point::DbgHasLeaks()
{
    return dbg_count_Points != 0;
}

Circle::Circle(Point pt, double radius)
    : m_pt(pt), m_radius(radius)
{}
bool Circle::Contains(const Point &pt)
{
    double diffX = pt.m_x - m_pt.m_x;
    double diffY = pt.m_y - m_pt.m_y;
    double dist = sqrt(diffX*diffX + diffY*diffY);
    return dist < m_radius;
}

Rectangle::Rectangle(Point topLeft, Point bottomRight)
    : m_TopLeft(topLeft)
    , m_BottomRight(bottomRight)
{

}
bool Rectangle::Contains(const Point &pt)
{
    if(pt.m_x==(m_TopLeft.m_x+m_BottomRight.m_x)/2 && pt.m_y==(m_TopLeft.m_y+m_BottomRight.m_y)/2)
        return true;
    return pt.m_x >= m_TopLeft.m_x &&
            pt.m_y <= m_TopLeft.m_y &&
            pt.m_x <= m_BottomRight.m_x &&
            pt.m_y >= m_BottomRight.m_y;
}
double Rectangle::Size()
{
    // artificially slow for exercise 4.  Please don't remove
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    return (m_TopLeft.m_x-m_BottomRight.m_x)*(m_TopLeft.m_y - m_BottomRight.m_y);
}
}
