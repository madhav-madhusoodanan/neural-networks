#include "Pre_node_base.cpp"
#include <iostream>
typedef unsigned int size;   
//in the future, consider long type for size if id runs into trillions
//this is primarily for distributed computing
//disengage this page for single-computer computing
//how i see you ask? just empty the class content below
class Node : public Node_base
{
protected:
    size neuron_count{0};
    size neuron_so_far_responded{0};
    static size spawn_count;
    std::optional<float> temp;
public:
    const size node_id;
    void total_number_of_neurons(size count) {neuron_count = count;}
    void add_neuron_responded_count() {neuron_so_far_responded++;}
    std::optional<float> check_then_process()
    {
        if (neuron_so_far_responded==neuron_count) {*temp = process(); return temp;}
        else return std::nullopt;
    }
    Node(function_type activation): Node_base(activation), node_id(spawn_count++)
    {}
    ~Node()
    {
        spawn_count--;
    }
};
size Node::spawn_count = 0;

//operator overloading
inline bool operator>(const Node &node1, const Node &node2)
{
    return (node1.node_id>node2.node_id);
}

inline bool operator<(const Node &node1, const Node &node2)
{
    return (node1.node_id<node2.node_id);
}

inline bool operator==(const Node &node1, const Node &node2)
{
    return (node1.node_id==node2.node_id);
}
inline bool operator!=(const Node &node1, const Node &node2)
{
    return !(node1.node_id==node2.node_id);
}
inline bool operator>=(const Node &node1, const Node &node2)
{
    return ((node1.node_id>node2.node_id) || (node1.node_id==node2.node_id));
}
inline bool operator<=(const Node &node1, const Node &node2)
{
    return ((node1.node_id<node2.node_id) || (node1.node_id==node2.node_id));
}
//SIGNED BY MADHAV