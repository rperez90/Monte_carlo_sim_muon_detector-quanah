#include <fstream>
#include <iostream>
{
   std::map<std::string, TH1D*> histo1D;
   std::map<std::string, TH1D*>::iterator histo1Diter;

   std::map<std::string, TH2D*> histo2D;
   std::map<std::string, TH2D*>::iterator histo2Diter;

   TFile *f1 = new TFile("histEXP4_45deg_AIR_3MILL.root","READ");
   TFile *f2 = new TFile("histEXP4_45deg_wateronly_3MILL.root","READ");

   TH1D* x11away=(TH1D*)f1->Get("xZ11");
   TH1D* x11tank=(TH1D*)f2->Get("xZ11");

   TH1D* y11away=(TH1D*)f1->Get("yZ11");
   TH1D* y11tank=(TH1D*)f2->Get("yZ11");

   TH2D* xy11away=(TH2D*)f1->Get("xyZ11");
   TH2D* xy11tank=(TH2D*)f2->Get("xyZ11");

   int nx1d=x11away->GetNbinsX();
   double xmin1d=-200.0;
   double xmax1d= 200.0;
   double dx=(xmax1d-xmin1d)/double(nx1d);
   cout<<"nx1d="<<nx1d<<"    dx="<<dx<<endl;

   TH1D* plotXtank=new TH1D("xTank","X Tank",nx1d,xmin1d,xmax1d);
   for (int ix=1; ix<nx1d; ix++) {
      double wt=x11tank->GetBinContent(ix);
	  double x=xmax1d-dx*ix+dx/2.0;
      plotXtank->Fill(x,wt);
	  //cout<<" xvalue="<<x<<endl;
   }
   
   int ny1d=y11away->GetNbinsX();
   double ymin1d=-200.0;
   double ymax1d= 200.0;
   double dy=(ymax1d-ymin1d)/double(ny1d);

   TH1D* plotYtank=new TH1D("yTank","Y Tank",ny1d,ymin1d,ymax1d);
   for (int iy=1; iy<ny1d; iy++) {
		double wt=y11tank->GetBinContent(iy);
		double y=ymax1d-dy*iy+dy/2.0;
		plotYtank->Fill(y,wt);
   }
   // xy9tank->Divide(xy9away); 

   int nx=xy11away->GetNbinsX();
   int ny=xy11away->GetNbinsY();
   cout<<"nx="<<nx<<"   ny="<<ny<<endl;

   TH2D* plotA=new TH2D("plotA","MC (Water only)",13,-15.0,12.0,13,-15.0,12.0);
//   TH2D* plotA=new TH2D("plotA","MC (Water 20ft)",12,-15.0,15.0,12,-15.0,15.0);

   ofstream out ("wtwateronly.txt");
   for (int ix=1; ix<nx; ix++) {
      for(int iy=1; iy<ny; iy++) {
       double wtA=xy11away->GetBinContent(ix,iy);
       //double wtT=xy11tank->GetBinContent(nx-ix+2,iy);
       double wtT=xy11tank->GetBinContent(ix,iy);
	   double wt=wtT/wtA;
       //cout<<"wt = "<<wtT<<endl;
	   if(wt>1.1) wt=1.0;
       double x=-25.0+2.0*ix-2.0/2.0;
       double y=-25.0+2.0*iy-2.0/2.0;
       //double x=2.5*(ix-26)-2.5/2.0;
       //double y=2.5*(iy-25)-2.5/2.0;
       plotA->Fill(x,y,wt);
	   //cout<<"x="<<x<<" y="<<y<<" wt="<<wt<<endl;
	   int bin_32ft = plotA->GetBinContent(wt);
	   //cout<<"bin_32ft = "<<bin_32ft<<" wt = "<<wt<<endl;
	   out<<wt<<endl;
	}
   }
  out.close();  
  plotA->GetXaxis()->SetTitle("X (m)");
  plotA->GetYaxis()->SetTitle("Y (m)");
  //int bin32ft = plotA->GetBinContent(wt);
}

