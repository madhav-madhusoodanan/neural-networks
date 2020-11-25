//this is where the computation comes in
#include "Model.cpp"
#ifndef MODEL2_CPP
#define MODEL2_CPP
/* The function that must be parallelized */
/* Alongwith Mapping */
void Model::train(std::vector<float> input, std::vector<float> output)
{
   auto in = input.begin();
   for (auto iter = layer[0].nodes.begin(); iter != layer[0].nodes.end(); iter++, in++)
   {
      (nodes_existing[*iter].input_val) = *in;
   }
   
   for(auto iter = Mapping.begin(); iter!= Mapping.end(); iter++)
   {
      *(nodes_existing[iter->output_node_id].input_val) += (nodes_existing[iter->input_node_id].process())*(iter->neuron_weight);
   }
   backpropagate(mean_squared_error); //generalize this
}

#endif