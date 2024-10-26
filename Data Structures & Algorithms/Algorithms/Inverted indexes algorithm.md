**Inverted Indexes**

An inverted index is a data structure used to efficiently store and retrieve information in large datasets, especially in the context of text search and information retrieval. It is a mapping of terms (words) to the documents or records that contain those terms. Inverted indexes are widely used in search engines, databases, and information retrieval systems to speed up the process of searching for specific words or phrases within a large collection of documents.

**Working of Inverted Indexes**

The process of creating an inverted index involves the following steps:

1. **Tokenization:** The text documents are tokenized, where each document is broken down into individual words or tokens. Punctuation marks, stop words (common words like "the," "is," etc.), and other irrelevant information may be removed during this step.

2. **Stemming:** Words are often reduced to their base or root form during stemming to normalize the index. For example, "running," "runs," and "ran" would all be reduced to the base form "run."

3. **Document Identification:** Each token is associated with the document(s) where it occurs. This creates a mapping of terms to the documents that contain them.

4. **Index Construction:** The inverted index is constructed using the mappings generated in the previous steps. The index is typically stored as a data structure such as a hash table, trie, or balanced search tree.

**Example:**

Let's consider a small collection of documents:

1. Document 1: "The quick brown fox jumps over the lazy dog."
2. Document 2: "A fast red fox leaps over the sleeping dog."
3. Document 3: "The lazy dog barks at the moon."

After tokenization and stemming, we get:

```
{
    "the": [1, 3],
    "quick": [1],
    "brown": [1],
    "fox": [1, 2],
    "jump": [1],
    "over": [1, 2],
    "lazy": [1, 3],
    "dog": [1, 2, 3],
    "a": [2],
    "fast": [2],
    "red": [2],
    "leap": [2],
    "sleep": [2],
    "bark": [3],
    "at": [3],
    "moon": [3]
}
```

In this example, the inverted index maps each word to the documents where it occurs. For instance, the word "lazy" is present in documents 1 and 3, so its entry in the index contains the list [1, 3] to indicate these document IDs.

**Python Implementation of Inverted Indexes:**

```python
class InvertedIndex:
    def __init__(self):
        self.index = {}

    def add_document(self, doc_id, content):
        words = content.split()
        for word in words:
            word = word.lower()  # Convert to lowercase for case-insensitivity
            if word not in self.index:
                self.index[word] = []
            if doc_id not in self.index[word]:
                self.index[word].append(doc_id)

    def search(self, query):
        query = query.lower()
        if query in self.index:
            return self.index[query]
        return []

if __name__ == "__main__":
    inverted_index = InvertedIndex()
    documents = {
        1: "The quick brown fox jumps over the lazy dog.",
        2: "A fast red fox leaps over the sleeping dog.",
        3: "The lazy dog barks at the moon."
    }

    for doc_id, content in documents.items():
        inverted_index.add_document(doc_id, content)

    query_word = "lazy"
    results = inverted_index.search(query_word)

    if results:
        print(f"Documents containing '{query_word}': {results}")
    else:
        print(f"'{query_word}' not found in any document.")
```

**C++ Implementation of Inverted Indexes:**

```cpp
#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <algorithm>

class InvertedIndex {
private:
    std::unordered_map<std::string, std::vector<int>> index;

public:
    void add_document(int doc_id, const std::string& content);
    std::vector<int> search(const std::string& query);
};

void InvertedIndex::add_document(int doc_id, const std::string& content) {
    std::istringstream iss(content);
    std::string word;
    while (iss >> word) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower); // Convert to lowercase for case-insensitivity
        index[word].push_back(doc_id);
    }
}

std::vector<int> InvertedIndex::search(const std::string& query) {
    std::string lower_query = query;
    std::transform(lower_query.begin(), lower_query.end(), lower_query.begin(), ::tolower);
    if (index.count(lower_query) > 0) {
        return index[lower_query];
    }
    return {};
}

int main() {
    InvertedIndex inverted_index;
    std::unordered_map<int, std::string> documents = {
        {1, "The quick brown fox jumps over the lazy dog."},
        {2, "A fast red fox leaps over the sleeping dog."},
        {3, "The lazy dog barks at the moon."}
    };

    for (const auto& doc : documents) {
        inverted_index.add_document(doc.first, doc.second);
    }

    std::string query_word = "lazy";
    std::vector<int> results = inverted_index.search(query_word);

    if (!results.empty()) {
        std::cout << "Documents containing '" << query_word << "': ";
        for (int doc_id : results) {
            std::cout << doc_id << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "'" << query_word << "' not found in any document." << std::endl;
    }

    return 0;
}
```

In this article, we explored the concept of inverted indexes, how they work, and their use cases. We provided Python and C++ implementations of the inverted index data structure, which efficiently maps terms to the documents that contain them. Inverted indexes are crucial for information retrieval tasks and play a significant role in search engines and database systems to enable fast and efficient search operations.
