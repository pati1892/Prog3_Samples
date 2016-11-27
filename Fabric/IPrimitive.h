#pragma once
class IPrimitive
{
public:
	virtual ~IPrimitive(); // virtual for delete override

	virtual void Draw() = 0;
	virtual void setWidth(int widthVal) = 0;
	virtual void setHeight(int heightVal) = 0;
	virtual void setLeftUpper(int X, int Y) = 0;
	virtual void setRect(int X, int Y, int widthVal, int heightVal) = 0;
};

class APrimitive : public IPrimitive
{
public:
	APrimitive() : x{ 0 }, y{ 0 }, width{ 0 }, height{ 0 } {};
	virtual ~APrimitive() override {}

	virtual void setWidth(int widthVal) override;
	virtual void setHeight(int heightVal) override ;
	virtual void setLeftUpper(int X, int Y) override;
	virtual void setRect(int X, int Y, int widthVal, int heightVal) override;

protected:
	int x;
	int y;
	int width;
	int height;
};
