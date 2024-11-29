### Perl - Sending Email

In Perl, you can send emails through several modules, each of which provides different levels of control and ease. The most commonly used modules for sending emails are `Email::Sender`, `MIME::Lite`, and `Net::SMTP`. 

---

### 1. **Using `Email::Sender`**

The `Email::Sender` module is part of the modern `Email::` family of Perl modules and is well-suited for general email tasks. 

#### Example: Basic Email with `Email::Sender`

1. **Install the `Email::Sender` module** (if not installed):

   ```shell
   cpan Email::Sender::Simple
   ```

2. **Send an email** using `Email::Sender::Simple` and `Email::Simple`.

   ```perl
   use Email::Sender::Simple qw(sendmail);
   use Email::Simple;
   use Email::Simple::Creator;

   my $email = Email::Simple->create(
       header => [
           To      => 'recipient@example.com',
           From    => 'sender@example.com',
           Subject => 'Test Email',
       ],
       body => 'This is a test email sent from Perl.',
   );

   sendmail($email);
   ```

For SMTP server configurations, you can use `Email::Sender::Transport::SMTP`.

#### Example: Using SMTP with Authentication

```perl
use Email::Sender::Simple qw(sendmail);
use Email::Sender::Transport::SMTP qw();
use Email::Simple;
use Email::Simple::Creator;

my $transport = Email::Sender::Transport::SMTP->new({
    host          => 'smtp.example.com',
    port          => 587,
    sasl_username => 'your_username',
    sasl_password => 'your_password',
    ssl           => 'starttls',
});

my $email = Email::Simple->create(
    header => [
        To      => 'recipient@example.com',
        From    => 'sender@example.com',
        Subject => 'Test Email',
    ],
    body => 'This is a test email sent using SMTP with Perl.',
);

sendmail($email, { transport => $transport });
```

---

### 2. **Using `MIME::Lite`**

`MIME::Lite` is a lightweight and widely used module for creating and sending MIME-encoded messages, including attachments.

1. **Install `MIME::Lite`**:

   ```shell
   cpan MIME::Lite
   ```

2. **Send an email with `MIME::Lite`**:

   ```perl
   use MIME::Lite;

   my $msg = MIME::Lite->new(
       From    => 'sender@example.com',
       To      => 'recipient@example.com',
       Subject => 'Hello!',
       Data    => "This is a simple email sent using MIME::Lite in Perl.",
   );

   $msg->send;
   ```

#### Example: Sending an Email with Attachments

```perl
use MIME::Lite;

my $msg = MIME::Lite->new(
    From    => 'sender@example.com',
    To      => 'recipient@example.com',
    Subject => 'Attached File',
    Type    => 'multipart/mixed',
);

$msg->attach(
    Type     => 'TEXT',
    Data     => "Please find the attached file.",
);

$msg->attach(
    Type        => 'application/pdf',
    Path        => '/path/to/file.pdf',
    Filename    => 'file.pdf',
    Disposition => 'attachment',
);

$msg->send;
```

---

### 3. **Using `Net::SMTP`**

`Net::SMTP` is a lower-level module that connects directly to an SMTP server. This is useful if you need more control over the SMTP protocol.

1. **Install `Net::SMTP`**:

   ```shell
   cpan Net::SMTP
   ```

2. **Send an email with `Net::SMTP`**:

   ```perl
   use Net::SMTP;

   my $smtp = Net::SMTP->new('smtp.example.com', Timeout => 30);

   $smtp->mail('sender@example.com');
   $smtp->to('recipient@example.com');

   $smtp->data();
   $smtp->datasend("From: sender@example.com\n");
   $smtp->datasend("To: recipient@example.com\n");
   $smtp->datasend("Subject: Test Email\n");
   $smtp->datasend("\n");
   $smtp->datasend("This is a test email sent using Net::SMTP.\n");
   $smtp->dataend();

   $smtp->quit;
   ```

---

### Summary of Perl Email Modules

| **Module**         | **Use Case**                                        | **Strengths**                                      |
|--------------------|-----------------------------------------------------|----------------------------------------------------|
| **Email::Sender**  | Simple emails, general use                          | Modern, easy to use, supports SMTP and TLS/SSL     |
| **MIME::Lite**     | MIME-encoded emails, attachments                    | Lightweight, attachment support                    |
| **Net::SMTP**      | Low-level SMTP interaction, fine-grained control    | Direct SMTP control, more protocol-specific tasks  |

Perl’s email-sending modules provide a range of options to suit different needs, from simple messages to MIME-encoded emails with attachments. Select a module based on your requirements for ease, control, or protocol features.
