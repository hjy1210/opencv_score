## ConsoleApp and JSON
[rapidjson](https://github.com/Tencent/rapidjson) 的網站如此說：
* RapidJSON is a JSON parser and generator for C++. It was inspired by RapidXml.

* RapidJSON is small but complete. It supports both SAX and DOM style API. The SAX parser is only a half thousand lines of code.

* RapidJSON is fast. Its performance can be comparable to strlen(). It also optionally supports SSE2/SSE4.2 for acceleration.

* RapidJSON is self-contained and header-only. It does not depend on external libraries such as BOOST. It even does not depend on STL.

* RapidJSON is memory-friendly. Each JSON value occupies exactly 16 bytes for most 32/64-bit machines (excluding text string). By default it uses a fast memory allocator, and the parser allocates memory compactly during parsing.

* RapidJSON is Unicode-friendly. It supports UTF-8, UTF-16, UTF-32 (LE & BE), and their detection, validation and transcoding internally. For example, you can read a UTF-8 file and let RapidJSON transcode the JSON strings into UTF-16 in the DOM. It also supports surrogates and "\u0000" (null character).


本專案練習使用rapidjson套件，使用Console Application樣板。
只要在專案屬性頁中 C++ > 一般 > 其他include目錄裡面加入rapidjson根目錄的上層目錄即可。


## App1(Universal Windows) with OpenCVBridge
[Process bitmaps with OpenCV](https://docs.microsoft.com/en-us/windows/uwp/audio-video-camera/process-software-bitmaps-with-opencv)是[Universal Windows Platform documentation](https://docs.microsoft.com/en-us/windows/uwp/index)裡面的一篇文章。

This article explains how to use the SoftwareBitmap class, which is used by many different UWP APIs to represent images, with the Open Source Computer Vision Library (OpenCV), an open source, native code library that provides a wide variety of image processing algorithms.

本專案依樣畫葫蘆，先製作OpenCVBridge，再用App1 呼叫它。

App1 有介面讓使用者選定一個圖檔，將此圖檔透過 OpenCVBridge 與 OpenCV 將圖形模糊化後顯示。

* 在 OpenCVBridge 中用 Nuget 方式參考 OpenCV。
* OpenCVBridge/OpenCV 的部分不能 Debug
* 此處OpenCVBridge 用 Windows Runtime Component(Universal Windows)樣板，App1 用 Windows Empty Application(Universal Windows)樣板。

## opencv_score
opencv_score 使用 Windows Console Application 樣板。

在屬性頁中進行設定
* C/C++
  * 其他include目錄，加入$(OPENCV_DIR)\..\..\include
* Linker
  * 其他程式庫目錄，加入$(OPENCV_DIR)\lib
  * 輸入 >  其他相依性，加入 opencv_world400d.lib

其中的環境變數OPENCV_DIR指向opencv的根目錄，opencv-4.0.0-alpha-vc14_vc15.exe 從[此處](https://sourceforge.net/projects/opencvlibrary/files/opencv-win/)下載。

**本專案可以進行完整的Debug**。
## image_watch_demo
與 opencv_score 相同，有使用到image_watch插件，可在Debug模式中觀看OpenCV 的 Mat。


## ScoreCore, ScoreWrapper and ScoreSandbox
[Creating a C++/CLI Wrapper](https://www.red-gate.com/simple-talk/dotnet/net-development/creating-ccli-wrapper/)說道：

The C++/CLI is a dialect of C++ that is designed to work with the Common Language Infrastructure (CLI). It is a replacement for 'Managed C++' and makes every feature of the CLI easily accessible from C++. Mircea demonstrates the architecture that is involved in a C++/CLI wrapper that allows you to use both managed and unmanaged code, and to provide the choice of controlling memory directly.

依樣畫葫蘆做了下面三個專案：
* ScoreCore 是個 C++ library，它用 OpenCV 做想要做的事。

* ScoreWrapper 是C++/CLI 專案，將 ScoreCore 包裝起來，讓 .Net 專案可以呼叫ScoreCore的函數。
* ScoreSandbox 是C#專案，透過ScoreWrapper呼叫ScoreCore。

## opencv-4.0.0-alpha-vc14_vc15.exe
似乎 opencv-4.0.0已可接受含有 non-ascii 字元的檔名。

## wxwidgetstart
* wxwidgetstart 用C++空白模板
* 屬性管理員 > Debug|x64 加入 hello-world/cmake/debug64/conanbuildinfo.props
* 加入[Hello World Example](https://docs.wxwidgets.org/stable/overview_helloworld.html)裡面介紹的完整source.cpp
* 用 wxFileDialog 讓讀者選取圖檔，用OpenCV 顯示影像。
* 用 wxDirDialog 讓使用者選取目錄，用 OpenCV 對目錄裡面的每一個jpg檔案顯示影像。