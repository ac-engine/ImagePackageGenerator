using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ImagePackageGenerator
{
	public class PropertyChangedObject : System.ComponentModel.INotifyPropertyChanged
	{
		public event System.ComponentModel.PropertyChangedEventHandler PropertyChanged;

		protected void OnClassPropertyChanged<T>(ref T target, ref T value, [System.Runtime.CompilerServices.CallerMemberName] string propertyName = null)
		{
			target = value;

			if (PropertyChanged != null)
			{
				PropertyChanged(this, new System.ComponentModel.PropertyChangedEventArgs(propertyName));
			}
		}

		protected void OnPropertyChanged<T>(ref T target, ref T value, [System.Runtime.CompilerServices.CallerMemberName] string propertyName = null) where T : IEquatable<T>
		{
			if (target.Equals(value)) return;
			
			target = value;

			if (PropertyChanged != null)
			{
				PropertyChanged(this, new System.ComponentModel.PropertyChangedEventArgs(propertyName));
			}
		}

		protected void OnPropertyChanged([System.Runtime.CompilerServices.CallerMemberName] string propertyName = null)
		{
			if (PropertyChanged != null)
			{
				PropertyChanged(this, new System.ComponentModel.PropertyChangedEventArgs(propertyName));
			}
		}
	}
}
