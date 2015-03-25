using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

using Microsoft.Win32;

namespace ImagePackageGenerator
{
	/// <summary>
	/// MainWindow.xaml の相互作用ロジック
	/// </summary>
	public partial class MainWindow : Window
	{
		public MainWindow()
		{
			InitializeComponent();
		}

		Context cxt = null;

		private void Window_Closed(object sender, EventArgs e)
		{
			cxt.Terminate();
			cxt = null;
		}

		private void Window_Loaded(object sender, RoutedEventArgs e)
		{
			cxt = new Context();
			DataContext = cxt;
		}

		private void MenuItem_Open(object sender, RoutedEventArgs e)
		{
			OpenFileDialog ofd = new OpenFileDialog();
			ofd.FileName = "";
			ofd.Filter = "PSD (.psd)|*.psd";
			ofd.Multiselect = false;
			ofd.InitialDirectory = System.IO.Directory.GetCurrentDirectory();
			if (ofd.ShowDialog() == true)
			{
				cxt.Load(ofd.FileName);
			}
		}

		private void MenuItem_Export(object sender, RoutedEventArgs e)
		{
			SaveFileDialog sfd = new SaveFileDialog();
			sfd.FileName = "";
			sfd.Filter = "aip (.aip)|*.aip";
			//sfd.CheckFileExists = true;
			sfd.InitialDirectory = System.IO.Directory.GetCurrentDirectory();

			if (sfd.ShowDialog() == true)
			{
				System.IO.File.WriteAllBytes(sfd.FileName, cxt.Export());
			}
		}
	}
}
