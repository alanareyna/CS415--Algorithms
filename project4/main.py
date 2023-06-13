# Creator: Alana Reyna
# Project 4: Knapsack project
import string
import sys
from tabulate import tabulate
import matplotlib.pyplot as plt


# dynamic programming approach class
class DPA:
    def __init__(self):
        # traditional dynamic programming optimal subset vector
        self.dp_optimal_subset = []
        # traditional dynamic programming table to save values
        self.dp_table = []
        # traditional dynamic programming number of basic operations
        self.dp_basic_op_num = 0

    # TASK 1A: TRADITIONAL DYNAMIC PROGRAMMING APPROACH
    # input: capacity, values, weights, length of values(n)
    # output: optimal value from subset of values and the subset of values used to get the optimal value
    def dynamic_programming(self, capacity, values, weights, n):
        # create a table with a size of n(length of values) x capacity with values initialized to 0
        self.dp_table = [[0 for x in range(capacity + 1)] for x in range(n + 1)]

        # build table using bottom up approach
        for i in range(n + 1):
            for y in range(capacity + 1):
                # if i or the capacity is 0, do not fill data into this cell, set cell to 0
                if i == 0 or capacity == 0:
                    self.dp_basic_op_num += 1
                    self.dp_table[i][y] = 0
                # we will compare the weight at i - 1 (looping through the length of the values) to the capacity at y
                # if the weight is less than the capacity, then set the cell value to whatever the maximum is between
                # the value at
                elif weights[i - 1] <= y:
                    self.dp_basic_op_num += 1
                    self.dp_table[i][y] = max(values[i - 1] + self.dp_table[i - 1][y - weights[i - 1]],
                                              self.dp_table[i - 1][y])
                    # print("dp_table i y: ", self.dp_table[i][y])
                else:
                    self.dp_table[i][y] = self.dp_table[i - 1][y]
        return self.dp_table[n][capacity]

    # input:
    def DP_optimal_path(self, capacity, values, weights, n, table):
        i = n
        j = capacity

        while i > 0 and j > 0:
            # add if j - wi < 0
            if j - weights[i - 1] < 0:
                i = i - 1
            elif table[i - 1][j] > table[i - 1][j - weights[i - 1]] + values[i - 1]:
                i = i - 1
            else:
                self.dp_optimal_subset.insert(0, i)
                i = i - 1
                j = j - weights[i]
        return self.dp_optimal_subset


# TASK 1B
class memory_DP:
    def __init__(self):
        # memory function dynamic programming optimal subset vector
        self.mdp_optimal_subset = []
        # memory function dynamic programming table to save values
        self.mdp_table = []
        # memory function dynamic programming number of basic operations
        self.mdp_basic_op_num = 0
        # size of values
        self.n = 0
        # capacity value
        self.capacity = 0
        # values
        self.values = []
        # weights
        self.weights = []

    # input: n, the size of the values array, and m, the capacity
    # output: the optimal value
    def memory_dynamic_programming(self, n, m, value):
        # print("MDP table at n,m: ", self.mdp_table[n][m])
        if n == 0 or m == 0:
            self.mdp_basic_op_num += 1
            self.mdp_table[n][m] = 0
            return self.mdp_table[n][m]
        if self.mdp_table[n][m] == -1:
            self.mdp_basic_op_num += 1
            if m < self.weights[n - 1]:
                self.mdp_basic_op_num += 1
                value = self.memory_dynamic_programming(n - 1, m, value)
            else:
                self.mdp_basic_op_num += 1
                value = max(self.memory_dynamic_programming(n - 1, m, value), self.values[n - 1]
                            + self.memory_dynamic_programming(n - 1, m - self.weights[n - 1], value))

                # print("Value at n-1: ", self.values[n-1], "weight at n-1: ", self.weights[n-1])
                # print("Value: ", value)
            self.mdp_basic_op_num += 1
            self.mdp_table[n][m] = value
            # print("MDP table at n,m: ", self.mdp_table[n][m])
        return self.mdp_table[n][m]

    def memory_dynamic_programming_op_path(self, n, m, table, weights, values):
        # size of values
        i = n
        # capacity size
        j = m

        while i > 0 and j > 0:
            # add if j - wi < 0
            # print("j index before if: ", j)
            if j - weights[i - 1] < 0:
                # print("index at if: ", i)
                i = i - 1
                # j = j - 1
            elif table[i - 1][j] > table[i - 1][j - weights[i - 1]] + values[i - 1]:
                # print("index at elif: ", i)
                # self.optimal_subset.append(i)
                i = i - 1
            else:
                # print("index at else statement: ", i)
                self.mdp_optimal_subset.insert(0, i)
                i = i - 1
                j = j - weights[i]
        return self.mdp_optimal_subset


# TASK 1C: SPACE EFFICIENT APPROACH USING HASH TABLE
class MDP_hash:
    def __init__(self):
        # optimal value given by the memory dynamic programming hash function
        self.optimal_value = 0
        # optimal subset that gives the optimal value given by the optimal subset
        self.optimal_subset = []
        # table containing values from knapsack
        self.table = []
        # array containing the values given by the input files
        self.values = []
        # array containing the values given by the weights files
        self.weights = []
        # capacity given by the input file
        self.capacity = 0
        # number of basic operations from hash knapsack function
        self.num_basic_ops = 0
        # k value
        self.k = len(self.values)

    # get the index given a key(value from values array) and perform hash % k (k = length of the table)
    # make length a prime value to optimize hash position value?
    def get_index(self, n, m):
        if n == 0 or m == 0:
            return 0
        else:
            key = ((n - 1) * self.capacity + m) % self.k
        return key

    # adds a value in the hash table
    # uses the get_index function to find the index the key will be inserted to the table
    def add_to_hash(self, key, value, n, m):
        key = self.get_index(n, m)
        if self.table[key] is not None:
            for j in self.table[key]:
                # first cell in the linked list stores the key, the remaining 1-n cells contain the values associated
                # at that cell
                if j[0] == key:
                    # j.append([key, value])
                    j.append([value])
                else:
                    j.append([value])
        else:
            self.table[key] = []
            self.table[key].append([value])
        return self.table[key]

    # get the last value in hash table at key
    def get_hash_val(self, key):
        linkedList = []
        if self.table[key] is None:
            return None
        else:
            for i in self.table[key]:
                for j in i:
                    linkedList.append(j)
        temp_optimal_value = str(linkedList[-1])
        optimal_value = temp_optimal_value.replace('[', "")
        optimal_value = optimal_value.replace(']', "")
        optimal_value = int(optimal_value)
        return optimal_value

    def search_hash(self, key):
        if key > self.k:
            return None
        elif self.table[key] is None:
            return None
        else:
            for i in self.table[key]:
                if i == key:
                    return self.table[key]

    # memory function for filling knapsack table using hash table
    # input n (len of values) and m (capacity) and the value being input
    def memory_function_hash(self, n, m, value):
        if n == 0 or m == 0:
            self.num_basic_ops += 1
            return 0
        key = self.get_index(n, m)
        self.num_basic_ops += 1
        if self.search_hash(key) is None:
            self.num_basic_ops += 1
            if m < self.weights[n - 1]:
                self.num_basic_ops += 1
                value = self.memory_function_hash(n - 1, m, value)
            else:
                self.num_basic_ops += 1
                value = max(self.memory_function_hash(n - 1, m, value),
                            self.values[n - 1] + self.memory_function_hash(n - 1, m - self.weights[n - 1], value))
            self.num_basic_ops += 1
            self.add_to_hash(key, value, n, m)
        self.num_basic_ops += 1
        optimal_value = self.get_hash_val(key)
        return optimal_value

    # returns the optimal subset for the hash table function
    def get_optimal_subset(self, n, m, table, weights, values):
        # size of values
        i = n
        # capacity size
        j = m

        index = self.get_index(n, m)
        index1 = self.get_index(n-1, m)
        index2 = self.get_index(n-1, m - weights[i-1])
        value_i1 = self.get_hash_val(index1)
        value_i2 = self.get_hash_val(index2)

        while i > 0 and j > 0:
            # add if j - wi < 0
            if j - weights[i - 1] < 0:
                i = i - 1
            elif value_i1 > value_i2 + values[i-1]:
                i = i - 1
            else:
                self.optimal_subset.append(i)
                i = i - 1
                j = j - weights[i]
        return self.optimal_subset


# TASK 2A: GREEDY APPROACH USING SORTING

# TASK 2B: GREEDY APPROACH USING MAX-HEAPa

# get capacity file id
def get_capacity_id(file_name_prefix):
    if int(file_name_prefix) >= 10:
        file_capacity_name = "p" + file_name_prefix + "_c.txt"
    else:
        # open file capacity file using the file name prefix given by user
        file_capacity_name = "p0" + file_name_prefix + "_c.txt"
    return file_capacity_name


# This function will take in the prefix number corresponding to the filename, identify the file we want, and return
# the data from capacity, values, and weight files
def get_capacity_file(file_name):
    file_capacity_name = open(file_name)
    file_capacity = file_capacity_name.read().split()
    # close file
    file_capacity_name.close()
    return file_capacity


# get values file ids
def get_values_id(file_name_prefix):
    if int(file_name_prefix) >= 10:
        file_value_name = "p" + file_name_prefix + "_v.txt"
    else:
        # open file capacity file using the file name prefix given by user
        file_value_name = "p0" + file_name_prefix + "_v.txt"
    return file_value_name


# open and return values
def get_values_file(file_name):
    file_value_name = open(file_name)
    # read file lines and save as a vector
    file_value = file_value_name.read().split()
    # close file
    file_value_name.close()
    return file_value


# get the id for weights file
def get_weights_id(file_name_prefix):
    if int(file_name_prefix) >= 10:
        file_weights_name = "p" + file_name_prefix + "_w.txt"
    else:
        # open file capacity file using the file name prefix given by user
        file_weights_name = "p0" + file_name_prefix + "_w.txt"
    return file_weights_name


def get_weights_file(file_name):
    file_weights_name = open(file_name)
    # read file and save as a vector array
    file_weights = file_weights_name.read().split()
    # close file
    file_weights_name.close()
    # return capacity, values, and weights
    return file_weights


def main():
    # re-add the line below and delete the line following it when we are done testing:
    file_name_prefix = sys.argv[1]
    file_name_prefix = ""
    value_file_ids = []
    DP_total_basic_ops = []
    MF_total_basic_ops = []
    MDP_hash_total_basic_ops = []
    MF_len_tables = []
    MF_hash_len_tables = []

    while file_name_prefix != 'stop':
        file_name_prefix = input("Enter prefix: ")
        if file_name_prefix == 'stop':
            print("Stopping program ... ")
            break
        # CAPACITY INFO:
        capacity_file_id = get_capacity_id(file_name_prefix)
        capacity_file = get_capacity_file(capacity_file_id)
        capacity = int(capacity_file[0])

        # VALUES INFO:
        value_file_id = get_values_id(file_name_prefix)
        value_file_ids.append(value_file_id)
        values_file = get_values_file(value_file_id)
        values = [int(i) for i in values_file]
        values_len = len(values)

        # WEIGHTS INFO:
        weight_file_id = get_weights_id(file_name_prefix)
        weights_file = get_weights_file(weight_file_id)
        weights = [int(i) for i in weights_file]

        # PRINT FILE NAME INFO:
        print("File containing the capacity, weights, and values are: ", capacity_file_id + ",", weight_file_id + ",",
              value_file_id + ",")

        # PRINT KNAPSACK CAPACITY AND TOTAL NUMBER OF ITEMS
        print("Knapsack capacity =", str(capacity) + ".", "Total number of items =", values_len)

        # TASK 1:
        DP = DPA()
        # TASK 1A:
        print("(1a) Traditional Dynamic Programming Optimal value: ", DP.dynamic_programming(capacity, values, weights,
                                                                                             values_len))
        print("(1a) Traditional Dynamic Programming Optimal Subset: ",
              DP.DP_optimal_path(capacity, values, weights, values_len, DP.dp_table))
        print("(1a) Traditional Dynamic Programming Total Basic Ops: ", DP.dp_basic_op_num)
        DP_total_basic_ops.append(DP.dp_basic_op_num)
        print(" ")

        # TASK 1B
        # create an object of the memory dynamic programming class and set values
        MDP = memory_DP()
        MDP.n = values_len
        MDP.capacity = capacity
        # print("MDP capacity: ", MDP.capacity)
        MDP.values = values
        MDP.weights = weights
        MDP.mdp_table = [[-1 for x in range(capacity + 1)] for x in range(values_len + 1)]
        # print("MDP table: ", MDP.mdp_table)
        # print("size of MDP table: ", len(MDP.mdp_table) * len(MDP.mdp_table[0]))
        value = 0
        # print statements
        print("(1b) Memory-function Dynamic Programming Optimal value: ", MDP.memory_dynamic_programming(MDP.n,
                                                                                                         MDP.capacity,
                                                                                                         value))
        print("(1b) Memory-function Dynamic Programming Optimal subset: ", MDP.memory_dynamic_programming_op_path(MDP.n,
                                                                                                                  MDP.capacity,
                                                                                                                  MDP.mdp_table,
                                                                                                                  MDP.weights,
                                                                                                                  MDP.values))
        print("(1b) Memory-function Dynamic Programming Total Basic Ops: ", MDP.mdp_basic_op_num)
        MF_total_basic_ops.append(MDP.mdp_basic_op_num)
        MF_table_size = len(MDP.mdp_table)
        MF_len_tables.append(MF_table_size)
        print(" ")

        # TASK 1C
        # create an object of the memory DP hash table
        hashMDP = MDP_hash()
        hashMDP.values = values
        hashMDP.capacity = capacity
        hashMDP.weights = weights
        prime = capacity
        for i in range(2, prime):
            if prime % i == 0:
                prime += 1
            else:
                hashMDP.k = prime
        # figure out how to optimize the size of the hash table ****************
        hashMDP.table = [None] * hashMDP.k
        print("(1c) Space-efficient Dynamic Programming Optimal value: ",
              hashMDP.memory_function_hash(values_len, hashMDP.capacity, value))
        print("(1c) Space-efficient Dynamic Programming Optimal subset: ",
              hashMDP.get_optimal_subset(values_len, capacity, hashMDP.table, hashMDP.weights, hashMDP.values))
        print("(1c) Space-efficient Dynamic Programming Total Basic Ops: ", hashMDP.num_basic_ops)
        MDP_hash_total_basic_ops.append(hashMDP.num_basic_ops)
        hash_table_size = len(hashMDP.table)
        print("(1c) Space-efficient Dynamic Programming Space Taken: ", hash_table_size)
        MF_hash_len_tables.append(hash_table_size)
        print("")

        # TASK 2
        # TASK 2A
        print("(2a) Greedy Approach Optimal value: ")
        print("(2a) Greedy Approach Optimal subset: ")
        print("(2a) Greedy Approach Total Basic Ops: ")
        print(" ")

        # TASK 2B
        print("(2b) Heap-based Greedy Approach Optimal value: ")
        print("(2b) Heap-based Greedy Approach Optimal subset: ")
        print("(2b) Heap-based Greedy Approach Total Basic Ops: ")

    # TASK 3
    # TASK 1A VS TASK 1B
    x1 = value_file_ids
    y1 = DP_total_basic_ops
    x2 = value_file_ids
    y2 = MF_total_basic_ops
    plt.plot(x1, y1, label="Dynamic Programming")
    plt.plot(x2, y2, label="Memory Function")
    plt.xlabel('x - case id')
    plt.ylabel('y - number of basic operations')
    plt.title('Task1A vs Task1B')
    plt.legend()
    plt.show()
    # TASK 1B VS 1C
    size_of_1b = MF_len_tables
    size_of_1c = MF_hash_len_tables
    y3 = MDP_hash_total_basic_ops
    plt.plot(size_of_1b, y2, label="Memory Function")
    plt.plot(size_of_1c, y3, label="Space-Efficient Memory Function (hash table)")
    plt.xlabel('x - space complexity')
    plt.ylabel('y - number of basic operations')
    plt.title('Task 1B vs Task 1C')
    plt.legend()
    plt.show()


main()
