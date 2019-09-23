#pragma once
#include "Base.h"
class Disco : public Base {
public:
	Disco();
	~Disco();
	void Draw(Graphics^ g);
};
Disco::Disco() {
}
Disco::~Disco() {
}
void Disco::Draw(Graphics^ g) {
	Color micolor = System::Drawing::Color::FromArgb(234, 190, 63);
	System::Drawing::SolidBrush^ brocha = gcnew System::Drawing::SolidBrush(micolor);
	System::Drawing::Pen^ p = gcnew System::Drawing::Pen(micolor);
	if (x > 0 && y > 0) {
		g->DrawEllipse(p, x, y, l, a);
		g->FillEllipse(brocha, x, y, l, a);
	}
}