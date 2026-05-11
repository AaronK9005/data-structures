Krátká odpověď:

* malé “value” struktury → často na stacku,
* datové struktury s dynamickou pamětí → většinou kombinace stack + heap,
* opaque pointer API → profesionálnější a flexibilnější design.

Nejlepší je naučit se obě varianty.

---

# 1. Stack allocated struct

Typický začátek:

```c
typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} Vector;
```

Použití:

```c
Vector v;
vector_init(&v);

vector_push(&v, 10);

vector_free(&v);
```

Tady:

* samotná struktura `Vector` je na stacku,
* ale `data` jsou na heapu.

Tohle je velmi běžné a často nejlepší varianta.

---

# Proč je to dobré

Výhody:

* žádný extra `malloc` pro samotný objekt,
* méně pointer indirection,
* jednodušší ownership,
* rychlejší,
* idiomatické C.

Takhle funguje hodně C knihoven.

---

# 2. Fully heap allocated (opaque pointer)

Profesionálnější API:

```c
typedef struct Vector Vector;
```

V `.c`:

```c
struct Vector {
    int *data;
    size_t size;
    size_t capacity;
};
```

API:

```c
Vector *vector_create();
void vector_destroy(Vector *v);
```

Použití:

```c
Vector *v = vector_create();

vector_push(v, 123);

vector_destroy(v);
```

---

# Proč se to používá

Opaque pointer:

* schová implementaci,
* dovolí měnit interní layout,
* zlepšuje ABI stabilitu,
* simuluje OOP,
* uživatel nevidí internals.

Používají to:

* SDL
* OpenSSL
* SQLite
* GTK
* mnoho profesionálních C API

---

# Kdy použít stack-style API

Doporučuju pro učení.

Například:

* vector
* stack
* queue
* linked list

Protože:

* lépe chápeš ownership,
* méně magie,
* jednodušší debugging.

---

# Kdy opaque pointer

Když:

* píšeš knihovnu,
* chceš skrýt implementaci,
* chceš stabilní API,
* struktura je komplikovaná,
* interně používáš mutexy/alokátory/cache.

---

# Důležitá věc

I stack-based struct skoro vždy používá heap interně.

Například:

```c
Vector v;
```

je na stacku, ALE:

```c
v.data = malloc(...)
```

je heap.

To je úplně normální.

---

# Co je špatný nápad

Tohle:

```c
typedef struct {
    int data[1000000];
} BigStruct;
```

na stacku.

Proč:

* stack overflow,
* kopírování je drahé.

Velké věci → heap.

---

# Doporučený learning path

## Fáze 1

Implementuj:

```c
Vector v;
vector_init(&v);
```

Naučíš se:

* ownership,
* lifetime,
* pointery.

---

## Fáze 2

Přepiš na:

```c
Vector *v = vector_create();
```

Naučíš se:

* opaque types,
* API design,
* encapsulation.

---

# Důležitý rozdíl v ergonomii

## Stack style

```c
Vector v;
```

automatický cleanup musíš řešit ručně.

---

## Heap style

```c
Vector *v;
```

jasnější ownership:

* kdo vytvoří,
* ten destroyne.

---

# Co používám v praxi

## Interní programy / embedded

Často:

```c
Vector v;
```

---

## Public library API

Často opaque pointer.

---

# Moje doporučení pro tebe

Pro učení:

1. implementuj vše jako:

```c
Struct s;
init(&s);
free(&s);
```

2. potom udělej druhou verzi:

* opaque pointer,
* create/destroy API.

Tím pochopíš:

* stack vs heap,
* ownership,
* ABI,
* encapsulation,
* “object-oriented C”.

To je obrovsky cenné.
