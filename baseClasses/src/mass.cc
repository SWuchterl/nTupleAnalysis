//#include "TChain.h"
#include "nTupleAnalysis/baseClasses/interface/mass.h"

using namespace nTupleAnalysis;

mass::mass(std::string name, fwlite::TFileService& fs) {

  dir = fs.mkdir(name);
  DeepCSV = dir.make<TH1F>("deepCSV", (name+"/deepCSV; ;Entries").c_str(), 120, -0.2, 1.2);
  invariant_mass    = dir.make<TH1F>("mass", (name+"/mass; ;Entries").c_str(), 100, 0, 1000);
  Ht  = dir.make<TH1F>("Ht", (name+"/Ht; ;Entries").c_str(), 100, 0, 1000);
  pt_1 = dir.make<TH1F>("pt_1", (name+"/pt_1; ;Entries").c_str(), 100, 0, 1000);
  pt_2 = dir.make<TH1F>("pt_2", (name+"/pt_2; ;Entries").c_str(), 100, 0, 1000);
  pt_3 = dir.make<TH1F>("pt_3", (name+"/pt_3; ;Entries").c_str(), 100, 0, 1000);
  pt_4 = dir.make<TH1F>("pt_4", (name+"/pt_4; ;Entries").c_str(), 100, 0, 1000);
}


void mass::Fill(const std::shared_ptr<jet> &jet, float weight){
  DeepCSV  ->Fill(jet->DeepCSV, weight);

  return;
}

void mass::FillMass(const float mass_val){
  invariant_mass -> Fill(mass_val);
  
  return;
}

void mass::FillHt(const float Ht_val){
    Ht -> Fill(Ht_val);
    return;
}

void mass::Fillpts(std::vector<float> pts){
    pt_1 -> Fill(pts.at(0));
    pt_2 -> Fill(pts.at(1));
    pt_3 -> Fill(pts.at(2));
    pt_4 -> Fill(pts.at(3));
    return;
}

/*void triggers::AddCut(std::string cut){
  DeepCSV ->GetXaxis()->FindBin(cut.c_str());
  mass    ->GetXaxis()->FindBin(cut.c_str());
  //cutL1->GetXaxis()->FindBin(cut.c_str()); 
  return;
}*/


mass::~mass(){} 

