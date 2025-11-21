// Kristoffer Carlino
// C++ 310
// Dr. Robert Flowers
// Module 11 Debugging Exercise
#include <iostream>
#include <stdexcept>
using namespace std;


template <class T>
class Box {
private:
    T data;

public:
    Box(T value = 0) : data(value) {}

    // Overloaded * operator
    Box<T> operator*(const Box<T>& other) const {
        return Box<T>(data * other.data);
    }

    // Member function with try/catch
    void updateValue(T newValue) {
        try {
            if (newValue > 100) {
                throw out_of_range("Value too large!");
            }
            data = newValue;
        }
        catch (const out_of_range& e) {
            
            cout << "Caught exception: " << e.errorMsg << endl;
        }
    }

    // Getter
    T get() const {
        return data;
    }
};

int main() {
    Box<int> a(10);
    Box<int> b(3);

    // Uses overloaded operator*
    Box<int> c = a * b;

    // ❌ INTENTIONAL ERROR #2 in main:
    // 'printValue' does not exist in Box class
    a.printValue();

    // Trigger exception handling
    a.updateValue(200);

    cout << "Result: " << c.get() << endl;

    return 0;
}
