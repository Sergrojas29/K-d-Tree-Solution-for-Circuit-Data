#include <iostream>
#include <memory>
#include <vector>
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
    bool found = UNUSED;
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
    bool LeftRight(float node_val, float compare_val); // helper function
};

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

bool kdtree::LeftRight(float node_val, float compare_val)
{
    return node_val < compare_val ? true : false;
}

void kdtree::insert(node *new_node)
{
    if (*root == nullptr)
    {
        *root = new_node;
    }
    else
    {
        node *current = *root;
        int level = 0; // inital k level is meant for the x axis equals 1

        while (current != nullptr)
        {
            level +=1;

            if (LeftRight( current->x , new_node->x))
            {
                if (current->left)
                {
                    /* code */
                }
                
            }
            


        }
    }
}

int main()
{
    vector<float> xCSV = {2587, 2603, 162, 240.5, 2814.5, 2594.5, 1456.5, 1476.5};
    vector<float> yCSV = {-787, 50, -311, -280.5, -532.5, -680.5, -320.5, -720.5};

    kdtree mykdtree;
    cout << mykdtree.LeftRight(2587, 2603) << endl;
    cout << "ALL GOOOOOOD" << endl;

    return 0;
}
