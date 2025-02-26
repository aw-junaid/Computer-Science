Building simple desktop applications in Java can be done using either **Swing** or **JavaFX**. Both frameworks provide the tools needed to create windows, add components, handle events, and organize layouts. Below are examples of building a simple desktop application using both frameworks.

---

### **1. Building a Simple Desktop Application with Swing**

Swing is a legacy GUI framework that is part of the Java Standard Edition (SE). It is lightweight and easy to use for simple applications.

#### **Example: A Simple Calculator**

```java
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SwingCalculator extends JFrame {
    private JTextField display;
    private double firstNumber = 0;
    private String operator = "";

    public SwingCalculator() {
        // Set up the frame
        setTitle("Simple Calculator");
        setSize(300, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // Create the display
        display = new JTextField();
        display.setFont(new Font("Arial", Font.PLAIN, 24));
        display.setEditable(false);
        add(display, BorderLayout.NORTH);

        // Create the buttons
        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new GridLayout(4, 4, 10, 10));

        String[] buttons = {
            "7", "8", "9", "/",
            "4", "5", "6", "*",
            "1", "2", "3", "-",
            "0", ".", "=", "+"
        };

        for (String text : buttons) {
            JButton button = new JButton(text);
            button.setFont(new Font("Arial", Font.PLAIN, 18));
            button.addActionListener(new ButtonClickListener());
            buttonPanel.add(button);
        }

        add(buttonPanel, BorderLayout.CENTER);
    }

    private class ButtonClickListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            String command = e.getActionCommand();

            if (command.matches("[0-9.]")) {
                display.setText(display.getText() + command);
            } else if (command.matches("[+\\-*/]")) {
                firstNumber = Double.parseDouble(display.getText());
                operator = command;
                display.setText("");
            } else if (command.equals("=")) {
                double secondNumber = Double.parseDouble(display.getText());
                double result = 0;

                switch (operator) {
                    case "+":
                        result = firstNumber + secondNumber;
                        break;
                    case "-":
                        result = firstNumber - secondNumber;
                        break;
                    case "*":
                        result = firstNumber * secondNumber;
                        break;
                    case "/":
                        result = firstNumber / secondNumber;
                        break;
                }

                display.setText(String.valueOf(result));
            }
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            SwingCalculator calculator = new SwingCalculator();
            calculator.setVisible(true);
        });
    }
}
```

---

### **2. Building a Simple Desktop Application with JavaFX**

JavaFX is a modern GUI framework that provides more advanced features than Swing, such as CSS styling and animations.

#### **Example: A Simple To-Do List**

```java
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ListView;
import javafx.scene.control.TextField;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class JavaFXToDoList extends Application {
    @Override
    public void start(Stage primaryStage) {
        // Create the input field and button
        TextField taskInput = new TextField();
        taskInput.setPromptText("Enter a task");

        Button addButton = new Button("Add");
        addButton.setOnAction(event -> {
            if (!taskInput.getText().isEmpty()) {
                taskList.getItems().add(taskInput.getText());
                taskInput.clear();
            }
        });

        // Create the task list
        ListView<String> taskList = new ListView<>();

        // Create the layout
        HBox inputBox = new HBox(10, taskInput, addButton);
        VBox root = new VBox(10, inputBox, taskList);

        // Create the scene
        Scene scene = new Scene(root, 300, 400);

        // Set the scene and show the stage
        primaryStage.setTitle("To-Do List");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
```

---

### **Steps to Build a Simple Desktop Application**

1. **Choose a Framework**:
   - Decide whether to use **Swing** or **JavaFX** based on your requirements.

2. **Set Up the Window**:
   - Create a `JFrame` (Swing) or `Stage` (JavaFX) to serve as the main window.

3. **Add Components**:
   - Add components like buttons, text fields, labels, etc., to the window.

4. **Handle Events**:
   - Add event listeners to handle user interactions (e.g., button clicks).

5. **Organize Layout**:
   - Use layout managers (e.g., `BorderLayout`, `VBox`) to organize components.

6. **Run the Application**:
   - Display the window and start the application.

---

### **Best Practices**

1. **Separate UI and Logic**:
   - Keep UI code separate from business logic for better maintainability.

2. **Use Layout Managers**:
   - Use layout managers to ensure a responsive and organized UI.

3. **Handle Exceptions**:
   - Handle exceptions gracefully to prevent crashes.

4. **Test on Multiple Platforms**:
   - Ensure your application works consistently across different platforms.

5. **Use Modern Frameworks**:
   - Prefer **JavaFX** for new projects due to its modern features and flexibility.

---

By following these steps and best practices, you can build simple and effective desktop applications in Java using Swing or JavaFX.
