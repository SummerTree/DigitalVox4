//
//  plane3-inl.h
//  DigitalVox4
//
//  Created by 杨丰 on 2022/1/16.
//

#ifndef plane3_inl_h
#define plane3_inl_h

namespace vox {
template <typename T>
Plane<T, 3>::Plane() : Plane(Vector3<T>(), 0)  {
    
}

template <typename T>
Plane<T, 3>::Plane(const Vector3<T>& newNormal, const T& newDistance):
normal(newNormal),
distance(newDistance){
}

template <typename T>
Plane<T, 3>::Plane(const Vector3<T>& point0, const Vector3<T>& point1, const Vector3<T>& point2) {
    T x0 = point0.x;
    T y0 = point0.y;
    T z0 = point0.z;
    T x1 = point1.x - x0;
    T y1 = point1.y - y0;
    T z1 = point1.z - z0;
    T x2 = point2.x - x0;
    T y2 = point2.y - y0;
    T z2 = point2.z - z0;
    T yz = y1 * z2 - z1 * y2;
    T xz = z1 * x2 - x1 * z2;
    T xy = x1 * y2 - y1 * x2;
    T invPyth = 1.0 / std::sqrt(yz * yz + xz * xz + xy * xy);

    T x = yz * invPyth;
    T y = xz * invPyth;
    T z = xy * invPyth;

    normal.x = x;
    normal.y = y;
    normal.z = z;
    distance = -(x * x0 + y * y0 + z * z0);
}

template <typename T>
Plane<T, 3>::Plane(const Plane& other):
normal(other.normal),
distance(other.distance) {
}

template <typename T>
Plane<T, 3> Plane<T, 3>::normalized() const {
    T factor = 1.0 / normal.length();

    Vector3<T> outNormal(normal.x * factor,
                         normal.y * factor,
                         normal.z * factor);
    return Plane<T, 3>(outNormal, distance * factor);
}

template <typename T>
void Plane<T, 3>::normalize() {
    T factor = 1.0 / normal.length();

    normal.x *= factor;
    normal.y *= factor;
    normal.z *= factor;
    distance *= factor;
}

}

#endif /* plane3_inl_h */
