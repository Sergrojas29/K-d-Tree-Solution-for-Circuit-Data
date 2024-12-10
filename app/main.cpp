#include "../code/KDTree.h"

using namespace std;


int main()
{

    vector<float> xCSV = {25, 26, 1, 2, 28, 27, 14, 15};
    vector<float> yCSV = {-7, 5, -3, -2, -53, -68, -32, -72};

    kdtree mykdtree;

    for (int i = 0; i < xCSV.size(); i++)
    {
        mykdtree.insert_data(xCSV[i], yCSV[i]);
    }

    mykdtree.nearestNeighbor(16, -5);


    return 0;
}

