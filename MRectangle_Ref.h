public ref class MRectangle
{
private:
    float left;   // 左下のx座標
    float bottom; // 左下のy座標
    float width;  // 幅
    float height; // 高さ

public:
    // コンストラクタ
    MRectangle(float l, float b, float w, float h)
    : left(l), bottom(b), width(w), height(h) {}

    // ゲッターメソッド
    float getLeft()   { return left; }
    float getBottom() { return bottom; }
    float getWidth()  { return width; }
    float getHeight() { return height; }

    // 他のMRectangleとの重なりを判定するメソッド
    bool IntersectsWith(MRectangle^ other)
    {
        // thisとotherの座標を比較して重なりを判定
        if (other->getLeft() < this->left + this->width && 
            other->getLeft() + other->getWidth() > this->left && 
            other->getBottom() < this->bottom + this->height && 
            other->getBottom() + other->getHeight() > this->bottom) {
            return true; // 重なっている
        }
        return false; // 重なっていない
    }
};
