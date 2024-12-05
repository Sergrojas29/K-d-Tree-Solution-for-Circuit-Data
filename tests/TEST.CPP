#include <sstream>
#include <iostream> // istring and ostringstream
#include <map>

using namespace std;

struct Point
{
    int x;
    int y;
    Point() : x(0),y(0){};
    Point(int xaxis , int yaxis) : x(xaxis), y(yaxis) {};
    ~Point(){};
};

struct node {
    Point data;
    node* next;
};

class LinkedList
{
public:
    node* top_ptr;

    LinkedList();
    ~LinkedList();
    node* init_node(Point data);
    void append(node* new_node);
    string report();

};
LinkedList::LinkedList(): top_ptr(nullptr){}
LinkedList::~LinkedList(){}

node* LinkedList::init_node(Point data){
    node* ret = new node;
    ret->data = data;
    ret->next = nullptr;
    return ret;
}


void LinkedList::append(node* new_node){
    node* cursor = top_ptr;
    if (cursor == nullptr){
        top_ptr = new_node;
        return;
    }

    while(cursor->next != nullptr){
        cursor = cursor->next;
    }
    cursor->next = new_node;
}

string LinkedList::report(){
    ostringstream oss;
    node* current = top_ptr;
    while (current != nullptr)
    {
        oss << "(" << current->data.x << ", " << current->data.y << ")";
        current = current->next;
    }
    
    return oss.str();
}






int main()
{
    Point P1(2,2);
    Point P2(4,4);
    Point P3(3,7);
    Point P4(5,5);
    Point P5(7,3);
    Point P6(6,8);
    Point P7(9,6);
    Point P8(9,9);

    LinkedList list;

    list.append(list.init_node(P1));
    list.append(list.init_node(P2));
    list.append(list.init_node(P3));
    list.append(list.init_node(P4));
    list.append(list.init_node(P5));
    list.append(list.init_node(P6));
    list.append(list.init_node(P7));
    list.append(list.init_node(P8));

    cout << list.report();
    
    return 0;    



}