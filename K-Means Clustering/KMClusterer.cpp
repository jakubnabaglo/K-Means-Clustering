//
//  KMClusterer.cpp
//  K-Means Clustering
//
//  Created by Jakub Nabaglo on 20/05/2015.
//  Copyright (c) 2015 Jakub Nabaglo. All rights reserved.
//

#include "KMClusterer.h"

#include <cstdlib>
#include <ctime>

#define UNDEFINED_INT ((int)((unsigned int)-1))

using namespace std; // omg

template<size_t D, typename C>
vector<int> initialClusters(size_t clusterNum, vector<KMPoint<D, C>> points);

template<size_t D, typename C>
vector<int> clustersFromMeans(vector<KMPoint<D, C>> points, vector<KMPoint<D, C>> means);

template<size_t D, typename C>
vector<KMPoint<D, C>> meansFromClusters(vector<KMPoint<D, C>> points, vector<int> clusters, size_t clusterNum);



template<size_t D, typename C>
vector<int> findClustersForPoints(size_t clusterNum, vector<KMPoint<D, C>> points) {
    vector<int> clusters = initialClusters(clusterNum, points);
    vector<KMPoint<D, C>> means = meansFromClusters(points, clusters);
    
    while (true) { // I know, I know
        vector<int> newClusters = clustersFromMeans(points, means);
        for (size_t i=0; i<clusters.size(); ++i)
            if (clusters[i] == newClusters[i]) {
                clusters = newClusters;
                goto endLoop; // not changed
            }
        clusters = newClusters;
        means = meansFromClusters(points, clusters, clusterNum);
    }
endLoop:
    return clusters;
}


template<size_t D, typename C>
vector<int> initialClusters(size_t clusterNum, vector<KMPoint<D, C>> points) {
    srand((unsigned int)time(0));
    size_t size = points.size();
    vector<int> clusters(size);
    for (size_t i=0; i<size; ++i) clusters[i] = rand() % clusterNum;
    return clusters;
}

template<size_t D, typename C>
vector<int> clustersFromMeans(vector<KMPoint<D, C>> points, vector<KMPoint<D, C>> means) {
    size_t size = points.size();
    size_t clusterNum = means.size();
    vector<int> clusters(clusterNum);
    for (int i=0; i<size; ++i) {
        int closestCluster = 0;
        C shortestDistance = (means[0]-points[i]).norm_sq();
        for (int j=1; i<clusterNum; ++j) {
            C newDistance = (means[j]-points[i]).norm_sq();
            if (newDistance < shortestDistance) {
                shortestDistance = newDistance;
                closestCluster = j;
            }
        }
        clusters[i] = closestCluster;
    }
}

template<size_t D, typename C>
vector<KMPoint<D, C>> meansFromClusters(vector<KMPoint<D, C>> points, vector<int> clusters, size_t clusterNum) {
    size_t size = points.size();
    vector<KMPoint<D, C>> means(clusterNum);
    vector<size_t> counts(clusterNum);
    for (size_t i=0; i<clusterNum; ++i) counts[i] = 0;
    for (size_t i=0; i<size; ++i) {
        int cluster = clusters[i];
        if (counts[cluster] == 0)
            means[cluster] = points[i];
        else
            means[cluster] += points[i];
        ++counts[cluster];
    }
    return means;
}