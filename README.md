# AOA PBLE 1: Smart Delivery Planning – Fractional Knapsack

## 📌 Description
This project implements the **Fractional Knapsack Problem** using the Greedy Algorithm in C. It helps a delivery company maximize the total value of packages carried by a vehicle with a fixed weight capacity.

The algorithm calculates the value-to-weight ratio of each package, sorts packages in decreasing order of their ratios, and selects complete packages or fractions of packages to obtain the maximum possible value.

## 🎯 Objectives
- Understand and implement the Greedy Method.
- Calculate the value-to-weight ratio of each package.
- Sort packages in decreasing order of ratio.
- Select complete packages and fractions when required.
- Calculate the maximum achievable value.
- Analyze the time and space complexity.

## ⚙️ Features
- Menu-driven C program.
- Enter and display package details.
- Calculate value-to-weight ratios.
- Sort packages by ratio.
- Find the maximum achievable value.
- Display selected packages, fractions, and total weight used.

## 🛠️ Technologies Used
- **Language:** C
- **Concepts:** Greedy Algorithm, Fractional Knapsack, Sorting, Arrays, Functions

## ▶️ How to Run

Compile the program:

```bash
gcc AOA_PBLE.c -o AOA_PBLE
```

Run on Windows:

```bash
.\AOA_PBLE
```

## 📊 Example

| Package | Value | Weight | Ratio |
|---|---:|---:|---:|
| 1 | 40 | 5 | 8.00 |
| 2 | 30 | 10 | 3.00 |
| 3 | 50 | 5 | 10.00 |
| 4 | 20 | 4 | 5.00 |

**Vehicle Capacity:** 15 units

**Maximum Value Obtained:** 113

## ⏱️ Complexity Analysis

- **Time Complexity:** O(n²), due to Bubble Sort.
- **Space Complexity:** O(n), for storing package details and selection fractions.

## 📚 Academic Information
- **Subject:** Analysis of Algorithms (AOA)
- **Practical-Based Learning Exercise:** PBLE 1
- **Topic:** Smart Delivery Planning – Fractional Knapsack

## 👨‍💻 Author
Shubham Sahni
