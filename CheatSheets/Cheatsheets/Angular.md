An extended Angular cheat sheet that covers essential commands, common functionalities, and explanations to help you work effectively with Angular.

---

# **Angular Extended Cheat Sheet**

## **1. Prerequisites**

### 1.1 Node.js Installation

Make sure you have Node.js installed. You can check by running:

```bash
node -v
```

### 1.2 Angular CLI Installation

To install Angular CLI globally, use:

```bash
npm install -g @angular/cli
```

**Explanation**: Installs the Angular Command Line Interface (CLI) globally on your machine, allowing you to create and manage Angular applications.

---

## **2. Creating a New Angular Project**

### 2.1 Create a New Project

**Command:**
```bash
ng new my-app
```

**Explanation**: Creates a new Angular project named `my-app`. The CLI will prompt you to set up routing and choose a stylesheet format (CSS, SCSS, etc.).

### 2.2 Navigate to Project Directory

**Command:**
```bash
cd my-app
```

**Explanation**: Changes the current directory to the newly created Angular project.

---

## **3. Serving the Application**

### 3.1 Start Development Server

**Command:**
```bash
ng serve
```

**Explanation**: Compiles the application and starts a development server. The application is usually accessible at `http://localhost:4200/`.

### 3.2 Specify Port

**Command:**
```bash
ng serve --port 4300
```

**Explanation**: Starts the server on port `4300` instead of the default `4200`.

---

## **4. Generating Components, Services, and Other Artifacts**

### 4.1 Generate a Component

**Command:**
```bash
ng generate component my-component
```
or
```bash
ng g c my-component
```

**Explanation**: Generates a new component named `my-component` and creates the necessary files in a `my-component` folder.

### 4.2 Generate a Service

**Command:**
```bash
ng generate service my-service
```
or
```bash
ng g s my-service
```

**Explanation**: Generates a new service named `my-service` and creates the necessary files.

### 4.3 Generate a Module

**Command:**
```bash
ng generate module my-module
```
or
```bash
ng g m my-module
```

**Explanation**: Generates a new module named `my-module`.

### 4.4 Generate a Directive

**Command:**
```bash
ng generate directive my-directive
```
or
```bash
ng g d my-directive
```

**Explanation**: Generates a new directive named `my-directive`.

### 4.5 Generate a Pipe

**Command:**
```bash
ng generate pipe my-pipe
```
or
```bash
ng g p my-pipe
```

**Explanation**: Generates a new pipe named `my-pipe`.

---

## **5. Working with Modules**

### 5.1 Importing Modules

To use Angular modules, import them in your module file, usually `app.module.ts`:

```typescript
import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { AppComponent } from './app.component';

@NgModule({
  declarations: [
    AppComponent
  ],
  imports: [
    BrowserModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
```

**Explanation**: The `NgModule` decorator is used to define an Angular module. You declare components in `declarations`, import other modules in `imports`, and specify the bootstrap component.

---

## **6. Routing in Angular**

### 6.1 Setting Up Routing

In `app-routing.module.ts`, set up routing:

```typescript
import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { MyComponent } from './my-component/my-component.component';

const routes: Routes = [
  { path: '', redirectTo: '/home', pathMatch: 'full' },
  { path: 'home', component: MyComponent }
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
```

**Explanation**: Defines the routes for the application. The `RouterModule.forRoot(routes)` method sets up the router with the given routes.

### 6.2 Adding Router Outlet

In your `app.component.html`, add the `<router-outlet>` directive:

```html
<router-outlet></router-outlet>
```

**Explanation**: This is where the routed components will be displayed.

---

## **7. Data Binding**

### 7.1 Interpolation

```html
<p>{{ title }}</p>
```

**Explanation**: Binds the `title` property from the component class to the template.

### 7.2 Property Binding

```html
<img [src]="imageUrl">
```

**Explanation**: Binds the `src` attribute of the `img` tag to the `imageUrl` property.

### 7.3 Event Binding

```html
<button (click)="onClick()">Click Me</button>
```

**Explanation**: Binds the button's click event to the `onClick()` method in the component.

### 7.4 Two-Way Data Binding

```html
<input [(ngModel)]="name">
```

**Explanation**: Binds the input value to the `name` property in both directions. (Note: Don't forget to import `FormsModule` in your module).

---

## **8. Services and Dependency Injection**

### 8.1 Creating a Service

Create a service using the CLI:

```bash
ng generate service data
```

**Explanation**: Creates a new service named `data.service.ts`.

### 8.2 Using a Service

Inject the service into a component:

```typescript
import { Component, OnInit } from '@angular/core';
import { DataService } from './data.service';

@Component({
  selector: 'app-my-component',
  templateUrl: './my-component.component.html',
})
export class MyComponent implements OnInit {
  constructor(private dataService: DataService) {}

  ngOnInit() {
    this.dataService.getData();
  }
}
```

**Explanation**: The `DataService` is injected into the `MyComponent` constructor, allowing you to use its methods.

---

## **9. Pipes**

### 9.1 Using Built-in Pipes

```html
<p>{{ birthday | date:'longDate' }}</p>
```

**Explanation**: Formats the `birthday` date using the `date` pipe.

### 9.2 Creating a Custom Pipe

Generate a pipe using the CLI:

```bash
ng generate pipe myCustomPipe
```

**Explanation**: Creates a new custom pipe.

#### Pipe Implementation Example:

```typescript
import { Pipe, PipeTransform } from '@angular/core';

@Pipe({
  name: 'myCustomPipe'
})
export class MyCustomPipe implements PipeTransform {
  transform(value: string): string {
    return value.toUpperCase();
  }
}
```

**Explanation**: This pipe transforms the input string to uppercase.

---

## **10. Forms in Angular**

### 10.1 Template-driven Forms

In your component:

```typescript
import { Component } from '@angular/core';

@Component({
  selector: 'app-my-form',
  templateUrl: './my-form.component.html'
})
export class MyFormComponent {
  model: any = {};
}
```

In your template:

```html
<form #myForm="ngForm" (ngSubmit)="onSubmit(myForm)">
  <input name="username" [(ngModel)]="model.username" required>
  <button type="submit">Submit</button>
</form>
```

**Explanation**: Sets up a template-driven form with two-way data binding using `ngModel`.

### 10.2 Reactive Forms

Import `ReactiveFormsModule` in your module, then create a form in your component:

```typescript
import { Component, OnInit } from '@angular/core';
import { FormBuilder, FormGroup } from '@angular/forms';

@Component({
  selector: 'app-reactive-form',
  templateUrl: './reactive-form.component.html'
})
export class ReactiveFormComponent implements OnInit {
  form: FormGroup;

  constructor(private fb: FormBuilder) {}

  ngOnInit() {
    this.form = this.fb.group({
      username: ['']
    });
  }

  onSubmit() {
    console.log(this.form.value);
  }
}
```

In your template:

```html
<form [formGroup]="form" (ngSubmit)="onSubmit()">
  <input formControlName="username">
  <button type="submit">Submit</button>
</form>
```

**Explanation**: Sets up a reactive form with `FormGroup` and `FormControl`.

---

## **11. Common Angular CLI Commands**

| Command                             | Description                                          |
|-------------------------------------|------------------------------------------------------|
| `ng serve`                          | Starts the development server.                       |
| `ng build`                          | Compiles the application into an output directory.   |
| `ng test`                           | Runs the unit tests for the application.             |
| `ng lint`                           | Lints the application code for errors.               |
| `ng e2e`                            | Runs end-to-end tests for the application.           |
| `ng update`                         | Updates your project dependencies.                   |
| `ng add <package>`                 | Adds support for an external library (e.g., Angular Material). |

---

## **12. Common

 Angular Patterns**

### 12.1 Async Pipe

Use the async pipe to handle Observables in the template:

```html
<ul>
  <li *ngFor="let item of items$ | async">{{ item }}</li>
</ul>
```

**Explanation**: The async pipe subscribes to the `items$` Observable and renders its values automatically.

### 12.2 Lifecycle Hooks

Common lifecycle hooks you can implement in your components:

- `ngOnInit()`: Called once the component is initialized.
- `ngOnChanges()`: Called when any data-bound input properties change.
- `ngOnDestroy()`: Cleanup just before Angular destroys the component.

---

## **Conclusion**

This cheat sheet provides a comprehensive overview of essential Angular commands, concepts, and usage patterns. It covers everything from setting up a new project to working with services, routing, forms, and more. As you gain more experience with Angular, you can delve deeper into advanced topics like state management, testing, and performance optimization. Happy coding!

--- 
