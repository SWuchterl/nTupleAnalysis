// -*- C++ -*-

#if !defined(truthParticle_H)
#define truthParticle_H
#include <TChain.h>
#include <TLorentzVector.h>
#include "nTupleAnalysis/baseClasses/interface/initBranch.h"

namespace nTupleAnalysis {
  //forward declaration for use in particle constructor from tree
  class truthParticle;
  //particle object
  class particle {

  public:
    float pt;
    float eta;
    float phi;
    float m;
    float e;
    TLorentzVector p;

    Int_t genPartIdxMother;
    Int_t pdgId;

    particle();
    particle(UInt_t, truthParticle*); 
    ~particle(); 

    //void dump();
  };

  typedef std::shared_ptr<particle> particlePtr;

  //class for tree access
  class truthParticle {

  public:
    std::string m_name;
    UInt_t nTruth;
    static const unsigned int MAXTRUTH = 10000;

    float pt [MAXTRUTH];
    float eta[MAXTRUTH];
    float phi[MAXTRUTH];
    float m  [MAXTRUTH];

    Int_t genPartIdxMother[MAXTRUTH];
    Int_t pdgId[MAXTRUTH];

    truthParticle(std::string name, TTree* tree, bool readIn = true); 
    void connectBranches(bool readIn, TTree* tree);
    void writeTruth(std::vector< std::shared_ptr<particle> > outputTruth);

    std::vector< std::shared_ptr<particle> > getParticles(Int_t absPDG = -1, Int_t absMomPDG = -1);
    ~truthParticle(); 

    //void dump();
  };

}
#endif // truthParticle_H

