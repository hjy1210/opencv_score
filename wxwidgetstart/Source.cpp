// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <string>
#include <filesystem>
#include <wx/dir.h>
using namespace cv;
using namespace std;
class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};
class MyFrame : public wxFrame
{
public:
	MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
	void OnHello(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();
};
enum
{
	ID_Hello = 1
};
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_MENU(ID_Hello, MyFrame::OnHello)
EVT_MENU(wxID_EXIT, MyFrame::OnExit)
EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
	MyFrame *frame = new MyFrame("Hello World", wxPoint(50, 50), wxSize(450, 340));
	frame->Show(true);
	return true;
}
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, title, pos, size)
{
	wxMenu *menuFile = new wxMenu;
	menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
		"Help string shown in status bar for this menu item");
	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT);
	wxMenu *menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);
	wxMenuBar *menuBar = new wxMenuBar;
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuHelp, "&Help");
	SetMenuBar(menuBar);
	CreateStatusBar();
	SetStatusText("Welcome to wxWidgets!");
}
void MyFrame::OnExit(wxCommandEvent& event)
{
	wxFileDialog
		openFileDialog(this, _("Open XYZ file"), "", "",
			"jpg files (*.jpg)|*.jpg", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	if (openFileDialog.ShowModal() == wxID_CANCEL)
		return;     // the user changed idea...

	// proceed loading the file chosen by the user;
	// this can be done with e.g. wxWidgets input streams:
	String path=std::string(openFileDialog.GetPath());
	Mat image;
	image = imread(path, IMREAD_COLOR); // Read the file
	if (image.empty()) // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
	}
	namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("Display window", image); // Show our image inside it.
	waitKey(10000);
	Close(true);
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox("This is a wxWidgets' Hello world sample",
		"About Hello World", wxOK | wxICON_INFORMATION);
	String imageName("d:\\mia¤¤¤å\\IMG_1902.JPG");
	Mat image;
	image = imread(imageName, IMREAD_COLOR); // Read the file
	if (image.empty()) // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
	}
	namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("Display window", image); // Show our image inside it.
	cout << "Detecting edges in input image" << endl;
	Mat edges;
	Canny(image, edges, 10, 100);
	imshow("Canny", edges);
	waitKey(0); // Wait for a keystroke in the window

}
void MyFrame::OnHello(wxCommandEvent& event)
{
	wxLogMessage("Hello world from wxWidgets!");
	wxDirDialog dlg(NULL, "Choose input directory", "",
		wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);
	if (dlg.ShowModal() == wxID_CANCEL)
		return;     // the user changed idea...
	wxString path = dlg.GetPath();
	wxString f = wxFindFirstFile(path+"/*.jpg");
	namedWindow("Display window", WINDOW_AUTOSIZE);
	while (!f.empty())	{
		std::string name(f.GetData());
		Mat image = imread(name, IMREAD_COLOR);
		imshow("Display window", image);
		waitKey(1000);
		f = wxFindNextFile();
	}
	//wxLogMessage("Next");
	wxArrayString *children = new wxArrayString;
	int count=wxDir::GetAllFiles(path, children);
	for (int i = 0; i < children->Count(); i++) {
		wxString s0 = children->Item(i);
		std::string s(s0);
		if (std::experimental::filesystem::is_regular_file(s)) {
			Mat image = imread(s, IMREAD_COLOR);
			imshow("Display window", image);
			waitKey(1000);
		}
		else {
			wxLogMessage(s0);
		}
	}
	delete children;
}