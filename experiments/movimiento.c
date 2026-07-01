#include <ncurses.h>  // se le dice al compilador que vamos a eusar esa biblioteca

int main () { // funcion principal

    int x = 10; // x es la columna de izquierda y derecha
    int y = 10; // y es la columna de arriba y abajo
    int tecla; // variable donde espera la respuesta del usuario con la tecla
    
    int partituraX = 15; //columna donde va a estar la partitura
    int partituraY = 5; // fila donde estara la partitura
    
    int partituraRecogida = 0;
    int contadorPartituras = 0; // cantidad de partituras recogidaas
    
    initscr(); // toma el control de la terminal
    keypad(stdscr, TRUE); // esta funcion le dice al programa cuales teclas especiales detectar
    // stdscr es pantalla principal y TRUE significa que esta activa
    while (1) { // aqui se crea un ciclo infinito
        clear(); // borra la pantalla para que no quede las posiciones viejas del personaje
        
        for (int i = 0; i < 21; i++) {
        
            mvprintw(0, i, "#"); // dibuja la pared superior
            mvprintw(20, i, "#"); // dibuja la pared inferior
            
        }
        
        for (int i = 0; i < 21; i++) {
        
            mvprintw(i, 0, "#"); // dibuja la pared izquierda
            mvprintw(i, 20, "#"); // dibuja la pared derecha
            
        }
        
        if (partituraRecogida == 0)
        {
            mvprintw(partituraY, partituraX, "*");
            
        }
        
        mvprintw(22, 0, "Partituras: %d", contadorPartituras); // en numero entero
        
        mvprintw(y, x, "@"); // dibuja a la violinista
        
        refresh(); // hace visible lo que acabamos de dibujar
        
        tecla = getch(); // es donde se va a guardar la tecla arriba, abajo, izquierda, derecha
        if (tecla == KEY_UP && y > 1)
            y--;
            
        else if (tecla == KEY_DOWN && y < 19)
            y++;
        else if (tecla == KEY_LEFT && x > 1)
            x--;
            
        else if (tecla == KEY_RIGHT && x < 19)
            x++;
            
        else if (tecla == 'q')
            break;
            
        if (x == partituraX && y == partituraY && partituraRecogida == 0) // aqui se pregunta si la columna y la fila de la violinista es la misma que la de la partitura
        {
        
            partituraRecogida = 1;
            contadorPartituras++;
            
        }
            
    }
    
    endwin(); // cierra ncurses correctamente
    
    return 0; // indica que el programa termino sin errores
    
} 
