//
//  KMPoint.h
//  K-Means Clustering
//
//  Created by Jakub Nabaglo on 20/05/2015.
//  Copyright (c) 2015 Jakub Nabaglo. All rights reserved.
//

#ifndef __K_Means_Clustering__KMPoint__
#define __K_Means_Clustering__KMPoint__

#import <stdio.h>

template<size_t D, typename C>
class KMPoint {
private:
    C coords[D];
public:
    void operator-=(const KMPoint &other) {
        for (size_t i=0; i<D; ++i)
            coords[i] -= other.coords[i];
    }
    void operator+=(const KMPoint &other) {
        for (size_t i=0; i<D; ++i)
            coords[i] += other.coords[i];
    }
    void operator*=(const C other) {
        for (size_t i=0; i<D; ++i)
            coords[i] *= other;
    }
    void operator/=(const C other) {
        for (size_t i=0; i<D; ++i)
            coords[i] /= other;
    }
    
    bool operator==(const KMPoint &other) const {
        for (size_t i=0; i<D; ++i)
            if (coords[i] != other.coords[i])
                return false;
        return true;
    }
    C norm_sq() const {
        C norm = coords[0];
        for (size_t i=1; i<D; ++i) norm += coords[i]*coords[i];
        return norm;
    }
};

template<size_t D, typename C>
KMPoint<D,C> operator-(const KMPoint<D,C> &point1, const KMPoint<D,C> &point2) {
    KMPoint<D,C> result = point1;
    result -= point2;
    return result;
}
template<size_t D, typename C>
KMPoint<D,C> operator+(const KMPoint<D,C> &point1, const KMPoint<D,C> &point2) {
    KMPoint<D,C> result = point1;
    result += point2;
    return result;
}
template<size_t D, typename C>
KMPoint<D,C> operator*(const KMPoint<D,C> &point1, C scalar) {
    KMPoint<D,C> result = point1;
    result *= scalar;
    return result;
}
template<size_t D, typename C>
KMPoint<D,C> operator/(const KMPoint<D,C> &point1, C scalar) {
    KMPoint<D,C> result = point1;
    result /= scalar;
    return result;
}
template<size_t D, typename C>
KMPoint<D,C> operator*(C scalar, const KMPoint<D,C> &point1) {
    KMPoint<D,C> result = point1;
    result *= scalar;
    return result;
}
template<size_t D, typename C>
KMPoint<D,C> operator/(C scalar, const KMPoint<D,C> &point1) {
    KMPoint<D,C> result = point1;
    result /= scalar;
    return result;
}


#endif /* defined(__K_Means_Clustering__KMPoint__) */
