#ifndef ARBRE
#define ARBRE

#endif // ARBRE

template<typename T> class node
{
private:
    T value;
    int depth;
    node * left;
    node * right;
public:
    node() : left(NULL), right(NULL), depth(0) {}
    node(T value) : value(value), depth(0),left(NULL), right(NULL){}
    node(node<T> & t1) : left(NULL), right(NULL), depth(0), value(t1.value) {}
    node(const node<T> & t, int depth) : value(t.value), depth(depth),left(NULL), right(NULL){}
    ~node()
    {
        delete(left);
        delete(right);
    }

    void add(node<T> & t1)
    {
        if(this->value > t1.value)
        {
            if(!this->left)
            {
                this->left = new node(t1,depth+1);
            }
            else
            {
                this->left->add(t1);
            }
        }
        else
        {
            if(!this->right)
            {
                this->right = new node(t1,depth+1);
            }
            else
            {
                this->right->add(t1);
            }
        }
    }

    void display(std::stringstream & s)
    {
        if(this->left)
        {
            this->left->display(s);
            s << "_";
        }

        s<< this->value;

        if(this->right)
        {
            s << "_";
            this->right->display(s);
        }
    }

};

void testNode(std::stringstream & output)
{
    node<int> n1(1);
    node<int> n2(2);
    node<int> n3(3);
    node<int> n4(4);
    node<int> n5(5);
    node<int> n6(6);
    node<int> n7(7);
    node<int> n8(8);
    node<int> n9(9);

    n5.add(n4);
    n5.add(n6);
    n5.add(n3);
    n5.add(n7);
    n5.add(n2);
    n5.add(n9);
    n5.add(n8);
    n5.add(n1);

    n5.display(output);
}


