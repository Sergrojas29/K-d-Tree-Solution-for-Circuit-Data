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
    coordinates.getDataFromCSV("../testData/OVATEST.csv");

    coordinates.OptimalCircuit(45,15,1);

    




    // cout << coordinates.get_OptimalCktInfo() << endl;
    return 0;
}
