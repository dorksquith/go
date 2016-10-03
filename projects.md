##Machine Learning with LHC data
_under construction_

   * The LHC : https://www.youtube.com/watch?v=uo60o9Y0RnE
   * Machine Learning : https://www.coursera.org/learn/machine-learning
   * The Pythia Monte Carlo generator : http://home.thep.lu.se/~torbjorn/Pythia.html

###PROJECT : BEAUTY 
####Can a program learn to distinguish between two almost-identical fundamental physics processes?
When protons collide at the LHC, the energy released in the collision can result in particle production (E=mc^2 : from energy we get mass and vice versa). One of the particles that LHC collisions produce is the famous Higgs boson. The Higgs is only able to exist for a tiny moment before decaying to a pair of other particles, which are most likely to be b quarks. The study of b-quarks and the particles they form is called "Beauty physics". One of the most interesting unsolved problems at the LHC is the identification of the H->bb process against the 'background' process gluon->bb, which is produced about a billion times for every H->bb. The gluon is a fundamental boson with mass=0, electric charge =0 and spin=1. The Higgs is a fundamental boson with mass=126 GeV, electric charge=0 and spin=0 (probably).
####Tasks:
   * Generate Monte Carlo samples for the processes H->bb and g->bb.
   * Identify kinematic variables with potential for uncovering subtle differences between the processes
   * #SupervisedLearning #Classification

###PROJECT : TUNES 
####Can a program tell us what we have right / wrong in our simulations?
How do various regression techniques separate a mixed sample of data and MC events?
####Tasks: 
    * Get familiar with rivet : https://rivet.hepforge.org/
    * #UnsupervisesdLearning #Regression

###PROJECT : FLAVOUR
####Can we tag jet images?
How can particle jets be differentiated using image processing techniques?
####Tasks:
    * Read this: https://arxiv.org/abs/1511.05190
    * Download fastjet : http://fastjet.fr/
    * #SupervisedLearning #Classification
    
###PROJECT : ANARCHY
####Can we disentangle hadronic final states with unsupervised learning?
What is the natural way to sort the data, if not by process? What factors in the algorithm used determine the outcome? Can we "unfold" from the alg's classification to the physics? Or can we learn something about how to improve the algorithms?
####Tasks:
    * Explore a mixed dataset
    * #UnsupervisesdLearning #Regression

###PROJECT : ENHANCE
####How do machine learning algorithms deal with scale?
Feed the same event into a program at several different scales, with the finest scale being tracks and clusters. Reduce the resolution / build physics objects - does it help us or hinder us?
####Tasks:
    * Download fastjet : http://fastjet.fr/
