In Flask, rendering an HTML page involves creating routes and using templates to generate dynamic HTML content. Here's a simple example to help you get started:

1. **Project Structure:**
   Organize your Flask project with a structure like the following:

   ```
   /your_project
       /templates
           index.html
       app.py
   ```

2. **Create the HTML Template:**
   Inside the `templates` folder, create an HTML file, for example, `index.html`. This file will serve as your template.

   ```html
   <!-- templates/index.html -->
   <!DOCTYPE html>
   <html lang="en">
   <head>
       <meta charset="UTF-8">
       <meta name="viewport" content="width=device-width, initial-scale=1.0">
       <title>Flask HTML Example</title>
   </head>
   <body>
       <h1>Hello, Flask!</h1>
       <p>This is a simple HTML page rendered with Flask.</p>
   </body>
   </html>
   ```

3. **Create the Flask Application:**
   In your `app.py` file, create a simple Flask application with a route that renders the HTML template.

   ```python
   # app.py
   from flask import Flask, render_template

   app = Flask(__name__)

   @app.route('/')
   def index():
       return render_template('index.html')

   if __name__ == '__main__':
       app.run(debug=True)
   ```

4. **Run the Flask Application:**
   Open a terminal, navigate to your project directory, and run the Flask application.

   ```bash
   python app.py
   ```

   Visit `http://127.0.0.1:5000/` in your web browser, and you should see the rendered HTML page.

This example uses the `render_template` function from Flask to render the HTML template. The `index()` function specifies the route ("/") that triggers the rendering of the template.

Remember that this is a basic example, and you can extend it by passing dynamic data to the template, using template inheritance, and incorporating additional features as your application grows.
