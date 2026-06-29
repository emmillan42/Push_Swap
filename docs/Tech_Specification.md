# Push_swap — Especificación Técnica v1.0

## 1. Objetivos de diseño

Antes de hablar de código, definimos los principios que guiarán todas las decisiones.

### Principio 1 — Una responsabilidad por módulo

Cada archivo tendrá un único propósito.

Por ejemplo:

* `parser.c` → convertir argumentos en datos válidos.
* `push.c` → implementar únicamente `pa` y `pb`.
* `rotate.c` → implementar únicamente `ra`, `rb` y `rr`.

Esto facilita el mantenimiento y las pruebas.

---

### Principio 2 — Encapsulación

Ningún módulo debe modificar directamente la estructura interna de una pila si existe una función del módulo `stack/` u `operations/` para hacerlo.

Por ejemplo, evitaremos escribir:

```c
stack->top = stack->top->next;
```

fuera del módulo correspondiente.

---

### Principio 3 — Operaciones atómicas

Cada operación (`sa`, `pb`, `ra`, etc.) será:

* Correcta.
* Independiente.
* Completamente testeable.

Una vez implementadas, no volverán a modificarse.

---

### Principio 4 — El algoritmo no manipula punteros

El algoritmo nunca hará esto:

```c
node->next = ...
```

Solo utilizará:

```c
pb(a, b);
ra(a);
rra(a);
```

El algoritmo piensa. Las operaciones ejecutan.

---

# 2. Arquitectura general

```text
                 main()
                    │
                    ▼
              parser/
                    │
                    ▼
          stack_init()
                    │
                    ▼
         assign_index()
                    │
                    ▼
      update_metadata()
                    │
                    ▼
               sort()
                    │
         ┌──────────┴──────────┐
         │                     │
   operations/          metadata/
         │                     │
         └──────────┬──────────┘
                    ▼
              stack state
                    │
                    ▼
              stack_clear()
```

---

# 3. Estructuras de datos

## `t_node`

Propongo esta definición como versión definitiva:

```c
typedef struct s_node
{
	int				value;
	int				index;

	int				position;
	int				cost;

	bool			above_median;
	bool			cheapest;

	struct s_node	*target;

	struct s_node	*next;
	struct s_node	*prev;
}	t_node;
```

### Responsabilidad de cada campo

| Campo          | Responsable de actualizarlo |
| -------------- | --------------------------- |
| `value`        | Nunca cambia                |
| `index`        | `assign_index()`            |
| `position`     | `update_positions()`        |
| `above_median` | `update_positions()`        |
| `target`       | `update_targets()`          |
| `cost`         | `update_costs()`            |
| `cheapest`     | `update_cheapest()`         |

Importante: **cada dato tiene un único propietario**. Así evitamos inconsistencias.

---

## `t_stack`

```c
typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
	char	name;
}	t_stack;
```

### Invariantes

Siempre deben cumplirse estas reglas:

* `size == 0` ⇒> `top == NULL` y `bottom == NULL`
* `size == 1` ⇒> `top == bottom`
* `top->prev == NULL`
* `bottom->next == NULL`

Estas condiciones nos servirán para detectar errores durante el desarrollo.

---

# 4. Organización del proyecto

```
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
    ├── operations/
    ├── parser/
    ├── metadata/
    ├── sort/
    └── utils/
```

Novedad respecto al diseño anterior: un módulo específico llamado **`metadata/`**. Mejora mucho la separación de responsabilidades.

---

# 5. API pública por módulo

## parser/

### Pública

```c
bool	parse_args(	t_stack *a, int argc, char **argv);
```

### Privada (`static`)

```c
is_valid_number()
has_duplicates()
convert_to_long()
...
```

Ninguna función auxiliar será visible desde otros módulos.

---

## stack/

### Pública

```c
t_stack	*stack_init(char name);

void	      stack_clear(t_stack *stack);

t_node	*node_new(int value);

void	      stack_push_top(t_stack *stack, t_node *node);

void	      stack_push_bottom(t_stack *stack, t_node *node);

t_node      *stack_pop_top(t_stack *stack);

bool	      stack_is_sorted(t_stack *stack);
```

Estas funciones **no imprimen nada**. Solo gestionan la estructura de datos.

---

## operations/

Aquí propondría una pequeña mejora respecto a nuestra conversación anterior.

### Primitivas internas

```c
void	swap_stack(t_stack *stack);

void	push_stack(t_stack *src, t_stack *dst);

void	rotate_stack(t_stack *stack);

void	reverse_rotate_stack(t_stack *stack);
```

Estas funciones modifican únicamente las pilas.

### Operaciones oficiales

```c
void	sa(t_stack *a);

void	sb(t_stack *b);

void	ss(t_stack *a, t_stack *b);

void	pa(t_stack *a, t_stack *b);

void	pb(t_stack *a, t_stack *b);

void	ra(t_stack *a);

void	rb(t_stack *b);

void	rr(t_stack *a, t_stack *b);

void	rra(t_stack *a);

void	rrb(t_stack *b);

void	rrr(t_stack *a,	t_stack *b);
```

Estas son las únicas funciones que imprimen operaciones.

---

## metadata/

Este módulo será el "cerebro auxiliar".

### Pública

```c
void	update_metadata(t_stack *a,	t_stack *b);

void	assign_index(t_stack *stack);
```

### Privada (`static`)

```c
update_positions()

update_targets()

update_costs()

update_cheapest()
```

El algoritmo nunca llamará directamente a estas funciones privadas.

---

## sort/

La API pública podría ser tan simple como:

```c
void	sort(t_stack *a, t_stack *b);
```

Internamente decidirá:

```text
size == 2

↓

sort_two()

↓

size == 3

↓

sort_three()

↓

size <= 5

↓

sort_small()

↓

sort_large()
```

---

# 6. Flujo de ejecución

```text
main()

↓

parse_args()

↓

stack creada

↓

stack_is_sorted()

↓

(assign_index)

↓

sort()

↓

free()
```

Un detalle importante: si la pila ya está ordenada, salimos inmediatamente sin imprimir nada. Es una optimización sencilla y evita trabajo innecesario.

---

# 7. Gestión de errores

Quiero que sea completamente centralizada.

Propongo un módulo `utils/error.c` con una única función pública:

```c
void	error_exit(t_stack *a, t_stack *b);
```

Responsabilidades:

* Liberar ambas pilas (si existen).
* Escribir `Error\n` en `stderr`.
* Finalizar con `EXIT_FAILURE`.

Así evitamos duplicar lógica de limpieza por todo el proyecto.

---

# 8. Convenciones de nombres

Para mantener coherencia durante todo el proyecto, propongo estas reglas:

| Elemento           | Convención                         |
| ------------------ | ---------------------------------- |
| Estructuras        | `t_node`, `t_stack`                |
| Funciones públicas | `stack_init`, `parse_args`, `sort` |
| Funciones privadas | `static` y descriptivas            |
| Variables          | `a`, `b`, `node`, `target`, `cost` |
| Archivos           | `snake_case.c`                     |

---

# 9. Política de memoria

Cada `malloc()` tendrá un único responsable de liberar esa memoria.

Por ejemplo:

* `node_new()` reserva un nodo.
* `stack_clear()` libera todos los nodos de la pila.

Ningún otro módulo debe liberar nodos individuales salvo que la lógica de la operación lo requiera.

---

# 10. Estrategia de desarrollo

Aquí quiero proponerte algo que considero una mejora respecto a la mayoría de proyectos de 42. En lugar de implementar por carpetas, lo haremos por **capas funcionales**, asegurando que cada fase queda completamente terminada antes de pasar a la siguiente.

| Fase | Objetivo                        | Estado esperado                            |
| ---: | ------------------------------- | ------------------------------------------ |
|    1 | Definir estructuras y cabeceras | Compila sin errores                        |
|    2 | Implementar `stack/`            | Gestión completa de pilas                  |
|    3 | Implementar `operations/`       | Las 11 operaciones funcionan correctamente |
|    4 | Implementar `parser/`           | Entradas válidas e inválidas gestionadas   |
|    5 | Implementar `metadata/`         | Índices y metadatos correctos              |
|    6 | Implementar `sort_small()`      | Casos de 2 a 5 elementos óptimos           |
|    7 | Implementar `sort_large()`      | Algoritmo principal                        |
|    8 | Optimización y pruebas          | Proyecto listo para evaluación             |

---

# Una propuesta adicional: el módulo `check/`

Antes de escribir el algoritmo de ordenación, podríamos crear un pequeño conjunto de funciones de comprobación, usadas únicamente en modo depuración:

```c
bool	stack_is_valid(t_stack *stack);
bool	stack_links_are_valid(t_stack *stack);
bool	stack_size_is_consistent(t_stack *stack);
```

Estas funciones verificarían que:

* todos los enlaces `next` y `prev` son coherentes;
* `top` y `bottom` apuntan a los nodos correctos;
* `size` coincide con el número real de nodos.

Durante el desarrollo podríamos invocarlas después de cada operación (`sa`, `pb`, `ra`, etc.) para detectar errores estructurales en el mismo momento en que aparecen. Más adelante, bastaría con desactivar estas comprobaciones mediante una macro de compilación (`#ifdef DEBUG`) para que no formen parte de la versión final.

---
