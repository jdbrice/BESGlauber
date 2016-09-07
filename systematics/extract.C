

int nBins = 35;
int cl[] = {0, 5 , 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75 , 80, 0 , 10, 20, 30, 40, 50, 60, 70, 10, 40, 0 , 20, 40, 60, 20, 50, 0 , 0 };
int ch[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 100, 10, 20, 30, 40, 50, 60, 70, 80, 40, 80, 20, 40, 60, 80, 50, 80, 60, 80 };


vector<double> extractValue( string hName = "avgNcoll", string fn="data/sys_nominal.root" ){
	vector<double> vals;

	TFile * f = new TFile( fn.c_str(), "READ" );
	TH2D * h2d = (TH2D*)f->Get( hName.c_str() );

	for ( int i = 0; i < nBins; i++ ){
		int ccl = cl[ i ];
		int cch = ch[ i ];
		
		int cclt = ccl;
		if ( 0 == cclt  ) cclt = 1;

		stringstream sstr;
		sstr << "cbin_" << i;
		TH1* hpy = h2d->ProjectionY( sstr.str().c_str(), cclt, cch );
		
		//cout << setw(10) << i << setw(10) << ccl << setw(10) << cch << setw(10) << hpy->GetMean() << endl;
		vals.push_back( hpy->GetMean() );

		//cout << hc->GetMean() << endl;
	} 

	return vals;

}



void extract( string fn="sys_nominal.root" ){
	

	/*TFile * f = new TFile( fn.c_str(), "READ" );

	//TFile * ef = new TFile( ("ex16_" + fn).c_str(), "RECREATE" );
	TH2D * coll = (TH2D*)f->Get( "avgNcoll" );
	TH2D * part = (TH2D*)f->Get( "avgNpart" );
*/

	extractValue(  );
	cout << endl << endl;
	extractValue( "avgNpart" );
	

/*
	cout << "<Ncoll>" << endl;
	for ( int i = 0; i < nBins; i++ ){
		int ccl = cl[ i ];
		int cch = ch[ i ];
		
		int cclt = ccl;
		if ( 0 == cclt  ) cclt = 1;

		TH1* hc = coll->ProjectionY( ("cbin_"+ts(i)).c_str(), cclt, cch );
		
		cout << setw(10) << i << setw(10) << ccl << setw(10) << cch << setw(10) << hc->GetMean() << endl;
		//cout << hc->GetMean() << endl;
	} 

	cout << "<Npart>" << endl;
	for ( int i = 0; i < nBins; i++ ){
		int ccl = cl[ i ];
		int cch = ch[ i ];

		int cclt = ccl;
		if ( 0 == cclt  ) cclt = 1;
		TH1* hp = part->ProjectionY( ("pbin_"+ts(i)).c_str(), cclt, cch );
		//cout << hp->GetMean() << endl;
		cout << setw(10) << i << setw(10) << ccl << setw(10) << cch << setw(10) << hp->GetMean() << endl;
	} */


	//ef->Write();

}