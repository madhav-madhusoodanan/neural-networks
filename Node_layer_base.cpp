#ifndef NODE_LAYER_BASE_CPP
#define NODE_LAYER_BASE_CPP
#include "Node_base.cpp"
#include<vector>

/* Member declaration */

enum connection_type //connection type with previous layer
    {
        dropout,
        custom,
        dense,
        local,
        input
    };
class Node_layer
{
public:
private:
    connection_type connection{dense};
public:
    std::vector<size> nodes;
    Node_layer(connection_type connection);
    ~Node_layer();
    void add(size num_nodes, function_type function);
};

/* Member definition */

Node_layer::Node_layer(connection_type connection)
    {
        connection = connection;
    }
Node_layer::~Node_layer() = default;
/* void Node_layer::compile(Node_layer& prev_layer)
    {
        switch (prev_layer.connection)
        {
        case dense:
            for (size_t i = 0; i < nodes.size(); i++)
            {
                for (size_t j = 0; j < prev_layer.nodes.size(); j++)
                {
                    nodes[i].add(prev_layer.nodes[j]);
                } 
            }
            
            break;
        
        default:
            break;
        }
    } */
/* void Node_layer::add(size_t num_nodes, function_type function)
{   //incase constructor misbehaves
    std::vector<std::shared_ptr<Node>> temp(num_nodes,std::make_shared<Node>(function));
} */
#endif