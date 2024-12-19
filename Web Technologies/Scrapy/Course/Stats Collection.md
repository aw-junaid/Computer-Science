In Scrapy, **stats collection** refers to tracking various statistics and metrics during the execution of a spider. Scrapy automatically collects many statistics about the crawl, such as the number of requests made, the number of items scraped, the number of errors encountered, and other relevant performance metrics.

These statistics can be useful for debugging, optimizing spider performance, or monitoring the crawl’s progress and health.

---

## 1. **Default Stats Collection**

By default, Scrapy collects a variety of statistics related to the execution of a spider. These statistics are automatically stored in the Scrapy engine and can be accessed at the end of the crawl.

Some of the default statistics collected include:

- **`request_count`**: The total number of requests made by the spider.
- **`item_scraped_count`**: The total number of items successfully scraped.
- **`downloader/request_count`**: The number of requests made by the downloader.
- **`downloader/response_count`**: The number of responses received by the downloader.
- **`downloader/response_status_count`**: The number of responses grouped by status code (e.g., 200, 404, etc.).
- **`log_count/INFO`**: The number of log messages at the `INFO` level.
- **`log_count/WARNING`**: The number of log messages at the `WARNING` level.
- **`log_count/ERROR`**: The number of log messages at the `ERROR` level.
- **`spider_opened`**: The number of times the spider was opened.
- **`spider_closed`**: The number of times the spider was closed.

---

## 2. **Accessing Stats in a Spider**

You can access Scrapy's statistics during the crawl by using the **`self.crawler.stats`** attribute. This gives you access to all the collected statistics.

### Example: Accessing Stats in a Spider

```python
import scrapy

class MySpider(scrapy.Spider):
    name = 'my_spider'
    start_urls = ['http://example.com']

    def parse(self, response):
        # Extract data from the response
        title = response.css('title::text').get()
        yield {'title': title}

    def closed(self, reason):
        # Access the stats at the end of the crawl
        total_requests = self.crawler.stats.get_value('request_count')
        total_items = self.crawler.stats.get_value('item_scraped_count')

        self.logger.info(f'Total requests made: {total_requests}')
        self.logger.info(f'Total items scraped: {total_items}')
```

In this example, the `closed` method is called when the spider finishes, and we access the stats using `self.crawler.stats.get_value()`.

### Common Methods for Accessing Stats:
- **`get_value(stat_name)`**: Retrieve the value of a specific stat (e.g., `'request_count'`).
- **`set_value(stat_name, value)`**: Set a custom value for a stat.
- **`get_stats()`**: Retrieve all the collected stats as a dictionary.

---

## 3. **Custom Stats Collection**

You can also create custom statistics during the crawl by using the `crawler.stats` object. This is useful if you want to track specific events or metrics that are not collected by default.

### Example: Custom Stats Collection

```python
import scrapy

class MySpider(scrapy.Spider):
    name = 'my_spider'
    start_urls = ['http://example.com']

    def parse(self, response):
        # Example of custom stat collection: Count the number of 404 errors
        if response.status == 404:
            self.crawler.stats.inc_value('custom/404_count')

        # Extract data from the response
        title = response.css('title::text').get()
        yield {'title': title}

    def closed(self, reason):
        # Access custom stat at the end of the crawl
        error_count = self.crawler.stats.get_value('custom/404_count')
        self.logger.info(f'Total 404 errors: {error_count}')
```

In this example, we use `self.crawler.stats.inc_value('custom/404_count')` to increment a custom stat whenever a 404 error is encountered. You can also create more complex stats tracking, depending on your specific needs.

---

## 4. **Enabling and Disabling Stats Collection**

Scrapy’s stats collection is enabled by default. However, you can disable it if it's not needed, or configure which stats are collected.

### Disabling Stats Collection

To disable the default stats collection, you can set `STATS_ENABLED = False` in the `settings.py` file:

```python
STATS_ENABLED = False
```

This will prevent Scrapy from collecting and storing the statistics during the crawl.

### Disabling Specific Stats

If you want to disable only specific types of statistics, you can configure them in `settings.py` by using `STATS_DUMP` or other settings to filter stats that should be collected.

For example, to disable the collection of request stats:

```python
STATS_DUMP = False
```

---

## 5. **Exporting Stats to a File**

You can export the collected stats to a file, which can be useful for analysis or monitoring purposes.

### Example: Exporting Stats to a JSON File

In `settings.py`, you can use the `FEED_FORMAT` and `FEED_URI` settings to export the stats to a file.

```python
FEED_URI = 'stats.json'
FEED_FORMAT = 'json'
```

This will save the statistics to a JSON file named `stats.json`. Scrapy will write the stats to the file at the end of the crawl.

---

## 6. **Stats Middleware and Extensions**

You can extend Scrapy’s stats collection by using middlewares or custom extensions. This allows you to modify the collection process or gather additional stats.

### Example: Custom Stats Middleware

You can create a custom middleware to track statistics, such as the number of retries, custom headers, or other details.

```python
class CustomStatsMiddleware:
    def process_request(self, request, spider):
        # Example: Track requests with custom headers
        if 'X-Custom-Header' in request.headers:
            spider.crawler.stats.inc_value('custom/requests_with_custom_header')

    def process_response(self, request, response, spider):
        # Example: Track responses with custom headers
        if 'X-Custom-Header' in response.headers:
            spider.crawler.stats.inc_value('custom/responses_with_custom_header')
        return response
```

You can enable this middleware in `settings.py`:

```python
DOWNLOADER_MIDDLEWARES = {
    'myproject.middlewares.CustomStatsMiddleware': 543,
}
```

---

## 7. **Summary**

Stats collection in Scrapy provides valuable insight into the crawl process and can help with debugging, performance monitoring, and analyzing the results of your spider. Here's a quick overview of how to work with stats:

1. **Default Stats**: Scrapy collects many useful stats automatically (e.g., request count, item scraped count).
2. **Access Stats**: Use `self.crawler.stats.get_value()` to retrieve specific statistics during or after the crawl.
3. **Custom Stats**: Track custom statistics using `self.crawler.stats.inc_value()` and `self.crawler.stats.set_value()`.
4. **Disabling Stats**: You can disable the collection of stats entirely by setting `STATS_ENABLED = False` in the `settings.py`.
5. **Export Stats**: Export stats to a file using `FEED_URI` and `FEED_FORMAT` settings for easy analysis.
6. **Custom Extensions/Middlewares**: Extend Scrapy’s stats collection with custom middlewares or extensions to track more granular data.
