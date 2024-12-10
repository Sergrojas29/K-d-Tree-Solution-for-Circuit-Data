#include "KDTree.h"

float kdtree::distance(node *current, float x_val, float y_val)
{
    float lenght = x_val - current->x;
    float height = y_val - current->y;
    return sqrt(pow(lenght, 2) + pow(height, 2));
}

node *kdtree::get_root()
{
    if (*root == NULL)
        return NULL;
    return *root;
}

kdtree::kdtree()
{
    root = new node *;
    *root = NULL;
}

node *kdtree::init_node(float x_val, float y_val)
{
    node *new_node = new node();
    new_node->x = x_val;
    new_node->y = y_val;
    new_node->left = nullptr;
    new_node->right = nullptr;

    return new_node;
}

void kdtree::insert_data(float x_val, float y_val)
{
    insert(init_node(x_val, y_val));
}

node *kdtree::leftOrRight(node *current, node *new_node, int level)
{
    float current_val = (level % K == 1) ? current->x : current->y;
    float new_val = (level % K == 1) ? new_node->x : new_node->y;

    if (current_val <= new_val)
    {
        //! current value is LARGER OR EQUAL goes RIGHT
        if (current->right == nullptr)
        {
            current->right = new_node;
            cout << "current right is node the new node :" << new_node->x << endl;
            current = nullptr;
        }
        else
        {
            current = current->right;
        }
    }
    else
    {
        if (current->left == nullptr)
        {
            current->left = new_node;
            cout << "current left is node the new node :" << new_node->x << endl;
            current = nullptr;
        }
        else
        {
            current = current->left;
        }
    }

    return current;
}

void kdtree::insert(node *new_node)
{
    if (*root == nullptr)
    {
        *root = new_node;
        cout << "new node is new root:" << new_node->x << endl;
        return;
    }
    else
    {
        node *current = *root;
        int level = 1; // inital k level is meant for the x axis equals 1

        while (current != nullptr)
        {
            current = leftOrRight(current, new_node, level);
            level++; // increments the level
        }
    }
}

void kdtree::search(node *current, node *&best_node, float &best_dist, float x_val, float y_val, int level)
{
    if (current == nullptr)
    {
        cout << "end recursion on level " << level << endl;
        return;
    }

    level++;
    float new_distance = distance(current, x_val, y_val);

    float nodeAxisValue = (level % K == 1) ? current->x : current->y;
    float targetAxisValue = (level % K == 1) ? x_val : y_val;

    cout << "new dist: " << new_distance << "   compared to best dist:" << best_dist << endl; // visual debug
    best_node = (new_distance < best_dist) ? current : best_node;
    best_dist = (new_distance < best_dist) ? new_distance : best_dist;

    if (targetAxisValue >= nodeAxisValue)
    {
        current = current->right;
        search(current, best_node, best_dist, x_val, y_val,level);
    }
    else
    {
        current = current->left;
        search(current, best_node, best_dist, x_val, y_val,level);
    }

    if(fabs(targetAxisValue- nodeAxisValue)< best_dist){
        search(current, best_node, best_dist, x_val, y_val,level); // check if the other side needs to be checked
    }


    return;
}

node *kdtree::nearestNeighbor(node *current, float x_val, float y_val)
{
    float best_dist = FLT_MAX;
    // float best_dist = 10000;
    node *best_node = nullptr;

    search(current,best_node, best_dist, x_val, y_val);
    cout << "Best node is : " << best_node->x << ", " << best_node->y;
    return best_node;
}
