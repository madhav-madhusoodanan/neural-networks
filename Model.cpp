/*     
This pig will watch over your code when you arent watching it...however it is your responsibility
to prevent errors from killing him. Understood?
                         _ 
 _._ _..._ .-',     _.._(`)) 
'-. `     '  /-._.-'    ',/ 
   )         \            '. 
  / _    _    |             \ 
 |  a    a    /              | 
 \   .-.     /               ;   
  '-('' ).-'       ,'       ; 
     '-;           |      .' 
        \           \    / 
        | 7  .__  _.-\   \ 
        | |  |  ``/  /`  / 
       /,_|  |   /,_/   / 
          /,_/      '`-' 
 */
// must perform a header-file optimization
// implement backpropagate and dropout, and gradient-search...
//#include "parallel-loop-1.h"
#include "Node_layer_base.cpp"
#include "Mapping.cpp"
#ifndef MODEL_CPP
#define MODEL_CPP
typedef std::set<Node_pair>::iterator Mapping_iterator ;
enum error_model
{
   auto_detect,
   categorical_crossentropy,
   binary_crossentropy,
   mean_squared_error
};

enum optimizer_model
{
   adam,
   adagrad
};
class Model 
{
   
protected:
   std::vector<Node> nodes_existing; //index = id no.
   std::vector<Node_layer> layer; //make them as pointers/references
   std::set<Node_pair> Mapping;  //mapping...output_node major
      //expect trillions of entries
      // replace map with a custom-made one
      // use nodes in terms of Node_layer[i]
      // generated when compile is called
public:
    std::vector<float> train_y;
    void add_layer(connection_type connection, function_type function, size_t num_nodes);
    bool add_connection(Node&, Node&);
    bool compile(error_model error, optimizer_model optimizer, bool show_data); //also build connections
    void train(std::vector<float> train_x, std::vector<float> train_y);
    std::vector<float> predict(std::vector<float> test_x);
    void idea(std::string idea);

    //weight/bias search techniques
    void backpropagate(error_model error);
    void add_layer(connection_type connection, function_type function, size num_nodes);
};

void Model::add_layer(connection_type connection, function_type function, size_t num_nodes)
{
   Node_layer temp(connection);
   layer.push_back(temp); //modify this to be anywhere inside the vector
   Mapping_iterator begin = Mapping.begin();
}
std::vector<float> Model::predict(std::vector<float> test_x)
{
   Mapping_iterator iter = Mapping.begin(); 
   while(iter!= Mapping.end())
   {
      *(nodes_existing[iter->output_node_id].input_val) += (nodes_existing[iter->output_node_id].process())*(iter->neuron_weight);
   }
   std::vector<float> test_y;
   for (auto iter = (layer.end())->nodes.begin(); iter != (layer.end())->nodes.end(); iter++)
   {
      test_y.push_back(nodes_existing[(*iter)].process());
   }
   return test_y;
}
#include "Model2.cpp"
#endif
