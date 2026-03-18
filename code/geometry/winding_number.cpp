// Check if a point is inside a polygon using the winding number algorithm

bool isInsidePolygon(const Point& p, const vector<Point>& polygon) {
    int windingNumber = 0;
    int n = polygon.size();

    for (int i = 0; i < n; i++) {
        const Point& v1 = polygon[i];
        const Point& v2 = polygon[(i + 1) % n];

        if (v1.y <= p.y) {
            if (v2.y > p.y && isLeft(p, v1, v2)) {
                ++windingNumber;
            }
        } else {
            if (v2.y <= p.y && !isLeft(p, v1, v2)) {
                --windingNumber;
            }
        }
    }

    return windingNumber != 0;
}