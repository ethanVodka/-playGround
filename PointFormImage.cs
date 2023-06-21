using System;
using System.Drawing;
using Emgu.CV;
using Emgu.CV.CvEnum;
using Emgu.CV.Structure;

public static void Main()
    {
        // 画像の読み込み
        Mat img = new Mat("path_to_your_image", ImreadModes.Color);
        
        // グレースケールに変換
        Mat gray = new Mat();
        CvInvoke.CvtColor(img, gray, ColorConversion.Bgr2Gray);
        
        // Cannyエッジ検出を適用
        Mat edges = new Mat();
        CvInvoke.Canny(gray, edges, 100, 200);
        
        // エッジの座標を取得
        for (int y = 0; y < edges.Rows; y++)
        {
            for (int x = 0; x < edges.Cols; x++)
            {
                double pixelValue = edges.Data[y, x, 0];
                if (pixelValue > 0) // エッジを検出した場合
                {
                    Console.WriteLine("Edge detected at: x={0}, y={1}", x, y);
                }
            }
        }
    }