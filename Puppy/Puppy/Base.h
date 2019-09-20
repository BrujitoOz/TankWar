#pragma once
#include <iostream>
#include <string.h>
using namespace System;
using namespace System::Drawing;
class Base{
protected:
	int x, y, dx, dy, l, a, vidas;
	bool Eliminar;
	char* PathIMG;
public:
	Base();
	~Base();
	void SetX(int X);
	void SetY(int y);
	void SetDX(int dx);
	void SetDY(int dy);
	void SetL(int l);
	void SetA(int a);
	void SetVidas(int vidas);
	void SetEliminar(bool eliminar);
	void SetPathIMG(char* nuevo);
	int GetX();
	int GetY();
	int GetDX();
	int GetDY();
	int GetL();
	int GetA();
	int GetVidas();
	bool GetEliminar();
	char* GetPathIMG();
};
Base::Base() {
}
Base::~Base() {
}
void Base::SetX(int x) {
	this->x = x;
}
void Base::SetY(int y) {
	this->y = y;
}
void Base::SetDX(int dx) {
	this->dx = dx;
}
void Base::SetDY(int dy) {
	this->dy = dy;
}
void Base::SetL(int l) {
	this->l = l;
}
void Base::SetA(int a) {
	this->a = a;
}
void Base::SetVidas(int vidas) {
	this->vidas = vidas;
}
void Base::SetEliminar(bool eliminar) {
	this->Eliminar = eliminar;
}
void Base::SetPathIMG(char* nuevo) {
	this->PathIMG = new char[100];
	strcpy(this->PathIMG, nuevo);
}
int Base::GetX() {
	return x;
}
int Base::GetY() {
	return y;
}
int Base::GetDX() {
	return dx;
}
int Base::GetDY() {
	return dy;
}
int Base::GetL() {
	return l;
}
int Base::GetA() {
	return a;
}
int Base::GetVidas() {
	return vidas;
}
bool Base::GetEliminar() {
	return Eliminar;
}
char* Base::GetPathIMG() {
	return this->PathIMG;
}