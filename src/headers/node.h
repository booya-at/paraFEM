#ifndef NODE_H
#define NODE_H

#include "base.h"
#include "eigen3/Eigen/Geometry"
#include <memory>


namespace paraFEM
{

typedef Eigen::Vector3d Vector3;
typedef Eigen::Vector2d Vector2;
    
class Node: Base
{
public:
    Node(double x, double y, double z);
    Vector3 previous_position;
    
    Vector3 position;
    Vector3 velocity;
    Vector3 acceleration;
    
    Vector3 externalForce;
    Vector3 internalForce;
    
    double massInfluence;

    void solveEquilibrium(double h);
    Vector3 fixed;
    
    int nr;
};

typedef std::shared_ptr<Node> NodePtr;
typedef std::vector<NodePtr> NodeVec;

}
#endif