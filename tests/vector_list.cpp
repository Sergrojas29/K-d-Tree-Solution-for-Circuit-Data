#include "../code/KDTree.h"
#include "../code/CircuteSearch.h"

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


int main()
{

    CircuteSearch coordinates;
    coordinates.getDataFromCSV("../testData/Data-test.csv");

    cout << "location :" << coordinates.searchLocation(2494.5,139.5) << endl;
    // kdtree test = coordinates.createKDTree();






    return 0;
}
