#include "../code/KDTree.h"
#include "../code/CircuteSearch.h"

using namespace std;

int main()
{
    string file_locaion;
    float x_axis, y_axis;
    cout << "Please enter relative file location of csv :";
    cin >> file_locaion;
    cout << endl <<"Please enter Panel X axis location :";
    cin >> x_axis;
    cout << endl <<"Please enter Panel Y axis location :";
    cin >> y_axis;


    CircuteSearch coordinates;
    coordinates.getDataFromCSV(file_locaion);

    //Add panel to circuit string list
    coordinates.OptimalCktInfo << "(" << x_axis << ", " << y_axis <<")";
    coordinates.OptimalCircuit(x_axis, y_axis, coordinates.data.size());

    cout << coordinates.get_OptimalCktInfo() << endl;

    return 0;
}
