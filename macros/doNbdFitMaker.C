/****************************************************************************************************
 * $Id: doNbdFitMaker.C,v 1.2 2012/04/25 05:29:16 hmasui Exp $
 * $Log: doNbdFitMaker.C,v $
 * Revision 1.2  2012/04/25 05:29:16  hmasui
 * Added histogram name
 *
****************************************************************************************************/

//____________________________________________________________________________________________________
void doNbdFitMaker(
    const Char_t* outputFileName = "",
    const Int_t nevents = 1000,
    const Char_t* realData = "refMult_periodB.root",
    const Char_t* glauber  = "hNCollNPart.root",
    const Char_t* realHistogram = "hRefMultTpc",
    const Double_t multiplicityCut = 30,
    const Double_t npp = 1.37,
    const Double_t k = 1.0,
    const Double_t x = 0.13,
    const Double_t efficiency = 1.00,
    const Double_t triggerbias = 1.00,
    const Bool_t isConstEfficiency = kTRUE
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
