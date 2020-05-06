// -*- C++ -*-

#if !defined(trijet_H)
#define trijet_H
#include <iostream>
#include <TLorentzVector.h>
#include "nTupleAnalysis/baseClasses/interface/jetData.h"
#include "nTupleAnalysis/baseClasses/interface/dijet.h"

namespace nTupleAnalysis {
  const float mt = 173.0;

  //trijet object
  class trijet {

  public:
    std::shared_ptr<jet> b;
    std::shared_ptr<dijet> W;

    std::shared_ptr<jet> jet_j;
    std::shared_ptr<jet> jet_l;

    TLorentzVector p;
    float dR;
    float st;
    float pt;
    float eta;
    float phi;
    float m;
    float e;

    float dRbW;
    float xt;
    float xbW;
    float xWt;
    float xWbW;
    float mbW;
    float rWbW;

    //TLorentzVector pbW;

    //trijet();
    trijet(std::shared_ptr<jet>&, std::shared_ptr<jet>&, std::shared_ptr<jet>&); 
    ~trijet(); 

    //void dump();
  };

}
#endif // dijet_H

