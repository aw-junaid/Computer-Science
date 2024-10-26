**Flood Fill Algorithm: An Overview**

The Flood Fill Algorithm is a simple and widely used technique for filling connected regions in a grid or image with a specific color. It is commonly used in computer graphics, image processing, and games for tasks like coloring regions, finding connected components, and simulating fluid behavior. The algorithm starts from a given seed point and recursively fills adjacent pixels or cells until it reaches the boundary or a region with a different color.

**Working of Flood Fill Algorithm**

1. **Step 1: Select Seed Point**: The algorithm starts by selecting a seed point (x, y) in the grid or image from which the filling will begin.

2. **Step 2: Fill Operation**: The algorithm examines the color of the pixel or cell at the seed point. It then fills the seed point with the desired color and recursively fills its neighboring pixels or cells that have the same color as the seed point.

3. **Step 3: Boundary Constraints**: The algorithm continues the fill operation, taking care not to fill outside the boundaries of the grid or image. It stops filling when it reaches a region with a different color or the grid's boundary.

4. **Step 4: Repeat (if required)**: The algorithm can be applied to multiple seed points to fill different connected regions with the desired color.

**Example Use Cases for Flood Fill Algorithm**

1. **Paint Bucket Tool**: In image editing software, the flood fill algorithm is commonly used for the paint bucket tool, which allows users to fill an area with a selected color.

2. **Connected Component Labeling**: The algorithm is used to identify and label connected components in images, which can be useful in image segmentation and object recognition.

3. **Maze Solving**: In maze-solving algorithms, flood fill can be used to explore and find a path from a starting point to an exit.

**Implementation of Flood Fill Algorithm in Python, C++, Rust, and Ruby**

**Python Code for Flood Fill Algorithm:**

```python
def flood_fill(image, x, y, new_color, original_color=None):
    if original_color is None:
        original_color = image[y][x]

    if x < 0 or x >= len(image[0]) or y < 0 or y >= len(image) or image[y][x] != original_color:
        return

    image[y][x] = new_color

    flood_fill(image, x + 1, y, new_color, original_color)
    flood_fill(image, x - 1, y, new_color, original_color)
    flood_fill(image, x, y + 1, new_color, original_color)
    flood_fill(image, x, y - 1, new_color, original_color)

# Example usage:
image = [
    [1, 1, 1, 1],
    [1, 0, 0, 1],
    [1, 0, 0, 1],
    [1, 1, 1, 1]
]

flood_fill(image, 1, 1, 2)
for row in image:
    print(row)
```

**C++ Code for Flood Fill Algorithm:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

void flood_fill(vector<vector<int>>& image, int x, int y, int new_color, int original_color = -1) {
    if (original_color == -1) {
        original_color = image[y][x];
    }

    if (x < 0 || x >= image[0].size() || y < 0 || y >= image.size() || image[y][x] != original_color) {
        return;
    }

    image[y][x] = new_color;

    flood_fill(image, x + 1, y, new_color, original_color);
    flood_fill(image, x - 1, y, new_color, original_color);
    flood_fill(image, x, y + 1, new_color, original_color);
    flood_fill(image, x, y - 1, new_color, original_color);
}

int main() {
    vector<vector<int>> image = {
        {1, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {1, 1, 1, 1}
    };

    flood_fill(image, 1, 1, 2);
    for (const auto& row : image) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}
```

**Rust Code for Flood Fill Algorithm:**

```rust
fn flood_fill(image: &mut Vec<Vec<i32>>, x: usize, y: usize, new_color: i32, original_color: i32) {
    if x >= image[0].len() || y >= image.len() || image[y][x] != original_color {
        return;
    }

    image[y][x] = new_color;

    flood_fill(image, x + 1, y, new_color, original_color);
    flood_fill(image, x - 1, y, new_color, original_color);
    flood_fill(image, x, y + 1, new_color, original_color);
    flood_fill(image, x, y - 1, new_color, original_color);
}

fn main() {
    let mut image = vec![
        vec![1, 1, 1, 1],
        vec![1, 0, 0, 1],
        vec![1, 0, 0, 1],
        vec![1, 1, 1, 1],
    ];

    let original_color = image[1][1];
    flood_fill(&mut image, 1, 1, 2, original_color);
    for row in &image {
        for pixel in row {
            print!("{} ", pixel);
        }
        println!();
    }
}
```

**Ruby Code for Flood Fill Algorithm:**

```ruby
def flood_fill(image, x, y, new_color, original_color = nil)
    original_color ||= image[y][x]

    if x < 0 || x >= image[0].length || y < 0 || y >= image.length || image[y][x] != original_color
        return
    end

    image[y][x] = new_color

    flood_fill(image, x + 1, y, new_color, original_color)
    flood_fill(image, x - 1, y, new_color, original_color)
    flood_fill(image, x, y + 1, new_color, original_color)
    flood_fill(image, x, y - 1, new_color, original_color)
end

# Example usage:
image = [
    [1, 1, 1, 1],
    [1, 0, 0, 1],
    [1, 0, 0, 1],
    [1, 1, 1, 1]
]

flood_fill(image, 1, 1, 2)
image.each { |row| puts row.join(' ') }
```

**Conclusion**

The Flood Fill Algorithm is a versatile and efficient algorithm used to fill connected regions in a grid or image with a specific color. Its applications

 in computer graphics, image processing, and games make it an essential tool for tasks like coloring regions, finding connected components, and simulating fluid behavior. The provided code examples in Python, C++, Rust, and Ruby demonstrate the implementation of the Flood Fill Algorithm, enabling you to efficiently fill connected regions with the desired color in your projects and applications.
