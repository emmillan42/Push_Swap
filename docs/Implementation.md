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
