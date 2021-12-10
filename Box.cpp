#include "Box.h"
using namespace boxcontainer;

//конструктор, геттеры и сеттеры, операторы
Box::Box(int theLength = 0, int theWidth = 0, int theHeight = 0, double theWeight = 0.0, int theValue = 0) {
    width = theWidth;
    height = theHeight;
    length = theLength;
    weight = theWeight;
    value = theValue;
}

int Box::getWidth() {
    return width;
}

int Box::getHeight() {
    return height;
}

int Box::getLength() {
    return length;
}

double Box::getWeigth() {
    return weight;
}

int Box::getValue() {
    return value;
}

void Box::setWidth(int width) {
    this->width = width;
}

void Box::setHeight(int height) {
    this->height = height;
}

void Box::setLength(int length) {
    this->length = length;
}

void Box::setWeigth(double weight) {
    this->weight = weight;
}

void Box::setValue(int value) {
    this->value = value;
}

bool Box::operator == (const Box& box) const {
    return width == box.width &&
           height == box.height &&
           length == box.length &&
           weight <= box.weight + EPS &&
           value == box.value;
};

bool Box::operator > (const Box& box) const {
    return width > box.width &&
           height > box.height &&
           length > box.length;
};

bool Box::operator < (const Box& box) const {
    return width < box.width&&
           height < box.height&&
           length < box.length;
};


int getValueSum(Box** boxes, int size) {
    int sum = 0;
    for (int i = 0; i <= size; i++) {
        sum += boxes[i]->getValue();
    }
    return sum;
}

bool checkSizes(Box** boxes, int n, int size) {
    int sizesSum = 0;
    for (int i = 0; i < size; i++) {
        sizesSum += boxes[i]->getHeight();
        sizesSum += boxes[i]->getWidth();
        sizesSum += boxes[i]->getLength();
    }
    return sizesSum <= n;
}

double getMaxWeight(Box** boxes, double maxV, int size) {
    double max = 0;
    for (int i = 0; i < size; i++) {
        if (boxes[i]->getHeight() * boxes[i]->getLength() * boxes[i]->getWidth() <= maxV && boxes[i]->getWeigth() > max) {
            max = boxes[i]->getWeigth();
        }
    }
    return max;
}

bool checkBoxed(Box** boxes, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (!(*boxes[i] > * boxes[j] || *boxes[i] < *boxes[j])) {
                return false;
            }
        }
    }
    return true;
}

namespace boxcontainer {
    ostream& operator << (ostream& s, const Box& box) {
        s << "Size: " << box.length << "x"
          << box.width << "x"
          << box.height << ", weight: " << box.weight << ", value: " << box.value;
        return s;
    };

    istream& operator >> (istream& s, Box& box) {
        cout << "Input\n  Length:";
        cin >> box.length;
        cout << "  Width:";
        cin >> box.width;
        cout << "  Height:";
        cin >> box.height;
        cout << "  Weight:";
        cin >> box.weight;
        cout << "  Value:";
        cin >> box.value;
        return s;
    };
}
