// PictureBox上で描画するためのGraphicsオブジェクトを作成します
System::Drawing::Graphics^ g = pictureBox1->CreateGraphics();
g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias; // Smooth the lines

// GDSファイルから読み込んだポリゴンの座標（この例では適当な値を設定）
cli::array<System::Drawing::PointF>^ gdspoints = gcnew cli::array<System::Drawing::PointF> {
    System::Drawing::PointF(-100000, -200000),
    System::Drawing::PointF(300000, -200000),
    System::Drawing::PointF(300000, 300000),
    System::Drawing::PointF(-100000, 300000),
};

// 描画用に座標を変換
float scale = 0.001f; // スケーリング係数（GDS座標からピクチャボックス座標へ）
float offsetX = pictureBox1->Width / 2; // PictureBoxの中心を新たな原点とする
float offsetY = pictureBox1->Height / 2; // PictureBoxの中心を新たな原点とする

cli::array<System::Drawing::PointF>^ polygonPoints = gcnew cli::array<System::Drawing::PointF>(gdspoints->Length);
for (int i = 0; i < gdspoints->Length; i++)
{
    float x = gdspoints[i].X * scale + offsetX;
    float y = gdspoints[i].Y * scale + offsetY;
    polygonPoints[i] = System::Drawing::PointF(x, y);
}

// ポリゴンを描画します
g->FillPolygon(gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black), polygonPoints);
