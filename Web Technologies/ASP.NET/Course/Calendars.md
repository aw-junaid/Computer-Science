### ASP.NET - Calendars

In ASP.NET, **Calendar controls** are used to display dates, months, and years in a visual calendar format. These controls can be used in web applications to let users select dates, view events, or navigate between months and years. ASP.NET provides several types of calendar controls, the most common of which is the `Calendar` control.

### Key Features of the Calendar Control:
- **Display of days, weeks, and months**: It displays a grid representing months and days, making it easy to navigate.
- **Date selection**: Users can select a specific date from the calendar.
- **Customization**: You can customize the calendar's appearance, the start day of the week, and the selection format.
- **Event handling**: You can handle events like date selection, day render, and more.
- **Day highlighting**: Specific days or dates can be highlighted or marked as special.

### Steps to Use the Calendar Control in ASP.NET

#### 1. **Add the Calendar Control to the Page**

To use the `Calendar` control, simply place it in your ASPX page. The Calendar control displays a month view by default, and users can navigate between months and years.

#### Example: Basic Calendar Control
```html
<asp:Calendar ID="Calendar1" runat="server" Width="200px" />
```

- **ID**: The identifier for the Calendar control.
- **runat="server"**: This makes the control a server-side control that you can access in the code-behind.
- **Width**: The width of the calendar. You can adjust this to fit your layout.

#### 2. **Selecting a Date**

By default, the Calendar control allows users to click a date to select it. You can capture the selected date using the `SelectedDate` property.

#### Example: Handle Date Selection
```html
<asp:Label ID="lblSelectedDate" runat="server" Text="Select a date" />
<asp:Calendar ID="Calendar1" runat="server" OnSelectionChanged="Calendar1_SelectionChanged" />

<script runat="server">
    protected void Calendar1_SelectionChanged(object sender, EventArgs e)
    {
        lblSelectedDate.Text = "You selected: " + Calendar1.SelectedDate.ToString("D");
    }
</script>
```

- **OnSelectionChanged**: The event handler that fires when the user selects a date.
- **SelectedDate**: The property that contains the selected date.
- **Label (`lblSelectedDate`)**: A label to display the selected date.

#### 3. **Navigating Between Months and Years**

The Calendar control has built-in navigation buttons to allow users to move between months and years. You can customize this behavior, such as limiting the available months or setting a specific starting year.

#### Example: Disable Past Dates
You can restrict the calendar to show only future dates by handling the `DayRender` event.

```html
<asp:Calendar ID="Calendar1" runat="server" OnDayRender="Calendar1_DayRender" />

<script runat="server">
    protected void Calendar1_DayRender(object sender, DayRenderEventArgs e)
    {
        // Disable past dates
        if (e.Day.Date < DateTime.Today)
        {
            e.Day.IsSelectable = false;
        }
    }
</script>
```

- **DayRender**: This event is triggered for each day cell in the calendar. You can customize the rendering of days, disable specific days, or add styles.

#### 4. **Highlighting Specific Dates**

You can highlight specific dates, such as holidays or important events, by setting the `Day`’s `CssClass` in the `DayRender` event.

#### Example: Highlight a Specific Date
```html
<asp:Calendar ID="Calendar1" runat="server" OnDayRender="Calendar1_DayRender" />

<script runat="server">
    protected void Calendar1_DayRender(object sender, DayRenderEventArgs e)
    {
        // Highlight Christmas (25th December)
        if (e.Day.Date.Month == 12 && e.Day.Date.Day == 25)
        {
            e.Day.IsSelectable = false;  // Disable the date if needed
            e.Cell.BackColor = System.Drawing.Color.Red;
            e.Cell.ForeColor = System.Drawing.Color.White;
        }
    }
</script>
```

In this example, Christmas (December 25) is highlighted with a red background and white text.

#### 5. **Display Multiple Months**

If you want to display more than one month in the calendar, you can use the `VisibleDate` property to set the initial visible date, or you can create a custom calendar with multiple instances.

#### Example: Display Two Months
```html
<asp:Calendar ID="Calendar1" runat="server" Width="250px" />
<asp:Calendar ID="Calendar2" runat="server" Width="250px" />

<script runat="server">
    protected void Page_Load(object sender, EventArgs e)
    {
        Calendar2.VisibleDate = Calendar1.VisibleDate.AddMonths(1); // Show the next month in the second calendar
    }
</script>
```

This setup shows two months next to each other by setting the `VisibleDate` of the second calendar.

---

### Additional Features and Customization

1. **Change the Start Day of the Week**:
   You can set the starting day of the week using the `FirstDayOfWeek` property.

   ```html
   <asp:Calendar ID="Calendar1" runat="server" FirstDayOfWeek="Sunday" />
   ```

2. **Display Week Numbers**:
   The `ShowWeekNumbers` property allows you to display the week numbers.

   ```html
   <asp:Calendar ID="Calendar1" runat="server" ShowWeekNumbers="true" />
   ```

3. **Setting the Minimum and Maximum Date**:
   You can limit the calendar’s selectable dates using the `MinDate` and `MaxDate` properties.

   ```html
   <asp:Calendar ID="Calendar1" runat="server" MinDate="2024-01-01" MaxDate="2024-12-31" />
   ```

4. **Using CSS for Customization**:
   You can style the calendar using CSS to customize the look and feel.

   ```css
   .calendar-day {
       background-color: #f0f0f0;
   }
   .calendar-selected {
       background-color: #ffcc00;
   }
   ```

---

### Conclusion

The `Calendar` control in ASP.NET provides a flexible way to display and interact with dates. It is highly customizable, allowing you to:
- Handle date selections.
- Navigate between months and years.
- Highlight specific dates.
- Limit date selections (e.g., only allow future dates or restrict certain months).

By using the `DayRender` event, you can customize the behavior of each day cell and add additional functionality such as marking holidays or restricting past dates. You can also enhance the user experience by integrating the `Calendar` with other controls, such as the `TextBox` for date inputs or the `Button` for event handling.

This makes the `Calendar` control an essential tool for applications that require date-related input or display, such as booking systems, event scheduling, or even basic date selection forms.
