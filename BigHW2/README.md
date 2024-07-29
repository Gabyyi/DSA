# Exercise 1 - Network Connectivity Checker

In the method `DFS()` we apply DFS to mark the connected edges in a graph.

In the method `isConnected()` we call the `DFS()` method and then search all edges in the graph and if it finds nodes that are not conected to the rest of the graph returns `"false"`. If all nodes in the graph are marked as visited from the `DFS()` method it means the graph in connected and returns `"true"`.

In the `main()` method we use an array to mark nodes between it exists an edge, then we add those in the graph

# Exercise 2 -  Binary trees 

`add(Character c)`

- Adds the Character(int value) c into the bst.
- Adds the Character(Struct) c into the Characters vector.
`removeMin()`

- Removes the minimum value from the bst and returns the corresponding Character value.

`generateEncodingTree()`

- Generates the encoding tree starting from the bst in an using an iterative approach.

`displayEncodingLevels()`

- Displays all the levels of the encoding tree using recursion.

`encode(char c, String path)`

- Returns the corresponding encoding of a character c(the path in the binary tree).

`encode(string message)`
- Iterates through the string and generates the encoding for each character.
- The these encodings are appended to a string that represents the encoded message whihc is returned.

`decode(string message)`
- While the message is not empty traverses the encoding tree and retreives the corresponding chars.
- The obtained characters are appended to the decoded message which is returned.

`readCharacters()`

- Used to read the characters and their frequency(used to build the bst and encodingTree).

`decodeFile()`

- Decodes the message from an input file and saves it in an output file.

`encodeFile()`

- Encodes the message from an input file and saves it into an output file.

## Usage

- Create an instance of the class : `EncodingTree tree;`
- Read the characters and their frequency: ` tree.readCharacters();`
- Generate the encoding tree:`tree.generateEcodingTree();`
- Decode a file: `tree.decodeFile();`
- Encode a file: `tree.encodeFile();` 

# Exercise 3 - Image Segmentation

In the method `void dfs()` we apply depth-first search to mark reachable nodes from the source.

In the method `int getMinWeight()` we get the minimum weight from the residual graph.

In the method `int getWeight()` we calculate the weight between two nodes based on the threshold.

In the method `void readImage()` we read the image from the input file and initialize the graph and residual graph.

In the method `void generateCut()` we generate the cut in the graph based on the minimum weight.

In the method `void displayGraphs()` we display the original image, graph, and residual graph in the output file.

In the method `void generateNewImage()` we generate the new segmented image based on the cut and write it to the output file.

