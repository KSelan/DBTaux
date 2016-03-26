#ifndef HANOI_H
#define HANOI_H


#include <vector>
#include <sstream>

void hanoi(std::vector<int> & source,std::vector<int> & dest,std::vector<int> & pivot, std::stringstream & s, int size)
{
    int tmp;
    if(size == 1)
    {
        tmp = source[source.size()-1];
        source.pop_back();
        dest.push_back(tmp);
    }
    else if(size == 2)
    {
        hanoi(source,pivot,dest,s,1);
        hanoi(source,dest,pivot,s,1);
        hanoi(pivot,dest,source,s,1);

    }
    else
    {

        hanoi(source,pivot,dest,s,size-1);

        tmp = source[source.size()-1];
        source.pop_back();
        dest.push_back(tmp);

        hanoi(pivot,dest,source,s,pivot.size());
    }
}

void hanoitest(std::stringstream & s)
{
    std::vector<int> source,dest,pivot;
    for(int i = 5; i > 0; i--)
    {
        source.push_back(i);
    }

    hanoi(source,dest,pivot,s,source.size());


}


#endif // HANOI_H
