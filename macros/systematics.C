

void systematics( int nEvents = 1000000, string name="nominal", string type = "default", int multOpt = 0 ){
	
	gSystem->Load("St_base");
	gSystem->Load("StUtilities");
	gSystem->Load("StGlauberUtilities");
	gSystem->Load("StCentralityMaker");
	gSystem->Load("StGlauberTree");


	// setup
	StGlauberTree *gtree = new StGlauberTree( 0 );
	string treeFile = "/star/institutions/rice/jdb/run14/auau15/glauber/" + name + ".root";
	if ( "mult1" == name || "mult2" == name || "low" == name || "high" == name )
		treeFile = "/star/institutions/rice/jdb/run14/auau15/glauber/nominal.root";
	gtree->Open( treeFile.c_str() );

	StNegativeBinomial * nbd 	= new StNegativeBinomial( 1.172, 2.0, 0.12, 0.14, 1.0, 0 );
	StCentrality * cen 			= new StCentrality( "auau_14gev", type.c_str() );

	// open the output file
	TFile * fOut 		= new TFile( ("systematics_BBC_or_VPD/sys_" + name + ".root").c_str(), "RECREATE" );

	// Make histograms for storing the values of interest
	TH1D * hMult 		= new TH1D( "mult", "mult", 500, 0, 500 );
  	TH2D * hAvgNpart 	= new TH2D( "avgNpart", "<Npart>", 100, 0, 100, 500, 0, 500 );
  	TH2D * hAvgNcoll 	= new TH2D( "avgNcoll", "<Ncoll>", 100, 0, 100, 1500, 0, 1500 );
  	TH2D * hb 			= new TH2D( "b", "<b>", 100, 0, 100, 200, 0, 20 );
  	TH2D * hspp 		= new TH2D( "spp", "Area (PP); % Most Central; <S_{PP}> (fm^2)", 100, 0, 100, 400, 0, 40 );
  	TH2D * hsrp 		= new TH2D( "srp", "Area (RP); % Most Central; <S_{RP}> (fm^2)", 100, 0, 100, 400, 0, 40 );


  	// generate events
	Int_t maxEvents = gtree->GetEntries();
	if ( maxEvents > nEvents)
		maxEvents = nEvents;


	for( Int_t iEvt = 0; iEvt < maxEvents; iEvt++ ){
		
		gtree->GetEntry( iEvt );

		UInt_t npart = gtree->GetNpart();
		UInt_t ncoll = gtree->GetNcoll();
		

		int mult       = nbd->GetMultiplicity( npart, ncoll );
	  	double avgCen  = cen->GetCentrality( mult, multOpt );


	  	// fill histos
	  	hMult->Fill( mult );
		hAvgNpart->Fill( avgCen, npart );
		hAvgNcoll->Fill( avgCen, ncoll );
		hb->Fill( avgCen, gtree->GetB() );
		hspp->Fill( avgCen, gtree->GetSPP(0) );
		hsrp->Fill( avgCen, gtree->GetSRP(0) );


		if ( iEvt % 10000  ==0 ){
			cout << "." << flush;
		}
	}


	fOut->Write();
	fOut->Close();

	delete gtree;
	delete nbd;
	delete cen;

}