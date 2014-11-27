#include "Neural_Network.h"
#include "Back_Prop.h"
#include "FilesIo.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>


using namespace std;
using namespace NeuralNetwork;
using namespace FilesIo;

int main()
{

	vector<int> scheme = { 24,6,1 };



	double lambda = 0.;
	double alpha = 3.0;
	double stop_crit = 0.0001;

	//string path = "F:/Projets-C++/neural_training_test/sinus2_training.csv";
	string path = "E:/add_data/sample_test.out";
	string save_path = "F:/Projets-C++/neural_training_test/cost_evol.out";
	vector<vector<double>> training_inputs = {};
	vector<vector<double>> training_outputs = {};

	vector<double> cost_vect;
	vector<vector<double>> data;

	vector<double> line;


	// importing datafile
	data = importD(path, 1, 0);

	cout << "end reading \n";

	for (size_t i = 0; i < data.size(); ++i)
	{
		//cout << "data " <<  data[i][0] << " " << data[i][1] << endl;

		training_outputs.push_back({ data[i][0] });

		line.clear();
		for (size_t j = 1; j < data[i].size()-1; ++j)
		{
			line.push_back(data[i][j]);
		}
		
		training_inputs.push_back(line);
	}


	// building network
	Network network;
	network.build_network(scheme,0,0);

	// building back prop
	Back_prop back_prop(network, lambda);

	back_prop.set_save_path(save_path);
	back_prop.training(training_inputs, training_outputs, alpha, stop_crit);


	cost_vect = back_prop.get_cost_vect();

	for (auto cost : cost_vect)
	{
		cout << "cost : " << cost << endl;
	}



	//--------------------------------------------

	vector<vector<double>> weights;

	//weights = back_prop.get_mod_weights();
	//network.set_allWeights(weights);

	save_path = "F:/Projets-C++/neural_training_test/trained_sin2.out";
	vector<vector<double>> x, y;
    vector<double> dat;
	vector<double> o;


	for (int i = -100; i < 100; ++i)
	{
		dat = { i*40. / 200. };
		x.push_back(dat);

		network.set_inputs(x.back());

		network.forward_prop();
		o = network.get_outputs();

		y.push_back(o);
	}

	ofstream sfile(save_path.c_str());

	if (sfile)
	{
		for (size_t i = 0; i < x.size(); ++i)
		{
			sfile << x[i][0] << ", " << y[i][0] << endl;
		}
	}
	else
	{
		cout << "ERROR can't open file to save \n";
	}


	return 0;


}