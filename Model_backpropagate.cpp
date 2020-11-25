#include"Model.cpp"
#ifndef MODEL_BACKPROPAGATE
#define MODEL_BACKPROPAGATE
/* The function that must be parallelized */
//correct the errors.

void Model::backpropagate(error_model error)
{
    for (Mapping_iterator iter = Mapping.end(); iter!=Mapping.begin(); iter--)
    {
        switch (error)
        {
        case mean_squared_error:
            auto i=train_y.begin();
                //firstly getting deviations
                for (auto iter = layer.end()->nodes.begin(); iter != layer.end()->nodes.end(); iter++, i++)
                {
                    *(nodes_existing[*(iter)].deviation) = (nodes_existing[*(iter)].process()) - *i;
                }

                for(auto iter = Mapping.end(); iter!= Mapping.begin(); iter--)
                {
                    *(nodes_existing[iter->input_node_id].deviation) += (*(nodes_existing[iter->output_node_id].deviation))*(iter->neuron_weight);
                }
                // now weight updating...will need to learn bias updating too
                for (auto iter = Mapping.begin(); iter!= Mapping.end(); iter++)
                {
                    //relearn backpropagation and verify
                    auto var1 = (nodes_existing[iter->input_node_id].process());
                    auto var2 = *(nodes_existing[iter->output_node_id].deviation);
                    auto ptr = (iter->neuron_weight); 
                    ptr += (var1 * var2);
                }
                break;
        default:
            break;
        }
    }
    
}
#endif
//HALF-SIGNERD BY MADHAV