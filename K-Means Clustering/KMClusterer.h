//
//  KMClusterer.h
//  K-Means Clustering
//
//  Created by Jakub Nabaglo on 20/05/2015.
//  Copyright (c) 2015 Jakub Nabaglo. All rights reserved.
//

#ifndef __K_Means_Clustering__KMClusterer__
#define __K_Means_Clustering__KMClusterer__

#include <stdio.h>
#include "KMPoint.h"
#include <vector>

template<size_t D, typename C>
std::vector<int> findClustersForPoints(size_t clusterNum, std::vector<KMPoint<D, C>> points);


#endif /* defined(__K_Means_Clustering__KMClusterer__) */
