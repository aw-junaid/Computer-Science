## **Date and Time API (`java.time`) in Java**
The **`java.time`** package was introduced in **Java 8** to address the limitations of `java.util.Date` and `java.util.Calendar`. It provides a modern, thread-safe, and easy-to-use API for handling date and time.

---

## **Key Features of `java.time` API**
✅ **Immutable & Thread-Safe** – No accidental modifications.  
✅ **Comprehensive API** – Supports local, zoned, and offset-based time.  
✅ **Better Readability** – Clearer method names and types.  
✅ **No `null` Issues** – Uses factory methods instead of constructors.  

---

## **Main Classes in `java.time` API**
| Class | Description |
|--------|-------------|
| `LocalDate` | Represents a **date** (year, month, day) without time. |
| `LocalTime` | Represents **time** (hour, minute, second) without a date. |
| `LocalDateTime` | Represents **both date and time** without timezone. |
| `ZonedDateTime` | Represents date, time, and **timezone**. |
| `OffsetDateTime` | Represents date, time, and **UTC offset**. |
| `Instant` | Represents an **exact timestamp** in UTC. |
| `Duration` | Measures the **time difference** between two instants. |
| `Period` | Measures the **date difference** between two dates. |
| `ZoneId` | Represents a **timezone ID** (e.g., `Asia/Karachi`). |

---

# **1. Working with `LocalDate` (Date Only)**
### ✅ **Creating a `LocalDate`**
```java
import java.time.LocalDate;

public class LocalDateExample {
    public static void main(String[] args) {
        LocalDate today = LocalDate.now();
        System.out.println("Today's Date: " + today);

        LocalDate specificDate = LocalDate.of(2025, 2, 27);
        System.out.println("Specific Date: " + specificDate);
    }
}
```
**Output:**
```
Today's Date: 2025-02-27
Specific Date: 2025-02-27
```

### ✅ **Getting Date Components**
```java
LocalDate date = LocalDate.of(2024, 12, 25);
System.out.println("Year: " + date.getYear());       // 2024
System.out.println("Month: " + date.getMonth());     // DECEMBER
System.out.println("Day: " + date.getDayOfMonth());  // 25
System.out.println("Day of Week: " + date.getDayOfWeek()); // WEDNESDAY
```

### ✅ **Modifying a `LocalDate`**
```java
LocalDate today = LocalDate.now();
LocalDate nextWeek = today.plusWeeks(1);
LocalDate lastMonth = today.minusMonths(1);

System.out.println("Next Week: " + nextWeek);
System.out.println("Last Month: " + lastMonth);
```

---

# **2. Working with `LocalTime` (Time Only)**
### ✅ **Creating a `LocalTime`**
```java
import java.time.LocalTime;

public class LocalTimeExample {
    public static void main(String[] args) {
        LocalTime now = LocalTime.now();
        System.out.println("Current Time: " + now);

        LocalTime specificTime = LocalTime.of(14, 30, 15);
        System.out.println("Specific Time: " + specificTime);
    }
}
```

### ✅ **Modifying Time**
```java
LocalTime time = LocalTime.of(10, 30);
LocalTime plusHours = time.plusHours(2);
LocalTime minusMinutes = time.minusMinutes(15);

System.out.println("Time + 2 Hours: " + plusHours);
System.out.println("Time - 15 Minutes: " + minusMinutes);
```

---

# **3. Working with `LocalDateTime` (Date & Time)**
### ✅ **Creating a `LocalDateTime`**
```java
import java.time.LocalDateTime;

public class LocalDateTimeExample {
    public static void main(String[] args) {
        LocalDateTime now = LocalDateTime.now();
        System.out.println("Current DateTime: " + now);

        LocalDateTime specificDateTime = LocalDateTime.of(2024, 12, 31, 23, 59);
        System.out.println("Specific DateTime: " + specificDateTime);
    }
}
```

### ✅ **Converting Between Types**
```java
LocalDateTime dateTime = LocalDateTime.now();
LocalDate date = dateTime.toLocalDate();
LocalTime time = dateTime.toLocalTime();

System.out.println("Date: " + date);
System.out.println("Time: " + time);
```

---

# **4. Working with `ZonedDateTime` (Date, Time & Timezone)**
### ✅ **Creating a `ZonedDateTime`**
```java
import java.time.ZonedDateTime;
import java.time.ZoneId;

public class ZonedDateTimeExample {
    public static void main(String[] args) {
        ZonedDateTime zonedDateTime = ZonedDateTime.now();
        System.out.println("Current Zoned DateTime: " + zonedDateTime);

        ZonedDateTime specificZone = ZonedDateTime.now(ZoneId.of("Asia/Karachi"));
        System.out.println("Karachi Time: " + specificZone);
    }
}
```

---

# **5. Working with `Instant` (Timestamps)**
### ✅ **Creating an `Instant`**
```java
import java.time.Instant;

public class InstantExample {
    public static void main(String[] args) {
        Instant now = Instant.now();
        System.out.println("Current Timestamp: " + now);
    }
}
```

---

# **6. Working with `Duration` and `Period` (Time Differences)**
### ✅ **Calculating `Duration` (Hours, Minutes, Seconds)**
```java
import java.time.Duration;
import java.time.LocalTime;

public class DurationExample {
    public static void main(String[] args) {
        LocalTime start = LocalTime.of(10, 0);
        LocalTime end = LocalTime.of(12, 30);
        Duration duration = Duration.between(start, end);
        
        System.out.println("Hours: " + duration.toHours()); // 2
        System.out.println("Minutes: " + duration.toMinutes()); // 150
    }
}
```

### ✅ **Calculating `Period` (Years, Months, Days)**
```java
import java.time.LocalDate;
import java.time.Period;

public class PeriodExample {
    public static void main(String[] args) {
        LocalDate birthDate = LocalDate.of(2000, 5, 15);
        LocalDate today = LocalDate.now();

        Period age = Period.between(birthDate, today);
        System.out.println("Age: " + age.getYears() + " years, " + age.getMonths() + " months");
    }
}
```

---

## **7. Formatting and Parsing Dates (`DateTimeFormatter`)**
### ✅ **Formatting a Date**
```java
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class FormattingExample {
    public static void main(String[] args) {
        LocalDateTime now = LocalDateTime.now();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd-MM-yyyy HH:mm:ss");
        String formattedDate = now.format(formatter);

        System.out.println("Formatted Date: " + formattedDate);
    }
}
```

### ✅ **Parsing a Date String**
```java
String dateStr = "27-02-2025 14:30:00";
DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd-MM-yyyy HH:mm:ss");
LocalDateTime dateTime = LocalDateTime.parse(dateStr, formatter);
System.out.println(dateTime);
```

---

## **Conclusion**
- `java.time` replaces old `Date` and `Calendar` APIs with **immutable**, **readable**, and **thread-safe** classes.
- It provides **clear separation** between date, time, and timezone handling.
- Supports **ISO formatting** and **custom patterns** for date formatting.
