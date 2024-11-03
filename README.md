# Codeforces Solutions 2

This repository contains my solutions to various Codeforces problems. Each problem's solution is organized for easy testing and verification.


## Usage

1. **Set Up Input/Output**:
    - Place the input for your test case in `input.txt`.
    - Write the expected output in `output.txt`.

2. **Compile and Run**:
    - Compile the `<problem_name_code>.cpp` file using your preferred C++ compiler:
      ```bash
      g++ main.cpp -o solution
      ```
    - Run the compiled program:
      ```bash
      ./solution < input.txt > result.txt
      ```
    - Compare `result.txt` with `output.txt` to check if the solution is correct.

3. **Adding New Problems**:
    - For every new problem, copy the content of `main.cpp` to a new file named `problem_name.cpp`, where `problem_name` describes the challenge (e.g., `div2_a.cpp`).
    - Update `input.txt` and `output.txt` accordingly to match the new problem requirements.

## Notes

- `main.cpp` file is only being used while testing various solutions the final solutions are in different files.
- Keep your code clean and well-commented to facilitate understanding and future modifications.

## Contributing

Feel free to fork this repository and submit your own solutions or improvements.

## Note
I have used CLion as my developer environment.