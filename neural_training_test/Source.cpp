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
	vector<double> training_inputs;
	vector<double> training_outputs;

	ifstream file(path.c_str());

	if (file)
	{
		double x, y;
		string input;

		getline(file, input);

		while (getline(file,input))
		{
			stringstream ss(input);

			while (ss >> x)
			{
				training_inputs.push_back(x);

				ss >> y;
				
				training_outputs.push_back(y);

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
		cout << i << endl;
	}

	Network network(scheme, 1);

	network.build_network();




	return 0;


}