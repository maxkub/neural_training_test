#include "stdafx.h"
#include "F:/Projets-C++/neural_network/neural_network/Neural_Network.h"
#include "F:/Projets-C++/neural_network/neural_network/Back_prop.h"
//#include "F:/Projets-C++/neural_network/neural_network/Neuron.h"
//#include "F:/Projets-C++/neural_network/neural_network/Layer.h"
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{

	vector<int> scheme = { 1, 5, 1 };

	string path = "F:/Projets-C++/neural_training_test/sinus_training.csv";
	vector<double> training_inputs;
	vector<double> training_outputs;

	fstream file(path.c_str());

	if (file)
	{
		double x, y;
		char separator;

		while (file >> x)
		{
			file >> separator;
			file >> y;
			file.ignore(1000, '\n');

			training_inputs.push_back(x);
			training_outputs.push_back(y);
		} 
	}
	else
	{
		cout << "ERROR in opening file : " << path.c_str() << endl;
	}

	Network network(scheme, 1);

	network.build_network();




	return 0;


}