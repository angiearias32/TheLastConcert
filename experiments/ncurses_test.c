#include <ncurses.h> // esta linea indica que se va a usar la biblioteca ncurses

int main() { // funcion principal donde empieza el programa

    initscr(); // en esta linea la biblioteca toma control de la pantalla de la terminal
    printw("The Last Concert"); // imprime el texto
    refresh(); //ncurses primero perpara los cambios en memoria y luego los dibuja realmente
    getch(); // esta linea espera a que el ususario presione una tecla para no cerrar
    endwin(); // cerramos ncurses
    return 0; // programa termina exitosamente
    
}
