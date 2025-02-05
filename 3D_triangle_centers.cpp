#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Point {
    double x, y, z;
};

// Vector operations
Point operator-(Point p1, Point p2) { return {p1.x - p2.x, p1.y - p2.y, p1.z - p2.z}; }
Point operator+(Point p1, Point p2) { return {p1.x + p2.x, p1.y + p2.y, p1.z + p2.z}; }

Point operator*(Point p1, Point p2) { return {p1.y*p2.z - p1.z*p2.y, p1.z*p2.x - p1.x*p2.z, p1.x*p2.y - p1.y*p2.x}; }

Point operator*(Point p, double t) { return {p.x*t, p.y*t, p.z*t}; }
Point operator/(Point p, double t) { return {p.x/t, p.y/t, p.z/t}; }

double distance(Point p1, Point p2) {
    double dx = p1.x - p2.x, dy = p1.y - p2.y, dz = p1.z - p2.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

// Computes the intersection of two lines using Cramer's rule
Point intersection(Point P, Point Q, Point l1, Point l2) {
    double det_A = l1.x * (Q.y - P.y) - l1.y * (Q.x - P.x);
    double det_B = l1.y * l2.x - l1.x * l2.y;
    double k = det_A / det_B;
    return Q + l2 * k;
}

int main() {
    Point A, B, C;
    cout << "Enter coordinates for three points (A, B, C):\n";
    cin >> A.x >> A.y >> A.z;
    cin >> B.x >> B.y >> B.z;
    cin >> C.x >> C.y >> C.z;
    
    // Compute normal vector
    Point AB = B - A, AC = C - A;
    Point n = AB * AC;
    if (n.x == 0 && n.y == 0 && n.z == 0) {
        cout << "The points are collinear, no solution.";
        return 0;
    }
    
    // Compute centroid
    Point G = (A + B + C) / 3;
    cout << "Centroid G = (" << G.x << ", " << G.y << ", " << G.z << ")\n";
    
    // Compute incenter
    double a = distance(B, C), b = distance(C, A), c = distance(A, B);
    Point I = (A * a + B * b + C * c) / (a + b + c);
    cout << "Incenter I = (" << I.x << ", " << I.y << ", " << I.z << ")\n";
    
    // Compute orthocenter
    Point l1 = AB * n, l2 = AC * n;
    Point H = intersection(C, B, l1, l2);
    cout << "Orthocenter H = (" << H.x << ", " << H.y << ", " << H.z << ")\n";
    
    // Compute circumcenter
    Point P = (A + B) / 2, Q = (A + C) / 2;
    Point O = intersection(P, Q, l1, l2);
    cout << "Circumcenter O = (" << O.x << ", " << O.y << ", " << O.z << ")\n";
    
    return 0;
}
