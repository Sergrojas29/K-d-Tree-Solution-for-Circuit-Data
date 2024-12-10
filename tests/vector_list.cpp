#include "../code/KDTree.h"

#include <iostream>
#include <memory>
#include <vector>
#include <cmath>
#include <cfloat>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Point
{
public:
    vector<float> coor;
    Point() {};
    Point(float x, float y)
    {
        coor.push_back(x);
        coor.push_back(y);
    };
    ~Point() {};
    void report()
    {
        for (auto &&i : coor)
        {
            cout << i << ',';
        }
    }
};

int main()
{

    vector<Point> coordinates;

    fstream data("../testData/Data-test.csv");

    if (data.fail())
    {
        cerr << "Error Opening File: " << endl;
        return 1;
    }

    string line;
    string Count, Name, Layer, File_Name, Title, Point_Link;
    float Position_X, Position_Y;
    getline(data, line);

    int count;

    while (getline(data, line))
    {
        string tempString;
        stringstream inputString(line);

        getline(inputString, Count, ',');
        getline(inputString, Name, ',');

        // get X postion
        getline(inputString, tempString, ',');
        Position_X = stof(tempString.c_str());
        // get Y postion
        getline(inputString, tempString, ',');
        Position_Y = stof(tempString.c_str());

        Point p(Position_X, Position_Y);

        coordinates.push_back(p);
        // p.~Point();
        line = "";
    }

    coordinates;

    kdtree mykdtree;
    for (auto &&i : coordinates)
    {
        cout << i.coor[0] << " , " << i.coor[1] << endl;
        mykdtree.insert_data(i.coor[0], i.coor[1]);
    }
    node *root = mykdtree.get_root();
    node *best = mykdtree.nearestNeighbor(root, 250.6, 200);

    cout << best->found << endl;

    return 0;
}
