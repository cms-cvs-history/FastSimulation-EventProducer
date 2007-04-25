#ifndef FastSimulation_EventProducer_FamosManager_H
#define FastSimulation_EventProducer_FamosManager_H

#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include <fstream>
#include <string>

namespace HepMC {
  class GenEvent;
}

class FSimEvent;
class TrajectoryManager;
class PUProducer;
class PileUpSimulator;
class MagneticField;
class CalorimetryManager;
class RandomEngine;

namespace CLHEP {
  class HepLorentzVector;
}

// using trailing _ for private data members, m_p prefix for PSet variables (MSt)

class FamosManager
{
 public:


  /// Constructor
  FamosManager(edm::ParameterSet const & p);

  /// Destructor
  ~FamosManager();

  /// Get information from the Event Setup
  void setupGeometryAndField(const edm::EventSetup & es);    

  /// The generated event
  const HepMC::GenEvent* genEvent() const { return myGenEvent; };

  /// The simulated event 
  FSimEvent* simEvent() const { return mySimEvent; }

  /// The real thing is done here
  void reconstruct(const HepMC::GenEvent* evt);

  /// The tracker 
  TrajectoryManager * trackerManager() const {return myTrajectoryManager;}

  /// The calorimeter 
  CalorimetryManager * calorimetryManager() const {return myCalorimetry;}

  
 private:   

  int iEvent;
  const HepMC::GenEvent* myGenEvent;
  FSimEvent* mySimEvent;
  TrajectoryManager* myTrajectoryManager;
  PUProducer* myPileUpProducer;
  PileUpSimulator* myPileUpSimulator;
  CalorimetryManager * myCalorimetry;

 private:

  bool m_pUseMagneticField;
  bool m_Tracking;
  bool m_Calorimetry;
  bool m_PileUp;
  CLHEP::HepLorentzVector * vtx_;
  double weight_;    
  int m_pRunNumber;
  int m_pVerbose;

 private:

  const RandomEngine* random;

};
                       
#endif
