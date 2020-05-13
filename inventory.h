#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <condition_variable>
#include <mutex>
#include <cstring>
#include <iostream>
#include <map>

#include "thread.h"
#include "lock.h"

class Inventory{
public:
    /* Inicializo el mapa con sus keys en 0 */
    Inventory (); 

    void add_material(char material);
    
    /* Devuelve falso si no hay stock y ya no se van a agregar mas materiales a mi
    inventario. Devuelvo verdadero y quito los materiales del 
    inventario en caso de disponer del stock requerido */
    bool consult_stock_and_get_materials_if_there_is(const char material1, 
        const int cantidad1, const char material2, const int cantidad2);
    
    void close();

    int get_stock(const char material);

    void set_cant_recolectores(int cantidad);

    /* Destructor */
    ~Inventory();

private:
    /* Quito la cantidad indicada del material indicado, de mi inventario */
    void remove_materials(const char material, const int cantidad);

    /* Devuelvo verdadero en caso de tener ese stock en mi inventario,
    devuelvo falso en caso de no disponerlo */
    bool consult_stock(const char material, const int cantidad);
    
    std::map<char, int> inventory;
    
    /* Si las colas están cerradas, cierro el inventario */
    int isClosed;
    
    std::mutex m;
    std::condition_variable cv;
    int cant_recolectores;
};







#endif