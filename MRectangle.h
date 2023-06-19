#include <iostream>

class MRectangle {
private:
    float left;   // 左下のx座標
    float bottom; // 左下のy座標
    float width;  // 幅
    float height; // 高さ

public:
    // コンストラクタ
    MRectangle(float left, float bottom, float width, float height) 
    : left(left), bottom(bottom), width(width), height(height) {}

    // ゲッターメソッド
    float getLeft() const { return left; }
    float getBottom() const { return bottom; }
    float getWidth() const { return width; }
    float getHeight() const { return height; }

    // 他のMRectangleとの重なりを判定するメソッド
    bool intersectsWith(const MRectangle& other) const {
        // thisとotherの座標を比較して重なりを判定
        if (other.getLeft() < this->left + this->width && 
            other.getLeft() + other.getWidth() > this->left && 
            other.getBottom() < this->bottom + this->height && 
            other.getBottom() + other.getHeight() > this->bottom) {
            return true; // 重なっている
        }
        return false; // 重なっていない
    }
};
