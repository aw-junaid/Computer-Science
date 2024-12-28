### **Mini Gaming Framework in C: Design and Code Structure Documentation**

This document outlines the design and code structure of a simple **Mini Gaming Framework** implemented in C, simulating object-oriented programming (OOP) principles such as **encapsulation**, **inheritance**, and **polymorphism**. The framework consists of basic game objects (e.g., `Player`, `Enemy`) that can be moved, rendered, and interacted with in a game loop.

---

## **Design Overview**

The framework is based on simulating OOP principles in C using **structures** and **function pointers**. The design includes the following key concepts:

1. **Encapsulation**: Each game object (e.g., `Player`, `Enemy`) encapsulates its own properties, such as position, health, or attack power. The behaviors related to these properties are exposed through specific methods (functions).

2. **Inheritance**: The `Player` and `Enemy` types are derived from a common base type (`GameObject`). This inheritance allows both types to share common behavior (e.g., `move`, `render`) while implementing their specific logic.

3. **Polymorphism**: Different types of game objects can have different implementations of the `move` and `render` methods. These implementations are invoked dynamically through function pointers, achieving polymorphism in C.

---

## **Code Structure**

### **1. Header Files**

The code structure follows a modular approach with header files (`.h`) and implementation files (`.c`) to separate the declaration and definition of functions and structures.

#### **game_object.h**

This file defines the base structure `GameObject`, which holds common properties and function pointers for all game objects.

```c
// game_object.h
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

// Forward declaration of GameObject to allow function pointer references
typedef struct GameObject GameObject;

// Function pointers for move and render behaviors
typedef struct GameObject {
    int x, y;
    void (*move)(GameObject*);
    void (*render)(GameObject*);
} GameObject;

// Function prototypes
void init_game_object(GameObject* obj, int x, int y, void (*move)(GameObject*), void (*render)(GameObject*));
void render_game_object(GameObject* obj);
void move_game_object(GameObject* obj);

#endif // GAME_OBJECT_H
```

#### **player.h**

This file defines the `Player` class that extends the `GameObject` structure and includes specific methods for `move` and `render`.

```c
// player.h
#ifndef PLAYER_H
#define PLAYER_H

#include "game_object.h"

// Player structure, extending GameObject
typedef struct Player {
    GameObject base;  // Inherited GameObject structure
    int health;       // Player-specific property
} Player;

// Function prototypes
void init_player(Player* player, int x, int y, int health);
void player_move(GameObject* obj);
void player_render(GameObject* obj);

#endif // PLAYER_H
```

#### **enemy.h**

This file defines the `Enemy` class that also extends the `GameObject` structure and includes its own methods for `move` and `render`.

```c
// enemy.h
#ifndef ENEMY_H
#define ENEMY_H

#include "game_object.h"

// Enemy structure, extending GameObject
typedef struct Enemy {
    GameObject base;   // Inherited GameObject structure
    int attack_power;  // Enemy-specific property
} Enemy;

// Function prototypes
void init_enemy(Enemy* enemy, int x, int y, int attack_power);
void enemy_move(GameObject* obj);
void enemy_render(GameObject* obj);

#endif // ENEMY_H
```

---

### **2. Source Files**

The source files implement the logic for each class (object type) and methods.

#### **game_object.c**

This file defines the general functionality shared by all game objects, such as initializing the object, moving it, and rendering it.

```c
// game_object.c
#include "game_object.h"
#include <stdio.h>

void init_game_object(GameObject* obj, int x, int y, void (*move)(GameObject*), void (*render)(GameObject*)) {
    obj->x = x;
    obj->y = y;
    obj->move = move;
    obj->render = render;
}

void render_game_object(GameObject* obj) {
    obj->render(obj);  // Polymorphism: Calls the appropriate render method
}

void move_game_object(GameObject* obj) {
    obj->move(obj);  // Polymorphism: Calls the appropriate move method
}
```

#### **player.c**

This file defines the behavior for the `Player` class, including how the player moves and renders.

```c
// player.c
#include "player.h"
#include <stdio.h>

void player_move(GameObject* obj) {
    Player* player = (Player*)obj;
    player->base.x += 1;  // Example: Move player to the right
    printf("Player moved to (%d, %d)\n", player->base.x, player->base.y);
}

void player_render(GameObject* obj) {
    Player* player = (Player*)obj;
    printf("Rendering player at (%d, %d) with health %d\n", player->base.x, player->base.y, player->health);
}

void init_player(Player* player, int x, int y, int health) {
    init_game_object(&player->base, x, y, player_move, player_render);
    player->health = health;
}
```

#### **enemy.c**

This file defines the behavior for the `Enemy` class, including how the enemy moves and renders.

```c
// enemy.c
#include "enemy.h"
#include <stdio.h>

void enemy_move(GameObject* obj) {
    Enemy* enemy = (Enemy*)obj;
    enemy->base.y += 1;  // Example: Move enemy down
    printf("Enemy moved to (%d, %d)\n", enemy->base.x, enemy->base.y);
}

void enemy_render(GameObject* obj) {
    Enemy* enemy = (Enemy*)obj;
    printf("Rendering enemy at (%d, %d) with attack power %d\n", enemy->base.x, enemy->base.y, enemy->attack_power);
}

void init_enemy(Enemy* enemy, int x, int y, int attack_power) {
    init_game_object(&enemy->base, x, y, enemy_move, enemy_render);
    enemy->attack_power = attack_power;
}
```

---

### **3. Main Game File**

The `main.c` file includes the game loop where objects are instantiated and interacted with, simulating a simple game framework.

```c
// main.c
#include <stdio.h>
#include "player.h"
#include "enemy.h"

int main() {
    // Create player and enemy objects
    Player player;
    Enemy enemy;
    
    // Initialize player and enemy
    init_player(&player, 0, 0, 100);   // Player starts at (0, 0) with 100 health
    init_enemy(&enemy, 10, 10, 20);    // Enemy starts at (10, 10) with 20 attack power

    // Game loop: Move and render player and enemy
    for (int i = 0; i < 5; i++) {
        printf("\n--- Game Tick %d ---\n", i + 1);
        
        // Move and render player
        move_game_object((GameObject*)&player);
        render_game_object((GameObject*)&player);
        
        // Move and render enemy
        move_game_object((GameObject*)&enemy);
        render_game_object((GameObject*)&enemy);
    }

    return 0;
}
```

---

## **Key Design Patterns**

### **1. Inheritance**

The `Player` and `Enemy` classes "inherit" from the `GameObject` structure by embedding it as the first member. This allows them to share common properties (`x`, `y`) and behaviors (`move`, `render`) while providing their own specific implementations of these behaviors.

### **2. Polymorphism**

Polymorphism is achieved by using **function pointers** inside the `GameObject` structure. Each game object type (`Player`, `Enemy`) has its own implementations of `move` and `render` methods. These methods are dynamically invoked based on the object type at runtime.

### **3. Encapsulation**

Each class encapsulates its specific properties (`health` for the player, `attack_power` for the enemy) and provides methods to interact with them (`move` and `render`). The internals of each object type are hidden from the outside world, and interaction is done through defined interfaces.

---

## **Future Improvements**

1. **Collision Detection**: Add logic to check for collisions between objects and handle them appropriately (e.g., player losing health or enemy being destroyed).
2. **Event Handling**: Implement user input handling (e.g., keyboard events) to control the player’s movement.
3. **Animation**: Extend the `render` method to include animation logic (e.g., sprite rendering).
4. **AI for Enemy**: Implement basic artificial intelligence for enemy movement or behavior.

---

This design provides a scalable framework for simulating OOP concepts in C and can be extended further for more complex game mechanics.
