#include <ncurses.h>  // se le dice al compilador que vamos a eusar esa biblioteca

int main () { // funcion principal

    int x = 10; // x es la columna de izquierda y derecha
    int y = 10; // y es la columna de arriba y abajo
    int tecla; // variable donde espera la respuesta del usuario con la tecla
    
    int partituraX[5] = {3, 15, 8, 17, 10}; //columna donde van a estar las partituras
    int partituraY[5] = {3, 5, 12, 16, 18}; // fila donde estaran las partituras
    
    int partituraRecogida[5] = {0, 0, 0, 0, 0,};
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
        
        for (int i = 6; i <= 11; i++) // recorre los valores
        {
            mvprintw(8, i, "#");
        }
        
        for (int i = 0; i < 5; i++) // se dibuja partituras sin recoger
        {
        
            if (partituraRecogida[i] == 0) // pregunta si la partitura existe
            {
                mvprintw(partituraY[i], partituraX[i], "*");
            
            }
        }
        mvprintw(22, 0, "Partituras: %d", contadorPartituras); // en numero entero
        
        mvprintw(y, x, "@"); // dibuja a la violinista
        
        refresh(); // hace visible lo que acabamos de dibujar
        
        tecla = getch(); // es donde se va a guardar la tecla arriba, abajo, izquierda, derecha
        if (tecla == KEY_UP && y > 1)// pregunta si el siguiente espacio esta libre
        {
            if (!(y - 1 == 8 && x >= 6 && x <= 11)) 
            {
                y--;
            }
        }
            
        else if (tecla == KEY_DOWN && y < 19)
        {
            if (!(y + 1 == 8 && x >= 6 && x <= 11))
            {
                y++;
            }
        }
        else if (tecla == KEY_LEFT && x > 1)
        {
            if (!(y == 8 && x -1 >= 6 && x - 1 <= 11))
            {
                x--;
            }
        }
        else if (tecla == KEY_RIGHT && x < 19)
        {
            if (!(y == 8 && x + 1 >= 6 && x + 1 <= 11))
            {
                x++;
            }
        }
        else if (tecla == 'q')
            break;
            
        for (int i = 0; i < 5; i++) // se revisa si se recogio la partitura
        {
            if (x == partituraX[i] && y == partituraY[i] && partituraRecogida[i] == 0)
            {
                partituraRecogida[i] = 1;
                contadorPartituras++;
            }
            
        }
        if (contadorPartituras == 5) // pregunta si recogio las 5 
        {
            clear(); // borra el escenario
            
            mvprintw(10, 3, "Felicidades!"); // mensaje de victoria
            mvprintw(11, 3, "Recuperaste todas las partituras.");
            mvprintw(13, 3, "Presiona cualquier tecla para salir.");
            
            refresh(); // hace que se vea el mensaje 
            getch(); //espera que el ususario presione una tecla
            
            break;
            
        }       
    }
    endwin(); // cierra ncurses correctamente
    
    return 0; // indica que el programa termino sin errores
    
} 
