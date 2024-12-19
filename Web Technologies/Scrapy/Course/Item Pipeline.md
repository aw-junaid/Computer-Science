In Scrapy, **Item Pipelines** are used to process the scraped data **after it is extracted** by the spider. They allow you to clean, validate, filter, or store the scraped data in a structured way, such as saving it to a database, file, or an API.

---

## 1. **What is an Item Pipeline?**

The Item Pipeline is a **series of components** that process each `Item` (scraped data) returned by the spider. Each component in the pipeline performs a specific task, such as:

- **Cleaning or transforming** the data.
- **Validating** the scraped data.
- **Storing** the data into a database or file.

---

## 2. **Item Pipeline Workflow**

1. The spider scrapes data and yields an `Item`.
2. Scrapy sends the `Item` to the **Item Pipeline**.
3. Each pipeline component processes the `Item` sequentially.
4. The final, processed `Item` can be stored or exported.

---

## 3. **Creating an Item Pipeline**

You need to define a Python class for each pipeline component. Each class must define a **`process_item`** method, which processes the item and returns it.

Here’s a simple example pipeline that cleans whitespace from an item’s field:

### `pipelines.py`:

```python
class CleanWhitespacePipeline:
    def process_item(self, item, spider):
        # Strip whitespace from all string fields
        for field in item.fields:
            if isinstance(item[field], str):
                item[field] = item[field].strip()
        return item
```

---

## 4. **Enabling Item Pipelines**

To enable a pipeline, add it to the **`ITEM_PIPELINES`** setting in your project's `settings.py` file.

The pipeline components are ordered by **priority**, where **lower numbers are higher priority**.

### Example:

```python
# settings.py
ITEM_PIPELINES = {
    'myproject.pipelines.CleanWhitespacePipeline': 300,
    'myproject.pipelines.SaveToDatabasePipeline': 800,
}
```

Here:
- `CleanWhitespacePipeline` runs first (priority 300).
- `SaveToDatabasePipeline` runs later (priority 800).

---

## 5. **Pipeline Methods**

Each pipeline class can define the following methods:

### `process_item(self, item, spider)`
- This method is **required**.
- It processes and modifies each item.
- It must **return** the item, or **raise DropItem** to discard it.

### `open_spider(self, spider)`
- Runs **when the spider opens**.
- Used for setup, such as opening a database connection.

### `close_spider(self, spider)`
- Runs **when the spider closes**.
- Used for cleanup, like closing a database connection.

### Example:

```python
import sqlite3

class SaveToDatabasePipeline:
    def open_spider(self, spider):
        # Connect to the database when the spider starts
        self.connection = sqlite3.connect("quotes.db")
        self.cursor = self.connection.cursor()
        self.cursor.execute('''CREATE TABLE IF NOT EXISTS quotes 
                             (text TEXT, author TEXT)''')

    def process_item(self, item, spider):
        # Insert item into the database
        self.cursor.execute("INSERT INTO quotes (text, author) VALUES (?, ?)", 
                            (item['text'], item['author']))
        self.connection.commit()
        return item

    def close_spider(self, spider):
        # Close the database connection when the spider finishes
        self.connection.close()
```

---

## 6. **Dropping Items**

To **filter out unwanted items**, you can raise the `DropItem` exception from `process_item`.

### Example: Dropping Items with Missing Fields:

```python
from scrapy.exceptions import DropItem

class DropEmptyFieldsPipeline:
    def process_item(self, item, spider):
        if not item.get('text') or not item.get('author'):
            raise DropItem("Missing text or author in %s" % item)
        return item
```

- If the `text` or `author` field is missing, the item is dropped.

---

## 7. **Chaining Multiple Pipelines**

Scrapy allows chaining multiple pipelines, and each pipeline processes the item in order.

**Example Order**:
1. Clean whitespace → `CleanWhitespacePipeline`
2. Drop invalid items → `DropEmptyFieldsPipeline`
3. Save valid items to a database → `SaveToDatabasePipeline`

### settings.py:

```python
ITEM_PIPELINES = {
    'myproject.pipelines.CleanWhitespacePipeline': 100,
    'myproject.pipelines.DropEmptyFieldsPipeline': 200,
    'myproject.pipelines.SaveToDatabasePipeline': 300,
}
```

---

## 8. **Exporting Data**

Item Pipelines can export data to various formats like **JSON**, **CSV**, or **XML**.

For basic use, Scrapy provides built-in exporters (via `scrapy crawl` command), but you can also customize pipelines to save data.

### Example: Save Items to a JSON File:

```python
import json

class SaveToJsonPipeline:
    def open_spider(self, spider):
        self.file = open("quotes.json", "w")

    def process_item(self, item, spider):
        line = json.dumps(dict(item)) + "\n"
        self.file.write(line)
        return item

    def close_spider(self, spider):
        self.file.close()
```

---

## 9. **Common Use Cases for Pipelines**

1. **Data Cleaning**: Stripping whitespace, fixing formatting, or transforming data.
2. **Validation**: Ensuring all necessary fields are present.
3. **Data Deduplication**: Removing duplicate items.
4. **Data Storage**:
   - Save data to databases (e.g., SQLite, PostgreSQL, MongoDB).
   - Save data to files (e.g., JSON, CSV, XML).
5. **Data Enrichment**: Adding more information to items, such as geolocation or API results.

---

## 10. **Order of Execution**

- Pipelines are executed in the order specified by their priority.
- If one pipeline raises an exception (e.g., `DropItem`), the subsequent pipelines will **not** process that item.

---

## 11. **Example Workflow**

Let’s assume you want to:
1. Clean whitespace.
2. Validate the item.
3. Save the item to a database.

### pipelines.py:

```python
from scrapy.exceptions import DropItem
import sqlite3

class CleanWhitespacePipeline:
    def process_item(self, item, spider):
        item['text'] = item['text'].strip()
        item['author'] = item['author'].strip()
        return item

class ValidateItemPipeline:
    def process_item(self, item, spider):
        if not item.get('text') or not item.get('author'):
            raise DropItem("Missing required fields")
        return item

class SaveToDatabasePipeline:
    def open_spider(self, spider):
        self.connection = sqlite3.connect("quotes.db")
        self.cursor = self.connection.cursor()
        self.cursor.execute('''CREATE TABLE IF NOT EXISTS quotes 
                               (text TEXT, author TEXT)''')

    def process_item(self, item, spider):
        self.cursor.execute("INSERT INTO quotes (text, author) VALUES (?, ?)", 
                            (item['text'], item['author']))
        self.connection.commit()
        return item

    def close_spider(self, spider):
        self.connection.close()
```

### settings.py:

```python
ITEM_PIPELINES = {
    'myproject.pipelines.CleanWhitespacePipeline': 100,
    'myproject.pipelines.ValidateItemPipeline': 200,
    'myproject.pipelines.SaveToDatabasePipeline': 300,
}
```

---

## Summary:

- **Item Pipelines** are used to process, clean, validate, or store scraped items.
- Each pipeline class must implement the `process_item` method.
- Use the `DropItem` exception to filter out unwanted data.
- Pipelines are executed in the order of their priority in `settings.py`.
- Pipelines can save data to databases, files, or other storage systems.

