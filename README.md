# WaveLabs_First_Assignment
Code in C++.
# Network Connection README

This code is designed to find the minimum number of additional cable connections needed to connect all workstations in a network setup. The workstations are represented by numbers from 0 to n-1, and they can be connected through existing cable connections.

## Algorithm

The code uses the Union-Find algorithm to determine the minimum number of connections needed. It follows the following steps:

1. Define a `path_root` function that finds the root/parent of a node in the set hierarchy. It utilizes path compression to optimize future lookups.

2. Define a `path_node` function that merges two sets by updating their root/parent and rank values. It performs a union operation between two sets.

3. Implement the `check_connection` function that takes the number of workstations (`n`) and a vector of connections (`connections`) as input. It initializes the systems and rank vectors, sets the initial number of components to `n`, and iterates over each connection.

4. For each connection, check if the root/parent of the first node and the root/parent of the second node are different. If they are different, merge the sets using the `path_node` function and decrement the number of components.

5. After processing all connections, return the number of components minus 1. If the number of connections is less than `n-1`, return -1, indicating that it is not possible to connect all workstations.

## Usage

To use this code, follow these steps:

1. Set the value of `n` to the total number of workstations in the network.

2. Create a vector `connections` that represents the existing cable connections between workstations. Each connection is represented by a vector of two integers, where the first integer is the source workstation and the second integer is the destination workstation.

3. Call the `check_connection` function, passing `n` and `connections` as arguments.

4. The function will return the minimum number of additional connections needed to connect all workstations. If it is not possible to connect all workstations, the function will return -1.

5. Display or use the returned value as desired.

Example:

```cpp
int n = 6;
std::vector<std::vector<int>> connections{{0, 1}, {0, 4}, {3, 4}, {0, 3}, {2, 5}};

int minConnections = check_connection(n, connections);
std::cout << "Minimum number of connections needed: " << minConnections << std::endl;
```

Output:

```
Minimum number of connections needed: 1
```
