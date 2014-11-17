#include "stdafx.h"
#include "Neural_Network.h"
#include "Back_Prop.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>


using namespace std;
using namespace NeuralNetwork;

int main()
{

	vector<int> scheme = { 1, 5,5,1 };

	double lambda = 0.;
	double alpha = 2.0;
	double stop_crit = 0.0001;

	string path = "F:/Projets-C++/neural_training_test/parabole_training.csv";
	string save_path = "F:/Projets-C++/neural_training_test/cost_evol.out";
	vector<vector<double>> training_inputs = {};
	vector<vector<double>> training_outputs = {};

	vector<double> cost_vect;

	vector<vector<double>> read(string,int,bool);
	vector<vector<double>> data;



	data = read(path, 1, 1);

	cout << "end reading \n";

	for (size_t i = 0; i < data.size(); ++i)
	{
		//cout << "data " <<  data[i][0] << " " << data[i][1] << endl;

		training_inputs.push_back({ data[i][0] });
		training_outputs.push_back({ data[i][1] });
	}


	/*ifstream file(path.c_str());

	if (file)
	{
		double x, y;
		string input;
		vector<double> in, out;


		getline(file, input);

		while (getline(file,input) )
		{
			stringstream ss(input);

			while (ss >> x)
			{
				in = { x };
				training_inputs.push_back(in);

				ss >> y;
				out = { y };
				
				training_outputs.push_back(out);

				//cout << "x ,y : " << x << " " << y << endl;
			}
		}
		cout << "end reading \n";
	}
	else
	{
		cout << "ERROR in opening file : " << path.c_str() << endl;
	}*/


	//test reading
	for (auto i : training_inputs)
	{
		cout << i[0] << endl;
	}

	// building network
	Network network;
	network.build_network(scheme,0,111);

	// building back prop
	Back_prop back_prop(network, lambda);
	back_prop.training(training_inputs, training_outputs, alpha, stop_crit, save_path);

	cost_vect = back_prop.get_cost_vect();

	for (auto cost : cost_vect)
	{
		cout << "cost : " << cost << endl;
	}



	//--------------------------------------------

	vector<vector<double>> weights;

	//weights = back_prop.get_mod_weights();
	//network.set_allWeights(weights);

	save_path = "F:/Projets-C++/neural_training_test/trained_parabole.out";
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