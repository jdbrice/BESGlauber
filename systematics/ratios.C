
string names[] = { "nosmear", "large", "small", "lxs", "sxs", "low", "high", "mult1", "mult2" };
string titles[] = { "no smearing", "large R, small d", "small R, large d", "#sigma_{NN}+1mb", "#sigma_{NN}-1mb", "small n_{pp}", "large n_{pp}", "+5% total xsec", "-5% total xsec" };



TFile * f0;

int colors[] = { kRed, kBlue, kGreen, kPink, kBlack, kRed + 2, kGreen + 2, kPink + 3, kOrange };

TCanvas * c = new TCanvas( "c", "c", 600, 900 );

void drawSet( string n = "ncoll" ){

	TLegend * leg = new TLegend(0.0,0.0,0.99,0.99);

	TProfile * hn = (TProfile*)f0->Get( (n+"_nominal").c_str()  );
	hn->Draw("p");
	hn->GetXaxis()->SetRangeUser( 0, 82 );
	hn->GetYaxis()->SetRangeUser( 0, hn->GetMaximum() * 1.2 );
	hn->SetLineColor( kBlack );
	hn->SetMarkerStyle( 20 );
	hn->SetLineWidth( 2 );

	leg->AddEntry( hn, "Nominal", "p" );

	for ( int i = 0; i < 9; i++ ){
		TProfile * hp = (TProfile*)f0->Get( (n+"_"+names[i]).c_str()  );
		
		hp->SetMarkerStyle( i + 20 );
		hp->SetMarkerColor( colors[ i ] );
		hp->SetLineWidth( 2 );
		hp->Draw( "same p" );

		leg->AddEntry( hp, titles[i].c_str(), "p" );

	}	

	c->cd(3);
	leg->Draw("");

}

void drawRSet( string n = "ncoll" ){


	TProfile * hn = (TProfile*)f0->Get( (n+"_nominal").c_str()  );
	//hn->Draw("p");
	hn->SetLineColor( kBlack );
	hn->SetLineWidth( 2 );

	TProfile * frame = (TProfile*)hn->Clone( "frame" );
	frame->Divide( hn );
	frame->GetYaxis()->SetTitle( "Ratio wrt. Nominal" );
	frame->Draw( "hist p" );
	frame->GetYaxis()->SetRangeUser( 0.5, 1.5 );

	double max = -1.5;
	double min = 0.5;

	for ( int i = 0; i < 9; i++ ){
		TProfile * hp = (TProfile*)f0->Get( (n+"_"+names[i]).c_str()  );
		TProfile * hpr = (TProfile*)hp->Clone( (n+"_"+names[i]+"_ratio").c_str() );
		hpr->Divide( hn );

		hpr->SetMarkerStyle( i + 20 );
		hpr->SetMarkerColor( colors[ i ] );
		hpr->SetLineWidth( 2 );
		

		if ( hpr->GetMaximum() > max )
			max = hpr->GetMaximum();


		hpr->Draw( "same hist p" );

	}	

	if ( "b" == n )
		min = 0.9;
	else if ( "spp" == n || "srp" == n)
		min = 0.75;

	frame->GetYaxis()->SetRangeUser( min, max * 1.05 );

}



void ratios( string var = "ncoll" ){
	
	gStyle->SetOptStat( 0 );
	f0 = new TFile( "data/profiles.root", "READ" );
	

	c->Divide( 1, 2 );
	c->cd(1);
	drawSet( var );
	c->cd(2);
	drawRSet( var );

	c->Print( ("report/" + var + ".pdf").c_str() );

}