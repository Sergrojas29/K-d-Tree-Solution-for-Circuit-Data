#ifndef CS_H__
#define CS_H__

#include "KDTree.h"

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
    string report()
    {
        stringstream ret;
        ret <<  "(" << coor[0] << ", " << coor[1] << ")";
        return ret.str();
    }
};


class CircuteSearch
{
public:
    vector<Point> data;
    stringstream OptimalCktInfo;
    CircuteSearch(){};
    ~CircuteSearch(){};
    string get_OptimalCktInfo();
    void getDataFromCSV(string fileLocation);
    void addpoint(Point coordinate);
    void remove(float x_val, float y_val);
    int searchLocation(float x_val, float y_val);
    void OptimalCircuit(float x_val, float y_val, int step);
    kdtree createKDTree();

};













#endif

