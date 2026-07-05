#include <ncurses.h>  // se le dice al compilador que vamos a usar esa biblioteca
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <json-c/json.h>

Mix_Music *musica = NULL;
Mix_Chunk *sonidoPartitura = NULL;
Mix_Chunk *sonidoVictoria = NULL;

int main () { // funcion principal

    int x = 10; // x es la columna de izquierda y derecha
    int y = 10; // y es la columna de arriba y abajo
    int tecla; // variable donde espera la respuesta del usuario con la tecla
    
    int partituraX[5] = {3, 15, 8, 17, 10}; //columna donde van a estar las partituras
    int partituraY[5] = {3, 5, 12, 16, 18}; // fila donde estaran las partituras
    
    int partituraRecogida[5] = {0, 0, 0, 0, 0,};
    int contadorPartituras = 0; // cantidad de partituras recogidas
    
    int escenarioX = 18; //variables para crear el escenario
    int escenarioY = 2;
    
    SDL_Init(SDL_INIT_AUDIO);
    
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    
    initscr(); // toma el control de la terminal
    musica = Mix_LoadMUS("assets/sounds/freesound_community-piano_violin-freesound-26340.mp3");

    sonidoPartitura = Mix_LoadWAV("assets/sounds/lumora_studios-pixel-coin-collect-197952.mp3");
    Mix_VolumeChunk(sonidoPartitura, 80);

    sonidoVictoria = Mix_LoadWAV("assets/sounds/u_it78ck90s3-orchestral-win-331233.mp3");

    Mix_PlayMusic(musica, -1);
    
    Mix_VolumeMusic(40);
     
    start_color(); // activa los colores en ncurses
    
    init_pair(1, COLOR_BLUE, COLOR_BLACK); // paredes
    init_pair(2, COLOR_GREEN, COLOR_BLACK); // partituras
    init_pair(3, COLOR_RED, COLOR_BLACK); // violinista
    init_pair(4, COLOR_YELLOW, COLOR_BLACK); // escenario
    init_pair(5, COLOR_CYAN, COLOR_BLACK); //contador
    
    keypad(stdscr, TRUE); // esta funcion le dice al programa cuales teclas especiales detectar
    // stdscr es pantalla principal y TRUE significa que esta activa
    while (1) { // aqui se crea un ciclo infinito
        clear(); // borra la pantalla para que no quede las posiciones viejas del personaje
        
        attron(COLOR_PAIR(1));
        for (int i = 0; i < 21; i++) {
    
            
            mvprintw(0, i, "#"); // dibuja la pared superior
            mvprintw(20, i, "#"); // dibuja la pared inferior
            
        }
        
        attroff(COLOR_PAIR(1));
        
        attron(COLOR_PAIR(1));
        for (int i = 0; i < 21; i++) {
            
            mvprintw(i, 0, "#"); // dibuja la pared izquierda
            mvprintw(i, 20, "#"); // dibuja la pared derecha
            
        }
        
        attroff(COLOR_PAIR(1));
        
        
        attron(COLOR_PAIR(1));
        for (int i = 6; i <= 11; i++) // recorre los valores
        {
            mvprintw(8, i, "#");
        }
        attroff(COLOR_PAIR(1));
        
        
        attron(COLOR_PAIR(2));
        
        for (int i = 0; i < 5; i++) // se dibuja partituras sin recoger
        {
        
            if (partituraRecogida[i] == 0) // pregunta si la partitura existe
            {
                mvprintw(partituraY[i], partituraX[i], "*");
            
            }
        }
        
        attroff(COLOR_PAIR(2));
        
        attron(COLOR_PAIR(4) | A_BOLD);
        
        if (contadorPartituras == 5)
        {
            mvprintw(escenarioY, escenarioX, "E");
        }
        attroff(COLOR_PAIR(4) | A_BOLD);
        
        attron(COLOR_PAIR(5));
        
        mvprintw(22, 0, "Partituras: %d", contadorPartituras); // en numero entero
        
        attroff(COLOR_PAIR(5));
        
        attron(COLOR_PAIR(3) | A_BOLD);
        
        mvprintw(y, x, "@"); // dibuja a la violinista
        
        attroff(COLOR_PAIR(3) | A_BOLD);
        
        refresh(); // hace visible lo que acabamos de dibujar
        
        tecla = getch(); // es donde se va a guardar la tecla arriba, abajo, izquierda, derecha
        if (tecla == KEY_UP && y > 1)// pregunta si el siguiente espacio esta libre
        {
            if (!(y - 1 == 8 && x >= 6 && x <= 11)) // si esta libre para subir
            {
                y--;
            }
        }
            
        else if (tecla == KEY_DOWN && y < 19)
        {
            if (!(y + 1 == 8 && x >= 6 && x <= 11)) // si esta libre para bajar
            {
                y++;
            }
        }
        else if (tecla == KEY_LEFT && x > 1) // si esta libre hacia la izquierda
        {
            if (!(y == 8 && x -1 >= 6 && x - 1 <= 11))
            {
                x--;
            }
        }
        else if (tecla == KEY_RIGHT && x < 19) // si esta libre hacia la derecha
        {
            if (!(y == 8 && x + 1 >= 6 && x + 1 <= 11))
            {
                x++;
            }
        }
        else if (tecla == 'q') // se presiona q para salir del juego
            break;
            
        for (int i = 0; i < 5; i++) // se revisa si se recogio la partitura
        {
            if (x == partituraX[i] && y == partituraY[i] && partituraRecogida[i] == 0)
            {
                partituraRecogida[i] = 1;
                contadorPartituras++;
                
                Mix_PlayChannel(-1, sonidoPartitura, 0);
            }
            
        }
        
        if (contadorPartituras == 5 &&
            x == escenarioX && y == escenarioY)
        {
        
            json_object *resultado = json_object_new_object();

            json_object_object_add(resultado, "partituras_recogidas", json_object_new_int(contadorPartituras));

            json_object_object_add(resultado, "concierto_alcanzado", json_object_new_boolean(1));

            FILE *archivo = fopen("resultado.json", "w");

            json_object_to_file_ext("resultado.json", resultado, JSON_C_TO_STRING_PRETTY);

            fclose(archivo);

            json_object_put(resultado);

            
            
            Mix_HaltMusic(); // aqui se detiene la musica de fondo para reproducir la de victoria
            
            Mix_PlayChannel(-1, sonidoVictoria, 0);
            
            clear();
          
            mvprintw(10, 3, "Felicidades!"); // mensaje de victoria
            mvprintw(11, 3, "Llegaste a tu ultimo concierto.");
            mvprintw(13, 3, "Presiona cualquier tecla para salir.");
   
            refresh(); // hace que se vea el mensaje 
            getch(); //espera que el ususario presione una tecla
            
            break;
            
        }       
    }
    endwin(); // cierra ncurses correctamente
    
    return 0; // indica que el programa termino sin errores
    
} 
