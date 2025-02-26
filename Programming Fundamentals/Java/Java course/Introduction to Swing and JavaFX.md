### **Introduction to Swing and JavaFX**

**Swing** and **JavaFX** are two popular frameworks for building **Graphical User Interfaces (GUIs)** in Java. Both frameworks allow developers to create desktop applications with rich user interfaces, but they differ in terms of architecture, features, and ease of use.

---

### **1. Swing**

**Swing** is a legacy GUI framework that has been part of the Java Standard Edition (SE) since Java 1.2. It is built on top of the **Abstract Window Toolkit (AWT)** and provides a rich set of components for building desktop applications.

#### **Key Features of Swing**
- **Lightweight Components**: Swing components are written entirely in Java and are not dependent on native platform components.
- **Pluggable Look-and-Feel**: Allows applications to have a consistent look across platforms or mimic the native platform's look.
- **Rich Component Library**: Includes buttons, labels, text fields, tables, trees, and more.
- **Customizable**: Components can be easily customized and extended.

#### **Example: Simple Swing Application**

```java
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SwingExample {
    public static void main(String[] args) {
        // Create the frame
        JFrame frame = new JFrame("Swing Example");
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Create a panel
        JPanel panel = new JPanel();
        frame.add(panel);

        // Create a button
        JButton button = new JButton("Click Me");
        panel.add(button);

        // Add an action listener to the button
        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(frame, "Button Clicked!");
            }
        });

        // Display the frame
        frame.setVisible(true);
    }
}
```

---

### **2. JavaFX**

**JavaFX** is a modern GUI framework introduced as a replacement for Swing. It provides a more powerful and flexible way to build rich desktop and mobile applications. JavaFX is not part of the Java SE but is included in the JDK since Java 8.

#### **Key Features of JavaFX**
- **Rich UI Controls**: Includes advanced controls like charts, tables, and media players.
- **CSS Styling**: Allows styling of UI components using CSS.
- **FXML**: Supports declarative UI design using XML-based FXML files.
- **Animation and Effects**: Provides built-in support for animations and visual effects.
- **3D Graphics**: Supports 3D graphics and transformations.
- **Scene Graph**: Uses a hierarchical scene graph to manage UI components.

#### **Example: Simple JavaFX Application**

```java
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class JavaFXExample extends Application {
    @Override
    public void start(Stage primaryStage) {
        // Create a button
        Button button = new Button("Click Me");

        // Set an action for the button
        button.setOnAction(event -> System.out.println("Button Clicked!"));

        // Create a layout and add the button
        StackPane root = new StackPane();
        root.getChildren().add(button);

        // Create a scene
        Scene scene = new Scene(root, 300, 200);

        // Set the scene and show the stage
        primaryStage.setTitle("JavaFX Example");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
```

---

### **Comparison: Swing vs JavaFX**

| Feature               | Swing                                      | JavaFX                                     |
|-----------------------|--------------------------------------------|--------------------------------------------|
| **Architecture**      | Built on AWT.                             | Built on a modern scene graph.             |
| **Look-and-Feel**     | Pluggable look-and-feel.                  | CSS-based styling.                         |
| **UI Controls**       | Basic controls (e.g., buttons, labels).   | Advanced controls (e.g., charts, media).   |
| **Animation**         | Limited support.                          | Built-in support for animations.           |
| **3D Graphics**       | Not supported.                            | Supported.                                 |
| **FXML**              | Not supported.                            | Supports declarative UI design with FXML.  |
| **Performance**       | Good for simple applications.             | Better for complex and modern UIs.         |

---

### **Best Practices**

1. **Choose the Right Framework**:
   - Use **Swing** for legacy applications or simple UIs.
   - Use **JavaFX** for modern, rich, and complex UIs.

2. **Separate UI and Logic**:
   - Keep UI code separate from business logic for better maintainability.

3. **Use FXML in JavaFX**:
   - Use FXML for declarative UI design in JavaFX.

4. **Leverage CSS in JavaFX**:
   - Use CSS for styling JavaFX applications.

5. **Test on Multiple Platforms**:
   - Ensure your application works consistently across different platforms.

---

### **Example: JavaFX with FXML**

JavaFX allows you to design UIs using FXML, which separates the UI design from the application logic.

#### **1. FXML File (`main.fxml`)**:
```xml
<?xml version="1.0" encoding="UTF-8"?>
<?import javafx.scene.control.Button?>
<?import javafx.scene.layout.StackPane?>

<StackPane xmlns="http://javafx.com/javafx/8" xmlns:fx="http://javafx.com/fxml/1">
    <Button text="Click Me" onAction="#handleButtonClick"/>
</StackPane>
```

#### **2. Controller Class (`MainController.java`)**:
```java
import javafx.fxml.FXML;
import javafx.scene.control.Button;

public class MainController {
    @FXML
    private Button button;

    @FXML
    private void handleButtonClick() {
        System.out.println("Button Clicked!");
    }
}
```

#### **3. JavaFX Application Class (`MainApp.java`)**:
```java
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class MainApp extends Application {
    @Override
    public void start(Stage primaryStage) throws Exception {
        // Load the FXML file
        Parent root = FXMLLoader.load(getClass().getResource("main.fxml"));

        // Create a scene
        Scene scene = new Scene(root, 300, 200);

        // Set the scene and show the stage
        primaryStage.setTitle("JavaFX FXML Example");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
```

---

By mastering Swing and JavaFX, you can build powerful and user-friendly desktop applications in Java. While Swing is suitable for simpler applications, JavaFX offers a more modern and feature-rich approach for complex UIs.
