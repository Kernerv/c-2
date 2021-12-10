#include "Container.h"
using namespace boxcontainer;

struct SizeException {

};


//конструктор
Container::Container(int length, int width, int height, double maxWeight) : boxes() {
    this->length = length;
    this->width = width;
    this->height = height;
    this->maxWeight = maxWeight;
}
//добавление и удаление
int Container::addBox(Box box) {
    if (getTotalWeight() + box.getWeigth() <= maxWeight) {
        boxes.push_back(box);
        return boxes.size() - 1;
    }
    else {
        throw new MaxWeightException();
    }
}
void Container::removeBox(int index) {
    boxes.erase(boxes.begin() + index);
}

//суммарные вес и стоимость
double Container::getTotalWeight() {
    double sum = 0.0;
    for (int i = 0; i < boxes.size(); i++) {
        sum += boxes.at(i).getWeigth();
    }
    return sum;
}

int Container::getTotalValue() {
    int sum = 0;
    for (int i = 0; i < boxes.size(); i++) {
        sum += boxes.at(i).getValue();
    }
    return sum;
}
//коробка по индексу
Box& Container::getBox(int index) {
    return boxes.at(index);
}
//количество коробок
int Container::getSize() {
    return boxes.size();
}
Box& Container::operator[] (int i) {
    return getBox(i);
}
//ввод и вывод
namespace box_container_ns {
    ostream &operator<<(ostream &s, Container &container) {
        for (int i = 0; i < container.getSize(); i++) {
            s << "Box #" << i << " {size: " << container.getBox(i).getLength() << "x"
              << container.getBox(i).getWidth() << "x"
              << container.getBox(i).getHeight() << ", weight: "
              << container.getBox(i).getWeigth() << ", value: "
              << container.getBox(i).getValue() << "}\n";
        }

        return s;
    };

    istream &operator>>(istream &s, Container &container) {
        int n;
        cout << "Input quantity of boxes:";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Box #" << i << " (length, width, height, weight, value): ";
            int ln, wd, hg, vl;
            double wg;
            cin >> ln >> wd >> hg >> wg >> vl;
            Box box(ln, wd, hg, wg, vl);
            container.addBox(box);
        }
        cout << "input end\n";
        return s;
    };

}