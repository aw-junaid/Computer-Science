In **Angular Material**, there isn't a built-in **Toast** component like you might find in other UI libraries. However, you can easily create a toast (a small, temporary notification) in your Angular Material application using a combination of **MatSnackBar** (Material's snackbar component) and custom styles.

### What is a Toast?

A **Toast** is a small message that pops up on the screen for a short period to provide feedback to users. It doesn't require any user interaction and automatically disappears after a few seconds.

In **Angular Material**, the **`MatSnackBar`** component is used to display messages in a similar way, making it a great choice for implementing toasts.

---

### Steps to Create Toasts Using `MatSnackBar`

#### 1. **Install Angular Material**

If Angular Material is not installed in your project, you can add it by running:

```bash
ng add @angular/material
```

During the installation, you can choose a pre-built theme or create your own custom theme. You can also install Angular CDK and animations if they are not already installed.

#### 2. **Import MatSnackBar Module**

In your module file (`app.module.ts`), import the `MatSnackBarModule` to use the snackbar (toast) component.

```typescript
import { MatSnackBarModule } from '@angular/material/snack-bar';

@NgModule({
  declarations: [AppComponent],
  imports: [
    // other modules
    MatSnackBarModule
  ],
  bootstrap: [AppComponent]
})
export class AppModule {}
```

#### 3. **Using MatSnackBar for Toasts**

Now that you have set up the module, you can inject **`MatSnackBar`** into your component and use it to show toasts.

##### Example: Basic Toast Notification

In your component (`app.component.ts`), inject `MatSnackBar` and call its `open` method to show a toast.

```typescript
import { Component } from '@angular/core';
import { MatSnackBar } from '@angular/material/snack-bar';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  constructor(private snackBar: MatSnackBar) {}

  openToast(message: string) {
    this.snackBar.open(message, 'Close', {
      duration: 3000,  // Toast will disappear after 3 seconds
    });
  }
}
```

In the template (`app.component.html`):

```html
<button mat-button (click)="openToast('This is a toast message!')">Show Toast</button>
```

Here:
- The **`openToast()`** method triggers the display of a toast message using **`MatSnackBar.open()`**.
- The `duration` option controls how long the toast will be visible before automatically disappearing (in this case, 3000ms or 3 seconds).
- The **`'Close'`** label adds an optional action button to close the toast.

#### 4. **Customizing the Toast**

You can customize the appearance and behavior of the toast in several ways.

##### Example: Custom Duration, Position, and Action

```typescript
openToastWithCustomOptions() {
  this.snackBar.open('This is a custom toast!', 'Undo', {
    duration: 5000,  // The toast will be visible for 5 seconds
    horizontalPosition: 'center',  // Horizontal position (left, center, right)
    verticalPosition: 'top',  // Vertical position (top, bottom)
    panelClass: ['custom-toast'],  // Custom class for styling
  });
}
```

In this example:
- **`horizontalPosition`** and **`verticalPosition`** allow you to control where the toast appears on the screen (top, bottom, left, right, center).
- **`panelClass`** adds a custom CSS class to the snackbar, allowing you to style it further.

##### Example: Styling the Toast

You can define custom styles in your `styles.scss` (or `styles.css`) file to change the appearance of the toast.

```scss
.custom-toast {
  background-color: #4caf50;  // Green background
  color: white;  // White text
  font-size: 16px;  // Larger text size
  border-radius: 8px;  // Rounded corners
}
```

The **`.custom-toast`** class will be applied to the toast, changing its background color, text color, and other styling properties.

---

### 5. **Toast with Action (User Interaction)**

Sometimes, you might want to add an action button to the toast, such as **"Undo"** or **"Retry"**.

```typescript
openToastWithAction() {
  const snackBarRef = this.snackBar.open('Item deleted!', 'Undo', {
    duration: 5000
  });

  snackBarRef.onAction().subscribe(() => {
    console.log('Undo clicked!');
    // Handle the action (e.g., restore the deleted item)
  });
}
```

In this example:
- **`onAction()`** is used to handle the event when the user clicks on the action button (in this case, "Undo").
- You can perform any necessary action when the user clicks the button, such as undoing an operation.

---

### 6. **Toast with Custom Content**

You can also pass custom HTML or components inside the toast.

```typescript
import { Component } from '@angular/core';
import { MatSnackBar } from '@angular/material/snack-bar';
import { ComponentPortal } from '@angular/cdk/portal';
import { CustomToastComponent } from './custom-toast/custom-toast.component';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  constructor(private snackBar: MatSnackBar) {}

  openCustomToast() {
    this.snackBar.openFromComponent(CustomToastComponent, {
      duration: 3000,
      horizontalPosition: 'center',
      verticalPosition: 'top'
    });
  }
}
```

In this example, **`openFromComponent()`** is used to open a custom Angular component as a toast. You can pass in any component to render inside the toast.

The `CustomToastComponent` could look like this:

```typescript
import { Component } from '@angular/core';

@Component({
  selector: 'app-custom-toast',
  template: '<span class="toast-message">Custom toast content</span>',
})
export class CustomToastComponent {}
```

---

### Conclusion

While **Angular Material** does not provide a dedicated "toast" component, you can easily create toast notifications using **`MatSnackBar`**. The **`MatSnackBar`** component is flexible and allows you to customize the message, duration, position, appearance, and even add action buttons or custom content. It's a simple and effective way to implement toast notifications in your Angular Material application.
