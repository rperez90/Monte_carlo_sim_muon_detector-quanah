#include <TAxis.h>

{
   std::map<std::string, TH1D*> histo1D;
   std::map<std::string, TH1D*>::iterator histo1Diter;

   std::map<std::string, TH2D*> histo2D;
   std::map<std::string, TH2D*>::iterator histo2Diter;

   TFile *f1 = new TFile("hist61_45deg_EX1_airtank.root","READ");
   TFile *f2 = new TFile("hist61_45deg_1126_full50ftwater.root","READ");

   TH1D* x9away=(TH1D*)f1->Get("xZ11");
   TH1D* x9tank=(TH1D*)f2->Get("xZ11");

   TH1D* y9away=(TH1D*)f1->Get("yZ11");
   TH1D* y9tank=(TH1D*)f2->Get("yZ11");

   TH2D* xy9away=(TH2D*)f1->Get("xyZ11");
   TH2D* xy9tank=(TH2D*)f2->Get("xyZ11");

   int nx1d=x9away->GetNbinsX();
   double xmin1d=-10000.0;
   double xmax1d= 10000.0;
   double dx=(xmax1d-xmin1d)/double(nx1d);
   cout<<"nx1d="<<nx1d<<"    dx="<<dx<<endl;

   TH1D* plotXtank=new TH1D("xTank","X Tank",nx1d,xmin1d,xmax1d);
   for (int ix=1; ix<nx1d; ix++) {
      double wt=x9tank->GetBinContent(ix);
      double x=xmax1d-dx*ix+dx/4.0;
//	  cout << "x1 : " << x << " wt1: " << wt << endl; 
      plotXtank->Fill(x,wt);
   }
   
   // xy9tank->Divide(xy9away); 

   int nx=xy9away->GetNbinsX();
   int ny=xy9away->GetNbinsY();
   int ntx=xy9tank->GetNbinsX();
   int nty=xy9tank->GetNbinsY();
   cout<<"nx="<<nx<<"   ny="<<ny<<endl;
   cout<<"ntx="<<ntx<<" nty="<<nty<<endl;
   TAxis* xAxis = xy9tank->GetXaxis();
   TAxis* yAxis = xy9tank->GetYaxis();
   double xmin2d=-(xAxis->GetBinLowEdge(ntx))/100;
   double xmax2d=(xAxis->GetBinUpEdge(ntx))/100;
   double ymin2d=-(yAxis->GetBinLowEdge(nty))/100;
   double ymax2d=(yAxis->GetBinUpEdge(nty))/100;
   cout<<"xmin2d = "<<xmin2d<<" xmax2d = "<<xmax2d<<" ymin2d = "<<ymin2d<<" ymax2d = "<<ymax2d<<endl;
//   double xmin2d=-20.0;  //hardcoded x and y bin sizes
//   double xmax2d=20.0;
//   double ymin2d=-20.0;
//   double ymax2d=20.0;
   double d2x=(xmax2d-xmin2d)/double(nx);
   double d2y=(ymax2d-ymin2d)/double(ny);
   TH2D* plotA=new TH2D("plotA","MC (Water full50ft)",15,-15.0,15.0,15,-15.0,15.0);
//   TH2D* plotA=new TH2D("plotA","MC (Water 18ft)",12,-15.0,15.0,12,-15.0,15.0);

   for (int ix=1; ix<nx; ix++) {
      for(int iy=1; iy<ny; iy++) {
         double wtA=xy9away->GetBinContent(ix,iy);
         double wtT=xy9tank->GetBinContent(ix,iy);        
		 double wt1=wtT/wtA;
         if(wt>1.1) wt=1.1;
         double x=xmax2d-d2x*ix+d2x/4.0;
		 double y=ymax2d-d2y*iy+d2y/4.0;
//		 double x=-25.0+2.0*ix-2.0/2.0;
//         double y=-25.0+2.0*iy-2.0/2.0;  //RP comment: what does x and y mean?
//         double x=2.5*(ix-12)-2.5/2.0;
//         double y=2.5*(iy-12)-2.5/2.0;
//		 cout << "x2 : " << x  << " y2: " << y  << " wtA " << wtA  << " wt2: " << wt << endl; 
//         TH2D* wt = plotA->SetBinsLength(1);

         plotA->Fill(x,y,wt);
//		 plotA->Rebin();
      }
   }

  plotA->GetXaxis()->SetTitle("X (m)");
  plotA->GetYaxis()->SetTitle("Y (m)");

}

