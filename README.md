# Ajedrez en C++

Este es un programa simple de ajedrez implementado en C++. Permite jugar una partida básica de ajedrez en consola entre dos jugadores.

## Requisitos

- Compilador de C++ compatible (por ejemplo, GCC, Clang, Visual Studio)
- Sistema operativo compatible con C++ (Windows, Linux, macOS)

**Reglas del juego:**
   - El programa sigue las reglas básicas del ajedrez.
   - Para mover una pieza, ingresa la fila y columna de origen y destino cuando sea tu turno.
   - El programa verificará la validez de los movimientos y mostrará mensajes de error si es necesario.
   - El juego finaliza cuando se coma uno de los dos reyes



## Estructura del código

- `main.cpp`: Contiene la función principal `main` donde se gestiona el flujo del juego.
- `tablero.h`: Archivo de encabezado que define las estructuras y funciones relacionadas con el tablero y las piezas.
- `tablero.cpp`: Implementación de las funciones definidas en `tablero.h`.
- `gameplay.h`: Funciones que incluyen movimiento y verificaciones de las piezas.
- `gameplay.cpp`: Implementación de las funciones definidas en `gameplay.h`.


## Notas

- Este programa es un proyecto educativo y no contiene todas las características avanzadas del ajedrez.
- El código puede ser mejorado y optimizado para un uso más eficiente y funcional en el futuro.
