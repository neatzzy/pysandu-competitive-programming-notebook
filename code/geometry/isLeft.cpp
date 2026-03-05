// Check if a point is to the left of a segment defined by two points
bool isLeft(const Point& p, const Point& v1, const Point& v2) {
    return (v2.x - v1.x) * (p.y - v1.y) - (v2.y - v1.y) * (p.x - v1.x) > 0;
}
