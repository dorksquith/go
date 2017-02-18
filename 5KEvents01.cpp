#include "fjcore.hh"
#include <iostream> // needed for io
#include <cstdio>   // needed for io
#include <fstream> // Need for writing csv file
#include <math.h> // Need for square root
#include <ctime>	 // Need for calling time

// Type "g++ -o Name fjcore.cc Name.cpp"
// This will produce program called "Name"

using namespace std;

double rnd(int a);

int main()
{
	srand(time(0));
	
	int events = 5000; // Number of events
	int part = 1000; // Number of particles
	double R = 0.1; // Radius parameter for jet algorithm
	
	int MaxE = 100+1; // Max energy, add one because of random number method
	double E, px, py, pz; // 4-momentum variables
	int MaxPx, MaxPy, MaxPz; //Used for random number generation (primitive)
	
	vector<fjcore::PseudoJet> input_particles; // Initialise input_particles vector
	
	ofstream myfile; // Used for writing to file
	myfile.open ("5KEvents01.csv"); // Open file
	// myfile << "pt,rap,phi,perp" << endl;
	
	for (unsigned j=0;j<events;j++)
	{
		
		for (unsigned i=0;i<part;i++)
		{// You will need to come back here and incorporate minus signs
			E = rnd(MaxE); // Generate random number between 0 and maxE
			MaxPx = E*E;  // Potential problem wth flooring the number here
			px = sqrt(rnd(MaxPx));
			MaxPy = E*E - px*px; // Same floor problem
			py = sqrt(rnd(MaxPy));
			MaxPz = E*E - px*px - py*py; // Same floor problem
			pz = sqrt(rnd(MaxPz));
			// cout << E << " " << px << " " << py << " " << pz << endl;
	
			// Read the particle data
			input_particles.push_back(fjcore::PseudoJet(px,py,pz,E));
		}
		
		
		// Create jet definition:
		fjcore::JetDefinition jet_def(fjcore::antikt_algorithm, R);
		
		// Run the jet clustering with the above jet definition
		fjcore::ClusterSequence clust_seq(input_particles, jet_def);
		
		// Get the resulting jets ordered in pt (what is pt?)
		double ptmin = 5.0;
		vector<fjcore::PseudoJet> inclusive_jets = sorted_by_pt(clust_seq.inclusive_jets(ptmin));
		
		// Write to the file
		for (unsigned int k=0; k<inclusive_jets.size(); k++)
		{
			myfile // << inclusive_jets.pt() << "," 
					<< inclusive_jets[k].rap() << "," 
					<< inclusive_jets[k].phi() << "," << inclusive_jets[k].perp() << endl;
		}
		
		input_particles.clear();
		
		//for (unsigned int k=0; k<inclusive_jets.size(); k++)
		//{
			//printf("%5u %15.8f %15.8f %15.8f\n",
			//k, inclusive_jets[k].rap(), inclusive_jets[k].phi(),
			//inclusive_jets[k].perp());
		//}
	}
	
	myfile.close();
	
	return 0;
}

double rnd(int a)
{
	return (static_cast<double>(rand())/(static_cast<long>(RAND_MAX)+1))*a; 
}