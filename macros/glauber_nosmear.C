
// Runs Hiroshi's fast Glauber Simulation

void glauber_nosmear(
    const TString outputFileName = "fastmcglauber.root",
    const UInt_t nevents = 1000,
    const TString system = "AuAu",
    const Double_t energy = 14.6,
    const TString type = "default",
    const Bool_t isDeformed = kFALSE,
    const Double_t replusionDistance = 0.0
){
  gBenchmark->Start("doFastGlauberMcMaker");

  gSystem->Load("St_base");
  gSystem->Load("StUtilities");
  gSystem->Load("StGlauberUtilities");
  gSystem->Load("StCentralityMaker");
  gSystem->Load("StGlauberTree");
  gSystem->Load("StFastGlauberMcMaker");

  cout << "out : " << outputFileName << endl;
  cout << "system : " << system << endl;
  cout << "energy : " << energy << endl;
  cout << "type : " << type << endl;
  StFastGlauberMcMaker* maker = new StFastGlauberMcMaker(outputFileName, system, energy, type, isDeformed);

  // Print available types
  maker->Print("type");

  maker->DoHardCoreCollision() ; // default on

  // Run nevents
  maker->Run(nevents);

  // Close ROOT file etc
  maker->Finish();

  gBenchmark->Stop("doFastGlauberMcMaker");
  gBenchmark->Show("doFastGlauberMcMaker");
  gBenchmark->Reset();
}
