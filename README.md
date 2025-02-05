# 3D Triangle Centers Calculator

## Overview
This program calculates key geometric properties of a triangle in 3D space, including its centroid, incenter, orthocenter, and circumcenter. Given three points in 3D space, it performs vector operations to compute these properties efficiently. The complexity of 3D computations compared to 2D lies in the additional dimension, which requires more intricate calculations such as cross products and line intersections.

## Features
- **Vector Operations**: Implemented using a struct to represent points and overloaded operators for arithmetic and cross-product calculations.
- **Geometric Properties**: Computes centroid, incenter, orthocenter, and circumcenter.
- **Line Intersections**: Uses Cramer's rule to find the intersection of two lines in 3D space.

## Lessons Learned
Through this project, I deepened my understanding of working with **structs** in C++ to represent vectors and perform operations on them. Additionally, I gained valuable insights into the challenges of geometric calculations in 3D compared to 2D, particularly when dealing with vector operations and line intersections.

## How to Use
1. Compile the program using a C++ compiler (e.g., g++):
   ```sh
   g++ -o centers_calculator 3D_triangle_centers.cpp -lm
   ```
2. Run the program:
   ```sh
   ./centers_calculator
   ```
3. Input the coordinates of three points in 3D space.
4. The program outputs the computed geometric properties.

## Future Improvements
- Implement additional geometric calculations, such as circumradius and Euler line.
- Improve numerical stability for special cases, such as collinear points.

## License
This project is open-source and available under the MIT License.

