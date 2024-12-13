#ifndef KDT_H__
#define KDT_H__

#include <iostream>
#include <memory>
#include <vector>
#include <cmath>
#include <cfloat>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

// Node K Dimensions
#define K 2
#define XAXIS 1
#define YAXIS 2
#define USED true
#define UNUSED false

using namespace std;




struct node
{
    float x;
    float y;
    bool found = UNUSED; // Should remove if not used
    node *left;
    node *right;
};

class kdtree
{
public:
    node **root;
    kdtree();
    ~kdtree(){};
    node *init_node(float x_val, float y_val);
    void insert(node *new_node);
    node *leftOrRight(node *current, node *new_node, int level); //helper function
    void insert_data(float x_val, float y_val);
    node *get_root();
    float distance(node *current, float x_val, float y_val);
    node *nearestNeighbor(node *current,float x_val, float y_val);
    void search(node *current, node *&best_node, float &best_dist, float x_val, float y_val, int level = 0);
};

#endif