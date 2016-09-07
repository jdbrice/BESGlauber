


Double_t fnCentral( Double_t * x, Double_t * p ){
	double M = x[0];
	return p[ 0 ] + p[1] / ( p[2] * M + p[3] ) + p[4]*( p[2] * M + p[3] );
}

TF1 * g1 = new TF1( "g1", fnCentral, 1, 30, 5 );

Double_t fnOuter( Double_t * x, Double_t * p ){
	double M = x[0];
	double z = 30;
	double g = g1->Eval( M );
	return g + p[0]*( g - 1 )*z*z;
}



void mcGlauberFit(  string fCentral = "../data/Run14_AuAu_14p5/period_C_nbdFit_center.root", string fOuter = "../data/Run14_AuAu_14p5/period_C_nbdFit_left.root" ){

	using namespace jdb;
	// Open the file containing the 
	TFile * f = new TFile( fCentral.c_str() );


	TH1D* data = (TH1D*)f->Get( "hRefMult_center" );
	TH1D* sim = (TH1D*)f->Get( "hRefMultSim" );
	TH1D * ratio = (TH1D*)sim->Clone( "ratio" );
	
	
	g1->SetParameters(0.9, 23, 1, 1, 0 );

	TFile * fo = new TFile( "gRatio.root", "RECREATE" );

	ratio->Divide( data );

	gStyle->SetOptStat(0);

	Reporter * rp = new Reporter( "glauberComparison.pdf", 200, 200 );

	sim->SetLineWidth( 4 );
	sim->SetMarkerStyle(8);
	sim->SetMarkerColor( kRed );
	sim->SetMarkerSize(0.3);
	sim->Draw();
	sim->GetYaxis()->SetRangeUser(1, 4e5 );
	sim->GetXaxis()->SetRangeUser( 1, 400 );
	data->SetLineWidth( 4 );
	data->SetMarkerStyle(8);
	data->SetMarkerSize(0.3);
	data->Draw("same");
	gPad->SetLogy(1);
	gPad->SetLogx(1);


	rp->saveImage( "overlap_central.pdf" );

	gPad->SetLogy(0);
	gPad->SetLogx(0);

	ratio->SetTitle( "Acceptance Correction" );
	ratio->GetXaxis()->SetTitle( "RefMult" );
	ratio->GetYaxis()->SetTitle( "Glauber / Data" );
	ratio->Draw();
	ratio->SetLineWidth( 4);
	ratio->GetYaxis()->SetRangeUser( 0.5, 10.2 );
	ratio->GetXaxis()->SetRangeUser( 1, 400 );
	gPad->SetLogx(1);
	
	ratio->Fit( g1, "R" );
	g1->SetLineColor( kBlue );
	g1->Draw("same");
	rp->saveImage( "ratio_central.pdf" );

	

	TF1 * g2 = new TF1( "g2", fnOuter, 1, 30, 1 );
	g2->SetParameter( 0, .1 );

	f = new TFile( fOuter.c_str() );
	data = (TH1D*)f->Get( "hRefMult_left" );
	sim = (TH1D*)f->Get( "hRefMultSim" );
	ratio = (TH1D*)sim->Clone( "ratio_Outer" );

	sim->SetLineWidth( 4 );
	sim->SetMarkerStyle(8);
	sim->SetMarkerColor( kRed );
	sim->SetMarkerSize(0.3);
	sim->Draw();
	sim->GetYaxis()->SetRangeUser(1, 4e5 );
	sim->GetXaxis()->SetRangeUser( 1, 400 );
	data->SetLineWidth( 4 );
	data->SetMarkerStyle(8);
	data->SetMarkerSize(0.3);
	data->GetXaxis()->SetRangeUser( 1, 400 );
	data->Draw("same");
	gPad->SetLogy(1);
	gPad->SetLogx(1);
	rp->saveImage( "overlap_outer.pdf" );

	gPad->SetLogy(0);
	gPad->SetLogx(0);

	ratio->Divide( data );


	ratio->SetTitle( "Acceptance Correction Outer" );
	ratio->GetXaxis()->SetTitle( "RefMult" );
	ratio->GetYaxis()->SetTitle( "Glauber / Data" );
	ratio->SetLineWidth( 4);
	ratio->GetYaxis()->SetRangeUser( 0.5, 10.2 );
	ratio->GetXaxis()->SetRangeUser( 1, 400 );
	ratio->Draw();
	gPad->SetLogx(1);
	
	ratio->Fit( g2, "R" );
	g2->SetLineColor( kBlue );
	g2->Draw("same");
	rp->saveImage( "ratio_Outer.pdf" );


	



	


	fo->cd();
	ratio->Write();
	fo->Write();

	delete rp;

	fo->Close();


}