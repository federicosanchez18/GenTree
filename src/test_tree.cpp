#include "test_tree.h"

// PROPOSITO: DEVUELVE LA CANTIDAD DE NODOS
int sizeT(GenTree t) {
    int r = 1;
    ArrayList ts = children(t);
    for(int i = 0; i < length(ts); i++) {
        r += sizeT(getAt(ts, i));
    }
    return r;
}

// PROPOSITO: INDICA SI EL ELEMENTO APARECE EN EL ARBOL
bool containsT(string x, GenTree t) {
    bool r= value(t) == x ? true:false;
    ArrayList ts = children(t);
    for(int i = 0; i < length(ts); (i)++) {
            r = r || containsT(x, getAt(children(t),i));

    }
    return r;
}

// PROPOSITO: INDICA LA CANTIDAD DE VECES QUE APARECE EL ELEMENTO
int occurrencesT(string x, GenTree t) {
    int r = 0;
    ArrayList ts = children(t);
    for(int i = 0; i < length(ts); i++) {
            r += (value(getAt(ts,i)) == x  ? 1:0) + occurrencesT(x,getAt(ts,i));
                 

    }
    return r;
}


// PROPOSITO: DEVUELVE LA CANTIDAD DE RAMAS
int countLeaves(GenTree t) {
    int r = 0;
    ArrayList ts = children(t);
    for(int i = 0; i < length(ts); i++) {
            r += (isLeaf(getAt(ts,i)) ? 1:0) + countLeaves(getAt(ts,i));

    }
    return r;
}

// PROPOSITO: DEVUELVE LA ALTURA DEL ARBOL
int heightT(GenTree t) {
    int r = 0;
    ArrayList  ts = children(t);
    for(int i = 0; i < length(ts);i++){
        r = max(r, heightT(getAt(ts,i))); 
    }
    r++;
    return r;
}

//Precondicion donde lis siempres es Empty
List elementosTree(List& lis, GenTree t){
        ArrayList ts = children(t);
        for(int i = 0; i< length(ts); i++){
            elementosTree(lis, getAt(ts,i));
        }
        snoc(lis,value(t));
        return lis;
}
// PROPOSITO: DEVUELVE LOS ELEMENTOS DEL ARBOL EN UNA LISTA
// PISTA: HACER UNA SUBTAREA QUE RECIBA UNA LISTA POR PARAMETRO
// PARA PODER MODIFICARLA
List toList(GenTree t) {
    List ls  = nil();
    elementosTree(ls,t);
    return ls;

}

List elementosDeHoja(List& ls , GenTree t){
    ArrayList ts = children(t);
   
    for(int i = 0; i< length(ts); i++){
            elementosDeHoja(ls, getAt(ts,i));
             
        }
        if(isLeaf (t)){
                  snoc(ls,value(t));
            };
    
         return ls;

}
// PROPOSITO: DEVUELVE LOS ELEMENTOS QUE ESTAN EN LAS HOJAS
List leaves(GenTree t) {
    List ls = nil();
    return elementosDeHoja(ls,t);
    
}

// PROPOSITO: agrega ts a los children de t
void addChildren(ArrayList ts, GenTree t) {
    for (int i = 0; i < length(ts); i++){
            addChild(t, getAt(ts,i));
    }
    
}


void elementosDelNivel(GenTree t , int n , List& xs){
    ArrayList ts = children(t);
    if(n == 0) {
            snoc(xs,value(t));
            return ;
    }
    for (int i = 0 ; i < length(ts) ; i++){
        elementosDelNivel(getAt(ts,i),n - 1,xs);
    }
}

// PROPOSITO: DEVUELVE LOS ELEMENTOS DEL NIVEL "n"
 List levelN(int n, GenTree t) {
    List ls = nil();
    elementosDelNivel(t,n,ls);
    return ls;
}
    
//PROPOSITO: DEVUELVE EL STRING CON MAYOR LONGITUD
string stringWithMaxSize(GenTree t) {
    string x = "";
    ArrayList ts = children(t);
    for (int i = 0; i < length(ts) ; i++ ){
        string y = stringWithMaxSize (getAt(ts,i));
        if(x < y){
            x = y;
        }
    }
    return x;
}
    

// PROPOSITO: DADO UN ARRAY CON NUMEROS QUE INDICAN UN CAMINO POR EL ARBOL
// DEVUELVE LOS ELEMENTOS QUE SE ENCUENTRAN EN DICHO CAMINO
List elemsInPath(GenTree t, int path[], int pathSize) {

}

// PROPOSITO: DEVUELVE EL ARBOL CON MAYOR ALTURA
// PRECONDICION: LA LISTA NO ESTA VACIA
GenTree maxHeight(ArrayList ts) {
    GenTree h = getAt(ts,0);
    for ( int i = 0 ; i < length(ts) ; i++){
        if(heightT(h) < heightT (getAt(ts,i))){
            h = getAt(ts,i);
        }
        maxHeight(children(getAt(ts,i)));
    }
    return h;
}

// PROPOSITO: DEVUELVE LA CONCATENACION DE LOS ELEMENTOS DE LOS ARBOLES DE LA LISTA
// List concatToList(ArrayList ts) { // consulta si tengo q recorrer todo el arbol o concatener el concatALL 
//     List xs = nil();
//     for (int = 0 ; i < length(ts); i++){
//         concatToList(children(getAt(ts,i)));
//         snoc(xs,value)
//     } 
//     return xs; 
// }

// PROPOSITO: INDICA SI TODOS LOS ELEMENTOS DE LA LISTA ESTAN EN EL ARBOL
// bool containsAll(List elems, GenTree t) {
//     bool x = true;
//     ListIterator i = initIt(elems)
    
//     while(not finished(elems)){

//         x = x && containsT(getCurrent(i,t));
//         next(i);
//     }
//     return x;

// }

// PROPOSITO: CONCATENA TODOS LOS STRINGS DEL ARBOL
string concatAll(GenTree t) {
    string xs = "";
    ArrayList ts = children(t);
     for (int i = 0 ; i < length(ts) ; i++){
          xs+= concatAll(getAt(ts,i));
    }
     return xs+=value(t);  
}

void testTree() {


    // ACA VAN LOS TEST DE LAS FUNCIONES IMPLEMENTADAS

    //instacinas de gentree
    GenTree x = leaf("z");
    GenTree y = leaf("w");
    GenTree t = leaf("");

    //agrego hijos
    addChild(y,x);
    addChild(y,t);

    //creo lista de Genode
    ArrayList xs = crearArrayList();
    add(xs,x);
    add(xs,y);
    for(int i = 0; i < 10; i++) {
        GenTree t2 = leaf("a");
        for(int j = 0; j < 10; j++) {
            addChild(t2, leaf("b"));
              
        }
        addChild(t, t2);
        
    }

    //test de sum : 
    cout << "sum: " << sizeT(t) << endl;

    //test de contains : 
    cout << "contains b: " << (containsT("b", t) ? "true" : "false") << endl;

    //test de ocurrrencia :
    cout << "occurrences b: " << occurrencesT("b", t) << endl;

    //test de leavs ;
    cout << "leaves: " << countLeaves(t) << endl;

    //test de height
    cout << "height: " << heightT(t) << endl;

    //test de toList:
    cout << "sizeToList:" << length(toList(t)) << endl;    
    printList(toList(t));

    //test de leaves
    cout <<  "leavesSize : " << length(leaves(t)) << endl;
    printList(leaves(t));

    //test de addchildren:
    cout << "Addchild :" ; imprimirArrayList(children(y));

    //test de levelN
    printList(levelN(2,t));
    // cout <<  "levelN : " << length(levelN(2 ,t)) << endl;

    //test de stringWithMaxSize:

    //test de elemsInPath:

    //test de maxHeight;

    //test de concatToList;

    //test de containsAll;
    
    //test de concatAll
    // cout << "concatALL : " << concatAll(y) << endl;

    //te
}
