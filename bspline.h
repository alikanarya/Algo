/*********************************************************************

 Simple b-spline curve algorithm

 Copyright 1994 by Keith Vertanen (vertankd@cda.mrs.umn.edu)

 Released to the public domain (your mileage may vary)

**********************************************************************/

#include <stdlib.h>

#ifndef BSPLINE
#define BSPLINE

struct point {
  double x;
  double y;
  double z;
};

void compute_intervals(int *u, int n, int t);
double blend(int k, int t, int *u, double v);
void compute_point(int *u, int n, int t, double v, point *control, point *output);
void bspline(int n, int t, point *control, point *output, int num_output);

#endif