#include "fjcore.hh"
#include "fjcore.cc"
#include <iostream> // needed for io
#include <cstdio>   // needed for io

// Run this with GenerateEvents < MomentumValues.dat

using namespace std;

int main()
{	
	// IMPORTANT!!!!
	// These numbers must match those in the momentum generation file
	// I could make it read these numbers from the input file, but I'll leave it for now
	int events = 5000; // Number of events
	int part = 1000; // Number of particles
	int x, y; // Used to count events and particles
	
	double px, py, pz, E;
	vector<fjcore::PseudoJet> input_particles; // Initialise input_particles vector
	double R = 0.5;
	
	ofstream myfile; // Used for writing to file
	myfile.open ("EventValues.csv"); // Open file
	
	for (int i=0; i<1; i++) // Will be used for different R values
	{
		x = 0;
		while(x<events)
		{
			if(x%5 == 0) // Just to keep track of where we're at
				{cout << "Event number: " << x << endl;}
			else{NULL;}
			
			y = 0;
			while(y<part)
			{
				cin >> px >> py >> pz >> E;
				// cout << "px: " << px << " py: " << py << " pz: " << pz << endl;
				// Read the particle data
				input_particles.push_back(fjcore::PseudoJet(px,py,pz,E));
				y += 1;
			}
			// Create jet definition:
			fjcore::JetDefinition jet_def(fjcore::antikt_algorithm, R);
			
			// Run the jet clustering with the above jet definition
			fjcore::ClusterSequence clust_seq(input_particles, jet_def);
			
			// Get the resulting jets ordered in pt (what is pt?)
			double ptmin = 5.0;
			vector<fjcore::PseudoJet> inclusive_jets = sorted_by_pt(clust_seq.inclusive_jets(ptmin));
			
			// Write to the file
			for (int k=0; k<inclusive_jets.size(); k++)
			{
				myfile << inclusive_jets[k].rap() << "," 
						<< inclusive_jets[k].phi() << ","
						<< inclusive_jets[k].perp() << endl;
			}
		
			input_particles.clear(); // Clear vector so values aren't input twice
			x += 1;
		}
		myfile.close();
	}
	
	
	return 0;
}