#include <iostream>
#include <cstdio>

int main() {
    char tekst[] = "5 3";
    int x, y;
    char rezultat[50];

    sscanf(tekst, "%d %d", &x, &y);
    sprintf(rezultat, "Umnozak je %d", x * y);

    std::cout << rezultat << std::endl;
    return 0;
}


