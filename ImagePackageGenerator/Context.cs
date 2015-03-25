using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ImagePackageGenerator
{
	class Context : PropertyChangedObject
	{
		PSD psd = new PSD();

		public System.Collections.ObjectModel.ObservableCollection<Layer> Layers { get; private set; }

		public Context()
		{
			Layers = new System.Collections.ObjectModel.ObservableCollection<Layer>();
		}

		public void Load(string path)
		{
			Layers.Clear();

			psd.Load(path);

			foreach(var l in psd.Layers)
			{
				Layers.Add(new Layer(l));
			}
		}

		public void Terminate()
		{ 
			if(psd != null)
			{
				psd.Terminate();
			}
			psd = null;
		}

		public byte[] Export()
		{
			return psd.Export();
		}
	}

	class Layer : PropertyChangedObject
	{
		PSD.Layer layer;

		public unsafe Layer(PSD.Layer layer)
		{
			this.layer = layer;

			Name = layer.Name;
			Rect = layer.Rect;

			var wi = new System.Windows.Media.Imaging.WriteableBitmap(Rect.Width, Rect.Height, 96, 96, System.Windows.Media.PixelFormats.Bgra32, null);

			var img = new Color[Rect.Width * Rect.Height];

			fixed (Color* p = layer.Pixels)
			{
				fixed (Color* i = img)
				{
					for (int n = 0; n < Rect.Width * Rect.Height; n++ )
					{
						i[n].R = p[n].B;
						i[n].G = p[n].G;
						i[n].B = p[n].R;
						i[n].A = p[n].A;
					}

					wi.WritePixels(new System.Windows.Int32Rect(0, 0, Rect.Width, Rect.Height), (IntPtr)i, Rect.Width * Rect.Height * 4, Rect.Width * 4);
				}
			}

			Image = wi;
		}

		public string Name { get; private set; }

		public Rect Rect { get; private set; }

		public System.Windows.Media.Imaging.BitmapSource Image { get; private set; }

		public override string ToString()
		{
			return Name;
		}
	}
}
