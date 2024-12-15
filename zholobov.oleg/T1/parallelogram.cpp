#include "parallelogram.hpp"

Parallelogram::Parallelogram():
  pos_{},
  p1_{},
  p2_{}
{}

Parallelogram::Parallelogram(const point_t& p1, const point_t& p2, const point_t& p3):
  p1_(p1),
  p2_(p2)
{
  pos_.x = (p2.x + p3.x) / 2.0f;
  pos_.y = (p2.y + p3.y) / 2.0f;
}

float Parallelogram::getArea(){
  return (p2_.x - p1_.x) * (pos_.y - p1_.y) * 2.0f; 
}

rectangle_t Parallelogram::getFrameRect()
{
  rectangle_t rect;
  rect.pos = pos_;
  rect.height = (pos_.y - p1_.y) * 2.0f;
  rect.width = (pos_.x - p1_.x) * 2.0f;
  return rect;
}

void Parallelogram::move(point_t p)
{
  pos_ = p;
}

void Parallelogram::move(float dx, float dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Parallelogram::scale(float k)
{
  p1_.x = (p1_.x - pos_.x) * k + pos_.x;
  p1_.y = (p1_.y - pos_.y) * k + pos_.y;  
  p2_.x = (p2_.x - pos_.x) * k + pos_.x;
  p2_.y = (p2_.y - pos_.y) * k + pos_.y;
}
