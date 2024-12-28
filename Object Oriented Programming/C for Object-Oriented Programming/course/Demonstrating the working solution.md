To demonstrate the working solution of the **Mini Gaming Framework in C** using object-oriented principles, follow these steps to compile and run the provided C code:

### **Step-by-Step Demonstration**

---

### **1. File Structure**

Ensure you have the following files in your project directory:

1. **game_object.h** - Contains the base `GameObject` structure and common functions.
2. **player.h** - Contains the `Player` class definition.
3. **enemy.h** - Contains the `Enemy` class definition.
4. **game_object.c** - Implements the `GameObject` functions.
5. **player.c** - Implements the `Player` class methods.
6. **enemy.c** - Implements the `Enemy` class methods.
7. **main.c** - Contains the main game loop that initializes and runs the game.

---

### **2. Full Code Listing**

Here is the full code for each file. You can copy-paste this into your development environment.

---

#### **game_object.h**

```c
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

typedef struct GameObject GameObject;

typedef struct GameObject {
    int x, y;
    void (*move)(GameObject*);
    void (*render)(GameObject*);
} GameObject;

void init_game_object(GameObject* obj, int x, int y, void (*move)(GameObject*), void (*render)(GameObject*));
void render_game_object(GameObject* obj);
void move_game_object(GameObject* obj);

#endif // GAME_OBJECT_H
```

---

#### **player.h**

```c
#ifndef PLAYER_H
#define PLAYER_H

#include "game_object.h"

typedef struct Player {
    GameObject base;
    int health;
} Player;

void init_player(Player* player, int x, int y, int health);
void player_move(GameObject* obj);
void player_render(GameObject* obj);

#endif // PLAYER_H
```

---

#### **enemy.h**

```c
#ifndef ENEMY_H
#define ENEMY_H

#include "game_object.h"

typedef struct Enemy {
    GameObject base;
    int attack_power;
} Enemy;

void init_enemy(Enemy* enemy, int x, int y, int attack_power);
void enemy_move(GameObject* obj);
void enemy_render(GameObject* obj);

#endif // ENEMY_H
```

---

#### **game_object.c**

```c
#include "game_object.h"
#include <stdio.h>

void init_game_object(GameObject* obj, int x, int y, void (*move)(GameObject*), void (*render)(GameObject*)) {
    obj->x = x;
    obj->y = y;
    obj->move = move;
    obj->render = render;
}

void render_game_object(GameObject* obj) {
    obj->render(obj); 
}

void move_game_object(GameObject* obj) {
    obj->move(obj);
}
```

---

#### **player.c**

```c
#include "player.h"
#include <stdio.h>

void player_move(GameObject* obj) {
    Player* player = (Player*)obj;
    player->base.x += 1;  
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

---

#### **enemy.c**

```c
#include "enemy.h"
#include <stdio.h>

void enemy_move(GameObject* obj) {
    Enemy* enemy = (Enemy*)obj;
    enemy->base.y += 1;  
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

#### **main.c**

```c
#include <stdio.h>
#include "player.h"
#include "enemy.h"

int main() {
    // Create player and enemy objects
    Player player;
    Enemy enemy;
    
    // Initialize player and enemy
    init_player(&player, 0, 0, 100);   
    init_enemy(&enemy, 10, 10, 20);    

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

### **3. Compiling and Running the Code**

To compile and run the program, follow these steps (assuming you are using GCC on a Linux/Unix system or have a similar setup):

1. **Open the terminal** in your project directory.

2. **Compile the code** using GCC. The command should look like this:

```bash
gcc -o game main.c game_object.c player.c enemy.c
```

This will compile all the C files into an executable named `game`.

3. **Run the program**:

```bash
./game
```

### **4. Output**

The game loop will run for 5 ticks, and you will see output similar to the following:

```text
--- Game Tick 1 ---
Player moved to (1, 0)
Rendering player at (1, 0) with health 100
Enemy moved to (10, 11)
Rendering enemy at (10, 11) with attack power 20

--- Game Tick 2 ---
Player moved to (2, 0)
Rendering player at (2, 0) with health 100
Enemy moved to (10, 12)
Rendering enemy at (10, 12) with attack power 20

--- Game Tick 3 ---
Player moved to (3, 0)
Rendering player at (3, 0) with health 100
Enemy moved to (10, 13)
Rendering enemy at (10, 13) with attack power 20

--- Game Tick 4 ---
Player moved to (4, 0)
Rendering player at (4, 0) with health 100
Enemy moved to (10, 14)
Rendering enemy at (10, 14) with attack power 20

--- Game Tick 5 ---
Player moved to (5, 0)
Rendering player at (5, 0) with health 100
Enemy moved to (10, 15)
Rendering enemy at (10, 15) with attack power 20
```

### **5. Explanation of Output**

- In each "Game Tick", both the `Player` and `Enemy` objects move and are rendered.
- The `move` method moves the objects based on their current `x` and `y` positions.
- The `render` method prints the current position and other relevant details (such as health for the player and attack power for the enemy).
- This demonstrates polymorphism, where the `move` and `render` methods are defined in each specific class (`Player` and `Enemy`), and the correct method is called at runtime based on the object type.

---

### **Conclusion**

This demonstrates how you can implement basic object-oriented concepts such as inheritance, polymorphism, and encapsulation in C using structures and function pointers. The framework provides a flexible design to extend further, adding more game objects, behaviors, and interactions.
