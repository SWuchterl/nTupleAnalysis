#include "nTupleAnalysis/baseClasses/interface/fourVectorHists.h"

using namespace nTupleAnalysis;

fourVectorHists::fourVectorHists(std::string name, fwlite::TFileService& fs, std::string title) {
  TFileDirectory dir = fs.mkdir(name);
  this->makeHists(name, dir, title);
}

fourVectorHists::fourVectorHists(std::string name, TFileDirectory& dir, std::string title) {
  this->makeHists(name, dir, title);
}

void fourVectorHists::makeHists(std::string name, TFileDirectory& dir, std::string title) {

    pt_s = dir.make<TH1F>("pt_s", (name+"/pt_s; "+title+" p_T [GeV]; Entries").c_str(),  100,0, 100);
    pt_m = dir.make<TH1F>("pt_m", (name+"/pt_m; "+title+" p_T [GeV]; Entries").c_str(),  100,0, 500);
    pt_l = dir.make<TH1F>("pt_l", (name+"/pt_l; "+title+" p_T [GeV]; Entries").c_str(),  100,0,1000);

    pz_l = dir.make<TH1F>("pz_l", (name+"/pz_l; "+title+" |p_z| [GeV]; Entries").c_str(),  150,0,1500);

    eta = dir.make<TH1F>("eta", (name+"/eta; "+title+" #eta; Entries").c_str(), 100, -5, 5);
    phi = dir.make<TH1F>("phi", (name+"/phi; "+title+" #phi; Entries").c_str(), 64, -3.2, 3.2);

    m_s = dir.make<TH1F>("m_s", (name+"/m_s; "+title+" Mass [GeV]; Entries").c_str(),   50,  0,   50);
    m   = dir.make<TH1F>("m",   (name+"/m;   "+title+" Mass [GeV]; Entries").c_str(),  100,  0,  500);
    m_l = dir.make<TH1F>("m_l", (name+"/m_l; "+title+" Mass [GeV]; Entries").c_str(),  140,100, 1500);
    e = dir.make<TH1F>("e", (name+"/e; "+title+" E [GeV]; Entries").c_str(),  100,0, 500);

    etaPhi = dir.make<TH2F>("etaPhi", (name+"/etaPhi; "+title+" Eta; Phi").c_str(),  50,-3, 3, 50, -3.3, 3.3);

    return;
} 

void fourVectorHists::Fill(TLorentzVector& p, float weight){

  pt_s->Fill(p.Pt(), weight);
  pt_m->Fill(p.Pt(), weight);
  pt_l->Fill(p.Pt(), weight);

  pz_l->Fill(fabs(p.Pz()), weight);

  eta->Fill(p.Eta(), weight);
  phi->Fill(p.Phi(), weight);

  m_s->Fill(p.M(), weight);
  m  ->Fill(p.M(), weight);
  m_l->Fill(p.M(), weight);
  e->Fill(p.E(), weight);

  etaPhi->Fill(p.Eta(), p.Phi(),  weight);

  return;
}

fourVectorHists::~fourVectorHists(){} 
