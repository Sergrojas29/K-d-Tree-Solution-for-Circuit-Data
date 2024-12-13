#include "CircuteSearch.h"
#include "KDTree.h"

void CircuteSearch::addpoint(Point coordinate)
{
    data.push_back(coordinate);
}

void CircuteSearch::remove(float x_val, float y_val)
{
    int coorLocation = searchLocation(x_val, y_val);
    data.erase(data.begin() + coorLocation);
    return;
}

int CircuteSearch::searchLocation(float x_val, float y_val)
{
    int location = 0;
    for (auto &&i : data)
    {
        if (x_val == i.coor[0] && y_val == i.coor[1])
        {
            return location;
        }
        ++location;
    }
    return 0;
}

kdtree CircuteSearch::createKDTree()
{
    kdtree mykdtree;
    for (auto &&i : data)
    {
        mykdtree.insert_data(i.coor[0], i.coor[1]);
    }
    return mykdtree;
}

void CircuteSearch::getDataFromCSV(string fileLocation)
{
    fstream data(fileLocation);

    if (data.fail())
    {
        cerr << "Error Opening File: " << endl;
        return;
    }

    string line;
    string Count, Name, Layer, File_Name, Title, Point_Link;
    float Position_X, Position_Y;
    getline(data, line);

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

        addpoint(p);
        line = "";
    }
};

string CircuteSearch::get_OptimalCktInfo(){
    return OptimalCktInfo.str();
}

void CircuteSearch::OptimalCircuit(float x_val, float y_val, int step)
{
    if (step ==0) return; // end recurssion
    

    kdtree mykdtree = createKDTree();
    node *root = mykdtree.get_root();
    node *best_node = mykdtree.nearestNeighbor(root, x_val,y_val);
    
    //!new target
    float tar_x = best_node->x;
    float tar_y = best_node->y;

    remove(tar_x,tar_y);
    

    OptimalCktInfo <<"(" << tar_x << ", " << tar_y << "),";

    OptimalCircuit(tar_x, tar_y,--step);

}
