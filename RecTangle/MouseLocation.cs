using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RecTangle
{
    public class MouseLocation : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;

        protected virtual void OnPropertyChanged(string propertyName)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
            }
        }

        #region Propperty
        /// <summary> 描画開始座標 </summary>
        public Point StartLocation { get; set; }
        /// <summary> 描画完了座標 </summary>
        public Point EndLocation { get; set; }
        public Point NowLocation
        {
            get { return nowLocation; }
            set
            {
                if (value == NowLocation) return;
                nowLocation = value;

                OnPropertyChanged(nameof(NowLocation));
            }
        }
        /// <summary> 描画中判定 </summary>
        public bool isDraw { get; set; } = false;
        #endregion

        #region Field
        private Point nowLocation;
        #endregion
    }
}
