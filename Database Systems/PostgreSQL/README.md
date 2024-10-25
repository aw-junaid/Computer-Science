![Logo](https://github.com/aw-junaid/PostgreSQL/blob/main/How%20to%20Install%20PostgreSQL%20on%20Linux.jpg?raw=true)

![Discord](https://img.shields.io/discord/1163365511309049948)
![GitHub followers](https://img.shields.io/github/followers/aw-junaid)
![YouTube Channel Views](https://img.shields.io/youtube/channel/views/UClhKVCHjOxBTNM50lOBTgoA)
![YouTube Channel Subscribers](https://img.shields.io/youtube/channel/subscribers/UClhKVCHjOxBTNM50lOBTgoA)
![X (formerly Twitter) Follow](https://img.shields.io/twitter/follow/abw_Junaid)
![Twitch Status](https://img.shields.io/twitch/status/awjunaid)
![Reddit User Karma](https://img.shields.io/reddit/user-karma/link/aw-junaid)

# PostgreSQL

PostgreSQL is a powerful, open-source object-relational database system (ORDBMS) with over 30 years of active development. It is known for its reliability, feature richness, and performance. PostgreSQL is used by a wide range of organizations, from small businesses to Fortune 500 companies, to power their most demanding applications.

## 🔗 Links
[![my_portfolio](https://img.shields.io/badge/Personal_blog-000?style=for-the-badge&logo=ko-fi&logoColor=white)](https://awjunaid.com/)

[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/aw-junaid/)

[![twitter](https://img.shields.io/badge/twitter-1DA1F2?style=for-the-badge&logo=twitter&logoColor=white)](https://twitter.com/abw_Junaid)

[![patreon](https://img.shields.io/badge/patreon-FF0000?style=for-the-badge&logo=patreon&logoColor=white)](https://www.patreon.com/awjunaid)

[![facebook](https://img.shields.io/badge/facebook-1877f2?style=for-the-badge&logo=facebook&logoColor=white)](https://www.facebook.com/abdulwahjunaid)

[![instagram](https://img.shields.io/badge/instagram-c32aa3?style=for-the-badge&logo=instagram&logoColor=white)](https://www.instagram.com/4wji_in41d)

[![twitch](https://img.shields.io/badge/twitch-9146ff?style=for-the-badge&logo=twitch&logoColor=white)](https://www.twitch.tv/awjunaid)

[![vk](https://img.shields.io/badge/vk-2a5885?style=for-the-badge&logo=vk&logoColor=white)](https://vk.com/aw.junaid)

[![pinterest](https://img.shields.io/badge/pinterest-ff0000?style=for-the-badge&logo=pinterest&logoColor=white)](https://www.pinterest.com/abwjunaid/)


## Features

- ACID-compliant transactions for data integrity
- Support for complex queries and advanced data types
- Extensible with custom functions, operators, and procedural languages
- Highly scalable and capable of handling large datasets
- Replication and high availability options for fault tolerance
- Full-text search, JSON/JSONB support, and geospatial data types

## Use Cases

PostgreSQL is well-suited for a wide range of applications, including:

- Web Applications
- Data Warehousing
- Geographic Information Systems (GIS)
- Financial Applications
- Healthcare Systems
- and more...

## Installation

# How to Install PostgreSQL on Linux

PostgreSQL is a powerful, open-source relational database management system that is widely used for various applications. Installing it on a Linux system is a straightforward process. Follow the steps below to get PostgreSQL up and running:

## Step 1: Update Package Lists

Before installing any new software, it's a good practice to update the package lists to ensure you have the latest information about available packages.

```bash
sudo apt update
```

## Step 2: Install PostgreSQL

To install PostgreSQL, use the package manager of your Linux distribution. For Ubuntu, use the following command:

```bash
sudo apt install postgresql postgresql-contrib
```

For CentOS, you can use `yum`:

```bash
sudo yum install postgresql-server
```

## Step 3: Start and Enable PostgreSQL

Once PostgreSQL is installed, start the service and enable it to start on boot:

For Ubuntu:

```bash
sudo systemctl start postgresql
sudo systemctl enable postgresql
```

For CentOS:

```bash
sudo systemctl start postgresql
sudo systemctl enable postgresql
```

## Step 4: Access PostgreSQL

By default, PostgreSQL creates a user named `postgres`. Switch to this user to access the PostgreSQL prompt:

```bash
sudo -i -u postgres
```

Now, you can access the PostgreSQL prompt by typing:

```bash
psql
```

## Step 5: Set a Password for the PostgreSQL User

While you're in the PostgreSQL prompt, you should set a password for the default `postgres` user:

```sql
ALTER USER postgres PASSWORD 'new_password';
```

Replace `'new_password'` with your desired password.

## Step 6: Create a New Database (Optional)

You can create a new database for your application:

```sql
CREATE DATABASE mydatabase;
```

Replace `mydatabase` with your desired database name.

## Step 7: Exit PostgreSQL Prompt

To exit the PostgreSQL prompt, type:

```sql
\q
```

## Step 8: Connect to PostgreSQL from Command Line

You can connect to PostgreSQL from the command line using the following command:

```bash
psql -U postgres -d mydatabase -h localhost -p 5432
```

Replace `mydatabase` with the name of the database you created (or `postgres` if you didn't create a new one).

## Step 9: Connect to PostgreSQL from a GUI Tool (Optional)

If you prefer a graphical user interface, you can use tools like pgAdmin or DBeaver to connect to your PostgreSQL database.

Congratulations! You've successfully installed PostgreSQL on your Linux system. You can now start creating and managing databases for your applications.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

