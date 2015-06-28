using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Media;
using System.Windows.Shapes;
using System.Windows.Controls;
using System.Windows.Interop;
using System.Diagnostics;

namespace ImagePackageGenerator
{
	class Program
	{
		[STAThread]
		static void Main(string[] args)
		{
			/*
			Application application = new Application();
			application.DispatcherUnhandledException += new System.Windows.Threading.DispatcherUnhandledExceptionEventHandler(application_DispatcherUnhandledException);

			var window = new MainWindow();
			window.Show();

			application.Run();
			*/

			System.Windows.Forms.Application.Run(new Window());
		}

		static void application_DispatcherUnhandledException(object sender, System.Windows.Threading.DispatcherUnhandledExceptionEventArgs e)
		{
			e.Handled = true;
		}
	}
}
