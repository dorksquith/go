#include <iostream> // needed for io
#include <fstream> // Need for writing csv file
#include <algorithm> // std::random_shuffle
#include <random> // c++11 package for exponential distribution
#include <ctime> // Time for srand()
#include <cstdlib> // std::rand, std::srand
#include <math.h> // Need for square root
#include <vector> // Include vector support

// Type "g++ -std=c++11 GenerateMomentum.cpp -o GenerateMomentum"

using namespace std;

double rnd(double a);

int main()
{
	srand(time(0));
	
	int events = 5000; // Number of events
	int part = 1000; // Number of particles
	
	double MaxE = 5000; // Max energy
	
	double E, pmax; // Energy and momentum max
	vector <double> p(3,0); // 3-momentum vector
	int num; // Used for determining minus signs on 3-momentum
	
	ofstream myfile; // Used for writing to file
	myfile.open ("MomentumValues.dat"); // Open file
	
	for (int j=0; j<events; j++)
	{
		if(j%5 == 0) // Just to keep track of where we're at
			{cout << "Event number: " << j << endl;}
		else{NULL;}
		
		for (int i=0; i<part; i++)
		{
			E = rnd(MaxE); // Work out energy from exponential distribution
			pmax = E*E; // Max limit on next momentum component (4-mom conservation)
			
			for (int l=0; l<3; l++) // NaN and minus signs
			{
				p[l] = sqrt(rnd(pmax));
				pmax -= p[l]*p[l]; // This is the new max limit on the momentum component
				
				if(p[l] != p[l])
					{p[l]=0;} // If NaN then turn to 0
				else {NULL;}
				
				num = rand()%2;
				if (num==0)
					{p[l] = (-1)*p[l];} // 50/50 chance of gaining a minus
				else {NULL;}
			}
			// cout << "p[0] before: " << p[0] << endl; // Check before shuffling
			random_shuffle(p.begin(),p.end()); // Shuffle 3-momentum
			// cout << "p[0] after: " << p[0] << endl; // Check after shuffling
			
			myfile << p[0] << "\t" << p[1] << "\t"
					 << p[2] << "\t" << E << endl; // Write to file
			
			// p.clear(); // Clear momentum vector (for some reason this stops random_shuffle)
		}
	}
	myfile.close(); // Close the file
	
	return 0;
}

double rnd(double a)
{
	default_random_engine generator (rand()); // rand() is seed for the generator
	uniform_real_distribution<double> lindist(0.0,a); // Create the linear distribution
	double b = lindist(generator); // Use the generator to pull a value
	
	return (a/log(a))*log(a-b);
}