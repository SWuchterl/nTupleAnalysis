// -*- C++ -*-
#if !defined(triggers_H)
#define triggers_H

#include <iostream>
#include <TH1F.h>
#include <TH2F.h>
#include "PhysicsTools/FWLite/interface/TFileService.h"
#include "TriggerStudies/NtupleAna/interface/eventData.h"

namespace nTupleAnalysis {

  class triggers {
  public:
    TFileDirectory dir;

    TH1F* cutflow;

    TH1F* n_ev;

    TH1F* ht_reco;
    TH1F* ht_l1;
    TH1F* ht_gen;

    TH1F* m4j_reco;
    TH1F* m4j_l1;
    TH1F* m4j_gen;

    TH1F* m2j_reco;
    TH1F* m2j_l1;
    TH1F* m2j_gen;

    TH1F* pt1_reco;
    TH1F* pt1_l1;
    TH1F* pt1_gen;
    TH1F* pt2_reco;
    TH1F* pt2_l1;
    TH1F* pt2_gen;
    TH1F* pt3_reco;
    TH1F* pt3_l1;
    TH1F* pt3_gen;
    TH1F* pt4_reco;
    TH1F* pt4_l1;
    TH1F* pt4_gen;

    TH1F* et1_reco;
    TH1F* et1_gen;
    TH1F* et2_reco;
    TH1F* et2_gen;
    TH1F* et3_reco;
    TH1F* et3_gen;
    TH1F* et4_reco;
    TH1F* et4_gen;

    TH1F* deepCSV_jet1;
    TH1F* deepCSV_jet2;
    TH1F* deepCSV_jet3;
    TH1F* deepCSV_jet4;
    TH1F* deepJet_jet1;
    TH1F* deepJet_jet2;
    TH1F* deepJet_jet3;
    TH1F* deepJet_jet4;

    TH1F* deepCSV_discr_b;
    TH1F* deepCSV_discr_l;
    TH1F* deepCSV_discr_c;
    TH1F* deepCSV_discr_lc;
    TH1F* deepCSV_discr_all;

    TH1F* deepJet_discr_b;
    TH1F* deepJet_discr_l;
    TH1F* deepJet_discr_lc;
    TH1F* deepJet_discr_c;
    TH1F* deepJet_discr_all;

    triggers(std::string, fwlite::TFileService&);
    void Fill(const TriggerStudies::eventData* event, const std::vector<nTupleAnalysis::jetPtr>& jets, const std::vector<nTupleAnalysis::jetPtr>& jetsForBTag, float weight);
    void FillCutflow(long unsigned int cut, const TriggerStudies::eventData* event, const std::vector<nTupleAnalysis::jetPtr>& jets,const std::vector<nTupleAnalysis::jetPtr>& jetsForBTag, float weight);
    void AddCut(std::string cut);
    ~triggers();

    static float rescaleL1TpT(const float pt,const float eta){
        if (abs(eta)<1.5){
            return (pt*1.40627)+11.1254;
        }else{
            if(abs(eta)<2.4){
                return (pt*1.4152)+24.8375;
            }else{
                return (pt*1.33052)+42.4039;
            }
        }
        // args:=(offline,Et,Eta); lambda:=Et>(offline-11.1254)/1.40627  else (Et>(offline-24.8375)/1.4152  else Et>(offline-42.4039)/1.33052)
    }

    float rescaleL1THT(const float ht){
        return 50.0182+(1.0961*ht);
    }

  };

}
#endif // cutflowHists_H
