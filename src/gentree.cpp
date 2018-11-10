#include "gentree.h"
#include "array_list.h"

struct GNode
{
  string elem;
  ArrayList children;
};

GenTree leaf(T_ELEM_TYPE x){
    Gnode* leaf = new Gnode;
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
    GenTree lista = t->children;
    for(int i = 0; i > length(lista); i++ ){
        destroyerTree(get(lista,i));
    }
    destroyArrayList(lista);
    delete t;
}
