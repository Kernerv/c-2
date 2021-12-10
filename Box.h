#pragma once
#include <iostream>

namespace boxcontainer {
    using namespace std;
    const double EPS = 0.00001;
    class Box {
    private:
        int width;
        int height;
        int length;
        double weight;
        int value;
    public:
        Box() {};
        int getWidth();
        int getHeight();
        int getLength();
        double getWeigth();
        int getValue();
        void setWidth(int width);
        void setHeight(int height);
        void setLength(int length);
        void setWeigth(double weight);
        void setValue(int value);
        bool operator > (const Box& box) const;
        bool operator == (const Box& box) const;
        bool operator < (const Box& box) const;
        Box(int theLength, int theWidth, int theHeight, double theWeight, int theValue);
        friend istream& operator >> (istream& s, Box& box);
        friend ostream& operator << (ostream& s, const Box& box);
    };

    ostream& operator << (ostream &s, const Box &box);

    istream& operator >> (istream &s, Box &box);

    int getValueSum(Box** boxes, int size);

    bool checkSizes(Box** boxes, int n, int size);

    double getMaxWeight(Box** boxes, double maxV, int size);

    bool checkBoxed(Box** boxes, int size);
}
