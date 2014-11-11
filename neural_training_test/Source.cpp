#include "stdafx.h"
//#include "F:/Projets-C++/neural_network/neural_network/Neural_Network.h"
//#include "F:/Projets-C++/neural_network/neural_network/Back_prop.h"
//#include "F:/Projets-C++/neural_network/neural_network/Neuron.h"
//#include "F:/Projets-C++/neural_network/neural_network/Layer.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{

	vector<int> scheme = { 1, 5, 1 };

	string path = "F:/Projets-C++/neural_training_test/sinus_training.csv";
	vector<vector<double>> training_inputs;
	vector<vector<double>> training_outputs;

	ifstream file(path.c_str());

	if (file)
	{
		double x, y;
		string input;
		vector<double> in, out;


		getline(file, input);

		while (getline(file,input))
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
	}


	//test reading
	for (auto i : training_inputs)
	{
		cout << i[0] << endl;
	}

	Network network(scheme, 1);

	network.build_network();






	return 0;


}