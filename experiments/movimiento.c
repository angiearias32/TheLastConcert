#include <ncurses.h>  // se le dice al compilador que vamos a eusar esa biblioteca

int main () { // funcion principal

    int x = 10; // x es la columna de izquierda y derecha
    int y = 10; // y es la columna de arriba y abajo
    int tecla; // variable donde espera la respuesta del usuario con la tecla
    
    initscr(); // toma el control de la terminal
    keypad(stdscr, TRUE); // esta funcion le dice al programa cuales teclas especiales detectar
    // stdscr es pantalla principal y TRUE significa que esta activa
    while (1) { // aqui se crea un ciclo infinito
        clear(); // borra la pantalla para que no quede las posiciones viejas del personaje
        
        mvprintw(y, x, "@"); // aqui se mueve el cursor a una posicion y escribe algo
        
        refresh(); // hace visible lo que acabamos de dibujar
        
        tecla = getch(); // es donde se va a guardar la tecla arriba, abajo, izquierda, derecha
        if (tecla == KEY_UP)
            y--;
            
        else if (tecla == KEY_DOWN)
            y++;
            
        else if (tecla == KEY_LEFT)
            x--;
            
        else if (tecla == KEY_RIGHT)
            x++;
            
        else if (tecla == 'q')
            break;
            
    }
    
    endwin(); // cierra ncurses correctamente
    
    return 0; // indica que el programa termino sin errores
    
} 
