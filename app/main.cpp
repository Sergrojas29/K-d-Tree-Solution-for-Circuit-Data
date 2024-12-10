#include "../code/KDTree.h"

using namespace std;


int main()
{

    // vector<float> xCSV = {25, 26, 1, 2, 28, 27, 14, 15};
    // vector<float> yCSV = {-7, 5, -3, -2, -53, -68, -32, -72};

    vector<float> xCSV = {3, 6, 1, 5, 1};
    vector<float> yCSV = {3, 2, 4, 5, 1};
    kdtree mykdtree;

    for (int i = 0; i < xCSV.size(); i++)
    {
        mykdtree.insert_data(xCSV[i], yCSV[i]);
    }

    node *root = mykdtree.get_root();
    
    *mykdtree.nearestNeighbor(root,2,5);    


    return 0;
}

