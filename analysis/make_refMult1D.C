


void make_refMult1D( string fn = "/star/u/jdb/tmp/rmcQA.nTof.noZDC.wzcorr.root", string period = "B"){
	

	string title ="";
	TFile * f = new TFile( fn.c_str(), "READ" );

	TH2D * periodB = (TH2D*)f->Get(  (period + "_refMultZ").c_str() );
	if ( "B" == period )
		title = "BBC_MB || VPD_MB";
	else 
		title = "BBC_MB || VPD_MB || ZDC_MB";

	periodB->SetTitle( title.c_str() );

	int cx1 = periodB->GetXaxis()->FindBin( -5 );
	int cx2 = periodB->GetXaxis()->FindBin( 5 );

	int lx1 = periodB->GetXaxis()->FindBin( -35 );
	int lx2 = periodB->GetXaxis()->FindBin( -25 );

	int rx1 = periodB->GetXaxis()->FindBin( 25 );
	int rx2 = periodB->GetXaxis()->FindBin( 35 );


	TH1D * periodB_center = periodB->ProjectionY( "hRefMult_center", cx1, cx2 );
	TH1D * periodB_left = periodB->ProjectionY( "hRefMult_left", lx1, lx2 );
	TH1D * periodB_right = periodB->ProjectionY( "hRefMult_right", rx1, rx2 );

	TFile * fout = new TFile( ("period_" + period + "_refMult1D.root").c_str() , "RECREATE" );

	periodB_center->SetTitle(  (title +" -5<vZ[cm]<5; refMult; dN/dRefMult" ).c_str() );
	periodB_left->SetTitle(  (title +" -35<vZ[cm]<-25; refMult; dN/dRefMult" ).c_str() );
	periodB_right->SetTitle(  (title +" 25<vZ[cm]<35; refMult; dN/dRefMult" ).c_str() );

	periodB_center->Write();
	periodB_left->Write();
	periodB_right->Write();


	fout->Close();

}