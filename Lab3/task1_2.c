#include <stdio.h>
#include <math.h>

struct Vector3D {
    char name;
    double x;
    double y;
    double z;
};

void printVector(struct Vector3D v) {
    printf("Vector %c = {%.2f, %.2f, %.2f}\n", v.name, v.x, v.y, v.z);
}

double vectorLength(struct Vector3D v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

double dotProduct(struct Vector3D v1, struct Vector3D v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

struct Vector3D crossProduct(struct Vector3D v1, struct Vector3D v2, char newName) {
    struct Vector3D result;
    result.name = newName;
    result.x = v1.y * v2.z - v1.z * v2.y;
    result.y = v1.z * v2.x - v1.x * v2.z;
    result.z = v1.x * v2.y - v1.y * v2.x;
    return result;
}

int main(void) {
    struct Vector3D vA = {'A', 3.0, 5.0, 2.0};
    struct Vector3D vB = {'B', 4.0, 9.0, 3.0};
    printVector(vA);
    printVector(vB);
    printf("|%c| = %.2f\n", vA.name, vectorLength(vA));
    printf("%c * %c (Dot Product) = %.2f\n", vA.name, vB.name, dotProduct(vA, vB));
    struct Vector3D vC = crossProduct(vA, vB, 'C');
    printf("Cross Product:\n");
    printVector(vC);
    return 0;
}