#pragma once
#include <vector>
#include "Box.h"
namespace boxcontainer {
    struct MaxWeightException {
        char stre;
    };
    class Container {
    private:
        vector<Box> boxes;
        int length;
        int width;
        int height;
        double maxWeight;
    public:
        Container(int length, int width, int height, double maxWeight);
        int getSize();
        double getTotalWeight();
        int getTotalValue();
        Box& getBox(int index);
        int addBox(Box box);
        void removeBox(int index);
        friend istream& operator >> (istream& s, Container& container);
        friend ostream& operator << (ostream& s, const Container& container);
        Box& operator[] (int i);
    };

}