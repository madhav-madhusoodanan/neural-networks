//include node-node mappings
#include "Model.cpp"
#include "Mapping.cpp"
#ifndef NODE_CONTAINER_CPP
#define NODE_CONTAINER_CPP

// an object goes to a friend
// while destructing, destroy the pointer list maturely!
class Node_container : public Node
{   
    std::set<Node> nodes;
    std::set<Node_pair> connections; //all node-pairs that have our homie-nodes
public:
    Node_container(function_type activation) : Node(activation)
    {
        nodes.clear();
        connections.clear();
    }
    Node_container(Node_container &node): Node(node.activation)
    {
        nodes = node.nodes;
        connections = node.connections;
    }
    ~Node_container();
    void accept_data(size_t id, float input);
    bool transmit();    //send the outputs to the respective output_nodes
    void backpropagate();
};
void Node_container::accept_data(size_t id, float input)
{
    // learn about searching for object with nodes.extract()...
}
Node_container::~Node_container()
{
    nodes.clear();
    connections.clear();
}
#endif
