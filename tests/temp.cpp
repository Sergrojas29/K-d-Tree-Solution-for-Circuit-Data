#include <iostream>
#include <vector>
#include <cmath>
#include <cfloat> // For FLT_MAX

#define K 2

using namespace std;

struct node
{
    float x;
    float y;
    node *left;
    node *right;
};

class kdtree
{
public:
    node **root;
    kdtree();
    ~kdtree() { delete *root; delete root; }
    node *init_node(float x_val, float y_val);
    void insert(node *new_node);
    node *leftOrRight(node *current, node *new_node, int level); // Helper function
    void insert_data(float x_val, float y_val);
    node *get_root();
    float distance(node *current, float x_val, float y_val);
    node *nearestNeighbor(float x_val, float y_val);

private:
    void search(node *current, float x_val, float y_val, int level, node *&best_node, float &best_distance);
};

kdtree::kdtree()
{
    root = new node *;
    *root = nullptr;
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

node *kdtree::get_root()
{
    return *root;
}

float kdtree::distance(node *current, float x_val, float y_val)
{
    float dx = current->x - x_val;
    float dy = current->y - y_val;
    return sqrt(dx * dx + dy * dy);
}

node *kdtree::leftOrRight(node *current, node *new_node, int level)
{
    float current_val = (level % K == 1) ? current->x : current->y;
    float new_val = (level % K == 1) ? new_node->x : new_node->y;

    if (new_val < current_val)
    {
        if (current->left == nullptr)
        {
            current->left = new_node;
            return nullptr;
        }
        return current->left;
    }
    else
    {
        if (current->right == nullptr)
        {
            current->right = new_node;
            return nullptr;
        }
        return current->right;
    }
}

void kdtree::insert(node *new_node)
{
    if (*root == nullptr)
    {
        *root = new_node;
        return;
    }

    node *current = *root;
    int level = 1;

    while (current != nullptr)
    {
        current = leftOrRight(current, new_node, level);
        level++;
    }
}

void kdtree::search(node *current, float x_val, float y_val, int level, node *&best_node, float &best_distance)
{
    if (current == nullptr)
        return;

    // Compute distance to current node
    float current_distance = distance(current, x_val, y_val);

    // Update best node and distance if closer
    if (current_distance < best_distance)
    {
        best_node = current;
        best_distance = current_distance;
    }

    // Determine splitting axis
    bool is_x_axis = (level % K == 1);
    float target_value = is_x_axis ? x_val : y_val;
    float current_value = is_x_axis ? current->x : current->y;

    // Recursively search left or right subtree
    node *next_branch = (target_value < current_value) ? current->left : current->right;
    node *other_branch = (target_value < current_value) ? current->right : current->left;

    search(next_branch, x_val, y_val, level + 1, best_node, best_distance);

    // Check if the other branch could contain a closer point
    if (fabs(target_value - current_value) < best_distance)
    {
        search(other_branch, x_val, y_val, level + 1, best_node, best_distance);
    }
}

node *kdtree::nearestNeighbor(float x_val, float y_val)
{
    if (*root == nullptr)
        return nullptr;

    node *best_node = nullptr;
    float best_distance = FLT_MAX;

    search(*root, x_val, y_val, 1, best_node, best_distance);
    return best_node;
}

int main()
{
    vector<float> xCSV = {25, 26, 1, 2, 28, 27, 14, 15};
    vector<float> yCSV = {-7, 5, -3, -2, -53, -68, -32, -72};

    kdtree mykdtree;

    for (int i = 0; i < xCSV.size(); i++)
    {
        mykdtree.insert_data(xCSV[i], yCSV[i]);
    }

    node *nearest = mykdtree.nearestNeighbor(30, -60);
    if (nearest != nullptr)
    {
        cout << "Nearest neighbor to (30, -60): (" << nearest->x << ", " << nearest->y << ")" << endl;
    }
    else
    {
        cout << "No nearest neighbor found!" << endl;
    }

    return 0;
}
