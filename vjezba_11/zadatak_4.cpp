#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

// Klasa nasljeđuje vector<int>
class MojVector : public vector<int>
{
private:
    int N; // broj elemenata za računanje prosjeka

public:
    MojVector(int n) : N(n) {}

    // Funkcija koja koristi lambda izraz
    void ispisiProsjek()
    {
        auto prosjek = [this]()
        {
            // Ako nema dovoljno elemenata
            if (this->size() < N)
            {
                cout << "Nema dovoljno elemenata za racunanje prosjeka."
                     << endl;
                return;
            }

            int suma = 0;

            // Zbrajanje zadnjih N elemenata
            for (int i = this->size() - N; i < this->size(); i++)
            {
                suma += (*this)[i];
            }

            double sredina = static_cast<double>(suma) / N;

            cout << "Prosjek zadnjih "
                 << N
                 << " elemenata: "
                 << sredina
                 << endl;
        };

        // Poziv lambda funkcije
        prosjek();
    }
};

int main()
{
    srand(time(0));

    int N = 5;

    MojVector brojevi(N);

    while (true)
    {
        // Generiranje slučajnog broja
        int broj = rand() % 100;

        // Dodavanje u vector
        brojevi.push_back(broj);

        cout << "Dodan broj: " << broj << endl;

        // Ispis svih elemenata
        cout << "Elementi: ";

        for (int x : brojevi)
        {
            cout << x << " ";
        }

        cout << endl;

        // Ispis tekuće srednje vrijednosti
        brojevi.ispisiProsjek();

        cout << "------------------------" << endl;

        // Pauza 1 sekunda
        this_thread::sleep_for(chrono::seconds(1));
    }

    return 0;
}
