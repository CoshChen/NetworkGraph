# NetworkGraph
This is a C++ sample program which can be used to create graphs manually or from an input file.

# Data Format
The example graph loader is based on a citation network dataset in which each block represents a paper. Inside each block, each line starting with a specific prefix indicates an attribute of the paper. However, the `Graph` and `Node` classes are designed with a more general purpose. 

# Class and Method Summary
* Class Node

  Node variables:
    - `id`, `label`
    - `out_neighbor`: for example, references cited in this paper.
    - `features`: A map, feature -> value.
    - `featureFields`: keys in map, can be viewed as column names.
    - Note that nodes in a graph can have different sets of featureFields.
    
  Methods:    
    - `void setLabel(double n)`
    - `void add_out_neighbor(int to)`
    - `void setFeature(string field, string value)`: Add a feature to the node. If the specified feature exists, a change-value message will show in the console.  
    - `int getId()`
    - `int getLabel()`
    - `set<int> get_out_neighbors()`
    - `int getFeatureNum()`: Get numbers of features.
    - `vector<string> getFeatureFields()`
    - `string getFeature(string field)`: Will return an empty string if the specified field does not exist.
    
    For safty, there is no function to reset the id value.
    
    
* Class Graph

  Graph variables:
    - `vertices`: A set of all node ids.
    - `in_adjList`: A map, for example, paper -> cited by.
    - `id_dict`: A map, id -> node-object. This will be used for extracting node information from id.
    
  Methods:
    - `void addVertex(Node* vertex)`: Update `vertices` and `in_adjList`. 
	  - `void addEdge(Node* from, Node* to)`: Update `vertices`, `in_adjList`, and `out_neighbor` of `from`.
	  - `set<int> getVertices()`
	  - `Node* getNode(int id)`: Obtain node information with the specified id.
	  - `unordered_map<int, set<int> > exportGraph()`: Update `in_adjList` by adding nodes without in_neighbors, then return `in_adjList`. 

* Class GraphLoader: construct a graph by applying the class method `readFile(string path)`.

  The implementation of `readFile` is based on a certain file format assumption.
  
* Header Test: Two test cases are provided.
