# The Last Concert
## Descripción
The Last Concert es un videojuego desarrollado en lenguaje C para sistemas Linux. El jugador controla una violinista que debe recuperar las páginas perdidas de su partitura antes de llegar a su concierto final.
El proyecto se desarrolla como un trabajo final del curso IE-0117 y tiene como objetivo integrar bibliotecas de código abierto mientras se aplican los conceptos de programación aprendidos.
## Historia
Una violinista famosa va a presentar su último concierto de la carrera. Durante el viaje hacia el teatro, varias de las páginas del concierto se pierden y quedan despersas en el camino. Antes de inicar el concierto , deberá investigar a sus alrededores para recuperar las páginas faltantes y llegar al escenario con la partitura completa. Sin dichas partituras la violinista no puede realzar el concierto.
## Objetivo General
Desarrollar un videojuego interactivo que integre varias bibliotecas y que incluya los aprendizajes obtenidos en clase.
## Bibliotecas Utilizadas
-ncurses: interfaz en terminal y manejo de entradas del teclado
-json-c: Almacenamiento de los resultados de la partida en un archivo JSON.
-SDL_mixer: Reproducción de efectos de sonido y música.
## Características

- Movimiento del personaje mediante las teclas de dirección.
- Recolección de cinco partituras distribuidas por el escenario.
- Contador de partituras recolectadas.
- Aparición de la salida al completar la colección.
- Pantalla de victoria al llegar al concierto.
- Música de fondo durante la partida.
- Efectos de sonido al recoger partituras y al ganar.
- Almacenamiento del resultado final en un archivo JSON.

## Dependencias

Antes de compilar el proyecto es necesario instalar las siguientes bibliotecas:

```bash
sudo apt install libncurses-dev
sudo apt install libsdl2-dev
sudo apt install libsdl2-mixer-dev
sudo apt install libjson-c-dev

## Compilación y ejecución

Para compilar el proyecto:

```bash
make
```

Para ejecutar el juego:

```bash
make run
```

Para eliminar el ejecutable generado:

```bash
make clean
```

## Diseño del proyecto

El proyecto está organizado de la siguiente manera:

- src/: contiene el código fuente principal del juego.
- include/: archivos de cabecera.
- assets/: recursos utilizados por el juego, como sonidos.
- docs/: documentación del proyecto.
- experiments/: pruebas realizadas durante el desarrollo.

El juego utiliza la biblioteca ncurses para la interfaz en terminal, SDL2_mixer para la reproducción de música y efectos de sonido, y json-c para almacenar el resultado final del juego en un archivo JSON.



## Controles

- Flechas del teclado: mover a la violinista.
- Q: salir del juego.


## Autora

**Angie Arias**

Proyecto final del curso **IE-0117 Programación bajo Plataformas Abiertas**
Universidad de Costa Rica



