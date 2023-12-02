#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "point.h"

struct point {
    float x;
    float y;
};

Point* createPoint(float x, float y) {
    Point* point = (Point*) malloc(sizeof(point));
    if(point == NULL){
        printf("Insufficient memory!\n");
        exit(1);
    }
}

void releaseMemory(Point* point) {
    free(point);
}

void getPointCoordinates(Point* point, float* x, float* y) {
    *x = point->x;
    *y = point->y;
}

void setCoordinates(Point* point, float x, float y) {
    point->x = x;
    point->y = y;
}

float getDistance(Point* point1, Point* point2) {
    float deltaX = point2->x - point1->x;
    float deltaY = point2->y - point1->y;

    return sqrt(pow(deltaX, 2) + pow(deltaY, 2));
}