#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    ofstream file("random.txt");

    srand(time(0)); // inicijalizacija generatora

    for (int i = 0; i < 10000; i++) {
        int broj = rand();
        file << broj << endl;
    }

    file.close();
    return 0;
}
