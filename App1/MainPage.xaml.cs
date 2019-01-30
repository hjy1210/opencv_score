using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.Graphics.Imaging;
using Windows.Storage;
using Windows.Storage.Pickers;
using Windows.Storage.Streams;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Media.Imaging;
using Windows.UI.Xaml.Navigation;

// 空白頁項目範本已記錄在 https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x404

namespace App1
{
    /// <summary>
    /// 可以在本身使用或巡覽至框架內的空白頁面。
    /// </summary>
    public sealed partial class MainPage : Page
    {
        public MainPage()
        {
            this.InitializeComponent();
        }
		async System.Threading.Tasks.Task processAsync()
		{
			FileOpenPicker fileOpenPicker = new FileOpenPicker();
			fileOpenPicker.SuggestedStartLocation = PickerLocationId.PicturesLibrary;
			fileOpenPicker.FileTypeFilter.Add(".jpg");
			fileOpenPicker.ViewMode = PickerViewMode.Thumbnail;

			var inputFile = await fileOpenPicker.PickSingleFileAsync();

			if (inputFile == null)
			{
				// The user cancelled the picking operation
				return;
			}

			SoftwareBitmap inputBitmap;
			using (IRandomAccessStream stream = await inputFile.OpenAsync(FileAccessMode.Read))
			{
				// Create the decoder from the stream
				BitmapDecoder decoder = await BitmapDecoder.CreateAsync(stream);

				// Get the SoftwareBitmap representation of the file
				inputBitmap = await decoder.GetSoftwareBitmapAsync();
			}

			if (inputBitmap.BitmapPixelFormat != BitmapPixelFormat.Bgra8
						|| inputBitmap.BitmapAlphaMode != BitmapAlphaMode.Premultiplied)
			{
				inputBitmap = SoftwareBitmap.Convert(inputBitmap, BitmapPixelFormat.Bgra8, BitmapAlphaMode.Premultiplied);
			}

			SoftwareBitmap outputBitmap = new SoftwareBitmap(inputBitmap.BitmapPixelFormat, inputBitmap.PixelWidth, inputBitmap.PixelHeight, BitmapAlphaMode.Premultiplied);


			var helper = new OpenCVBridge.OpenCVHelper();
			helper.Blur(inputBitmap, outputBitmap);

			var bitmapSource = new SoftwareBitmapSource();
			await bitmapSource.SetBitmapAsync(outputBitmap);
			imageControl.Source = bitmapSource;
		}
		private void MyButton_Click(object sender, RoutedEventArgs e)
		{
			processAsync().Wait(3);
		}
	}
}
