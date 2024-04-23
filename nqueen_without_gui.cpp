#include <iostream>
#include <vector>

class NQueensSolver {
public:
    NQueensSolver(int n) : n(n) {}
    std::vector<std::vector<int>> solve() {
        solutions.clear();
        std::vector<int> solution;
        backtrack(0, solution);
        return solutions;
    }
private:
    int n;
    std::vector<std::vector<int>> solutions;

    void backtrack(int row, std::vector<int>& solution) {
        if (row == n) {
            solutions.push_back(solution);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (isSafe(row, col, solution)) {
                solution.push_back(col);
                backtrack(row + 1, solution);
                solution.pop_back();
            }
        }
    }

    bool isSafe(int row, int col, const std::vector<int>& solution) {
        for (size_t r = 0; r < row; ++r) {
            if (solution[r] == col || std::abs(static_cast<int>(row - r)) == std::abs(col - solution[r])) {
                return false;
            }
        }
        return true;
    }
};

void printSolution(const std::vector<int>& solution) {
    for (int row : solution) {
        for (int col = 0; col < solution.size(); ++col) {
            std::cout << (col == row ? 'Q' : '.');
            std::cout << ' ';
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Enter the value of N: ";
    std::cin >> n;

    NQueensSolver solver(n);
    std::vector<std::vector<int>> solutions = solver.solve();

    if (solutions.empty()) {
        std::cout << "There is no solution for the " << n << "-Queens problem." << std::endl;
    } else {
        std::cout << "Found " << solutions.size() << " solution(s) for the " << n << "-Queens problem:" << std::endl;
        for (size_t i = 0; i < solutions.size(); ++i) {
            std::cout << "Solution " << i + 1 << ":" << std::endl;
            printSolution(solutions[i]);
        }
    }

    return 0;
}
//created by Aryan Gupta
