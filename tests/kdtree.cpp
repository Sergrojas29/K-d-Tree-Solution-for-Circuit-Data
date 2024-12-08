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
    node *leftOrRight(node *current, node *new_node, int level); //helper function
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

node *kdtree::leftOrRight(node *current, node *new_node, int level)
{
    float current_val = (level % K == 1) ? current->x : current->y;
    float new_val = (level % K == 1) ? new_node->x : new_node->y;

    if (current_val < new_val)
    {
        //! current value is LARGER goes RIGHT
        if (current->right == nullptr)
        {
            current->right = new_node;
            cout << "current right is node the new node :" << new_node->x << endl;
            current = nullptr;
        }
        else
        {
            current == current->right;
        }
    }
    else
    {
        //current value is SMALLER goes LEFT
        if (current->left == nullptr)
        {
            current->left = new_node;
            cout << "current left is node the new node :" << new_node->x << endl;
            current = nullptr;
        }
        else
        {
            current == current->left;
        }
    }


    // cout << "value depending on level for current: " << current_val << endl;
    // cout << "value depending on level for new node: " << new_val << endl;

    return current;
}

void kdtree::insert(node *new_node)
{
    if (*root == nullptr)
    {
        *root = new_node;
        cout << "new node is new root:" << new_node->x << endl;
    }
    else
    {
        node *current = *root;
        int level = 1; // inital k level is meant for the x axis equals 1

        while (current != nullptr)
        {
            if (level % K == 1)
            {
                if (current->x < new_node->x)
                {
                    //! current value is LARGER goes RIGHT
                    if (current->right == nullptr)
                    {
                        current->right = new_node;
                        cout << "current right is node the new node :" << new_node->x << endl;
                        current = nullptr;
                    }
                    else
                    {
                        current == current->right;
                        level += 1;
                    }
                }
                else
                {
                    //current value is SMALLER goes LEFT
                    if (current->left == nullptr)
                    {
                        current->left = new_node;
                        cout << "current left is node the new node :" << new_node->x << endl;
                        current = nullptr;
                    }
                    else
                    {
                        current == current->left;
                        level += 1;
                    }
                }
            }
            else
            {
                cout << "other" << endl;
                current = nullptr;
            }
        }
    }
}

int main()
{
    vector<float> xCSV = {2587, 2603, 162, 240.5, 2814.5, 2594.5, 1456.5, 1476.5};
    vector<float> yCSV = {-787, 50, -311, -280.5, -532.5, -680.5, -320.5, -720.5};

    kdtree mykdtree;
    node *p1 = mykdtree.init_node(2587, -787);
    node *p2 = mykdtree.init_node(240.5, 50);
    node *p3 = mykdtree.init_node(2603.5, -311);
    node *p4 = mykdtree.init_node(2814.5, 90);

    // mykdtree.insert(p1);
    // mykdtree.insert(p2);
    // mykdtree.insert(p3);
    // mykdtree.insert(p4);

    mykdtree.leftOrRight(p3, p4, 2);

    // cout << "ALL GOOOOOOD" << endl;

    return 0;
}
