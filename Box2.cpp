// Box2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "Box.h"
#include "Container.h"
using namespace boxcontainer;

const unsigned int SIZE = 4;
const unsigned int N = 45;
const double mV = 10.0;

int main() {
    int n = 4;
    Box* arr = new Box[n];
    arr[0] = Box(1, 2, 3, 7, 5);
    arr[1] = Box(4, 5, 6, 1, 5);
    arr[2] = Box(7, 8, 9, 2, 10);
    arr[3] = Box(1, 1, 1, 5, 1);
    cout << arr[1];
    Container container(10, 10, 10, 15);
    Box a(1, 2, 3, 7, 5);
    Box b(4, 5, 6, 1, 5);
    Box c(7, 8, 9, 2, 10);
    Box d(1, 1, 1, 5, 1);
    container.addBox(a);
    container.addBox(b);
    container.addBox(c);
    cout << "" << endl;
    cout << "Size: " << container.getSize() << endl;
    cout << "Box: " << container.getBox(1) << endl;
    cout << "Sum Value: " << container.getTotalValue() << endl;
    cout << "Sum Weight: " << container.getTotalWeight() << endl;
    container.removeBox(1);
    cout << "Container: " << container.getBox(1) << endl;
    container[1] = d;
    cout << "Sizes "<< container[1] << endl;
    try {
        container.addBox(a);
    } catch(MaxWeightException *e) {
        cout << "Error" << endl;
    }
    system("pause");
    return 0;
}