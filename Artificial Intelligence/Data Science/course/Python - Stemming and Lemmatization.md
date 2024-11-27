**Stemming** and **Lemmatization** are text normalization techniques in Natural Language Processing (NLP) used to reduce words to their base or root forms. While they both aim to simplify words for analysis, they differ in how they perform the reduction.

- **Stemming**: It is a simpler, rule-based approach that removes prefixes or suffixes from words to get the root form. The result is not always a valid word.
- **Lemmatization**: It uses a dictionary or vocabulary and applies grammatical rules to return a valid base form (lemma) of the word.

### 1. **Stemming**

Stemming is the process of removing suffixes from a word to reduce it to its root form. A stemming algorithm does not ensure that the resulting word is a valid word in the language.

#### Popular Stemming Algorithms:
- **Porter Stemmer** (one of the most widely used stemmers)
- **Lancaster Stemmer** (more aggressive than Porter)
- **Snowball Stemmer** (an improvement over the Porter Stemmer)

In Python, stemming is usually done with the **NLTK** library.

#### Example of Stemming Using NLTK

```python
import nltk
from nltk.stem import PorterStemmer, LancasterStemmer

# Initialize stemmers
porter_stemmer = PorterStemmer()
lancaster_stemmer = LancasterStemmer()

# Example words
words = ["running", "runner", "easily", "happiness", "flies"]

# Using Porter Stemmer
porter_stemmed_words = [porter_stemmer.stem(word) for word in words]

# Using Lancaster Stemmer
lancaster_stemmed_words = [lancaster_stemmer.stem(word) for word in words]

print("Porter Stemmer:", porter_stemmed_words)
print("Lancaster Stemmer:", lancaster_stemmed_words)
```

#### Output:

```
Porter Stemmer: ['run', 'runner', 'easili', 'happi', 'fli']
Lancaster Stemmer: ['run', 'run', 'eas', 'happy', 'fli']
```

- As you can see, **stemming** often results in words that are not real words (e.g., "easili", "happi").
- **Lancaster Stemmer** is more aggressive than **Porter Stemmer**, which is why "easily" becomes "eas", and "happiness" becomes "happy".

---

### 2. **Lemmatization**

**Lemmatization** reduces words to their base or dictionary form (lemma) and ensures that the resulting word is a valid word in the language. It considers the context of the word (e.g., part of speech) to apply proper rules for reduction.

Lemmatization is typically more accurate but computationally heavier compared to stemming. In Python, **spaCy** and **NLTK** are commonly used for lemmatization.

#### Lemmatization with NLTK

To perform lemmatization in **NLTK**, you need to use the **WordNetLemmatizer**, and optionally specify the part of speech (POS) for better results.

```python
import nltk
from nltk.stem import WordNetLemmatizer
from nltk.corpus import wordnet

# Download NLTK resources
nltk.download('wordnet')
nltk.download('omw-1.4')

# Initialize Lemmatizer
lemmatizer = WordNetLemmatizer()

# Example words
words = ["running", "runner", "easily", "happiness", "flies"]

# Lemmatize without POS tagging
lemmatized_words = [lemmatizer.lemmatize(word) for word in words]
print("Lemmatized words (default):", lemmatized_words)

# Lemmatize with POS tagging (e.g., verb -> 'run', noun -> 'runner')
lemmatized_words_with_pos = [
    lemmatizer.lemmatize(word, pos=wordnet.VERB) for word in words
]
print("Lemmatized words with POS (Verb):", lemmatized_words_with_pos)
```

#### Output:

```
Lemmatized words (default): ['running', 'runner', 'easily', 'happiness', 'fly']
Lemmatized words with POS (Verb): ['run', 'runner', 'easily', 'happiness', 'fly']
```

- Without specifying POS, **lemmatization** only converts some words (like "flies" to "fly").
- When specifying the **verb** POS, the word "running" is correctly reduced to "run".

#### Lemmatization with spaCy

**spaCy** provides more advanced lemmatization and handles the POS tagging automatically. Here's an example:

```python
import spacy

# Load the spaCy English model
nlp = spacy.load("en_core_web_sm")

# Example text
text = "running runners easily happy flies"

# Process the text
doc = nlp(text)

# Lemmatize the text using spaCy
lemmatized_words_spacy = [token.lemma_ for token in doc]

print("Lemmatized words with spaCy:", lemmatized_words_spacy)
```

#### Output:

```
Lemmatized words with spaCy: ['run', 'runner', 'easily', 'happy', 'fly']
```

- **spaCy** automatically handles POS tagging and correctly identifies the base form of each word.

---

### Key Differences: Stemming vs. Lemmatization

| **Aspect**            | **Stemming**                              | **Lemmatization**                         |
|-----------------------|-------------------------------------------|-------------------------------------------|
| **Purpose**           | Reduce words to their root form           | Reduce words to their base form (lemma)   |
| **Result**            | May produce non-existent words (e.g., "run" → "runn") | Produces valid words (e.g., "running" → "run") |
| **Method**            | Rule-based, removing prefixes/suffixes    | Dictionary-based, uses context and POS tags |
| **Accuracy**          | Less accurate, faster                     | More accurate, slower                     |
| **Libraries**         | NLTK (Porter, Lancaster, Snowball)        | NLTK (WordNetLemmatizer), spaCy           |
| **Example Words**     | "running" → "run", "better" → "better"    | "running" → "run", "better" → "good"      |

---

### Conclusion

- **Stemming** is a faster but less accurate method for reducing words to their base forms by simply removing suffixes. It can lead to invalid or incomplete words.
- **Lemmatization** is more accurate as it returns valid words based on the word's meaning and part of speech. It is computationally more expensive but provides better results for tasks such as text classification or information retrieval.

In practice:
- **Use stemming** when you need a quick, rough reduction of words, and exact accuracy is not critical (e.g., search engines).
- **Use lemmatization** when the quality of the word reduction is important, such as for text classification, sentiment analysis, and other NLP applications.
