// Abstract data type;

typedef struct point Point;

// Create a new point
Point* createPoint(float x, float y);

// Receive a point and release it from memory
void releaseMemory(Point* point);

void getPointCoordinates(Point* point, float* x, float* y);

void setCoordinates(Point* point, float x, float y);

float getDistance(Point* point1, Point* point2);