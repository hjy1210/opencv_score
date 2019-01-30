## ConsoleApp and JSON
[rapidjson](https://github.com/Tencent/rapidjson) �������p�����G
* RapidJSON is a JSON parser and generator for C++. It was inspired by RapidXml.

* RapidJSON is small but complete. It supports both SAX and DOM style API. The SAX parser is only a half thousand lines of code.

* RapidJSON is fast. Its performance can be comparable to strlen(). It also optionally supports SSE2/SSE4.2 for acceleration.

* RapidJSON is self-contained and header-only. It does not depend on external libraries such as BOOST. It even does not depend on STL.

* RapidJSON is memory-friendly. Each JSON value occupies exactly 16 bytes for most 32/64-bit machines (excluding text string). By default it uses a fast memory allocator, and the parser allocates memory compactly during parsing.

* RapidJSON is Unicode-friendly. It supports UTF-8, UTF-16, UTF-32 (LE & BE), and their detection, validation and transcoding internally. For example, you can read a UTF-8 file and let RapidJSON transcode the JSON strings into UTF-16 in the DOM. It also supports surrogates and "\u0000" (null character).


���M�׽m�ߨϥ�rapidjson�M��A�ϥ�Console Application�˪O�C
�u�n�b�M���ݩʭ��� C++ > �@�� > ��Linclude�ؿ��̭��[�Jrapidjson�ڥؿ����W�h�ؿ��Y�i�C


## App1(Universal Windows) with OpenCVBridge
[Process bitmaps with OpenCV](https://docs.microsoft.com/en-us/windows/uwp/audio-video-camera/process-software-bitmaps-with-opencv)�O[Universal Windows Platform documentation](https://docs.microsoft.com/en-us/windows/uwp/index)�̭����@�g�峹�C

This article explains how to use the SoftwareBitmap class, which is used by many different UWP APIs to represent images, with the Open Source Computer Vision Library (OpenCV), an open source, native code library that provides a wide variety of image processing algorithms.

���M�ר̼˵e��Ī�A���s�@OpenCVBridge�A�A��App1 �I�s���C

App1 ���������ϥΪ̿�w�@�ӹ��ɡA�N�����ɳz�L OpenCVBridge �P OpenCV �N�ϧμҽk�ƫ���ܡC

* �b OpenCVBridge ���� Nuget �覡�Ѧ� OpenCV�C
* OpenCVBridge/OpenCV ���������� Debug
* ���BOpenCVBridge �� Windows Runtime Component(Universal Windows)�˪O�AApp1 �� Windows Empty Application(Universal Windows)�˪O�C

## opencv_score
opencv_score �ϥ� Windows Console Application �˪O�C

�b�ݩʭ����i��]�w
* C/C++
  * ��Linclude�ؿ��A�[�J$(OPENCV_DIR)\..\..\include
* Linker
  * ��L�{���w�ؿ��A�[�J$(OPENCV_DIR)\lib
  * ��J >  ��L�̩ۨʡA�[�J opencv_world400d.lib

�䤤�������ܼ�OPENCV_DIR���Vopencv���ڥؿ��Aopencv-4.0.0-alpha-vc14_vc15.exe �q[���B](https://sourceforge.net/projects/opencvlibrary/files/opencv-win/)�U���C

**���M�ץi�H�i�槹�㪺Debug**�C
## image_watch_demo
�P opencv_score �ۦP�A���ϥΨ�image_watch����A�i�bDebug�Ҧ����[��OpenCV �� Mat�C


## ScoreCore, ScoreWrapper and ScoreSandbox
[Creating a C++/CLI Wrapper](https://www.red-gate.com/simple-talk/dotnet/net-development/creating-ccli-wrapper/)���D�G

The C++/CLI is a dialect of C++ that is designed to work with the Common Language Infrastructure (CLI). It is a replacement for 'Managed C++' and makes every feature of the CLI easily accessible from C++. Mircea demonstrates the architecture that is involved in a C++/CLI wrapper that allows you to use both managed and unmanaged code, and to provide the choice of controlling memory directly.

�̼˵e��Ī���F�U���T�ӱM�סG
* ScoreCore �O�� C++ library�A���� OpenCV ���Q�n�����ơC

* ScoreWrapper �OC++/CLI �M�סA�N ScoreCore �]�˰_�ӡA�� .Net �M�ץi�H�I�sScoreCore����ơC
* ScoreSandbox �OC#�M�סA�z�LScoreWrapper�I�sScoreCore�C

## opencv-4.0.0-alpha-vc14_vc15.exe
���G opencv-4.0.0�w�i�����t�� non-ascii �r�����ɦW�C

## wxwidgetstart
* wxwidgetstart ��C++�ťռҪO
* �ݩʺ޲z�� > Debug|x64 �[�J hello-world/cmake/debug64/conanbuildinfo.props
* �[�J[Hello World Example](https://docs.wxwidgets.org/stable/overview_helloworld.html)�̭����Ъ�����source.cpp
* �� wxFileDialog ��Ū�̿�����ɡA��OpenCV ��ܼv���C
* �� wxDirDialog ���ϥΪ̿���ؿ��A�� OpenCV ��ؿ��̭����C�@��jpg�ɮ���ܼv���C