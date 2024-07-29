# Exercise 1 - Linked List

We use a linked list in which each node represent an array of strings.

The method `isFlightFull` checks if all elements of the array in a node are not empty.

In the `bookFlight` method we check if the list is empty or if all elements of the array in the current node are occupied.
If not we start from the first node and we go through the array till we find an empty spot where we insert the new passenger.

In the `cancelBooking` method we identify the node by dividing the seat index that we want to delete by 5.
Then we move left all elements of the array starting from seat index modulo 5.
For the last element we check if the next node is not empty and and copy his first element in the last element of the current node.
We repete this untill all element are moved.

In the `displayFlights` method we display all elements if the array in the current node starting from the first and then we move to the next
node.

In the `getPassenger` method we identify the flight as seat index divided by 5 and return the element at index seat index modulo 5.
If the seat is empty we get `"Empty seat"` message and if the index doesn't exist we get `"Invalid index"`.

# Exercise 2 - Queue

We use a stack of type `Oasis` which contain an amount of water and a distance to the next oasis.
Also we use files to handle the input and output.
 
We copy the initial stack in an auxiliar one.
We check for each element in the stack if the condition `D>=nextDistance` is true and if yes we pop the element.
If the auxiliar stack is empty it means we can make the jurney without remaining out of water and ok variable is true.
If not we pop the element of the initial matrix and push it back and start again, we do this noOasis times.
If ok is still false it means the water is not enough to make the jurney.

# Execise 3 - Stack

We use a stack of type char to perform the evaluation of the expression and an array of type Pair which is made up of a char and a numerical value, used to the name of the variable and the value.
Also we use files to handle the input and output.

The `isValidVariable` method check if the name of the variable is valid, only capital letters are accepted.

The `isValidOperator` method check if the operator is valid in order to perfrom mathematical evaluation.

In the `readInput` method we read line by line storing the name of the variables and their values, check for user input errors and we add the last line which is the expression we need to evaluate in a char array.

In the `execute` method we implement reversed polish notation.
We convert the expression from infix to postfix, each stored in the arrays `IE` and `PE`.
Then we go through the PE array and if the element is an alphbetical character we compare it with the variables we have and push the corresponding value into the stack.
If it is an operator we pop 2 numbers from the stack, perform the mathematical evaluation and and push the value into the stack.
For dividing we check if the denominator is different from 0.

In the `writeOutput` we display the result.

### ! There is a small error if you use more than four variables, it calculates the correct result but it doesn't display it in the file. For the other cases it works fine and displays input errors.