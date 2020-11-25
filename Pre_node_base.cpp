/* the node can also yield the derivative of its function if requested by the model.
by performing level 1 derivative [adding del x to input and getting del y]
read about backpropagation and continue developing

even one byte of saving in case of neurons could mean a gigabyte-level saving in total memory intake.
*/

/* Member declaration */

#ifndef NODE_BASE_CPP
#define NODE_BASE_CPP
#include<utility>
#include<optional>
#include<memory>
#include<cmath>
#include<set>
//replace function_type with a char, for less space
enum function_type
    {
        none,
        linear,
        sigmoid,
        relu,
        relu6,
        elu,
        sine_type
    };
class Node_base
{
public:
    std::optional<float> input_val; //try to kill this guy
    std::optional<float> deviation;
    float bias{};
    bool is_active{};
    function_type activation{};

    Node_base(function_type activation);//how'd you initialize static members?
    ~Node_base() = default;
    float process();
};
/* inline bool operator!(const Node_base& node1)
{
    if (node1.input_val){return false;}
    return true;
} */

/* Member definition */
Node_base::Node_base(function_type activation)
    {
        activation = activation;
        bias = 0.05;
        is_active = true;
    }
float Node_base::process()
{
   
    *input_val += bias;         
    switch (activation)
    {
    case  sigmoid:
        return (1.0/(1.0+exp(-(*input_val))));
        break;
    case sine_type:
        return ((1.0+(sinf(M_PI*(*input_val))))/2.0);
        break;
    default:
        break;
    }
}
#endif
// SIGNED BY MADHAV