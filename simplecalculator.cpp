#include <iostream>
using namespace std;

void operators() {
    cout << "Simple calculator" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "Enter your choice from 1-4:";
}
int main() {
    double a, b, result;
    int choice;
    operators();
    cin >> choice;
    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b;
    switch (choice) {
        case 1: 
            result = a + b;
            cout << "Result: "<< result << endl;
            break;
        case 2: 
            result = a - b;
            cout << "Result: " << result << endl;
            break;
        case 3: 
            result = a* b;
            cout << "Result: " <<  result << endl;
            break;
        case 4:
            if (b!= 0) {
                result = a / b;
                cout << "Result: " << result << endl;
            } else {
                cout << "Error(second number should not be zero )" << endl;
            }
            break;
        default:
            cout << "Invalid choice" << endl;
    }
   return 0;
}
