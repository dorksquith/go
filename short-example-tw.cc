#include "fastjet/ClusterSequence.hh"
#include <iostream>
using namespace fastjet;
using namespace std;

int main () {
  vector<PseudoJet> particles;

  // add a lot more particles, maybe a thousand
  for (unsigned i = 0; i < 1000; i++) {
    double px,py,pz,e =0.; //find a good way of generating px,py,pz,e randomly

    particles.push_back( PseudoJet(   px,py,pz,e) ); 
  }

  // an event with three particles:   px    py  pz      E
  particles.push_back( PseudoJet(   99.0,  0.1,  0, 100.0) ); 
  particles.push_back( PseudoJet(    4.0, -0.1,  0,   5.0) ); 
  particles.push_back( PseudoJet(  -99.0,    0,  0,  99.0) );

  //now we have created our particles - where are they in eta-phi space?
  for (unsigned i = 0; i < particles.size(); i++) {
    cout << "particle " << i << " pT: "<< particles[i].pt() << " ,rap: " << particles[i].rap() << ", eta: " 
                   << particles[i].eta() << ", phi: " << particles[i].phi() << endl;
  }
  //rap is rapidity, eta is pseudorapidity. If a particle is massless, rap=eta

  // choose a jet definition
  // you will choose two, like 1.0/1.2 for the big, 
  double R = 0.7;

  JetDefinition jet_def(antikt_algorithm, R);

  // run the clustering, extract the jets
  ClusterSequence cs(particles, jet_def);
  vector<PseudoJet> jets = sorted_by_pt(cs.inclusive_jets());

  // print out some infos
  cout << "Clustering with " << jet_def.description() << endl;

  // print the jets
  cout <<   "        pt y phi" << endl;

  for (unsigned i = 0; i < jets.size(); i++) {

    cout << "jet " << i << ": "<< jets[i].pt() << " " << jets[i].rap() << " " << jets[i].phi() << endl;
                   

    // vector<PseudoJet> constituents = jets[i].constituents();

    // for (unsigned j = 0; j < constituents.size(); j++) {
      
    //   cout << "    constituent " << j << "'s pt: " << constituents[j].pt()<< endl;
           
    // }//loop over constituents per jet
  }//loop over jets
} 