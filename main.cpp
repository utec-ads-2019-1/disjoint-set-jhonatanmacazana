#include <iostream>
#include "node.h"
#include <map>
using namespace std;


void initData(void);
void showData(void);
void makeSet(int data);
Node* find(int val, map<int, Node*> cont);

void unionRandom(int val1, int val2);
void unionRank(int val1, int val2);
void unionSize(int val1, int val2);

typedef enum{RANDOM, RANK, BYSIZE} UnionTypes;

map<int, Node*> mapForRandom;
map<int, Node*> mapForRank;
map<int, Node*> mapForSize;

int main(int argc, char** argv) {


    initData();

    unionRandom(1,2);
    unionRandom(3,4);
    unionRandom(3,5);
    unionRandom(1,7);
    unionRandom(3,6);
    unionRandom(8,9);
    unionRandom(1,8);
    unionRandom(3,10);
    unionRandom(3,11);
    unionRandom(3,12);
    unionRandom(3,13);
    unionRandom(14,15);
    unionRandom(16,1);
    unionRandom(14,16);
    unionRandom(1,3);
    unionRandom(1,14);


    unionRank(1,2);
    unionRank(3,4);
    unionRank(3,5);
    unionRank(1,7);
    unionRank(3,6);
    unionRank(8,9);
    unionRank(1,8);
    unionRank(3,10);
    unionRank(3,11);
    unionRank(3,12);
    unionRank(3,13);
    unionRank(14,15);
    unionRank(16,1);
    unionRank(14,16);
    unionRank(1,3);
    unionRank(1,14);


    unionSize(1,2);
    unionSize(3,4);
    unionSize(3,5);
    unionSize(1,7);
    unionSize(3,6);
    unionSize(8,9);
    unionSize(1,8);
    unionSize(3,10);
    unionSize(3,11);
    unionSize(3,12);
    unionSize(3,13);
    unionSize(14,15);
    unionSize(16,1);
    unionSize(14,16);
    unionSize(1,3);
    unionSize(1,14);

    showData();
}

void initData(void)
{
    for(int i = 1; i<17; i++)
    {
        mapForRandom[i] = new Node(i);
        mapForRank[i] = new Node(i);
        mapForSize[i] = new Node(i);
    }
}

void showData(void)
{
    cout << "Union - Random " << endl;
    for(int i = 1; i<17; i++)
    {
        cout << "Data: " << mapForRandom[i]->data << "  \t" ;
        cout << "Data of the root: " << find(i, mapForRandom)->data <<endl;
    }

    cout << "Union - Rank " << endl;
    for(int i = 1; i<17; i++)
    {
        cout << "Data: " << mapForRank[i]->data << "  \t" ;
        cout << "Data of the root: " << find(i, mapForRank)->data <<endl;
    }

    cout << "Union - Size " << endl;
    for(int i = 1; i<17; i++)
    {
        cout << "Data: " << mapForSize[i]->data << "  \t" ;
        cout << "Data of the root: " << find(i, mapForSize)->data <<endl;
    }

}

Node* find(int val, map<int, Node*> cont)
{
    map<int, Node*>::iterator it;
    it = cont.find(val);
    auto tempNode = it->second;
    while(tempNode->parent != tempNode)
        tempNode = tempNode->parent;
    return tempNode;
}

void unionRandom(int val1, int val2)
{
    auto parent1 = find(val1, mapForRandom);
    auto parent2 = find(val2, mapForRandom);
    parent1->parent = parent2;
}

void unionRank(int val1, int val2)
{
    auto parent1 = find(val1, mapForRank);
    auto parent2 = find(val2, mapForRank);
    if(parent1->rank == parent2->rank)
    {
        parent1->parent = parent2;
        parent2->rank++;
    }
    else if(parent1->rank < parent2->rank)
        parent1->parent = parent2;
    else
        parent2->parent = parent1;
}

void unionSize(int val1, int val2)
{
    auto parent1 = find(val1, mapForSize);
    auto parent2 = find(val2, mapForSize);
    if(parent1->rank == parent2->rank)
    {
        parent1->parent = parent2;
        parent2->rank++;
    }
    else if(parent1->rank < parent2->rank)
        parent1->parent = parent2;
    else
        parent2->parent = parent1;
}



