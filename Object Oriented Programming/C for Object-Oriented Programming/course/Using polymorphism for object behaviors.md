### **Using Polymorphism for Object Behaviors in C**

Polymorphism is one of the core principles of object-oriented programming (OOP), allowing objects of different types to be treated as objects of a common base type. In C, we can simulate polymorphism using **function pointers** within **structures**. This enables objects (such as `Player`, `Enemy`, etc.) to share a common interface but implement different behaviors for certain methods.

In this example, we'll simulate polymorphism by creating a base object (e.g., a `Character`) and allowing derived objects (e.g., `Player`, `Enemy`) to override the base methods.

---

### **Simulating Polymorphism with Function Pointers**

We’ll create a **base class** (`Character`) that has common attributes and methods, then define derived types (`Player` and `Enemy`) that implement different behaviors for methods like `attack` or `move`.

### **Step-by-Step Implementation**

1. **Define the Base Structure**: The `Character` structure will represent the base class, containing function pointers to simulate behavior.
2. **Define Derived Structures**: The `Player` and `Enemy` structures will embed the `Character` structure and override the behavior methods.
3. **Simulate Polymorphism**: We’ll demonstrate polymorphism by calling the overridden methods using function pointers, and each object will execute its own specific behavior.

---

### **1. Header File (`Character.h`)**

The header file will define the base structure and the common methods that all derived objects will implement.

```c
// Character.h
#ifndef CHARACTER_H
#define CHARACTER_H

// Define the Character structure with function pointers for polymorphism
typedef struct {
    int health;
    int x, y;  // Position

    // Function pointers to simulate polymorphism
    void (*move)(void*, int, int);
    void (*attack)(void*);
    void (*displayInfo)(void*);
} Character;

// Function declarations for Character
void initializeCharacter(Character* character, int health, int x, int y);
void moveCharacter(void* obj, int dx, int dy);
void attackCharacter(void* obj);
void displayCharacterInfo(void* obj);

#endif  // CHARACTER_H
```

### **Explanation of `Character.h`**:
- **Base Structure (`Character`)**: The base class `Character` has common attributes (`health`, `x`, `y`) and function pointers for polymorphic behaviors.
- **Function Declarations**: We declare the common functions (`move`, `attack`, `displayInfo`) that all characters will have, but the behavior will be implemented in the derived structures.

---

### **2. Source File (`Character.c`)**

This file contains the implementations of the common methods that can be shared across all character types.

```c
// Character.c
#include <stdio.h>
#include "Character.h"

// Initialize the Character object with default values
void initializeCharacter(Character* character, int health, int x, int y) {
    character->health = health;
    character->x = x;
    character->y = y;

    // Set default implementations for function pointers (can be overridden)
    character->move = moveCharacter;
    character->attack = attackCharacter;
    character->displayInfo = displayCharacterInfo;
}

// Default move method for all characters
void moveCharacter(void* obj, int dx, int dy) {
    Character* character = (Character*)obj;
    character->x += dx;
    character->y += dy;
    printf("Character moved to position (%d, %d)\n", character->x, character->y);
}

// Default attack method for all characters
void attackCharacter(void* obj) {
    Character* character = (Character*)obj;
    printf("Character attacks with basic damage. Health: %d\n", character->health);
}

// Default display info method for all characters
void displayCharacterInfo(void* obj) {
    Character* character = (Character*)obj;
    printf("Character Info:\n");
    printf("Health: %d\n", character->health);
    printf("Position: (%d, %d)\n", character->x, character->y);
}
```

### **Explanation of `Character.c`**:
- **`initializeCharacter`**: Initializes a `Character` object with basic health and position and assigns default behaviors (functions) to the function pointers.
- **Default Methods**: We implement basic versions of `move`, `attack`, and `displayInfo` methods, but these can be overridden in derived types (like `Player` and `Enemy`).

---

### **3. Derived Structures (`Player.c` and `Enemy.c`)**

We now create derived structures `Player` and `Enemy`, each of which overrides the `attack` method to provide specific behavior.

#### **Player Header File (`Player.h`)**:
```c
// Player.h
#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"

// Define the Player structure, which is derived from Character
typedef struct {
    Character base;  // Embed the base class
    int level;
} Player;

// Function declarations for Player
void initializePlayer(Player* player, int health, int x, int y, int level);
void attackPlayer(void* obj);

#endif  // PLAYER_H
```

#### **Player Source File (`Player.c`)**:
```c
// Player.c
#include <stdio.h>
#include "Player.h"

// Initialize the Player object
void initializePlayer(Player* player, int health, int x, int y, int level) {
    initializeCharacter(&player->base, health, x, y);  // Initialize base class
    player->level = level;

    // Override the attack method
    player->base.attack = attackPlayer;
}

// Player-specific attack method
void attackPlayer(void* obj) {
    Player* player = (Player*)obj;
    printf("Player with level %d attacks with a sword! Health: %d\n", player->level, player->base.health);
}
```

#### **Enemy Header File (`Enemy.h`)**:
```c
// Enemy.h
#ifndef ENEMY_H
#define ENEMY_H
#include "Character.h"

// Define the Enemy structure, which is derived from Character
typedef struct {
    Character base;  // Embed the base class
    int damage;
} Enemy;

// Function declarations for Enemy
void initializeEnemy(Enemy* enemy, int health, int x, int y, int damage);
void attackEnemy(void* obj);

#endif  // ENEMY_H
```

#### **Enemy Source File (`Enemy.c`)**:
```c
// Enemy.c
#include <stdio.h>
#include "Enemy.h"

// Initialize the Enemy object
void initializeEnemy(Enemy* enemy, int health, int x, int y, int damage) {
    initializeCharacter(&enemy->base, health, x, y);  // Initialize base class
    enemy->damage = damage;

    // Override the attack method
    enemy->base.attack = attackEnemy;
}

// Enemy-specific attack method
void attackEnemy(void* obj) {
    Enemy* enemy = (Enemy*)obj;
    printf("Enemy attacks with %d damage! Health: %d\n", enemy->damage, enemy->base.health);
}
```

### **4. Main File (`main.c`)**

In `main.c`, we’ll create instances of `Player` and `Enemy` and demonstrate polymorphism by calling their `attack` methods through the common `Character` interface.

```c
// main.c
#include <stdio.h>
#include "Player.h"
#include "Enemy.h"

int main() {
    // Create and initialize a Player
    Player player;
    initializePlayer(&player, 100, 0, 0, 5);

    // Create and initialize an Enemy
    Enemy enemy;
    initializeEnemy(&enemy, 50, 10, 10, 20);

    // Use polymorphism to call the appropriate attack method for each object
    Character* characterPtr = (Character*)&player;
    characterPtr->attack(characterPtr);  // Player's attack

    characterPtr = (Character*)&enemy;
    characterPtr->attack(characterPtr);  // Enemy's attack

    return 0;
}
```

### **Explanation of `main.c`**:

- **Creating Objects**: We create a `Player` and an `Enemy` object and initialize them using their respective functions.
- **Polymorphic Behavior**: By assigning the `Character` pointer to both `Player` and `Enemy`, we demonstrate polymorphism. The `attack` method is called through the common `Character` interface, but each object executes its specific implementation (`attackPlayer` for the player and `attackEnemy` for the enemy).

### **Compiling and Running the Code**

To compile and run the program, use the following command:

```bash
gcc -o game_program main.c Player.c Enemy.c Character.c
```

Then run the program:

```bash
./game_program
```

### **Output:**
```
Player with level 5 attacks with a sword! Health: 100
Enemy attacks with 20 damage! Health: 50
```

---

### **Benefits of Using Polymorphism in C**

1. **Flexible Behavior**: Polymorphism allows objects of different types to share a common interface, enabling different implementations for the same method (e.g., `attack`).
2. **Code Reusability**: The common interface (like `Character`) allows you to reuse the same code to interact with different types of objects, simplifying the codebase.
3. **Extensibility**: New types of characters (like `Boss`, `NPC`, etc.) can be added easily by defining new structures and overriding behavior methods.
4. **Simulating OOP**: By using function pointers in structures, we can simulate core OOP principles (like **polymorphism**, **inheritance**, and **encapsulation**) in C, even though C is not an object-oriented language.

---

### **Conclusion**

Using function pointers within structures allows you to simulate **polymorphism** in C, enabling objects to share a common interface but exhibit different behaviors depending on their type. This technique can be very useful for complex systems like game development, where you might need to model entities with different actions but similar interfaces. 
