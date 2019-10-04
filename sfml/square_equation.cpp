#include <cstdio>
#include <cmath>

int main()
{
    std::puts("please enter a, b and c for 'ax^2 + bx + c = 0':");

    float a = 0;
    float b = 0;
    float c = 0;
    std::scanf("%f %f %f", &a, &b, &c);

    float x1 = (-b + std::sqrt(b * b - 4 * a * c)) / (2 * a);
    float x2 = (-b - std::sqrt(b * b - 4 * a * c)) / (2 * a);

    if (x1 == x2)
    {
        std::printf("solution: %f\n", x1);
    }
    else
    {
        std::printf("solution: %f %f\n", x1, x2);
    }
}