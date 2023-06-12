#pragma once

#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

struct hit_record {
    point3 p;
    vec3 normal;
    double t;

    bool front_face;

    // 朝外的表面法线 与 射线的 点乘，如果小于0，说明射线是从外往里射的，法线是朝外
    // 反之， 朝外的表面法线 与 射线的 点乘 大于0， 说明射线是从里往外射的，法线得朝里，所以取反
    inline void set_face_normal(const ray& r, const vec3& outward_normal) {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal :-outward_normal;
    }

};

class hittable {
public:
    virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};

#endif