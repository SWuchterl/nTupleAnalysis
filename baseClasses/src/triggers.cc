//#include "TChain.h"
#include "nTupleAnalysis/baseClasses/interface/triggers.h"
#include "nTupleAnalysis/baseClasses/interface/helpers.h"

using namespace nTupleAnalysis;

triggers::triggers(std::string name, fwlite::TFileService& fs) {

  dir = fs.mkdir(name);
  // cutflow = dir.make<TH1F>("cutflow", (name+"/test; ;Entries").c_str(), 64, 0, 64);
  n_ev = dir.make<TH1F>("n_ev", (name+"; ;Entries").c_str(), 1, 0, 1.);

  ht_reco = dir.make<TH1F>("ht_reco", (name+"; ;Entries").c_str(), 100, 0, 1000);
  ht_l1 = dir.make<TH1F>("ht_l1", (name+"; ;Entries").c_str(), 100, 0, 1000);
  ht_gen = dir.make<TH1F>("ht_gen", (name+"; ;Entries").c_str(), 100, 0, 1000);

  m4j_reco = dir.make<TH1F>("m4j_reco", (name+"; ;Entries").c_str(), 200, 0, 2000);
  m4j_l1 = dir.make<TH1F>("m4j_l1", (name+"; ;Entries").c_str(), 200, 0, 2000);
  m4j_gen = dir.make<TH1F>("m4j_gen", (name+"; ;Entries").c_str(), 200, 0, 2000);

  m2j_reco = dir.make<TH1F>("m2j_reco", (name+"; ;Entries").c_str(), 200, 0, 2000);
  m2j_l1 = dir.make<TH1F>("m2j_l1", (name+"; ;Entries").c_str(), 200, 0, 2000);
  m2j_gen = dir.make<TH1F>("m2j_gen", (name+"; ;Entries").c_str(), 200, 0, 2000);

  pt1_reco = dir.make<TH1F>("pt1_reco", (name+"; ;Entries").c_str(), 100, 0, 500);
  pt1_l1 = dir.make<TH1F>("pt1_l1", (name+"; ;Entries").c_str(), 100, 0, 500);
  pt1_gen = dir.make<TH1F>("pt1_gen", (name+"; ;Entries").c_str(), 100, 0, 500);
  pt2_reco = dir.make<TH1F>("pt2_reco", (name+"; ;Entries").c_str(), 100, 0, 500);
  pt2_l1 = dir.make<TH1F>("pt2_l1", (name+"; ;Entries").c_str(), 100, 0, 500);
  pt2_gen = dir.make<TH1F>("pt2_gen", (name+"; ;Entries").c_str(), 100, 0, 500);
  pt3_reco = dir.make<TH1F>("pt3_reco", (name+"; ;Entries").c_str(), 100, 0, 500);
  pt3_l1 = dir.make<TH1F>("pt3_l1", (name+"; ;Entries").c_str(), 100, 0, 500);
  pt3_gen = dir.make<TH1F>("pt3_gen", (name+"; ;Entries").c_str(), 100, 0, 500);
  pt4_reco = dir.make<TH1F>("pt4_reco", (name+"; ;Entries").c_str(), 100, 0, 500);
  pt4_l1 = dir.make<TH1F>("pt4_l1", (name+"; ;Entries").c_str(), 100, 0, 500);
  pt4_gen = dir.make<TH1F>("pt4_gen", (name+"; ;Entries").c_str(), 100, 0, 500);

  et1_reco = dir.make<TH1F>("et1_reco", (name+"; ;Entries").c_str(), 100, 0, 500);
  et1_gen = dir.make<TH1F>("et1_gen", (name+"; ;Entries").c_str(), 100, 0, 500);
  et2_reco = dir.make<TH1F>("et2_reco", (name+"; ;Entries").c_str(), 100, 0, 500);
  et2_gen = dir.make<TH1F>("et2_gen", (name+"; ;Entries").c_str(), 100, 0, 500);
  et3_reco = dir.make<TH1F>("et3_reco", (name+"; ;Entries").c_str(), 100, 0, 500);
  et3_gen = dir.make<TH1F>("et3_gen", (name+"; ;Entries").c_str(), 100, 0, 500);
  et4_reco = dir.make<TH1F>("et4_reco", (name+"; ;Entries").c_str(), 100, 0, 500);
  et4_gen = dir.make<TH1F>("et4_gen", (name+"; ;Entries").c_str(), 100, 0, 500);

  deepCSV_jet1 = dir.make<TH1F>("deepCSV_jet1", (name+"; ;Entries").c_str(), 280,-0.2,1.2);
  deepCSV_jet2 = dir.make<TH1F>("deepCSV_jet2", (name+"; ;Entries").c_str(), 280,-0.2,1.2);
  deepCSV_jet3 = dir.make<TH1F>("deepCSV_jet3", (name+"; ;Entries").c_str(), 280,-0.2,1.2);
  deepCSV_jet4 = dir.make<TH1F>("deepCSV_jet4", (name+"; ;Entries").c_str(), 280,-0.2,1.2);

  deepJet_jet1 = dir.make<TH1F>("deepJet_jet1", (name+"; ;Entries").c_str(), 280,-0.2,1.2);
  deepJet_jet2 = dir.make<TH1F>("deepJet_jet2", (name+"; ;Entries").c_str(), 280,-0.2,1.2);
  deepJet_jet3 = dir.make<TH1F>("deepJet_jet3", (name+"; ;Entries").c_str(), 280,-0.2,1.2);
  deepJet_jet4 = dir.make<TH1F>("deepJet_jet4", (name+"; ;Entries").c_str(), 280,-0.2,1.2);

  deepCSV_discr_b = dir.make<TH1F>("deepCSV_discr_b", (name+"; ;Entries").c_str(), 280,-0.2,1.2);
  deepCSV_discr_l = dir.make<TH1F>("deepCSV_discr_l", (name+"; ;Entries").c_str(), 280,-0.2,1.2);
  deepCSV_discr_c = dir.make<TH1F>("deepCSV_discr_c", (name+"; ;Entries").c_str(), 280,-0.2,1.2);
  deepCSV_discr_lc = dir.make<TH1F>("deepCSV_discr_lc", (name+"; ;Entries").c_str(), 280,-0.2,1.2);
  deepCSV_discr_all = dir.make<TH1F>("deepCSV_discr_all", (name+"; ;Entries").c_str(), 280,-0.2,1.2);

  deepJet_discr_b = dir.make<TH1F>("deepJet_discr_b", (name+"; ;Entries").c_str(), 280,-0.2,1.2);
  deepJet_discr_l = dir.make<TH1F>("deepJet_discr_l", (name+"; ;Entries").c_str(), 280,-0.2,1.2);
  deepJet_discr_c = dir.make<TH1F>("deepJet_discr_c", (name+"; ;Entries").c_str(), 280,-0.2,1.2);
  deepJet_discr_lc = dir.make<TH1F>("deepJet_discr_lc", (name+"; ;Entries").c_str(), 280,-0.2,1.2);
  deepJet_discr_all = dir.make<TH1F>("deepJet_discr_all", (name+"; ;Entries").c_str(), 280,-0.2,1.2);
 }


void triggers::FillCutflow(long unsigned int cut, const TriggerStudies::eventData* event, const std::vector<nTupleAnalysis::jetPtr>& jets, const std::vector<nTupleAnalysis::jetPtr>& jetsForBTag, float weight){
  cutflow  ->Fill(cut);
  // return;
}

void triggers::Fill(const TriggerStudies::eventData* event, const std::vector<nTupleAnalysis::jetPtr>& jets, const std::vector<nTupleAnalysis::jetPtr>& jetsForBTag, float weight){
    n_ev->Fill(0.5,weight);

  for (const nTupleAnalysis::jetPtr& jet : jets){
      if(!jet->isUndefined){
          if(jet->isB>0 || jet->isLeptonicB>0 || jet->isLeptonicB_C>0 || jet->isBB>0 || jet->isGBB>0){
          // if(jet->isB>0 || jet->isBB>0 || jet->isGBB>0){
          // if(jet->hadronFlavour==5){
          // if(jet->hadronFlavour==5 && (jet->isB>0 || jet->isLeptonicB>0 || jet->isLeptonicB_C>0 || jet->isBB>0 || jet->isGBB>0)){
          // if(jet->hadronFlavour==5 && (jet->isB>0 ||  jet->isBB>0 || jet->isGBB>0)){
              deepCSV_discr_b->Fill(jet->DeepCSV, weight);
              deepJet_discr_b->Fill(jet->DeepJet, weight);
          }
          // else if((jet->isUD>0 || jet->isS>0 || jet->isG>0) &&(jet->hadronFlavour == 0 && (jet->flavourCleaned!=0))){
          else if(jet->isUD>0 || jet->isS>0 || jet->isG>0 ){
          // else if(jet->hadronFlavour == 0 && (jet->flavourCleaned!=0)){
              deepCSV_discr_l->Fill(jet->DeepCSV, weight);
              deepJet_discr_l->Fill(jet->DeepJet, weight);
          }
          if(jet->isC>0 || jet->isUD>0 || jet->isS>0 || jet->isG>0 || jet->isGCC>0 || jet->isCC>0){
              deepCSV_discr_lc->Fill(jet->DeepCSV, weight);
              deepJet_discr_lc->Fill(jet->DeepJet, weight);
          }
          if(jet->isC>0 || jet->isGCC>0 || jet->isCC>0){
          // if(jet->hadronFlavour == 4){
              deepCSV_discr_c->Fill(jet->DeepCSV, weight);
              deepJet_discr_c->Fill(jet->DeepJet, weight);
          }
          if(jet->isC>0 || jet->isUD>0 || jet->isS>0 || jet->isG>0 || jet->isGCC>0 || jet->isCC>0 || jet->isB>0 || jet->isLeptonicB>0 || jet->isLeptonicB_C>0 || jet->isBB>0 || jet->isGBB>0){
              deepCSV_discr_all->Fill(jet->DeepCSV, weight);
              deepJet_discr_all->Fill(jet->DeepJet, weight);
          }
      }

  }

  ht_reco->Fill(event->HLT_HT_2p4_sumEt, weight);
  // ht_l1->Fill(event->L1_HT_sumEt, weight);
  ht_l1->Fill(rescaleL1THT(event->L1_HT_sumEt), weight);
  ht_gen->Fill(event->genHT, weight);

  if(jets.size()>3){
      m4j_reco->Fill((jets.at(0)->p+jets.at(1)->p+jets.at(2)->p+jets.at(3)->p).M(), weight);
  }
  if(jets.size()>1){
      m2j_reco->Fill((jets.at(0)->p+jets.at(1)->p).M(), weight);
  }
  if(event->nL1_PuppiJets>3){
      TLorentzVector LV_0(0.,0.,0.,0.);
      LV_0.SetPtEtaPhiM(event->L1_PuppiJets_pt[0],event->L1_PuppiJets_eta[0],event->L1_PuppiJets_phi[0],event->L1_PuppiJets_m[0]);
      TLorentzVector LV_1(0.,0.,0.,0.);
      LV_1.SetPtEtaPhiM(event->L1_PuppiJets_pt[1],event->L1_PuppiJets_eta[1],event->L1_PuppiJets_phi[1],event->L1_PuppiJets_m[1]);
      TLorentzVector LV_2(0.,0.,0.,0.);
      LV_2.SetPtEtaPhiM(event->L1_PuppiJets_pt[2],event->L1_PuppiJets_eta[2],event->L1_PuppiJets_phi[2],event->L1_PuppiJets_m[2]);
      TLorentzVector LV_3(0.,0.,0.,0.);
      LV_3.SetPtEtaPhiM(event->L1_PuppiJets_pt[3],event->L1_PuppiJets_eta[3],event->L1_PuppiJets_phi[3],event->L1_PuppiJets_m[3]);
      m4j_l1->Fill((LV_0+LV_1+LV_2+LV_3).M(), weight);
  }
  if(event->nL1_PuppiJets>1){
      TLorentzVector LV_0(0.,0.,0.,0.);
      LV_0.SetPtEtaPhiM(event->L1_PuppiJets_pt[0],event->L1_PuppiJets_eta[0],event->L1_PuppiJets_phi[0],event->L1_PuppiJets_m[0]);
      TLorentzVector LV_1(0.,0.,0.,0.);
      LV_1.SetPtEtaPhiM(event->L1_PuppiJets_pt[1],event->L1_PuppiJets_eta[1],event->L1_PuppiJets_phi[1],event->L1_PuppiJets_m[1]);
      m2j_l1->Fill((LV_0+LV_1).M(), weight);
  }
  if(jets.size()>3){
      m4j_gen->Fill((jets.at(0)->p_gen+jets.at(1)->p_gen+jets.at(2)->p_gen+jets.at(3)->p_gen).M(), weight);
  }
  if(jets.size()>1){
      m2j_gen->Fill((jets.at(0)->p_gen+jets.at(1)->p_gen).M(), weight);
  }

  // find highest 4 btag scores
  std::vector<float> btagScores;
  // for (const nTupleAnalysis::jetPtr& jet : jets){
  for (const nTupleAnalysis::jetPtr& jet : jetsForBTag){
      btagScores.push_back(jet->DeepCSV);
  }
  std::sort(btagScores.begin(), btagScores.end(), std::greater<float>());

  if(jets.size()>0){
      pt1_reco->Fill(jets.at(0)->pt, weight);
      pt1_gen->Fill(jets.at(0)->GenJet_pt, weight);
      et1_reco->Fill(jets.at(0)->p.Et(), weight);
      // et1_gen->Fill(jets.at(0)->GenJet_pt, weight);
      deepCSV_jet1->Fill(btagScores.at(0), weight);
      deepJet_jet1->Fill(jets.at(0)->DeepJet, weight);
      if(jets.size()>1){
          pt2_reco->Fill(jets.at(1)->pt, weight);
          pt2_gen->Fill(jets.at(1)->GenJet_pt, weight);
          et2_reco->Fill(jets.at(1)->p.Et(), weight);
          // pt2_gen->Fill(jets.at(1)->GenJet_pt, weight);
          deepCSV_jet2->Fill(btagScores.at(1), weight);
          deepJet_jet2->Fill(jets.at(1)->DeepJet, weight);
          if(jets.size()>2){
              pt3_reco->Fill(jets.at(2)->pt, weight);
              pt3_gen->Fill(jets.at(2)->GenJet_pt, weight);
              et3_reco->Fill(jets.at(2)->p.Et(), weight);
              // pt3_gen->Fill(jets.at(2)->GenJet_pt, weight);
              deepCSV_jet3->Fill(btagScores.at(2), weight);
              deepJet_jet3->Fill(jets.at(2)->DeepJet, weight);
              if(jets.size()>3){
                  pt4_reco->Fill(jets.at(3)->pt, weight);
                  pt4_gen->Fill(jets.at(3)->GenJet_pt, weight);
                  et4_reco->Fill(jets.at(3)->p.Et(), weight);
                  // pt4_gen->Fill(jets.at(3)->GenJet_pt, weight);
                  deepCSV_jet4->Fill(btagScores.at(3), weight);
                  deepJet_jet4->Fill(jets.at(3)->DeepJet, weight);
              }
          }
      }
  }


  if(event->nL1_PuppiJets>0) pt1_l1->Fill(rescaleL1TpT(event->L1_PuppiJets_pt[0], event->L1_PuppiJets_eta[0]), weight);
  if(event->nL1_PuppiJets>1) pt2_l1->Fill(rescaleL1TpT(event->L1_PuppiJets_pt[1], event->L1_PuppiJets_eta[1]), weight);
  if(event->nL1_PuppiJets>2) pt3_l1->Fill(rescaleL1TpT(event->L1_PuppiJets_pt[2], event->L1_PuppiJets_eta[2]), weight);
  if(event->nL1_PuppiJets>3) pt4_l1->Fill(rescaleL1TpT(event->L1_PuppiJets_pt[3], event->L1_PuppiJets_eta[3]), weight);

}

void triggers::AddCut(std::string cut){
  cutflow ->GetXaxis()->FindBin(cut.c_str());
}


triggers::~triggers(){}
