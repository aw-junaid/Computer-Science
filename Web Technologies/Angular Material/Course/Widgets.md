In **Angular Material**, "widgets" typically refer to a collection of UI components designed to improve user interaction by following Material Design guidelines. These widgets include a variety of interactive and informative components like forms, buttons, dialogs, cards, sliders, and much more. They help developers create clean, responsive, and feature-rich applications.

Here are some of the most commonly used **Angular Material widgets** that can be used in your Angular applications:

### 1. **Button (`<mat-button>`)**
Angular Material provides a variety of button types, such as raised, flat, and icon buttons.

**Example:**
```html
<button mat-raised-button>Click Me</button>
<button mat-flat-button>Flat Button</button>
<button mat-icon-button>
  <mat-icon>home</mat-icon>
</button>
```

### 2. **Checkbox (`<mat-checkbox>`)**
The **checkbox** widget allows users to select or deselect options.

**Example:**
```html
<mat-checkbox>Accept Terms and Conditions</mat-checkbox>
```

### 3. **Radio Button (`<mat-radio-group>`)**
The **radio button** widget allows users to choose one option from a group of options.

**Example:**
```html
<mat-radio-group [(ngModel)]="selectedOption">
  <mat-radio-button value="option1">Option 1</mat-radio-button>
  <mat-radio-button value="option2">Option 2</mat-radio-button>
</mat-radio-group>
```

### 4. **Input Field (`<mat-input>` / `<mat-form-field>`)**
**Input fields** allow users to enter text. Material Design input fields come with labels, hints, and validation support.

**Example:**
```html
<mat-form-field>
  <mat-label>Username</mat-label>
  <input matInput placeholder="Enter your username" [(ngModel)]="username">
</mat-form-field>
```

### 5. **Select Dropdown (`<mat-select>`)**
The **select dropdown** widget allows users to choose an option from a dropdown list.

**Example:**
```html
<mat-form-field>
  <mat-label>Favorite Food</mat-label>
  <mat-select [(ngModel)]="selectedFood">
    <mat-option value="pizza">Pizza</mat-option>
    <mat-option value="burger">Burger</mat-option>
    <mat-option value="pasta">Pasta</mat-option>
  </mat-select>
</mat-form-field>
```

### 6. **Date Picker (`<mat-datepicker>`)**
The **date picker** widget allows users to select a date from a calendar pop-up.

**Example:**
```html
<mat-form-field>
  <mat-label>Pick a Date</mat-label>
  <input matInput [matDatepicker]="picker" placeholder="Choose a date" [(ngModel)]="selectedDate">
  <mat-datepicker #picker></mat-datepicker>
</mat-form-field>
```

### 7. **Slider (`<mat-slider>`)**
The **slider** widget is used for selecting a value from a range, such as volume control, brightness control, etc.

**Example:**
```html
<mat-slider min="1" max="100" step="1" [(ngModel)]="value"></mat-slider>
<p>Value: {{ value }}</p>
```

### 8. **Progress Bar (`<mat-progress-bar>`)**
The **progress bar** widget is used to show the progress of a task, such as file uploads or background tasks.

**Example:**
```html
<mat-progress-bar mode="indeterminate"></mat-progress-bar>
<mat-progress-bar mode="determinate" [value]="progressValue"></mat-progress-bar>
```

### 9. **Dialog (`<mat-dialog>`)**
The **dialog** widget is used for displaying modal pop-ups that can contain any content, such as forms or information.

**Example:**
```typescript
import { MatDialog } from '@angular/material/dialog';
import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
})
export class AppComponent {
  constructor(private dialog: MatDialog) {}

  openDialog(): void {
    this.dialog.open(DialogContentComponent);
  }
}
```

In the HTML:
```html
<button mat-raised-button (click)="openDialog()">Open Dialog</button>
```

**Dialog Content Component** (`dialog-content.component.ts`):
```typescript
@Component({
  selector: 'app-dialog-content',
  template: `<h1 mat-dialog-title>Dialog Title</h1>
             <div mat-dialog-content>Content goes here</div>
             <div mat-dialog-actions>
               <button mat-button mat-dialog-close>Close</button>
             </div>`
})
export class DialogContentComponent {}
```

### 10. **Snack Bar (`<mat-snack-bar>`)**
The **snack bar** widget is used to display brief messages at the bottom of the screen, often used for notifications or status updates.

**Example:**
```typescript
import { MatSnackBar } from '@angular/material/snack-bar';

@Component({
  selector: 'app-root',
  template: `<button mat-button (click)="openSnackBar()">Show Snack Bar</button>`
})
export class AppComponent {
  constructor(private snackBar: MatSnackBar) {}

  openSnackBar(): void {
    this.snackBar.open('Message sent!', 'Close', {
      duration: 2000,
    });
  }
}
```

### 11. **Bottom Sheet (`<mat-bottom-sheet>`)**
The **bottom sheet** widget slides up from the bottom of the screen to display additional content or actions.

**Example:**
```typescript
import { MatBottomSheet } from '@angular/material/bottom-sheet';
import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  template: `<button mat-raised-button (click)="openBottomSheet()">Open Bottom Sheet</button>`
})
export class AppComponent {
  constructor(private bottomSheet: MatBottomSheet) {}

  openBottomSheet(): void {
    this.bottomSheet.open(BottomSheetContentComponent);
  }
}
```

The `BottomSheetContentComponent` might look like this:
```typescript
@Component({
  selector: 'app-bottom-sheet-content',
  template: `<p>Content of the bottom sheet</p>
             <button mat-button (click)="close()">Close</button>`
})
export class BottomSheetContentComponent {
  constructor(private bottomSheetRef: MatBottomSheetRef<BottomSheetContentComponent>) {}

  close(): void {
    this.bottomSheetRef.dismiss();
  }
}
```

### 12. **Table (`<mat-table>`)**
The **table** widget is used for displaying data in rows and columns, often used in dashboards, reports, or any other structured data.

**Example:**
```html
<mat-table [dataSource]="data">
  <ng-container matColumnDef="name">
    <mat-header-cell *matHeaderCellDef>Name</mat-header-cell>
    <mat-cell *matCellDef="let row">{{ row.name }}</mat-cell>
  </ng-container>

  <ng-container matColumnDef="age">
    <mat-header-cell *matHeaderCellDef>Age</mat-header-cell>
    <mat-cell *matCellDef="let row">{{ row.age }}</mat-cell>
  </ng-container>

  <mat-header-row *matHeaderRowDef="displayedColumns"></mat-header-row>
  <mat-row *matRowDef="let row; columns: displayedColumns;"></mat-row>
</mat-table>
```

### 13. **Tooltip (`<mat-tooltip>`)**
The **tooltip** widget is used to display small informational messages when a user hovers over an element.

**Example:**
```html
<button mat-raised-button matTooltip="Click to save">Save</button>
```

### Conclusion:
Angular Material provides a rich set of **widgets** that can be used to build modern, responsive, and interactive UIs with minimal effort. These widgets follow **Material Design** principles, ensuring a consistent, well-designed interface. Whether you're creating forms, dialogs, tables, or buttons, Angular Material provides the tools you need for a great user experience.
