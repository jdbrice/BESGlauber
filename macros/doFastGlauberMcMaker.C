//****************************************************************************************************
//  Run Fast Monte Carlo Glauber simulation (StFastGlauberMcMaker)
//****************************************************************************************************
/****************************************************************************************************
 * $Id: doFastGlauberMcMaker.C,v 1.3 2012/04/25 05:29:34 hmasui Exp $
 * $Log: doFastGlauberMcMaker.C,v $
 * Revision 1.3  2012/04/25 05:29:34  hmasui
 * Added deformation flag
 *
 * Revision 1.2  2010/10/27 00:31:45  hmasui
 * Added loading relevant STAR libs
 *
 * Revision 1.1  2010/06/24 23:41:40  hmasui
 * Macro to run StFastGlauberMcMaker
 *
 ****************************************************************************************************/

//____________________________________________________________________________________________________
// Specify the system by TString, detailed parameters will be defined inside StFastGlauberMcMaker 
void doFastGlauberMcMaker(
    const TString outputFileName = "fastmcglauber.root",
    const UInt_t nevents = 1000,
    const TString system = "AuAu",
    const Double_t energy = 14.5,
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

  maker->DoHardCoreSmearing() ; // Hard-core smearing ON
  maker->DoHardCoreCollision() ; // default on

  // Run nevents
  maker->Run(nevents);

  // Close ROOT file etc
  maker->Finish();

  gBenchmark->Stop("doFastGlauberMcMaker");
  gBenchmark->Show("doFastGlauberMcMaker");
  gBenchmark->Reset();
}
