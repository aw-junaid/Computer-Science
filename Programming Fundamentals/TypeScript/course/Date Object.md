### TypeScript - Date Object

The `Date` object in TypeScript is used to work with dates and times. It provides functionality for creating, manipulating, and formatting dates. The `Date` object is part of JavaScript and is fully compatible with TypeScript.

---

### **1. Creating a Date Object**

You can create a `Date` object using the `Date` constructor in various ways:

#### **a. Current Date and Time**
```typescript
const now: Date = new Date();
console.log(now); // Outputs the current date and time
```

#### **b. Specific Date**
You can specify a date using the year, month, and day.

```typescript
const specificDate: Date = new Date(2024, 10, 19); // Year, Month (0-based), Day
console.log(specificDate); // Outputs: 2024-11-19T00:00:00.000Z
```

#### **c. Specific Date and Time**
Specify date and time components.

```typescript
const specificDateTime: Date = new Date(2024, 10, 19, 14, 30, 0);
console.log(specificDateTime); // Outputs: 2024-11-19T14:30:00.000Z
```

#### **d. From a Timestamp**
Pass a timestamp (milliseconds since the Unix Epoch).

```typescript
const fromTimestamp: Date = new Date(1672531200000);
console.log(fromTimestamp); // Outputs the corresponding date and time
```

#### **e. From a Date String**
Create a `Date` from a valid date string.

```typescript
const fromString: Date = new Date("2024-11-19T14:30:00Z");
console.log(fromString); // Outputs: 2024-11-19T14:30:00.000Z
```

---

### **2. Common Date Methods**

The `Date` object provides several methods for retrieving and manipulating date values.

#### **a. Getting Date and Time Components**
- **Date Components:**
```typescript
const date: Date = new Date();

console.log(date.getFullYear()); // Gets the year
console.log(date.getMonth());    // Gets the month (0-based: 0 = January)
console.log(date.getDate());     // Gets the day of the month
console.log(date.getDay());      // Gets the day of the week (0 = Sunday)
```

- **Time Components:**
```typescript
console.log(date.getHours());    // Gets the hours (0-23)
console.log(date.getMinutes());  // Gets the minutes (0-59)
console.log(date.getSeconds());  // Gets the seconds (0-59)
console.log(date.getMilliseconds()); // Gets milliseconds (0-999)
```

#### **b. Setting Date and Time Components**
Modify specific components of the date.

```typescript
const date: Date = new Date();

date.setFullYear(2025);
date.setMonth(5);       // June (0-based)
date.setDate(15);       // 15th day of the month
date.setHours(10);      // 10 AM
date.setMinutes(45);    // 45 minutes
date.setSeconds(30);    // 30 seconds

console.log(date); // Outputs the updated date and time
```

#### **c. Formatting Dates**
Format a date as a string.

```typescript
const date: Date = new Date();

console.log(date.toDateString()); // Outputs: "Tue Nov 19 2024"
console.log(date.toISOString());  // Outputs: "2024-11-19T00:00:00.000Z"
console.log(date.toLocaleDateString()); // Outputs: locale-specific date (e.g., "11/19/2024" in US)
console.log(date.toLocaleTimeString()); // Outputs: locale-specific time
console.log(date.toString());     // Outputs full date and time as a string
```

---

### **3. Working with Timestamps**

#### **a. Get Current Timestamp**
Retrieve the number of milliseconds since January 1, 1970 (Unix Epoch).

```typescript
const now: number = Date.now();
console.log(now); // Outputs the current timestamp
```

#### **b. Get Timestamp of a Specific Date**
Use `getTime()` to get the timestamp for a `Date` object.

```typescript
const date: Date = new Date("2024-11-19");
console.log(date.getTime()); // Outputs timestamp
```

#### **c. Compare Dates Using Timestamps**
Compare two dates by their timestamps.

```typescript
const date1: Date = new Date("2024-11-19");
const date2: Date = new Date("2024-12-19");

if (date1.getTime() < date2.getTime()) {
  console.log("Date1 is earlier than Date2");
} else {
  console.log("Date1 is later than or the same as Date2");
}
```

---

### **4. Adding/Subtracting Dates**

#### **a. Add Days**
Add days to a date.

```typescript
function addDays(date: Date, days: number): Date {
  const result = new Date(date);
  result.setDate(result.getDate() + days);
  return result;
}

const today = new Date();
const nextWeek = addDays(today, 7);
console.log(nextWeek);
```

#### **b. Subtract Days**
Subtract days by adding a negative number.

```typescript
const yesterday = addDays(today, -1);
console.log(yesterday);
```

#### **c. Add Time**
You can add time (e.g., hours or minutes) in a similar way:

```typescript
function addHours(date: Date, hours: number): Date {
  const result = new Date(date);
  result.setHours(result.getHours() + hours);
  return result;
}

const laterToday = addHours(new Date(), 5);
console.log(laterToday);
```

---

### **5. Comparing Dates**

#### **a. Direct Comparison**
Dates can be compared using comparison operators.

```typescript
const date1 = new Date("2024-11-19");
const date2 = new Date("2024-11-20");

console.log(date1 < date2); // true
console.log(date1 > date2); // false
console.log(date1 === date2); // false (different objects)
```

#### **b. Comparing Specific Components**
Compare only certain parts of the date.

```typescript
if (date1.getFullYear() === date2.getFullYear()) {
  console.log("Dates are in the same year.");
}
```

---

### **6. Handling Invalid Dates**

If a `Date` object cannot parse a value, it becomes `Invalid Date`.

```typescript
const invalidDate = new Date("invalid-date-string");
console.log(invalidDate); // Outputs: Invalid Date

console.log(isNaN(invalidDate.getTime())); // true: Indicates invalid date
```

---

### **7. Summary**

The `Date` object in TypeScript provides comprehensive methods for handling dates and times. Here are some key takeaways:

1. Use the `Date` constructor to create a date.
2. Retrieve and modify date and time components with `get` and `set` methods.
3. Use `Date.now()` for the current timestamp.
4. Manipulate dates with custom functions for adding or subtracting days or time.
5. Be cautious of `Invalid Date` when parsing strings.

The `Date` object is powerful and versatile for date manipulation, making it an essential tool for working with time-sensitive applications.
