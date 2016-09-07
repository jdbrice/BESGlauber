/****************************************************************************************************
 * $Id: doNbdFitMaker.C,v 1.2 2012/04/25 05:29:16 hmasui Exp $
 * $Log: doNbdFitMaker.C,v $
 * Revision 1.2  2012/04/25 05:29:16  hmasui
 * Added histogram name
 *
****************************************************************************************************/

//____________________________________________________________________________________________________
void doNbdFitMaker(
    const Char_t* outputFileName = "period_B_nbdFit_center.root",
    const Int_t nevents = 3000000,
    const Char_t* realData = "data/Run14_AuAu_14p5/period_B_refMult1D.root",
    const Char_t* glauber  = "data/Run14_AuAu_14p5/hNCollNPart_nominal.root",
    const Char_t* realHistogram = "hRefMult_center",
    const Double_t multiplicityCut = 30,
    const Double_t npp = 1.162,
    const Double_t k = 2.0,
    const Double_t x = 0.12,
    const Double_t efficiency = 0.14,
    const Double_t triggerbias = 1.00,
    const Bool_t isConstEfficiency = 0
){
  gSystem->Load("St_base");
  gSystem->Load("StUtilities");
  gSystem->Load("StGlauberUtilities");
  gSystem->Load("StCentralityMaker");

  StNbdFitMaker* maker = new StNbdFitMaker();
  maker->DoCentralityDetermination() ;

  // Set parameters
  maker->SetParameters(npp, k, x, efficiency, triggerbias, isConstEfficiency);

  // Set low multiplicity cut off for fitting
  maker->SetMinimumMultiplicityCut(multiplicityCut);

  // Read input files
  maker->ReadData(realData, glauber, realHistogram);

  // Fit
  maker->Fit(nevents, outputFileName);
}
