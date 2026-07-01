```
push_swap/
│
├── Makefile
├── includes/
│   └── push_swap.h
│
├── src/
│   ├── main.c
│   │
│   ├── parser/
│   │   ├── parser.c
│   │   ├── parser_utils.c
│   │   ├── split_args.c
│   │   └── validation.c
│   │
│   ├── stack/
│   │   ├── stack_init.c
│   │   ├── stack_node.c
│   │   ├── stack_push.c
│   │   ├── stack_pop.c
│   │   ├── stack_utils.c
│   │   └── stack_clear.c
│   │
│   ├── operations/
│   │   ├── swap.c
│   │   ├── push.c
│   │   ├── rotate.c
│   │   ├── reverse_rotate.c
│   │   └── operation_utils.c
│   │
│   ├── metadata/
│   │   ├── metadata1.c
│   │   ├── metadata2.c
│   │   ├── metadata3.c
│   │   ├── metadata4.c
│   │   ├── metadata5.c
│   │   └── metadata6.c
│   │
│   ├── sort/
│   │   ├── sort.c
│   │   ├── sort_small.c
│   │   ├── sort_large.c
│   │   ├── cost.c
│   │   ├── target.c
│   │   └── optimizer.c
│   │
│   ├── utils/
│   │   ├── error.c
│   │   ├── memory.c
│   │   └── math_utils.c
│   │
│   └── debug/
│       └── print_stack.c
│
├── libft/
│
└── tests/
    ├── stack/
    ├── operations/
    ├── parser/
    ├── metadata/
    ├── sort/
    └── utils/

push_swap/
│
├── Makefile
├── includes/
├── libft/
├── src/
│   ├── parser/
│   ├── stack/
│   ├── operations/
│   ├── metadata/
│   ├── sort/
│   ├── utils/
│   └── debug/
│
└── tests/
    ├── stack/
    │   ├── main_stack_init.c
    │   ├── main_stack_node.c
    │   ├── main_stack_push.c
    │   ├── main_stack_pop.c
    │   ├── main_stack_utils.c
    │   └── main_stack_clear.c
	│
    ├── operations/
    ├── parser/
    ├── metadata/
    ├── sort/
    └── utils/

               +----------------+
               |   push_swap    |
               +----------------+
                       │
          ┌────────────┴─────────────┐
          │                          │
      Algoritmo                   Parser
          │                          │
          └────────────┬─────────────┘
                       │
                Operaciones
                       │
                       ▼
                Stack Library
```

# Stack Library

## stack_init.c
### stack_init()
Responsabilidad: Crear una pila vacía.
Prototipo:
```c
t_stack	*stack_init(char name);
```
```
Entrada:
'A'
o
'B'
Salida:
Devuelve una pila correctamente inicializada
Error: Si falla malloc():
return (NULL);
Complejidad: O(1)
```

## stack_node.c
### node_new()
Responsabilidad: Crear un nodo completamente inicializado.
Prototipo:
```c
t_node	*node_new(int value);
```
```
Entrada:
int value;
Salida:
Un nodo correctamente inicializado.
Error: Si malloc() falla:
return (NULL);
Complejidad: O(1)
```

### node_free()
Responsabilidad: Liberar un nodo.
Prototipo:
```c
void	node_free(t_node *node);
```
```
Entrada:
Un nodo válido o NULL
Salida:
Ninguna.
Complejidad: O(1)
```

## stack_push.c
### stack_push_top
Responsabilidad:
Insertar un nodo al principio de la pila.
No reserva memoria. No imprime nada. No crea nodos. Sólo modifica punteros.
Prototipo:
```c
void	stack_push_top(t_stack *stack, t_node *node);
```
```
Precondiciones:
stack != NULL
node != NULL
Postcondiciones:
Después de ejecutarse node será el nuevo top y size aumentará en uno.
Complejidad: O(1)
```

### stack_push_bottom
Responsabilidad:
Añadir un nodo al final de la pila.
Prototipo:
```c
void	stack_push_bottom(t_stack *stack, t_node *node);
```
```
Precondiciones:
stack != NULL
node != NULL
Postcondiciones:
Node será el nuevo bottom. Size aumentará en uno.
```

## stack_pop.c
### stack_pop_top
Responsabilidad:
Extraer el primer nodo de la pila y devolverlo.
```
✅ devuelve el nodo.
✅ lo desenlaza completamente.
✅ actualiza la pila.
❌ no libera memoria.
❌ no modifica el contenido del nodo.
```
No libera memoria. No modifica el contenido del nodo. Simplemente lo desenlaza.
Prototipo:
```c
t_node	*stack_pop_top(t_stack *stack)
```
```
Entrada:
t_stack *stack
Salida:
Devuelve t_node *
Si la pila está vacía return (NULL);
Complejidad: O(1)
```

### stack_pop_bottom
Responsabilidad:
Extraer el último nodo de la pila y devolverlo.
```
✅ devuelve el nodo.
✅ lo desenlaza completamente.
✅ actualiza la pila.
❌ no libera memoria.
❌ no modifica el contenido del nodo.
```
No libera memoria. No modifica el contenido del nodo. Simplemente lo desenlaza.
Prototipo:
```c
t_node	*stack_pop_bottom(t_stack *stack);
```
```
Entrada:
t_stack *stack
Salida:
Devuelve t_node *
Si la pila está vacía return (NULL);
Complejidad: O(1)
```
## stack_insert.c
### stack_append
Responsabilidad:
Añadir un nuevo valor al final de la pila.
La función será responsable de:
reservar memoria para el nodo;
inicializarlo;
insertarlo al final de la pila.
No imprime.
No libera memoria.
Devuelve:
true si todo ha ido bien.
false si falla la reserva de memoria.
```c
bool	stack_append(t_stack *stack, int value)
```
```
Complejidad: O(1)
```
## stack_clear.c
### stack_clear
Responsabilidad:
Liberar completamente una pila.
```c
void	stack_clear(t_stack *stack)
```
La función debe liberar todos los nodos, liberar la estructura t_stack y liquidar la pila.
```
Complejidad: O(1)
```

## stack_utils.c
### stack_is_sorted
Responsabilidad:
Comprobar si una pila está ordenada de menor a mayor.
```
✅ Recorre la pila.
✅ No modifica ningún nodo.
✅ No reserva memoria.
✅ No libera memoria.
```
Prototipo
```c
bool	stack_is_sorted(t_stack *stack);
```
```
Complejidad: O(1)
```
```
|     Nº | Archivo         | Función               |  Estado  |
| -----: | --------------- | --------------------- |  :----:  |
|     01 | `stack_init.c`  | `stack_init()`        |    ✅   |
|     02 | `stack_node.c`  | `node_new()`          |    ✅   |
|     03 | `stack_node.c`  | `node_free()`         |    ✅   |
|     04 | `stack_push.c`  | `stack_push_top()`    |    ✅   |
|     05 | `stack_push.c`  | `stack_push_bottom()` |    ✅   |
|     06 | `stack_pop.c`   | `stack_pop_top()`     |    ✅   |
|     07 | `stack_pop.c`   | `stack_pop_bottom()`  |    ✅   |
|     08 | `stack_clear.c` | `stack_clear()`       |    ✅   |
|     09 | `stack_utils.c` | `stack_is_sorted()`   |    ✅   |

```

# Operations Library

## src/operations/

## swap.c
### swap_stack()
Responsabilidad:
Intercambiar los dos primeros nodos de una pila.
No imprime.
No reserva memoria.
No libera memoria.
No conoce las operaciones sa, sb o ss.
Prototipo:
```c
static void	swap_stack(t_stack *stack);
```
```
Complejidad
O(1)
```

### sa()
Responsabilidad:
Intercambiar los dos primeros nodos de la pila A.
Comprueba si puede actuar, llama a la primitiva, imprime.
Reutiliza swap_stack(). Imprime "sb\n". No contiene lógica de intercambio.
Prototipo:
```c
void	sa(t_stack *a)
```
Complejidad
O(1)

### sb()
Responsabilidad:
Intercambiar los dos primeros nodos de la pila B.
Comprueba si puede actuar, llama a la primitiva, imprime.
Reutiliza swap_stack(). Imprime "sb\n". No contiene lógica de intercambio.
Prototipo:
```c
void	sa(t_stack *b)
```
Complejidad
O(1)

### ss()
Responsabilidad:
Intercambiar simultáneamente los dos primeros elementos de ambas pilas.
Comprueba si puede actuar, llama a la primitiva, imprime.
Reutiliza swap_stack(). Imprime "ss\n". No contiene lógica de intercambio.
Prototipo:
```c
void	ss(t_stack *a, t_stack *b);
```
Complejidad
O(1)

| Nº | Archivo         | Función               | Estado |
| -: | --------------- | --------------------- | :----: |
| 01 | `stack_init.c`  | `stack_init()`        |    ✅   |
| 02 | `stack_node.c`  | `node_new()`          |    ✅   |
| 03 | `stack_node.c`  | `node_free()`         |    ✅   |
| 04 | `stack_push.c`  | `stack_push_top()`    |    ✅   |
| 05 | `stack_push.c`  | `stack_push_bottom()` |    ✅   |
| 06 | `stack_pop.c`   | `stack_pop_top()`     |    ✅   |
| 07 | `stack_pop.c`   | `stack_pop_bottom()`  |    ✅   |
| 08 | `stack_clear.c` | `stack_clear()`       |    ✅   |
| 09 | `stack_utils.c` | `stack_is_sorted()`   |    ✅   |
| 10 | `swap.c`        | `swap_stack()`        |    ✅   |
| 11 | `swap.c`        | `sa()`                |    ✅   |
| 12 | `swap.c`        | `sb()`                |   🚧   |
| 13 | `swap.c`        | `ss()`                |   🚧   |


## push.c
### push_stack()
Responsabilidad:
Mover el nodo situado en el top de la pila origen al top de la pila destino.
No imprime. No crea nodos. No destruye nodos. Simplemente mueve un nodo entre dos pilas.
Prototipo:
```c
static void	push_stack(t_stack *src, t_stack *dst);
```
Complejidad
O(1)

### pa()
Responsabilidad:
Mover el primer nodo de B hacia A. Imprime pa solo si realmente se ha movido un nodo.
No crea nodos. No destruye nodos. Simplemente mueve un nodo entre dos pilas.
Prototipo:
```c
void	pa(t_stack *a, t_stack *b);
```
Complejidad
O(1)

### pb()
Responsabilidad:
Mover el primer nodo de A hacia B. Imprime pb solo si realmente se ha movido un nodo.
No crea nodos. No destruye nodos. Simplemente mueve un nodo entre dos pilas.
Prototipo:
```c
void	pb(t_stack *b, t_stack *a);
```
Complejidad
O(1)


## rotate.c
### rotate_stack()
Responsabilidad:
Mover el primer nodo de la pila al final.
No imprime. No reserva memoria. No libera memoria.
Prototipo:
```c
static void	rotate_stack(t_stack *stack);
```
Complejidad
O(1)

### ra()
Responsabilidad:
Mover el primer nodo de la pila A al final. Imprime "ra\n" únicamente si la operación se realiza.
No crea nodos. No destruye nodos.
Prototipo:
```c
void	ra(t_stack *a)
```
Complejidad
O(1)

### rb()
Responsabilidad:
Mover el primer nodo de la pila B al final. Imprime "rb\n" únicamente si la operación se realiza.
No crea nodos. No destruye nodos.
Prototipo:
```c
void	rb(t_stack *b)
```
Complejidad
O(1)

### rr()
Responsabilidad:
Rotar simultáneamente las pilas A y B.
Debe imprimir únicamente: rr y solo si al menos una de las dos pilas ha rotado.
Prototipo:
```c
void	rr(t_stack *a, t_stack *b);
```
Complejidad
O(1)


## reverse_rotate.c
### reverse_rotate_stack()
Responsabilidad:
Mover el último nodo de la pila al principio.
No imprime. No reserva memoria. No libera memoria.
Prototipo:
```c
static void	reverse_rotate_stack(t_stack *stack);
```
Complejidad
O(1)

### rra()
Responsabilidad:
Rotar en sentido inverso la pila A. Reutiliza reverse_rotate_stack().
Imprime "rra\n" únicamente si se realiza la operación.
Prototipo:
```c
void	ra(t_stack *a)
```
Complejidad
O(1)

### rrb()
Responsabilidad:
Rotar en sentido inverso la pila B. Reutiliza reverse_rotate_stack().
Imprime "rrb\n" únicamente si se realiza la operación.
Prototipo:
```c
void	rb(t_stack *b)
```
Complejidad
O(1)

### rr()
Responsabilidad:
Ejecutar simultáneamente un reverse rotate sobre ambas pilas.
Debe imprimir únicamente: rrr y solo si al menos una de las dos pilas ha rotado.
Prototipo:
```c
void	rrr(t_stack *a, t_stack *b);
```
Complejidad
O(1)


# Parser Library

## src/parser/

## parser_atoi.c
### parse_int()
Responsabilidad:
Convertir una cadena en un entero.
Si la conversión es válida:
devuelve true, almacena el resultado en *value.
Si hay cualquier error:
devuelve false, no importa el contenido de *value.
Debe:
aceptar un signo opcional (+ o -);
comprobar que existe al menos un dígito;
detectar overflow;
rechazar cualquier carácter sobrante;
devolver el resultado mediante value.
No imprime. No reserva memoria. No finaliza el programa.
Prototipo:
```c
bool	parse_int(const char *str, int *value);
```
Complejidad
O(n)

### parse_sign()
Responsabilidad:
La función debe:
detectar + o detectar -. avanzar el puntero si existe un signo. devolver 1 o -1
No comprueba dígitos.
No convierte números.
No detecta overflow.
Prototipo:
```c
static int	parse_sign(const char **str)
```
Complejidad
O(1)

### parse_digits()
Responsabilidad:
Leer únicamente la parte numérica.
Debe:
comprobar que existe al menos un dígito;
convertir todos los dígitos;
detectar overflow;
dejar el puntero situado en el primer carácter no numérico.
No comprueba:
espacios;
signos;
caracteres finales.
Eso será responsabilidad de parse_int().
Prototipo:
```c
static bool	parse_digits(const char **str, int sign, long *number);
```
Complejidad
O(n)
