#include<iostream>
using namespace std;
int main()
{
    
    int x, y, z;
    cin>>x>>y>>z;
    if ((y+z)/x == ((y/x)+1))
    {
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
return 0;
}

//----------------------------^hackerrank submission^------------------------------------------

//if ((factorial[max_digit(num - check_sum)] == 0)&&(check_sum != num))
        // {
       //     ++skip;
         //   check_sum = factorial[max_digit(num)-skip-1];
           // check_sum = max_digit(num)-skip-1;
        //}
//#include <iostream>
//#include <limits>
//#include <numeric>
//#include <optional>
//int main(){

/*   cout << endl;

  auto begin= chrono::system_clock::now();

  auto asyncLazy=async(launch::deferred,[]{ return  chrono::system_clock::now();});

  auto asyncEager=async( launch::async,[]{ return  chrono::system_clock::now();});

  this_thread::sleep_for(chrono::seconds(6));

  auto lazyStart= asyncLazy.get() - begin;
  auto eagerStart= asyncEager.get() - begin;

  auto lazyDuration= chrono::duration<double>(lazyStart).count();
  auto eagerDuration=  chrono::duration<double>(eagerStart).count();

  cout << "asyncLazy evaluated after : " << lazyDuration << " seconds." << endl;
  cout << "asyncEager evaluated after: " << eagerDuration << " seconds." << endl;

  cout << endl;
 */
//string

//}

/* #include <chrono>
#include <iostream>
#include <future>
#include <random>
#include <vector>
#include <numeric>

static const int NUM= 100000000;
parallel dot product using tasks....
long long getDotProduct(vector<int>& v, vector<int>& w){

  auto future1= async([&]{return inner_product(&v[0],&v[v.size()/4],&w[0],0LL);});
  auto future2= async([&]{return inner_product(&v[v.size()/4],&v[v.size()/2],&w[v.size()/4],0LL);});
  auto future3= async([&]{return inner_product(&v[v.size()/2],&v[v.size()*3/4],&w[v.size()/2],0LL);});
  auto future4= async([&]{return inner_product(&v[v.size()*3/4],&v[v.size()],&w[v.size()*3/4],0LL);});

  return future1.get() + future2.get() + future3.get() + future4.get();
}--------------------------------------------------------------------------------------------------
 */

/* // for_each example
#include <iostream>     // cout
#include <algorithm>    // for_each
#include <vector>       // vector
#include <execution>
void myfunction (int &i) {  // function:
  i += 5; 
  cout << ' ' << i;
}

int main () {
  vector<int> myvector;
  myvector.push_back(10);
  myvector.push_back(20);
  myvector.push_back(30);

  cout << "myvector contains:";
  for_each (execution::par, myvector.begin(), myvector.end(), myfunction);
  cout << '\n';
} */
/* The awesome picture:
...
#include"Model.cpp"
int main()
{
    Model model{};
    model.idea("image processing, 2D");  //designs a runtime interface for confirmation and further addition
            //put tags to give the model an idea ("<tag1>, <tag2>, <tag3>,...")
    model.add_layer(input, None, 100); //auto-defines the dimensions from input, just put total number (x*y)
    model.add_layer(LSTM, sigmoid, 81);
    model.add_layer(Dropout, None);
    model.add_layer(Dense, relu, 9);
    model.compile(error = categorical_crossentropy, optimizer = adam, show_data = true)
    model.train(array_input, array_output); //this could be a folder, file, or an array of input-output
            //just put in the required class/struct object and i will handle the rest
    
}---------------------------------------------------------------------------------------------------
 */

/* The 2nd Picture
    #include "AI_mode.cpp"
    int main()
    {
        output = AI_mode("Text that describes your version of a program");
            //this guy makes an AI.txt file that if changed to AI.cpp file
                 can then be used as the code you wanted

            //this guy uses NLP to convert english explanations to c++ code
            //This 2nd level project is a direct competition to DeepMind and OpenAI
        cout<<output; //true or false
    }
 */