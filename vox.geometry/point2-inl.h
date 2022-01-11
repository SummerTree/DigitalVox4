// Copyright (c) 2018 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef INCLUDE_JET_DETAIL_POINT2_INL_H_
#define INCLUDE_JET_DETAIL_POINT2_INL_H_

#include "macros.h"
#include "math_utils.h"

#include <algorithm>
#include <cassert>

namespace jet {

// Constructors
template <typename T>
template <typename U>
Point<T, 2>::Point(const std::initializer_list<U>& lst) {
    set(lst);
}

// Basic setters
template <typename T>
void Point<T, 2>::set(T s) {
    value << s, s;
}

template <typename T>
void Point<T, 2>::set(T newX, T newY) {
    value << newX, newY;
}

template <typename T>
template <typename U>
void Point<T, 2>::set(const std::initializer_list<U>& lst) {
    JET_ASSERT(lst.size() >= 2);

    auto inputElem = lst.begin();
    value << static_cast<T>(*inputElem), static_cast<T>(*(++inputElem));
}

template <typename T>
void Point<T, 2>::set(const Point& v) {
    value = v.value;
}

template <typename T>
void Point<T, 2>::setZero() {
    value.setZero();
}

// Binary operators: new instance = this (+) v
template <typename T>
Point<T, 2> Point<T, 2>::add(T v) const {
    return Point(value + ValueType(v, v));
}

template <typename T>
Point<T, 2> Point<T, 2>::add(const Point& v) const {
    return Point(value + v.value);
}

template <typename T>
Point<T, 2> Point<T, 2>::sub(T v) const {
    return Point(value - ValueType(v, v));
}

template <typename T>
Point<T, 2> Point<T, 2>::sub(const Point& v) const {
    return Point(value - v.value);
}

template <typename T>
Point<T, 2> Point<T, 2>::mul(T v) const {
    return Point(value * v);
}

template <typename T>
Point<T, 2> Point<T, 2>::mul(const Point& v) const {
    return Point(value.cwiseProduct(v.value));
}

template <typename T>
Point<T, 2> Point<T, 2>::div(T v) const {
    return Point(value / v);
}

template <typename T>
Point<T, 2> Point<T, 2>::div(const Point& v) const {
    return Point(value.cwiseQuotient(v.value));
}

// Binary operators: new instance = v (+) this
template <typename T>
Point<T, 2> Point<T, 2>::rsub(T v) const {
    return Point(ValueType(v, v) - value);
}

template <typename T>
Point<T, 2> Point<T, 2>::rsub(const Point& v) const {
    return Point(v.value - value);
}

template <typename T>
Point<T, 2> Point<T, 2>::rdiv(T v) const {
    return Point(ValueType(v, v).cwiseQuotient(value));
}

template <typename T>
Point<T, 2> Point<T, 2>::rdiv(const Point& v) const {
    return Point(v.value.cwiseQuotient(value));
}

// Augmented operators: this (+)= v
template <typename T>
void Point<T, 2>::iadd(T v) {
    value += ValueType(v, v);
}

template <typename T>
void Point<T, 2>::iadd(const Point& v) {
    value += v.value;
}

template <typename T>
void Point<T, 2>::isub(T v) {
    value -= ValueType(v, v);
}

template <typename T>
void Point<T, 2>::isub(const Point& v) {
    value -= v.value;
}

template <typename T>
void Point<T, 2>::imul(T v) {
    value *= v;
}

template <typename T>
void Point<T, 2>::imul(const Point& v) {
    value = value.cwiseProduct(v.value);
}

template <typename T>
void Point<T, 2>::idiv(T v) {
    value /= v;
}

template <typename T>
void Point<T, 2>::idiv(const Point& v) {
    value = value.cwiseQuotient(v.value);
}

// Basic getters
template <typename T>
const T& Point<T, 2>::at(size_t i) const {
    assert(i < 2);
    return value[i];
}

template <typename T>
T& Point<T, 2>::at(size_t i) {
    assert(i < 2);
    return value[i];
}

template <typename T>
T Point<T, 2>::sum() const {
    return value.sum();
}

template <typename T>
T Point<T, 2>::min() const {
    return value.minCoeff();
}

template <typename T>
T Point<T, 2>::max() const {
    return value.maxCoeff();
}

template <typename T>
T Point<T, 2>::absmin() const {
    return jet::absmin(value[0], value[1]);
}

template <typename T>
T Point<T, 2>::absmax() const {
    return jet::absmax(value[0], value[1]);
}

template <typename T>
size_t Point<T, 2>::dominantAxis() const {
    return (std::fabs(value[0]) > std::fabs(value[1])) ? 0 : 1;
}

template <typename T>
size_t Point<T, 2>::subminantAxis() const {
    return (std::fabs(value[0]) < std::fabs(value[1])) ? 0 : 1;
}

template <typename T>
template <typename U>
Point2<U> Point<T, 2>::castTo() const {
    return Point2<U>(static_cast<U>(value[0]), static_cast<U>(value[1]));
}

template <typename T>
bool Point<T, 2>::isEqual(const Point& other) const {
        return value == other.value;
}

// Operators
template <typename T>
T& Point<T, 2>::operator[](size_t i) {
    assert(i < 2);
    return value[i];
}

template <typename T>
const T& Point<T, 2>::operator[](size_t i) const {
    assert(i < 2);
    return value[i];
}

template <typename T>
Point<T, 2>& Point<T, 2>::operator=(const std::initializer_list<T>& lst) {
    set(lst);
    return (*this);
}

template <typename T>
Point<T, 2>& Point<T, 2>::operator=(const Point& v) {
    set(v);
    return (*this);
}

template <typename T>
Point<T, 2>& Point<T, 2>::operator+=(T v) {
    iadd(v);
    return (*this);
}

template <typename T>
Point<T, 2>& Point<T, 2>::operator+=(const Point& v) {
    iadd(v);
    return (*this);
}

template <typename T>
Point<T, 2>& Point<T, 2>::operator-=(T v) {
    isub(v);
    return (*this);
}

template <typename T>
Point<T, 2>& Point<T, 2>::operator-=(const Point& v) {
    isub(v);
    return (*this);
}

template <typename T>
Point<T, 2>& Point<T, 2>::operator*=(T v) {
    imul(v);
    return (*this);
}

template <typename T>
Point<T, 2>& Point<T, 2>::operator*=(const Point& v) {
    imul(v);
    return (*this);
}

template <typename T>
Point<T, 2>& Point<T, 2>::operator/=(T v) {
    idiv(v);
    return (*this);
}

template <typename T>
Point<T, 2>& Point<T, 2>::operator/=(const Point& v) {
    idiv(v);
    return (*this);
}

template <typename T>
bool Point<T, 2>::operator==(const Point& v) const {
    return isEqual(v);
}

template <typename T>
bool Point<T, 2>::operator!=(const Point& v) const {
    return !isEqual(v);
}

// Math functions
template <typename T>
Point<T, 2> operator+(const Point<T, 2>& a) {
    return a;
}

template <typename T>
Point<T, 2> operator-(const Point<T, 2>& a) {
    return Point<T, 2>(-a.x, -a.y);
}

template <typename T>
Point<T, 2> operator+(const Point<T, 2>& a, T b) {
    return a.add(b);
}

template <typename T>
Point<T, 2> operator+(T a, const Point<T, 2>& b) {
    return b.add(a);
}

template <typename T>
Point<T, 2> operator+(const Point<T, 2>& a, const Point<T, 2>& b) {
    return a.add(b);
}

template <typename T>
Point<T, 2> operator-(const Point<T, 2>& a, T b) {
    return a.sub(b);
}

template <typename T>
Point<T, 2> operator-(T a, const Point<T, 2>& b) {
    return b.rsub(a);
}

template <typename T>
Point<T, 2> operator-(const Point<T, 2>& a, const Point<T, 2>& b) {
    return a.sub(b);
}

template <typename T>
Point<T, 2> operator*(const Point<T, 2>& a, T b) {
    return a.mul(b);
}

template <typename T>
Point<T, 2> operator*(T a, const Point<T, 2>& b) {
    return b.rmul(a);
}

template <typename T>
Point<T, 2> operator*(const Point<T, 2>& a, const Point<T, 2>& b) {
    return a.mul(b);
}

template <typename T>
Point<T, 2> operator/(const Point<T, 2>& a, T b) {
    return a.div(b);
}

template <typename T>
Point<T, 2> operator/(T a, const Point<T, 2>& b) {
    return b.rdiv(a);
}

template <typename T>
Point<T, 2> operator/(const Point<T, 2>& a, const Point<T, 2>& b) {
    return a.div(b);
}

template <typename T>
Point<T, 2> min(const Point<T, 2>& a, const Point<T, 2>& b) {
    return Point<T, 2>(a.value.cwiseMin(b.value));
}

template <typename T>
Point<T, 2> max(const Point<T, 2>& a, const Point<T, 2>& b) {
    return Point<T, 2>(a.value.cwiseMax(b.value));
}

template <typename T>
Point<T, 2> clamp(
    const Point<T, 2>& v, const Point<T, 2>& low, const Point<T, 2>& high) {
    return Point<T, 2>(clamp(v.x(), low.x(), high.x()), clamp(v.y(), low.y(), high.y()));
}

template <typename T>
Point<T, 2> ceil(const Point<T, 2>& a) {
    return Point<T, 2>(std::ceil(a.x()), std::ceil(a.y()));
}

template <typename T>
Point<T, 2> floor(const Point<T, 2>& a) {
    return Point<T, 2>(std::floor(a.x()), std::floor(a.y()));
}

}  // namespace jet

#endif  // INCLUDE_JET_DETAIL_POINT2_INL_H_
