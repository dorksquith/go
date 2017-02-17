// Headers and Namespaces
// Lily's pythia8 installation is in /usr/local/Cellar/pythia8/
#include <iostream>
#include "Pythia8/Pythia.h" // Include Pythia headers.
using namespace Pythia8; 	// Let Pythia:: be implicit.

int main()					// Begin main program.
{
	//Set up generation.
	Pythia pythia;			// Declare Pythia object
	pythia.readString("HiggsSM:gg2H = on"); // Switch on process.
	pythia.readString("Beams:eCM = 8000."); // 8 TeV CM energy.
	pythia.readString("Next:numberShowEvent = 0");
	pythia.init(); // Initialize; incoming pp beams is default
	
	// Generate event(s)

	int countgood=0;
	for (int iEvent = 0; iEvent < 10; ++iEvent)
	{
		if(countgood==100)break;
		//std::cout<<"\n Doing event : "<<iEvent<<std::endl;
		pythia.next(); // Generate an(other) event. Fill event record.
		bool b = false;
		double etab = 0;
		double phib = 0;
		bool bbar = false;
		double etabbar = 0;
		double phibbar = 0;
		double pTparent,mparent=0.;
		Vec4 mombbar,momb;
		for (int i = 0; i < pythia.event.size(); ++i)
		{


			//std::cout<<"Doing particle : "<<i<<std::endl;

			if (pythia.event[i].id() == 5 && pythia.event[pythia.event[i].mother1()].id() == 25 && pythia.event[i].pT() > 25)
			{
				b = true;
				etab = pythia.event[i].eta();
				phib = pythia.event[i].phi();
				momb = pythia.event[i].p();
				pTparent = pythia.event[pythia.event[i].mother1()].pT();
				mparent = pythia.event[pythia.event[i].mother1()].m();

				//std::cout<<"Got my b, particle : "<<i<<std::endl;
			}
			if (pythia.event[i].id() == -5 && pythia.event[pythia.event[i].mother1()].id() == 25 && pythia.event[i].pT() > 25)
			{
				bbar = true;
				etabbar = pythia.event[i].eta();
				phibbar = pythia.event[i].phi();
				mombbar = pythia.event[i].p();
				//std::cout<<"Got my bbar, particle  : "<<i<<std::endl;

			}

			if(b and bbar)break;

		}
		
		if ((b == true) && (bbar == true))
		{
			double Dphi = phib - phibbar;
			//std::cout<<"Phis : "<<phib<<", "<<phibbar<<std::endl;
			double Deta = etab - etabbar;
			//std::cout<<"Etas : "<<etab<<", "<<etabbar<<std::endl;
			double Dr = sqrt(Dphi*Dphi + Deta*Deta);
			std::cout<<"delta R: "<<Dr<<std::endl;
			
			if(Dr<1.0){
				countgood++;
			
				double m = (pTparent/2)*Dr;
				std::cout<<"pT parent: "<<pTparent<<std::endl;
				std::cout<<"M parent: "<<mparent<<std::endl;
				std::cout << "\nEvent " << iEvent + 1 << ": Parent mass = " << m;
			}

			double invM = (momb+mombbar).mCalc();
			std::cout<<"invM: "<<invM<<std::endl; 
		}
	}
	
	return 0;
}				   // End main program with error-free return.