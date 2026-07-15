# Push_swap -- Algoritmo Turk (Implementación del proyecto)

## Objetivo

El algoritmo **Turk** es el algoritmo principal de complejidad
aproximada **O(n²)** que hemos implementado para ordenar pilas de tamaño
medio utilizando las operaciones permitidas por *push_swap*.

Nuestra implementación está dividida en módulos para separar claramente
las responsabilidades.

------------------------------------------------------------------------

# Arquitectura

``` text
sort_turk()
        │
        ├── Metadata
        │      ├── update_positions()
        │      ├── update_targets_*
        │      ├── update_costs_*
        │      └── find_cheapest()
        │
        ├── Movement
        │      ├── move_a_to_b()
        │      ├── move_b_to_a()
        │      ├── bring_to_top()
        │      ├── rotate_both()
        │      └── reverse_rotate_both()
        │
        └── Stack Operations
               pa pb sa sb ss
               ra rb rr
               rra rrb rrr
```

La idea principal es que **el algoritmo nunca calcula directamente
movimientos**. Primero genera toda la información (metadata) y después
ejecuta el movimiento óptimo.

------------------------------------------------------------------------

# Flujo del algoritmo

## 1. Preparación

Se envían dos elementos de `A` a `B`.

``` text
pb
pb
```

Esto garantiza que `B` tenga referencias para calcular los primeros
*targets*.

------------------------------------------------------------------------

## 2. Mover de A hacia B

Mientras `A` tenga más de tres elementos:

1.  Actualizar metadata (`update_metadata_a_to_b()`).
2.  Buscar el nodo más barato (`find_cheapest()`).
3.  Llevar simultáneamente el nodo y su target a la parte superior si es
    posible (`rr` / `rrr`).
4.  Terminar las rotaciones individuales.
5.  Ejecutar `pb`.

------------------------------------------------------------------------

## 3. Ordenar tres elementos

Cuando solo quedan tres nodos en `A` utilizamos:

``` text
sort_three()
```

Este algoritmo ya está completamente validado.

------------------------------------------------------------------------

## 4. Mover de B hacia A

Mientras `B` no esté vacío:

1.  Actualizar metadata (`update_metadata_b_to_a()`).
2.  Llevar el target de `A` arriba.
3.  Llevar el nodo de `B` arriba.
4.  Ejecutar `pa`.

------------------------------------------------------------------------

## 5. Rotación final

Al finalizar todos los elementos vuelven a `A`, pero el menor índice
puede no quedar arriba.

Se ejecuta:

``` text
final_rotation()
```

que coloca el índice 0 en el tope utilizando únicamente `ra` o `rra`,
según sea más barato.

------------------------------------------------------------------------

# Papel de cada módulo

## Metadata

Responsable de **calcular información**, nunca de mover nodos.

Calcula:

-   posición
-   above_median
-   target
-   coste
-   nodo más barato

No modifica las pilas.

------------------------------------------------------------------------

## Movement

Responsable únicamente de mover nodos.

Nunca calcula costes ni targets.

Utiliza la metadata previamente calculada.

Funciones principales:

-   move_a_to_b()
-   move_b_to_a()
-   bring_to_top()
-   rotate_both()
-   reverse_rotate_both()

------------------------------------------------------------------------

## Algorithm

Coordina todo el proceso.

No conoce cómo se calculan los costes ni cómo funcionan las operaciones
internas.

Simplemente sigue el flujo del algoritmo.

------------------------------------------------------------------------

# Idea del cálculo de costes

Cada nodo conoce:

-   cuántas rotaciones necesita en `A`;
-   cuántas rotaciones necesita su target en `B`.

El coste total es la combinación de ambos movimientos.

Después se marca un único nodo como:

``` text
cheapest = true
```

Ese será el siguiente en moverse.

------------------------------------------------------------------------

# Optimización principal

Si tanto el nodo como su target necesitan rotar en el mismo sentido:

``` text
rr
```

o

``` text
rrr
```

en lugar de rotarlos por separado.

Esto reduce significativamente el número de movimientos.

------------------------------------------------------------------------

# Separación de responsabilidades

  Módulo      Responsabilidad
  ----------- -----------------------------------------------------------
  Stack       Estructuras y operaciones básicas
  Metadata    Calcular información para decidir el siguiente movimiento
  Movement    Ejecutar movimientos usando la metadata
  Algorithm   Coordinar el flujo completo de Turk

Esta separación hace que cada módulo tenga una única responsabilidad y
facilita la depuración y las futuras mejoras.

------------------------------------------------------------------------

# Estado del algoritmo

La implementación actual ha sido validada mediante:

-   Casos manuales (8, 10, 15 y 20 elementos).
-   Las **720 permutaciones posibles de 6 elementos**.

Actualmente consideramos **Turk v1.0 congelado**, por lo que no se
modificarán sus reglas salvo que aparezca un caso de prueba que
demuestre un fallo real.
