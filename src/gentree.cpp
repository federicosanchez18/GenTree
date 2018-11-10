#include "gentree.h"
#include "array_list.h"

struct GNode
{
  string elem;
  ArrayList children;
};


GenTree leaf(T_ELEM_TYPE x){
    GNode* leaf = new Gnode;
    leaf->elem = x;
    leaf->children = crearArrayList();
    return leaf;
} 

bool isLeaf(GenTree t){
    return length(t->children) == 0; 
}

T_ELEM_TYPE value(GenTree t){
    return t->elem;
}

ArrayList children(GenTree t){
    return t->children;
}

void addChild(GenTree& t, GenTree child){
     add(t->children, child); 
}

void destroyTree(GenTree& t){
    ArrayList lista = t->children;
    for(int i = 0; i < length(lista); i++ ){
        GNode node = getAt(lista,i)
        destroyerTree(node); // recursion
    }
    destroyArrayList(lista); //elimina la lista del t 
    delete t; // elimina el nodo
}
