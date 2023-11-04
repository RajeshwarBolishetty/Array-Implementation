#include <iostream>
#include <vector>

class SparseMatrix {
private:
    // Dimensions of the original matrix
    int rows, cols;

    // Vectors to store the non-zero values and their row and column indices
    std::vector<int> row_indices;
    std::vector<int> col_indices;
    std::vector<int> values;

public:
    // Constructor for the sparse matrix with row and column sizes
    SparseMatrix(int r, int c) : rows(r), cols(c) {}

    // Function to add elements to the sparse matrix
    void addElement(int r, int c, int val) {
        if (r >= rows || c >= cols) {
            std::cout << "Invalid indices" << std::endl;
            return;
        }
        if (val != 0) {
            row_indices.push_back(r);
            col_indices.push_back(c);
            values.push_back(val);
        }
    }

    // Function to display the sparse matrix elements
    void display() {
        std::cout << "Row\tColumn\tValue\n";
        for (size_t i = 0; i < values.size(); ++i) {
            std::cout << row_indices[i] << '\t' << col_indices[i] << '\t' << values[i] << '\n';
        }
    }
};

int main() {
    // Dimensions of the sparse matrix
    int rows = 4, cols = 5;

    // Create a SparseMatrix object
    SparseMatrix sm(rows, cols);

    // Add non-zero elements to the sparse matrix
    // The indices are zero-based (row index, column index, value)
    sm.addElement(0, 2, 3);
    sm.addElement(0, 3, 4);
    sm.addElement(1, 2, 5);
    sm.addElement(1, 3, 7);
    sm.addElement(3, 1, 2);
    sm.addElement(3, 2, 6);

    // Display the array representation of the sparse matrix
    sm.display();

    return 0;
}
