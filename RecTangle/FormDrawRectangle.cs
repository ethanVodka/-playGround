using System;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Windows.Forms;

namespace RecTangle
{
    public partial class FormDrawRectangle : Form
    {
        //MouseClass インスタンス準備
        private readonly MouseLocation Mouse;

        public FormDrawRectangle()
        {
            InitializeComponent();

            Mouse = new MouseLocation();

            //DataBinding
            LabelX.DataBindings.Add("Text", Mouse, nameof(Mouse.NowLocation), true, DataSourceUpdateMode.OnPropertyChanged);
        }


        private void PictureBox_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                //左クリックのみ
                Mouse.isDraw = true;

                Mouse.StartLocation = e.Location;
            }
            else
            {
                return;
            }

        }

        private void PictureBox_MouseMove(object sender, MouseEventArgs e)
        {
            Mouse.NowLocation = e.Location;

            if (Mouse.isDraw)
            {
                //描画中判定
                //随時更新
                //Draw Startp To NowP
                DrawRectangle(Mouse.StartLocation, Mouse.NowLocation, false);
            }
            else
            {
                return;
            }
        }

        private void PictureBox_MouseUp(object sender, MouseEventArgs e)
        {
            if (Mouse.isDraw)
            {
                Mouse.isDraw = false;

                Mouse.EndLocation = e.Location;
                //描画確定
                //DrawRect StartP To EndP
                DrawRectangle(Mouse.StartLocation, Mouse.EndLocation, true);
            }
            else
            {
                return;
            }


        }
        private void PictureBox_MouseLeave(object sender, EventArgs e)
        {
            Mouse.NowLocation = new Point(0, 0);
        }

        private void DrawRectangle(Point startP, Point endP, bool isFill)
        {
            Rectangle rect = new Rectangle();
            
            //座標の大小から始点座標計算
            rect.X = Math.Min(startP.X, endP.X);
            rect.Y = Math.Min(startP.Y, endP.Y);
            //矩形の幅、高を絶対値で算出
            rect.Width = Math.Abs(startP.X - endP.X);
            rect.Height = Math.Abs(startP.Y - endP.Y);

            //描画
            Bitmap objBmp = new Bitmap(pictureBox.Width, pictureBox.Height);
            using (Graphics objGrp = Graphics.FromImage(objBmp))
            {
                Pen pen = new Pen(Color.Red, 1);
                pen.DashStyle = DashStyle.Dash;
                if (isFill)
                {
                    objGrp.FillRectangle(Brushes.Blue, rect);
                }
                else
                {
                    objGrp.DrawRectangle(pen, rect);
                }

                pictureBox.Image = objBmp;
            }

        }
    }
}
