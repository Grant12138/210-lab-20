/***************************************************************************
* COMSC-210 | Lab 20 | Grant Luo
* Editor: CLion
* Compiler: Apple clang version 16.0.0
*/
#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 3;
const int MIN = 10000, MAX = 99999;

class Chair {
    private:
        int legs;
        double * prices;
    public:
// constructors
        Chair() {
            prices = new double[SIZE];
            legs = (rand() % 2) + 3;
            for (int i = 0; i < SIZE; i++)
                prices[i] = (rand() % (MAX - MIN + 1) + MIN) / 100.0;
        }
        Chair(int l, double p[SIZE]) {
            prices = new double[SIZE];
            legs = l;
            for (int i = 0; i < SIZE; i++)
                prices[i] = p[i];
        }
        ~Chair()
        {
            delete[] prices;
        }
// setters and getters
        void setLegs(int l) { legs = l; }
        int getLegs() const { return legs; }
        void setPrices(double p1, double p2, double p3) {
            prices[0] = p1; prices[1] = p2; prices[2] = p3;
        }
        double getAveragePrices() const {
            double sum = 0;
            for (int i = 0; i < SIZE; i++)
                sum += prices[i];
            return sum / SIZE;
        }
        void print() {
            cout << "CHAIR DATA - legs: " << legs << endl;
            cout << "Price history: " ;
            for (int i = 0; i < SIZE; i++)
                cout << fixed << setprecision(2) << prices[i] << " ";
            cout << endl << "Historical avg price: " << fixed << setprecision(2) << getAveragePrices();
            cout << endl << endl;
        }
};

void print_id(string const& lab_desc);

int main()
{
    print_id("Lab 20: Chair Maker 3000");

    srand(time(0));

    cout << fixed << setprecision(2);

//creating pointer to first chair object
    Chair *chairPtr = new Chair;
    cout << "ChairPtr (Default Constructor):" << endl;
    chairPtr->print();

//creating dynamic chair object with constructor
    double customPrices[SIZE] = {525.25, 434.34, 252.52};
    Chair *livingChair = new Chair(3, customPrices);
    cout << "LivingChair (Parametrized Constructor):" << endl;
    livingChair->print();

    delete livingChair;
    livingChair = nullptr;
//creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];
    cout << "Collection of Chairs (Default Constructors):" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Chair " << i + 1 << ":" << endl;
        collection[i].print();
    }

    delete[] collection;
    collection = nullptr;

    return 0;
}

void print_id(string const& lab_desc)
{
    cout << "\nCOMSC210 | Grant Luo | " << lab_desc << "\n";
    cout << "Editor: CLion\n";
    cout << "Compiler: Apple clang version 16.0.0\n";
    cout << "File: " << __FILE__ << "\n";
    cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";
}