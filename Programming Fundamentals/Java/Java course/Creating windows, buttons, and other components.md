Creating windows, buttons, and other components is a fundamental part of building **Graphical User Interfaces (GUIs)** in Java. Both **Swing** and **JavaFX** provide a rich set of components for creating interactive desktop applications. Below are examples of how to create windows, buttons, and other components using both frameworks.

---

### **1. Swing Components**

Swing provides a variety of components like buttons, labels, text fields, and more. Here's how to create a simple window with buttons and other components using Swing.

#### **Example: Swing Window with Buttons and Labels**
```java
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SwingWindowExample {
    public static void main(String[] args) {
        // Create the frame (window)
        JFrame frame = new JFrame("Swing Window Example");
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Create a panel to hold components
        JPanel panel = new JPanel();
        frame.add(panel);

        // Create a label
        JLabel label = new JLabel("Enter your name:");
        panel.add(label);

        // Create a text field
        JTextField textField = new JTextField(20);
        panel.add(textField);

        // Create a button
        JButton button = new JButton("Submit");
        panel.add(button);

        // Add an action listener to the button
        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String name = textField.getText();
                JOptionPane.showMessageDialog(frame, "Hello, " + name + "!");
            }
        });

        // Display the frame
        frame.setVisible(true);
    }
}
```

---

### **2. JavaFX Components**

JavaFX provides a modern and flexible way to create GUIs. It supports advanced features like CSS styling, animations, and FXML for declarative UI design.

#### **Example: JavaFX Window with Buttons and Labels**
```java
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class JavaFXWindowExample extends Application {
    @Override
    public void start(Stage primaryStage) {
        // Create a label
        Label label = new Label("Enter your name:");

        // Create a text field
        TextField textField = new TextField();

        // Create a button
        Button button = new Button("Submit");

        // Set an action for the button
        button.setOnAction(event -> {
            String name = textField.getText();
            System.out.println("Hello, " + name + "!");
        });

        // Create a layout and add components
        VBox root = new VBox(10); // 10 is the spacing between components
        root.getChildren().addAll(label, textField, button);

        // Create a scene
        Scene scene = new Scene(root, 300, 200);

        // Set the scene and show the stage
        primaryStage.setTitle("JavaFX Window Example");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
```

---

### **Common Components in Swing and JavaFX**

#### **1. Buttons**
- **Swing**:
  ```java
  JButton button = new JButton("Click Me");
  button.addActionListener(e -> System.out.println("Button Clicked!"));
  ```
- **JavaFX**:
  ```java
  Button button = new Button("Click Me");
  button.setOnAction(event -> System.out.println("Button Clicked!"));
  ```

#### **2. Labels**
- **Swing**:
  ```java
  JLabel label = new JLabel("This is a label");
  ```
- **JavaFX**:
  ```java
  Label label = new Label("This is a label");
  ```

#### **3. Text Fields**
- **Swing**:
  ```java
  JTextField textField = new JTextField(20); // 20 is the column width
  ```
- **JavaFX**:
  ```java
  TextField textField = new TextField();
  ```

#### **4. Checkboxes**
- **Swing**:
  ```java
  JCheckBox checkBox = new JCheckBox("Check Me");
  ```
- **JavaFX**:
  ```java
  CheckBox checkBox = new CheckBox("Check Me");
  ```

#### **5. Radio Buttons**
- **Swing**:
  ```java
  JRadioButton radioButton = new JRadioButton("Select Me");
  ButtonGroup group = new ButtonGroup();
  group.add(radioButton);
  ```
- **JavaFX**:
  ```java
  RadioButton radioButton = new RadioButton("Select Me");
  ToggleGroup group = new ToggleGroup();
  radioButton.setToggleGroup(group);
  ```

#### **6. Combo Boxes**
- **Swing**:
  ```java
  JComboBox<String> comboBox = new JComboBox<>(new String[]{"Option 1", "Option 2"});
  ```
- **JavaFX**:
  ```java
  ComboBox<String> comboBox = new ComboBox<>();
  comboBox.getItems().addAll("Option 1", "Option 2");
  ```

---

### **Layout Managers**

Both Swing and JavaFX provide layout managers to organize components in a window.

#### **1. Swing Layouts**
- **BorderLayout**:
  ```java
  JPanel panel = new JPanel(new BorderLayout());
  panel.add(new JButton("North"), BorderLayout.NORTH);
  panel.add(new JButton("Center"), BorderLayout.CENTER);
  ```
- **GridLayout**:
  ```java
  JPanel panel = new JPanel(new GridLayout(2, 2)); // 2 rows, 2 columns
  panel.add(new JButton("1"));
  panel.add(new JButton("2"));
  panel.add(new JButton("3"));
  panel.add(new JButton("4"));
  ```

#### **2. JavaFX Layouts**
- **VBox** (Vertical Box):
  ```java
  VBox root = new VBox(10); // 10 is the spacing between components
  root.getChildren().addAll(new Button("Button 1"), new Button("Button 2"));
  ```
- **HBox** (Horizontal Box):
  ```java
  HBox root = new HBox(10); // 10 is the spacing between components
  root.getChildren().addAll(new Button("Button 1"), new Button("Button 2"));
  ```
- **GridPane**:
  ```java
  GridPane grid = new GridPane();
  grid.add(new Button("1"), 0, 0); // Column 0, Row 0
  grid.add(new Button("2"), 1, 0); // Column 1, Row 0
  grid.add(new Button("3"), 0, 1); // Column 0, Row 1
  grid.add(new Button("4"), 1, 1); // Column 1, Row 1
  ```

---

### **Best Practices**

1. **Use Layout Managers**:
   - Use layout managers to organize components instead of hardcoding positions.

2. **Separate UI and Logic**:
   - Keep UI code separate from business logic for better maintainability.

3. **Use Event Listeners**:
   - Add event listeners to components to handle user interactions.

4. **Test on Multiple Platforms**:
   - Ensure your application works consistently across different platforms.

5. **Use FXML in JavaFX**:
   - Use FXML for declarative UI design in JavaFX.

---

By mastering the creation of windows, buttons, and other components, you can build interactive and user-friendly desktop applications in Java using Swing or JavaFX.
