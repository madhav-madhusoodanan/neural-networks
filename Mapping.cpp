#ifndef MAPPING_CPP
#define MAPPING_CPP
#include "Node_base.cpp"
#include <vector>
typedef float Neuron;
class Node_pair
{   
    public:
    size input_node_id;
    size output_node_id;
    float neuron_weight{0.1};
    Node_pair(size input_id, size output_id);
};
/* operator overloading going on */

inline bool operator==(const Node_pair& Node_pair1, const Node_pair& Node_pair2)
{return (((Node_pair1.input_node_id)== (Node_pair2.input_node_id))&&((Node_pair1.output_node_id)== (Node_pair2.output_node_id)));}
inline bool operator!=(const Node_pair& Node_pair1, const Node_pair& Node_pair2)
{return !(Node_pair1==Node_pair2);}
inline bool operator<(const Node_pair& Node_pair1, const Node_pair& Node_pair2)
{
    if ((Node_pair1.output_node_id) < (Node_pair2.output_node_id))
    {//can you implement a reference for input&output? else duplication could occur in Model's mapping...
    
        return true;
    }
    else if((Node_pair1.output_node_id) == (Node_pair2.output_node_id))
    {
        return ((Node_pair1.input_node_id) < (Node_pair2.input_node_id));
    }
    return false;
}
inline bool operator>(const Node_pair& Node_pair1, const Node_pair& Node_pair2)
{
    if ((Node_pair1.output_node_id) > (Node_pair2.output_node_id))
    {
        return true;
    }
    else if((Node_pair1.output_node_id) == (Node_pair2.output_node_id))
    {
        return ((Node_pair1.input_node_id) > (Node_pair2.input_node_id));
    }
    return false;
}
inline bool operator<=(const Node_pair& Node_pair1, const Node_pair& Node_pair2)
{
    if ((Node_pair1) < (Node_pair2) || (Node_pair1) == (Node_pair2))
    {
        return true;
    }
    else  return false;
}
inline bool operator>=(const Node_pair& Node_pair1, const Node_pair& Node_pair2)
{
    if ((Node_pair1) > (Node_pair2) || (Node_pair1) == (Node_pair2))
    {
        return true;
    }
    else  return false;
}
/* operator overloading ends */
Node_pair::Node_pair(size input_id, size output_id) : input_node_id(input_id), output_node_id(output_id)
{/*is_trampled = false;*/}
#endif
//SIGNED BY MADHAV