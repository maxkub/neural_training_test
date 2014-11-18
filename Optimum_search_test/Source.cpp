#include <iostream>
#include <vector>
#include "FilesIo.h"
#include "Neural_Network.h"
#include "Optimum_search.h"

using namespace std;
using namespace FilesIo;
using namespace NeuralNetwork;

int main()
{

	double lambda = 0.;
	double alpha = 3.0;
	double stop_crit = 0.0001;

	int N_input = 1;
	int N_neuron_max = 10;
	int N_layer_max = 5;
	int N_output = 1;

	string path = "F:/Projets-C++/neural_training_test/sinus2_training.csv";
	string save_path = "F:/Projets-C++/neural_training_test/optimum_search.out";
	vector<vector<double>> training_inputs = {};
	vector<vector<double>> training_outputs = {};
	vector<vector<double>> cv_inputs = {};
	vector<vector<double>> cv_outputs = {};
	vector<vector<double>> data;


	// importing datafile
	data = import(path, 1, 1);

	cout << "end reading \n";

	for (size_t i = 0; i < data.size(); ++i)
	{

		if (i%2 == 0)
		{
			cout << "data tr " <<  data[i][0] << " " << data[i][1] << endl;
			training_inputs.push_back({ data[i][0] });
			training_outputs.push_back({ data[i][1] });
		}
		else
		{
			cout << "data cv " <<  data[i][0] << " " << data[i][1] << endl;
			cv_inputs.push_back({ data[i][0] });
			cv_outputs.push_back({ data[i][1] });
		}
	}

	

	// creating object 
	Optimum_search opt_search;

	//initializing parameters of trainings
	opt_search.init(lambda, alpha, stop_crit);

	// giving the training set
	opt_search.training_set(training_inputs, training_outputs);

	// giving the cross validation set
	opt_search.cv_set(cv_inputs, cv_outputs);

	// setting print path
	opt_search.set_save_path(save_path);

	// testing multiple networks
	opt_search.search(N_input, N_neuron_max, N_layer_max, N_output);


	return 0;
}