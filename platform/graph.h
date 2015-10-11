#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
 #include <map>
#include <sstream>

template<typename T> class Graph
{
public:

    T value;
     std::vector<Graph<T> *> sons;

    Graph(T value)
    {
        this->value = value;
    }
    ~Graph()
    {

    }

    void add(Graph<T> * son)
    {
        this->sons.push_back(son);
    }

    void display(std::stringstream & output)
    {
        std::map<Graph<T>*,Graph<T>*> nodes;
        output << this->value << std::endl;
        const int level = 0;
        nodes[this] = this;

        for(std::vector<Graph<T> *>::iterator it = sons.begin(); it != sons.end();it++)
        {
            (*it)->display(output,level,nodes);
        }
    }

private:
    void display(std::stringstream & output, int level, std::map<Graph<T> *,Graph<T> *> & nodes)
    {
        if(nodes.find(this) == nodes.end())
        {
            for(int i=0;i<=level;i++)
            {
                output << "_\t";
            }

            output << this->value << std::endl;
            nodes[this] = this;

            for(std::vector<Graph<T> *>::iterator it = sons.begin(); it != sons.end();it++)
            {
                (*it)->display(output,level+1,nodes);
            }
        }
    }
};

#endif // GRAPH_H
