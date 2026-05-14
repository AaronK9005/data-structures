## Assignment: Implement a Concurrent LRU Cache in C

### Difficulty

Advanced undergraduate / interview-prep / systems-programming level

### Goal

Implement a **thread-safe Least Recently Used (LRU) cache** library in C with:

* O(1) average lookup
* O(1) insertion
* O(1) eviction
* configurable capacity
* generic key/value support
* optional persistence extension

This assignment combines:

* hash tables
* doubly linked lists
* memory management
* concurrency
* API design
* testing and benchmarking

---

# Functional Requirements

## Core Data Structure

Implement an LRU cache using:

1. **Hash table**

   * maps keys → nodes
   * enables O(1) lookup

2. **Doubly linked list**

   * stores usage order
   * head = most recently used
   * tail = least recently used

---

# Public API

Create these files:

```text
lru_cache.h
lru_cache.c
test.c
Makefile
```

---

## API Specification

```c
typedef struct lru_cache lru_cache_t;

typedef void* (*cache_key_copy_fn)(const void*);
typedef void* (*cache_value_copy_fn)(const void*);
typedef void  (*cache_free_fn)(void*);
typedef int   (*cache_compare_fn)(const void*, const void*);
typedef size_t (*cache_hash_fn)(const void*);

lru_cache_t* lru_cache_create(
    size_t capacity,
    cache_hash_fn hash_fn,
    cache_compare_fn compare_fn,
    cache_key_copy_fn key_copy_fn,
    cache_value_copy_fn value_copy_fn,
    cache_free_fn key_free_fn,
    cache_free_fn value_free_fn
);

void lru_cache_destroy(lru_cache_t* cache);

int lru_cache_put(
    lru_cache_t* cache,
    const void* key,
    const void* value
);

void* lru_cache_get(
    lru_cache_t* cache,
    const void* key
);

int lru_cache_remove(
    lru_cache_t* cache,
    const void* key
);

size_t lru_cache_size(
    lru_cache_t* cache
);

void lru_cache_print(
    lru_cache_t* cache
);
```

---

# Requirements

## 1. Generic Types

The cache must support arbitrary keys and values using function pointers.

Examples:

* string → string
* int → struct
* UUID → binary blob

---

## 2. Thread Safety

Use:

```c
pthread_mutex_t
```

Requirements:

* multiple threads may call `put/get/remove`
* no data races
* avoid deadlocks

Bonus:

* use reader/writer locks (`pthread_rwlock_t`)
* segment locking

---

## 3. Collision Handling

Implement one:

* chaining
* open addressing

You must justify your choice in a README.

---

## 4. Eviction Policy

When full:

* evict least recently used entry
* eviction must be O(1)

---

## 5. Memory Safety

No leaks allowed.

Must pass:

```bash
valgrind --leak-check=full
```

---

# Internal Design Constraints

## Node Structure

Example:

```c
typedef struct cache_node {
    void* key;
    void* value;

    struct cache_node* prev;
    struct cache_node* next;

    struct cache_node* hnext;
} cache_node_t;
```

---

## Time Complexity Targets

| Operation | Complexity   |
| --------- | ------------ |
| get       | O(1) average |
| put       | O(1) average |
| remove    | O(1) average |
| eviction  | O(1)         |

---

# Required Tests

Write tests for:

## Correctness

* insertion
* update existing key
* eviction order
* deletion
* empty cache behavior

## Concurrency

Spawn:

* 4 reader threads
* 4 writer threads

Run 1M operations total.

---

# Benchmark Program

Measure:

* throughput
* hit rate
* collision statistics

Compare:

* capacity = 1K
* capacity = 100K
* different hash functions

---

# Deliverables

## 1. Source Code

```text
src/
include/
tests/
bench/
```

---

## 2. README

Explain:

* architecture
* complexity
* synchronization strategy
* tradeoffs

---

## 3. Build System

Support:

```bash
make
make test
make bench
make clean
```

---

# Advanced Extensions (Choose 2)

## Option A — TTL Expiration

Support:

```c
put(key, value, ttl_ms)
```

Expired entries removed lazily.

---

## Option B — Persistence

Serialize cache to disk.

Functions:

```c
save_cache("cache.bin");
load_cache("cache.bin");
```

---

## Option C — Lock-Free Reads

Use:

* RCU
* atomics
* hazard pointers

---

## Option D — Sharded Cache

Split cache into N shards.

Reduces lock contention.

---

## Option E — Adaptive Replacement Cache (ARC)

Replace LRU with ARC policy.

Much harder.

---

# Evaluation Rubric

| Area                  | Points |
| --------------------- | ------ |
| Correctness           | 30     |
| Complexity guarantees | 20     |
| Memory safety         | 15     |
| Concurrency design    | 15     |
| Code quality          | 10     |
| Testing               | 10     |

---

# Suggested Development Order

1. Doubly linked list
2. Hash table
3. Single-threaded cache
4. Eviction logic
5. Generic API
6. Thread safety
7. Tests
8. Benchmarks
9. Extensions

---

# Optional Stretch Goal

Implement a production-grade cache with:

* slab allocator
* custom memory pool
* lock striping
* SIMD hashing
* statistics dashboard

---

# Example Usage

```c
lru_cache_t* cache = lru_cache_create(
    128,
    str_hash,
    str_compare,
    str_copy,
    str_copy,
    free,
    free
);

lru_cache_put(cache, "name", "alice");

char* value = lru_cache_get(cache, "name");

printf("%s\n", value);

lru_cache_destroy(cache);
```

---

# What You’ll Learn

This assignment teaches:

* systems programming
* ownership semantics
* generic interfaces in C
* synchronization
* cache design
* performance engineering
* debugging with Valgrind/GDB
* API architecture

If you'd like, I can also give:

* a harder assignment (B-tree, skip list, lock-free queue, radix tree, etc.)
* a university-style PDF spec
* starter code
* unit test skeletons
* grading scripts
* benchmark datasets
* interview-style variants
* a step-by-step roadmap without full solutions
