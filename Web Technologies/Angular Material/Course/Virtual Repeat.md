**Angular Material** provides a **Virtual Scrolling** mechanism that enables efficient rendering of large lists of data by only rendering items that are currently visible on the screen. This is useful for optimizing performance when dealing with large datasets, as it reduces the number of DOM elements in the view and ensures smooth scrolling.

The **`cdk-virtual-scroll-viewport`** component is part of **Angular CDK** (Component Dev Kit), not directly part of Angular Material, but it integrates well with Angular Material components. It allows you to display large lists efficiently using virtual scrolling, where only a subset of items are rendered at any given time.

---

### 1. **Virtual Scroll Overview**

Virtual scrolling is a technique where only a subset of a large collection of data is rendered in the DOM. As the user scrolls through the list, new items are dynamically added while others are removed, reducing the rendering workload and improving performance.

Angular Material uses the **`CdkVirtualFor`** directive and the **`CdkVirtualScrollViewport`** component to implement virtual scrolling.

### 2. **Setting Up Virtual Scroll in Angular Material**

To get started with virtual scrolling in Angular Material, follow these steps:

#### Step 1: Install Angular CDK

First, make sure that Angular CDK is installed, as the virtual scroll feature is part of the **CDK (Component Dev Kit)**:

```bash
ng add @angular/cdk
```

#### Step 2: Import the Required Modules

In your **`app.module.ts`**, import **`ScrollingModule`** from **`@angular/cdk/scrolling`**:

```typescript
import { ScrollingModule } from '@angular/cdk/scrolling';
import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { AppComponent } from './app.component';

@NgModule({
  declarations: [AppComponent],
  imports: [BrowserModule, ScrollingModule],
  bootstrap: [AppComponent]
})
export class AppModule {}
```

The **`ScrollingModule`** provides the **`CdkVirtualScrollViewport`** component and other virtual scrolling-related utilities.

#### Step 3: Create Virtual Scroll in the Template

Now, in your component's template (e.g., **`app.component.html`**), use the **`cdk-virtual-scroll-viewport`** to create a virtual scrolling container. Inside the viewport, use **`cdkVirtualFor`** to loop through the list of items you want to display.

##### Example: Basic Virtual Scroll Implementation

```html
<cdk-virtual-scroll-viewport itemSize="50" class="viewport">
  <div *cdkVirtualFor="let item of items" class="item">
    {{ item }}
  </div>
</cdk-virtual-scroll-viewport>
```

- **`cdk-virtual-scroll-viewport`**: This is the container that manages the virtual scrolling and defines the size of the viewport.
  - **`itemSize`**: Specifies the height (or width, for horizontal scrolling) of each item in the list.
  - **`class="viewport"`**: Optional class to style the viewport.

- **`*cdkVirtualFor`**: Similar to `*ngFor`, this directive iterates over the items and renders only the items that are visible within the viewport.

##### Example: Complete Component Code

```typescript
import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss']
})
export class AppComponent {
  items = Array.from({ length: 1000 }, (_, i) => `Item ${i + 1}`);
}
```

Here:
- **`items`**: An array of 1000 items, each labeled `Item 1`, `Item 2`, ..., `Item 1000`.

##### Example: Styling the Virtual Scroll Viewport

You can add some basic styles to ensure that the virtual scroll container behaves as expected:

```scss
.viewport {
  height: 400px;  /* Height of the viewport */
  width: 100%;  /* Full width */
  border: 1px solid #ccc;
  overflow: auto;
}

.item {
  padding: 10px;
  border-bottom: 1px solid #ddd;
}
```

In this example, the **`viewport`** has a fixed height, and each **`item`** has some padding and a border for separation.

---

### 3. **Virtual Scroll with Angular Material Components**

You can use virtual scrolling with Angular Material components like **`mat-list`**, **`mat-table`**, or other containers to create rich user interfaces that work efficiently with large datasets.

#### Example: Virtual Scroll with `mat-list`

```html
<cdk-virtual-scroll-viewport itemSize="50" class="viewport">
  <mat-list>
    <mat-list-item *cdkVirtualFor="let item of items">
      {{ item }}
    </mat-list-item>
  </mat-list>
</cdk-virtual-scroll-viewport>
```

In this example:
- **`mat-list`**: A Material Design list container.
- **`mat-list-item`**: A Material Design list item that is used with virtual scrolling.

#### Example: Virtual Scroll with `mat-table`

You can also use virtual scrolling with **`mat-table`** to display tabular data.

```html
<cdk-virtual-scroll-viewport itemSize="50" class="viewport">
  <table mat-table [dataSource]="items">
    <ng-container matColumnDef="name">
      <th mat-header-cell *matHeaderCellDef> Name </th>
      <td mat-cell *matCellDef="let element"> {{element.name}} </td>
    </ng-container>

    <tr mat-header-row *matHeaderRowDef="displayedColumns"></tr>
    <tr mat-row *matRowDef="let row; columns: displayedColumns;"></tr>
  </table>
</cdk-virtual-scroll-viewport>
```

In this example:
- **`mat-table`**: The Material table component is used to display tabular data.
- **`displayedColumns`**: An array that defines which columns to display in the table.
- **`dataSource`**: An array that holds the data to be displayed.

You can also combine **`mat-paginator`** with virtual scrolling to provide pagination in combination with infinite scrolling.

---

### 4. **Advantages of Virtual Scrolling**

- **Performance**: Virtual scrolling improves the performance of your application by reducing the number of DOM elements rendered at any given time. This is especially important when dealing with large datasets (thousands or more items).
- **Smooth Scrolling**: As new items are dynamically loaded into the DOM, users experience smooth scrolling without lag.
- **Memory Efficiency**: Only a subset of items is rendered, which reduces memory usage and enhances the responsiveness of the application.

---

### 5. **Customizing Virtual Scroll Behavior**

You can customize how virtual scrolling behaves by adjusting properties of the **`cdk-virtual-scroll-viewport`** and the **`cdkVirtualFor`** directive:

- **`itemSize`**: Defines the height (or width) of each item. It is important to set this to the correct size of your items, as this helps Angular determine which items should be rendered in the viewport.
- **`minBufferPx`** and **`maxBufferPx`**: These properties control how many items should be preloaded above and below the viewport to avoid flickering during scrolling.

Example:

```html
<cdk-virtual-scroll-viewport itemSize="50" minBufferPx="100" maxBufferPx="200" class="viewport">
  <div *cdkVirtualFor="let item of items" class="item">
    {{ item }}
  </div>
</cdk-virtual-scroll-viewport>
```

In this example:
- **`minBufferPx`**: The minimum number of pixels to preload before the first item is rendered.
- **`maxBufferPx`**: The maximum number of pixels to preload after the last item is rendered.

---

### Conclusion

Angular Material’s **virtual scrolling** (via **`CdkVirtualScrollViewport`** and **`cdkVirtualFor`**) is a powerful tool for efficiently displaying large datasets. It ensures that only the items visible within the viewport are rendered, which improves performance and user experience.

By integrating virtual scrolling with other Angular Material components like **`mat-list`** or **`mat-table`**, you can create smooth, high-performance applications that handle large amounts of data effortlessly.
