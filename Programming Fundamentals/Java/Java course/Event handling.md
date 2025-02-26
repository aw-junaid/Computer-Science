**Event handling** is a crucial aspect of building interactive applications. It allows your application to respond to user actions, such as button clicks, mouse movements, or keyboard input. Both **Swing** and **JavaFX** provide mechanisms for handling events.

---

### **Event Handling in Swing**

In Swing, event handling is done using **listeners**. A listener is an object that implements a specific interface (e.g., `ActionListener`, `MouseListener`) and is registered with a component (e.g., button, text field).

---

#### **1. ActionListener for Button Clicks**

The `ActionListener` interface is used to handle button clicks.

```java
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SwingEventExample {
    public static void main(String[] args) {
        // Create the frame
        JFrame frame = new JFrame("Swing Event Example");
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Create a panel
        JPanel panel = new JPanel();
        frame.add(panel);

        // Create a button
        JButton button = new JButton("Click Me");
        panel.add(button);

        // Add an ActionListener to the button
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

#### **2. MouseListener for Mouse Events**

The `MouseListener` interface is used to handle mouse events (e.g., click, enter, exit).

```java
import javax.swing.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class SwingMouseEventExample {
    public static void main(String[] args) {
        // Create the frame
        JFrame frame = new JFrame("Swing Mouse Event Example");
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Create a panel
        JPanel panel = new JPanel();
        frame.add(panel);

        // Create a label
        JLabel label = new JLabel("Hover or click here");
        panel.add(label);

        // Add a MouseListener to the label
        label.addMouseListener(new MouseListener() {
            @Override
            public void mouseClicked(MouseEvent e) {
                label.setText("Mouse Clicked!");
            }

            @Override
            public void mouseEntered(MouseEvent e) {
                label.setText("Mouse Entered!");
            }

            @Override
            public void mouseExited(MouseEvent e) {
                label.setText("Mouse Exited!");
            }

            @Override
            public void mousePressed(MouseEvent e) {}

            @Override
            public void mouseReleased(MouseEvent e) {}
        });

        // Display the frame
        frame.setVisible(true);
    }
}
```

---

### **Event Handling in JavaFX**

In JavaFX, event handling is done using **event handlers** or **lambda expressions**. JavaFX provides a more modern and flexible approach compared to Swing.

---

#### **1. EventHandler for Button Clicks**

The `EventHandler` interface is used to handle button clicks.

```java
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class JavaFXEventExample extends Application {
    @Override
    public void start(Stage primaryStage) {
        // Create a button
        Button button = new Button("Click Me");

        // Add an EventHandler to the button
        button.setOnAction(event -> System.out.println("Button Clicked!"));

        // Create a layout and add the button
        StackPane root = new StackPane();
        root.getChildren().add(button);

        // Create a scene
        Scene scene = new Scene(root, 300, 200);

        // Set the scene and show the stage
        primaryStage.setTitle("JavaFX Event Example");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
```

---

#### **2. MouseEvent for Mouse Actions**

JavaFX provides `MouseEvent` to handle mouse actions (e.g., click, hover).

```java
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class JavaFXMouseEventExample extends Application {
    @Override
    public void start(Stage primaryStage) {
        // Create a label
        Label label = new Label("Hover or click here");

        // Add MouseEvent handlers to the label
        label.setOnMouseClicked(event -> label.setText("Mouse Clicked!"));
        label.setOnMouseEntered(event -> label.setText("Mouse Entered!"));
        label.setOnMouseExited(event -> label.setText("Mouse Exited!"));

        // Create a layout and add the label
        StackPane root = new StackPane();
        root.getChildren().add(label);

        // Create a scene
        Scene scene = new Scene(root, 300, 200);

        // Set the scene and show the stage
        primaryStage.setTitle("JavaFX Mouse Event Example");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
```

---

### **Common Event Types**

#### **1. Action Events**
- Triggered by button clicks, menu selections, etc.
- **Swing**: `ActionListener`
- **JavaFX**: `EventHandler<ActionEvent>`

#### **2. Mouse Events**
- Triggered by mouse actions (click, hover, drag, etc.).
- **Swing**: `MouseListener`
- **JavaFX**: `MouseEvent`

#### **3. Key Events**
- Triggered by keyboard input.
- **Swing**: `KeyListener`
- **JavaFX**: `KeyEvent`

#### **4. Window Events**
- Triggered by window actions (close, minimize, etc.).
- **Swing**: `WindowListener`
- **JavaFX**: `WindowEvent`

---

### **Best Practices**

1. **Use Lambda Expressions**:
   - In JavaFX, prefer lambda expressions for concise event handling.

2. **Separate Event Handling Logic**:
   - Keep event handling logic separate from UI code for better maintainability.

3. **Use Adapter Classes**:
   - In Swing, use adapter classes (e.g., `MouseAdapter`) to avoid implementing all methods of a listener interface.

4. **Test Events**:
   - Ensure all events are tested for correct behavior.

5. **Avoid Blocking the Event Dispatch Thread**:
   - In Swing, avoid long-running tasks in event handlers to prevent freezing the UI.

---

### **Example: KeyEvent in JavaFX**

Handling keyboard input in JavaFX using `KeyEvent`.

```java
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.StackPane;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class JavaFXKeyEventExample extends Application {
    @Override
    public void start(Stage primaryStage) {
        // Create a text node
        Text text = new Text("Press a key");

        // Add a KeyEvent handler to the scene
        StackPane root = new StackPane();
        root.getChildren().add(text);

        Scene scene = new Scene(root, 300, 200);
        scene.setOnKeyPressed(event -> text.setText("Key Pressed: " + event.getCode()));

        // Set the scene and show the stage
        primaryStage.setTitle("JavaFX Key Event Example");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
```

---

By mastering event handling in Swing and JavaFX, you can create interactive and responsive desktop applications. Both frameworks provide powerful tools for handling user interactions effectively.
