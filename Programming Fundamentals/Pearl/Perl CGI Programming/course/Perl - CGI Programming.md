### Perl - CGI Programming

CGI (Common Gateway Interface) programming is a method for web servers to interact with external applications to generate dynamic web content. Perl, with its simplicity and powerful text processing capabilities, is widely used for CGI programming. A Perl CGI script typically generates HTML content in response to HTTP requests.

### 1. **Setting Up a Perl CGI Script**

To use Perl for CGI programming, the following setup is necessary:

1. **Web Server**: A web server like Apache is required. Make sure the server is configured to allow CGI scripts.
2. **CGI Directory**: The web server must be set up to execute scripts in a specific directory (e.g., `cgi-bin`).

#### Example Directory Structure:
```shell
/var/www/html/
    └── cgi-bin/
        └── script.pl
```

3. **Permissions**: Make sure the Perl CGI script has the correct file permissions (`chmod 755 script.pl`).

---

### 2. **Creating a Simple CGI Script**

A basic CGI script in Perl will output an HTTP header followed by HTML content.

#### Example: Basic CGI Script

```perl
#!/usr/bin/perl
use strict;
use warnings;

# Print HTTP header (Content-Type)
print "Content-type: text/html\n\n";

# Print the HTML content
print "<html><head><title>Perl CGI Example</title></head>\n";
print "<body><h1>Hello, World from Perl CGI!</h1>\n";
print "</body></html>\n";
```

- **Shebang (`#!/usr/bin/perl`)**: This tells the server to use Perl to execute the script.
- **HTTP Header**: The `Content-type: text/html` header tells the web server that the response will be HTML.
- **HTML Output**: The script generates basic HTML output.

---

### 3. **CGI Environment Variables**

When a CGI script is executed, the web server passes environment variables containing information about the HTTP request. These variables can be accessed in Perl via the `%ENV` hash.

#### Useful CGI Environment Variables:
- `QUERY_STRING`: The part of the URL after the `?` in a GET request.
- `REQUEST_METHOD`: The HTTP method used (e.g., `GET`, `POST`).
- `CONTENT_TYPE`: The type of content being sent (for POST requests).
- `REMOTE_ADDR`: The IP address of the client.
- `SERVER_NAME`: The name of the server.
  
#### Example: Accessing Environment Variables

```perl
#!/usr/bin/perl
use strict;
use warnings;

# Print HTTP header
print "Content-type: text/html\n\n";

# Print client IP and request method
print "<html><body>\n";
print "<h2>Client IP Address: $ENV{'REMOTE_ADDR'}</h2>\n";
print "<h3>Request Method: $ENV{'REQUEST_METHOD'}</h3>\n";
print "</body></html>\n";
```

---

### 4. **Reading Input from Forms**

CGI scripts often interact with HTML forms to collect user input. Forms can send data to a CGI script using either the `GET` or `POST` methods. For `GET`, form data is included in the URL, and for `POST`, it is sent in the body of the request.

To read form data, the `CGI` module in Perl provides convenient functions. First, ensure the `CGI` module is installed and available (`cpan CGI`).

#### Example: Reading Form Data Using the `CGI` Module

1. **HTML Form**

```html
<!DOCTYPE html>
<html>
<head>
    <title>Perl CGI Form</title>
</head>
<body>
    <form method="post" action="/cgi-bin/form.pl">
        Name: <input type="text" name="name"><br>
        Age: <input type="text" name="age"><br>
        <input type="submit" value="Submit">
    </form>
</body>
</html>
```

2. **CGI Script (form.pl)**

```perl
#!/usr/bin/perl
use strict;
use warnings;
use CGI;

# Create CGI object
my $cgi = CGI->new;

# Get form data
my $name = $cgi->param('name');
my $age = $cgi->param('age');

# Print HTTP header
print $cgi->header;

# Print HTML response
print "<html><body>\n";
print "<h2>Form Data</h2>\n";
print "<p>Name: $name</p>\n";
print "<p>Age: $age</p>\n";
print "</body></html>\n";
```

In this example:
- The HTML form submits data to the Perl CGI script using the `POST` method.
- The Perl script reads the submitted `name` and `age` values using `$cgi->param()`.
- The response is dynamically generated and displayed.

---

### 5. **Handling Different HTTP Methods**

CGI scripts can handle different HTTP methods like `GET` and `POST`. The `REQUEST_METHOD` environment variable tells which method was used, and the `CGI` module simplifies the handling.

#### Example: Handling `GET` and `POST` Methods

```perl
#!/usr/bin/perl
use strict;
use warnings;
use CGI;

my $cgi = CGI->new;
my $method = $cgi->request_method;

# Print HTTP header
print $cgi->header;

# Process GET request
if ($method eq 'GET') {
    print "<html><body>\n";
    print "<h2>This is a GET request.</h2>\n";
    print "</body></html>\n";
}

# Process POST request
elsif ($method eq 'POST') {
    my $name = $cgi->param('name');
    print "<html><body>\n";
    print "<h2>Received POST request.</h2>\n";
    print "<p>Name: $name</p>\n";
    print "</body></html>\n";
}
```

Here:
- If the request method is `GET`, the script displays a simple message.
- If the request method is `POST`, it processes the form data.

---

### 6. **Redirecting to Another URL**

Sometimes, after processing a request, it is necessary to redirect the user to another URL. This can be done using the `Location` header.

#### Example: Redirecting to Another Page

```perl
#!/usr/bin/perl
use strict;
use warnings;
use CGI;

my $cgi = CGI->new;

# Redirect to another page
print $cgi->redirect('http://www.example.com');
```

The `redirect` method sends an HTTP 302 status code, instructing the browser to load the new URL.

---

### 7. **File Uploads**

CGI scripts can handle file uploads via forms. The `CGI` module simplifies this by automatically handling file content from the `POST` request.

#### Example: Handling File Upload

1. **HTML Form for File Upload**

```html
<!DOCTYPE html>
<html>
<head>
    <title>File Upload</title>
</head>
<body>
    <form enctype="multipart/form-data" method="post" action="/cgi-bin/upload.pl">
        Select file: <input type="file" name="file"><br>
        <input type="submit" value="Upload">
    </form>
</body>
</html>
```

2. **CGI Script for File Upload (upload.pl)**

```perl
#!/usr/bin/perl
use strict;
use warnings;
use CGI;

my $cgi = CGI->new;

# Get file data
my $file = $cgi->param('file');

# Get file name
my $filename = $cgi->param('file');

# Read the file content
my $file_content = $cgi->upload('file');

# Save the file to the server
open my $out, '>', "/path/to/uploaded/$filename" or die "Cannot open file: $!";
while (my $bytesread = read($file_content, my $buffer, 1024)) {
    print $out $buffer;
}
close $out;

print $cgi->header;
print "<html><body>\n";
print "<h2>File Upload Successful!</h2>\n";
print "<p>Uploaded file: $filename</p>\n";
print "</body></html>\n";
```

Here:
- The form allows the user to upload a file.
- The CGI script handles the uploaded file using `$cgi->upload()`, and saves it to a specified directory.

---

### 8. **Using Cookies**

CGI scripts can set and retrieve cookies. The `CGI` module provides methods like `cookie` to manage cookies.

#### Example: Setting and Getting Cookies

```perl
#!/usr/bin/perl
use strict;
use warnings;
use CGI;

my $cgi = CGI->new;

# Set a cookie
print $cgi->header(-cookie => $cgi->cookie(-name => 'user', -value => 'John Doe'));

# Get the cookie value
my $user = $cgi->cookie('user');

# Output the result
print "<html><body>\n";
print "<h2>Welcome, $user!</h2>\n";
print "</body></html>\n";
```

---

### Conclusion

Perl's CGI programming is a robust and flexible way to create dynamic web applications. By using the `CGI` module and HTTP headers, you can interact with web clients, process form data, manage files, handle cookies, and much more. CGI scripts allow you to create powerful web applications with Perl’s simplicity and efficiency.
