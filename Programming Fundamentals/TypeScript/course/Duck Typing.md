### TypeScript - Duck Typing

**Duck Typing** is a concept derived from the phrase "If it looks like a duck, swims like a duck, and quacks like a duck, it probably is a duck." In programming, Duck Typing is a type system concept where an object’s suitability is determined by the presence of certain methods and properties, rather than the actual type or class of the object.

In TypeScript, Duck Typing is achieved using **structural typing**. This means that an object is considered to be of a certain type if it has the necessary properties and methods, regardless of its explicit type declaration or class. TypeScript uses this approach, which is more flexible and focuses on the structure of the object.

### **1. Understanding Duck Typing in TypeScript**

TypeScript is a **structural typing** system, meaning that it doesn't require objects to explicitly declare the same type but instead checks whether an object has the required shape (properties and methods). This is different from **nominal typing**, which requires types to match exactly by name.

In TypeScript, Duck Typing can be demonstrated with interfaces and objects that match the interface structure without explicitly implementing the interface.

#### **Example: Duck Typing with Interfaces**

```typescript
interface Duck {
  quack(): void;
  swim(): void;
}

class Mallard {
  quack() {
    console.log("Quack!");
  }
  swim() {
    console.log("Swim in the lake!");
  }
}

class Penguin {
  quack() {
    console.log("Quack!");
  }
  swim() {
    console.log("Swim in cold waters!");
  }
}

function makeItQuack(duck: Duck) {
  duck.quack();  // Expecting an object that has quack() method
  duck.swim();   // Expecting an object that has swim() method
}

const mallard = new Mallard();
const penguin = new Penguin();

makeItQuack(mallard);   // Output: Quack! Swim in the lake!
makeItQuack(penguin);   // Output: Quack! Swim in cold waters!
```

- **Explanation**:
  - In this example, both `Mallard` and `Penguin` have the same structure (methods `quack` and `swim`), and TypeScript allows us to pass both to the `makeItQuack` function, even though they don't explicitly declare that they implement the `Duck` interface.
  - TypeScript checks that both classes have the required methods and treats them as `Duck` types because they match the structure of the `Duck` interface.

---

### **2. Benefits of Duck Typing in TypeScript**

1. **Flexibility**:
   Duck Typing allows TypeScript to be more flexible when working with objects, as it doesn’t enforce that the object explicitly implements an interface or extends a class. This makes it easier to work with different objects as long as they have the required properties.

2. **Loose Coupling**:
   Duck Typing encourages loose coupling because objects don't need to explicitly declare a common interface or inheritance. This promotes more adaptable and reusable code.

3. **Ad-hoc Types**:
   You can create types dynamically by checking if an object has certain properties, without requiring formal inheritance or interface implementation.

4. **Better Code Reusability**:
   Duck Typing enables more reusable functions or methods that can operate on a variety of object shapes as long as they conform to the expected structure.

---

### **3. Duck Typing Example in Functions**

One of the key places where Duck Typing shines is when writing functions that accept objects of various types that share certain characteristics.

```typescript
interface Flyer {
  fly(): void;
}

interface Swimmer {
  swim(): void;
}

function makeItFly(flyer: Flyer) {
  flyer.fly();
}

function makeItSwim(swimmer: Swimmer) {
  swimmer.swim();
}

class Bird implements Flyer {
  fly() {
    console.log("Flying high!");
  }
}

class Fish implements Swimmer {
  swim() {
    console.log("Swimming in the sea!");
  }
}

const bird = new Bird();
const fish = new Fish();

makeItFly(bird);   // Output: Flying high!
makeItSwim(fish);  // Output: Swimming in the sea!
```

- **Explanation**:
  - The `Bird` and `Fish` classes don’t have any explicit relationship, but they are passed to functions based on their method presence (`fly` for `Bird` and `swim` for `Fish`).
  - Duck Typing here allows these classes to interact with functions expecting specific methods, even though they don't explicitly declare conformance to an interface.

---

### **4. Duck Typing with Type Aliases**

You can also use Duck Typing with **type aliases** in TypeScript. A type alias allows you to define an object type without having to create a class or interface.

```typescript
type Car = {
  drive(): void;
  honk(): void;
};

type Boat = {
  sail(): void;
  honk(): void;
};

function testVehicle(vehicle: Car) {
  vehicle.drive();
  vehicle.honk();
}

const car: Car = {
  drive: () => console.log("Driving on the road!"),
  honk: () => console.log("Honk! Honk!")
};

const boat: Boat = {
  sail: () => console.log("Sailing in the water!"),
  honk: () => console.log("Boat horn!")
};

testVehicle(car);  // Output: Driving on the road! Honk! Honk!
testVehicle(boat); // Error: Argument of type 'Boat' is not assignable to parameter of type 'Car'
```

- **Explanation**:
  - The `testVehicle` function expects an object of type `Car`, but the `boat` object doesn’t match because it doesn’t have the `drive` method. Even though it has a `honk` method, the structure mismatch results in a TypeScript error.

---

### **5. TypeScript’s Structural vs. Nominal Typing**

In TypeScript:
- **Structural typing** (Duck Typing) is when an object is considered of a certain type if it has the required structure (properties and methods), not necessarily because it is explicitly declared as such.
- **Nominal typing** is when two types are considered compatible only if they explicitly share the same name or inheritance.

TypeScript uses **structural typing** by default, which means Duck Typing is its core behavior.

#### **Example of Structural Typing:**

```typescript
interface Point {
  x: number;
  y: number;
}

function logPoint(p: Point) {
  console.log(`Point is at (${p.x}, ${p.y})`);
}

const point1 = { x: 10, y: 20 };  // Object literal with the same structure
logPoint(point1);  // Output: Point is at (10, 20)

const point2 = { x: 30, y: 40, z: 50 };  // Object with extra property
logPoint(point2);  // Output: Point is at (30, 40)
```

- **Explanation**: 
  - Even though `point2` has an extra property `z`, it is still compatible with the `Point` interface because its structure matches.

---

### **6. When to Use Duck Typing**

Duck Typing is useful when:
- You are working with loosely-typed data or external data sources where the type may not be explicitly declared.
- You want to write functions that operate on multiple types of objects with shared behaviors but don’t need to require explicit type or interface declarations.
- You want to write generic, reusable code without worrying about the exact inheritance or class structure.

---

### **Conclusion**

Duck Typing in TypeScript leverages **structural typing**, allowing objects to be treated as certain types if they have the necessary properties or methods. It enables more flexible and reusable code because it focuses on the shape of objects rather than their declared types. This approach allows you to write more adaptable and maintainable software, especially when working with dynamic data or interfaces where explicit class or interface inheritance is not necessary.
